# Pointers
### Everything you need to know about pointers, from first principles to advanced tricks, across your entire journey (Linked Lists → Trees → Graphs → Advanced CP)

---

## How to use this doc
This is a **reference you'll outgrow gradually**, not a one-time read. Sections 1–5 you need *now* (before Linked Lists). Sections 6–9 you'll need soon (Trees/Graphs). Sections 10–13 are CP-specific tricks you'll appreciate more once you've solved 50+ problems. Come back to this file every few weeks.

---

## 1. The Absolute Fundamentals

### 1.1 What a pointer really is
A pointer is a variable. Nothing magical. It just happens to store **a memory address** instead of an ordinary value like `5` or `'a'`.

```cpp
int x = 42;
int* p = &x;
```

Think of memory as a giant street of numbered houses. `x` lives at some house number, say `1000`. `p` is a separate variable that stores the number `1000` written on a piece of paper. `p` doesn't *contain* `42` — it contains the *address where 42 lives*.

### 1.2 The three core operators

| Operator | Name | Meaning |
|---|---|---|
| `&x` | Address-of | "Give me the address where `x` lives" |
| `*p` | Dereference | "Go to the address in `p`, give me what's stored there" |
| `p->field` | Arrow (dereference + member access) | Shorthand for `(*p).field` |

```cpp
int x = 42;
int* p = &x;
cout << p;    // prints an address like 0x7ffee3a1c
cout << *p;   // prints 42 (follows the address, reads the value)
*p = 100;     // follows the address, WRITES 100 there — x is now 100!
```

This last line is important: **dereferencing a pointer lets you both read AND write the original variable.** This is why pointers let functions "reach back" and modify things outside their own scope.

### 1.3 Stack vs Heap — memory's two neighborhoods

| | Stack | Heap |
|---|---|---|
| Lifetime | Auto-destroyed when function returns | Lives until you explicitly `delete` it (or program ends) |
| Speed | Very fast | Slower (bookkeeping overhead) |
| Size known at compile time? | Usually yes | No — can be decided at runtime |
| How you get it | Just declare a variable: `int x;` | `new` keyword: `int* p = new int;` |
| Used for | Local variables, function calls | Linked structures (lists, trees, graphs), anything needing to outlive its creating function, dynamically-sized data |

**Why DSA cares:** A linked list node must exist even after the function that created it returns, and the total number of nodes isn't known ahead of time. That's a heap job, always.

```cpp
ListNode* buildNode() {
    ListNode local(5);        // STACK — destroyed when function ends. BAD if you return &local!
    ListNode* heapNode = new ListNode(5);  // HEAP — survives, safe to return
    return heapNode;           // fine
}
```

**Golden rule:** Never return the address of a stack (local) variable from a function. It will be garbage the moment the function returns. This is called a **dangling pointer**, covered in section 4.

---

## 2. Pointer Declaration & Types — Precision Matters

### 2.1 Reading pointer declarations right-to-left
```cpp
int* p;          // p is a pointer to an int
int** pp;        // pp is a pointer to a pointer to an int
const int* p;    // p is a pointer to a CONST int (can't change *p, CAN change p)
int* const p;    // p is a CONST pointer to an int (can change *p, CAN'T change p)
const int* const p;  // neither can change
```

This trips up almost everyone at first. Trick: read from the variable name outward.
- `const int* p` → start at `p`, it's a pointer(`*`)... to a `const int`. So the **int** is const, not the pointer.
- `int* const p` → start at `p`, it's `const`, pointer to `int`. So the **pointer itself** is const (can't be reassigned), but you can freely modify what it points to.

### 2.2 Why this matters in DSA/CP
You'll rarely need `const int* const` gymnastics in basic DSA, but you WILL constantly see and write:
```cpp
void printList(ListNode* head) {  // head is a plain pointer — can walk it, can't affect caller's head
    while (head) {
        cout << head->val << " ";
        head = head->next;  // fine — only changes local copy
    }
}
```
And in function signatures where you promise not to modify data:
```cpp
int getLength(const ListNode* head) {  // promises: I will NOT modify any node's contents
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}
```

---

## 3. Pointers vs References — Know the Difference Cold

| | Pointer | Reference |
|---|---|---|
| Syntax | `int* p = &x;` | `int& r = x;` |
| Can be null? | Yes (`nullptr`) | No — must always refer to something |
| Can be reassigned to point elsewhere? | Yes | No — bound forever to its initial variable |
| Needs dereferencing (`*`) to access value? | Yes | No — used just like the original variable |
| Common DSA use | Traversal, dynamic structures, optional "may not exist" (nullptr) | Function parameters to avoid copying, especially large objects |

```cpp
int x = 5, y = 10;

int* p = &x;
p = &y;        // fine, p now points to y

int& r = x;
// r = &y;     // ERROR — can't rebind a reference, this would just assign y's VALUE into x!
r = y;         // this makes x = 10 (copies y's value into x, since r IS x)
```

### When to use which in DSA
- **Pointer**: when the thing might not exist (`nullptr` is a valid "nothing here" state) — perfect for linked list `next`, tree `left`/`right`, optional results.
- **Reference**: when passing large objects (vectors, strings) to avoid expensive copies, and the thing definitely always exists.

```cpp
void process(vector<int>& nums) { ... }   // reference: avoid copying a potentially huge vector
ListNode* next;                            // pointer: "next" might legitimately be nothing (nullptr)
```

---

## 4. Dangerous Pointer States — Know These by Name

| State | What it means | Example |
|---|---|---|
| **Null pointer** | Explicitly points to nothing, safe to check | `ListNode* p = nullptr;` |
| **Dangling pointer** | Points to memory that has been freed/destroyed — using it is undefined behavior | Returning address of a local stack variable, or using a pointer after `delete` |
| **Wild pointer** | Never initialized at all — points to garbage/random memory | `ListNode* p; p->val = 5;` (never assigned!) |
| **Uninitialized pointer** | Same as wild — declared but never given a valid address | `int* p; cout << *p;` |

### Rule to live by
**Every pointer should be either `nullptr` or a valid address — never left in limbo.** Always initialize:
```cpp
ListNode* p = nullptr;   // explicit, safe default
// NOT: ListNode* p;     // garbage value, dangerous
```

### The dangling pointer trap in DSA specifically
```cpp
ListNode* deleteNode(ListNode* node) {
    ListNode* nextNode = node->next;
    delete node;
    return node;   // BUG: node is now dangling — you deleted it, then tried to use it!
}
```
Once you `delete node`, the address is no longer yours to use. Even reading `node->val` after `delete node` is undefined behavior — it might "work" by accident sometimes, then crash randomly later. This is one of the nastiest classes of bugs precisely because it doesn't always crash immediately.

---

## 5. Dynamic Memory Management — `new` / `delete` in Depth

### 5.1 The full picture
```cpp
ListNode* node = new ListNode(5);  // (1) allocate heap memory  (2) run constructor  (3) return address
delete node;                        // (1) run destructor  (2) free memory back to OS
```

### 5.2 Memory leaks — the silent killer
```cpp
void leaky() {
    ListNode* node = new ListNode(5);
    // function ends, "node" (the pointer variable) is destroyed
    // but the MEMORY IT POINTED TO is never freed — it's now unreachable AND still reserved
    // this is a memory leak
}
```
On LeetCode, this genuinely doesn't matter (process runs once, exits, OS reclaims everything). In real systems running for days/weeks, this is how servers slowly run out of memory and crash.

### 5.3 Double-free — a real crash risk
```cpp
delete node;
delete node;   // CRASH or undefined behavior — you already freed this memory once
```
Fix: after deleting, it's good practice to set `node = nullptr;` so a second accidental delete is at least a safe no-op (`delete nullptr;` is explicitly safe and does nothing).

### 5.4 `new[]` / `delete[]` for arrays — must match
```cpp
int* arr = new int[10];
delete[] arr;   // MUST use delete[] for array new — plain delete is undefined behavior here
```

### 5.5 Smart pointers (know they exist, use later)
Modern C++ mostly avoids raw `new`/`delete` using **smart pointers**, which auto-delete when no longer needed:
```cpp
#include <memory>
unique_ptr<ListNode> node = make_unique<ListNode>(5);  // auto-deleted when it goes out of scope
shared_ptr<ListNode> shared = make_shared<ListNode>(5); // reference-counted, deleted when last owner gone
```
**For now:** LC/CP problems almost universally use raw pointers (`ListNode*`) because judges pre-define `struct ListNode` that way, and the simplicity matters more than leak-safety in a contest/interview setting. Just know smart pointers exist for when you write production C++ later.

---

## 6. Pointer Arithmetic & Arrays

### 6.1 Arrays and pointers are deeply related
```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* p = arr;        // arrays "decay" to a pointer to their first element
cout << *p;           // 10
cout << *(p + 1);     // 20 — pointer arithmetic moves by sizeof(int), not by 1 byte
cout << p[2];         // 30 — arr[i] is literally defined as *(arr + i)
```

**Critical insight:** `p + 1` doesn't mean "address + 1 byte." It means "address + 1 × sizeof(the pointed-to type)." This is why `int* p; p+1` jumps 4 bytes (on most systems), while `char* c; c+1` jumps just 1 byte. The compiler handles this scaling for you.

### 6.2 Why this matters less in modern DSA/CP
Most LC/CP work uses `vector<int>` rather than raw arrays, and vectors don't need manual pointer arithmetic — you use `[]` or iterators. But understanding *why* `arr[i]` works reveals why arrays have O(1) random access (direct address computation) while linked lists don't (must walk one `next` at a time — no arithmetic shortcut exists when nodes aren't contiguous in memory).

### 6.3 Iterators are basically pointers
```cpp
vector<int> v = {1,2,3};
vector<int>::iterator it = v.begin();
cout << *it;      // dereference, just like a raw pointer
it++;             // move forward, just like pointer arithmetic
```
This is not a coincidence — STL iterators are deliberately designed to feel like pointers, because pointers were the original "walk through memory" tool in C, and C++ generalized the idea.

---

## 7. Pointer-to-Pointer & Reference-to-Pointer

Already covered in the previous doc's Section 5, but here's the fuller picture for when this generalizes beyond linked lists:

```cpp
void modifyPointer(ListNode** pp) {
    *pp = nullptr;   // changes what the CALLER's pointer points to
}

void modifyPointerRef(ListNode*& p) {
    p = nullptr;     // same effect, cleaner syntax
}

int main() {
    ListNode* head = new ListNode(1);
    modifyPointer(&head);       // must pass address of the pointer itself
    modifyPointerRef(head);     // just pass the pointer, reference handles the rest
}
```

### Where this shows up beyond Linked Lists
- **Trees**: deleting the root, or rebalancing where the root itself might change (AVL/Red-Black tree rotations).
- **Recursive builders**: building a tree/list recursively where each recursive call might need to set a parent's child pointer.
- **Union-Find / DSU**: path compression modifies pointers (or parent array indices, which are conceptually the same idea) during traversal.

---

## 8. Pointers in Structs/Classes Beyond Linked Lists

The self-referential struct trick from Linked Lists generalizes directly:

```cpp
// Binary Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Graph (adjacency list is more common, but node-pointer style graphs exist too)
struct GraphNode {
    int val;
    vector<GraphNode*> neighbors;
};

// Doubly Linked List
struct DListNode {
    int val;
    DListNode* prev;
    DListNode* next;
};
```

**Mental model upgrade:** A linked list is a chain (1 pointer forward). A tree is a chain that branches (2+ pointers forward, no pointer back up unless you add a `parent` pointer). A graph is a chain that can branch AND merge AND cycle (pointers can point anywhere, including back to earlier nodes). All three are "pointer thinking" — you're always asking "what does *this* node currently point to?"

---

## 9. Common Pointer Bugs Checklist (Debug Against This List)

| Bug | Symptom | Fix |
|---|---|---|
| Dereferencing `nullptr` | Segfault / crash | Check `if (p)` before `p->...` |
| Dangling pointer (use-after-delete) | Random garbage values, intermittent crashes | Never use a pointer after `delete`; set to `nullptr` after deleting |
| Memory leak | Memory usage climbs over time (not visible on LC, visible in real systems) | Match every `new` with a `delete` in real code |
| Double free | Crash on second `delete` | Set pointer to `nullptr` after first delete |
| Off-by-one pointer arithmetic | Reads/writes one element too far, corrupting memory | Double check loop bounds (`<` vs `<=`) |
| Forgetting to update `next` when inserting/deleting a node | List gets "cut" or a node becomes unreachable | Draw the before/after arrows explicitly before coding |
| Losing the only reference to a node before rewiring | Memory leak or lost sublist | Save `nextNode = curr->next` BEFORE changing `curr->next` |
| Passing pointer by value when caller needs the change | Caller's pointer looks "unchanged" after function call | Use `Node*&` or return the new pointer |

---

## 10. The Master Pattern List — Pointer Tricks Across All of DSA/CP

These are the pointer-based *techniques* you'll reuse constantly, organized by where they first appear and where they reappear later.

### 10.1 Two Pointers (same direction, different speeds)
**First seen:** Linked list middle/cycle detection.
**Reused in:** Array problems (fast/slow for cycle detection in `nums` treated as implicit linked list, e.g., LC 287 Find the Duplicate Number), sliding window boundaries.
```cpp
ListNode *slow = head, *fast = head;
while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
```

### 10.2 Two Pointers (opposite ends, converging)
**First seen:** Two Sum II (sorted array), palindrome checking.
**Reused in:** Array partitioning, container-with-most-water style problems.
```cpp
int l = 0, r = n - 1;
while (l < r) { ... l++; r--; }
```

### 10.3 Dummy/Sentinel Node
**First seen:** Linked list head-mutation problems.
**Reused in:** Any structure where the "first" element is a special case you want to eliminate from your logic (e.g., building trees, simplifying edge cases in merge operations).
```cpp
ListNode dummy(0);
dummy.next = head;
```

### 10.4 Prev/Curr/Next Triple
**First seen:** Iterative reversal.
**Reused in:** Any in-place rewiring — reversing sublists, rotating lists, deleting with lookahead.
```cpp
ListNode *prev = nullptr, *curr = head, *nxt;
```

### 10.5 Pointer as "Optional" Value
**First seen:** `nullptr` meaning "no next node."
**Reused in:** Tree leaves (`left == nullptr` means no left child), graph "no parent" sentinel, optional return values before `std::optional` existed.

### 10.6 Recursive Pointer Rewiring
**First seen:** Recursive list reversal.
**Reused in:** Tree recursion (build/modify subtrees and return new subtree root), backtracking where you build/unbuild structures via pointers.

### 10.7 Pointer-to-Pointer for Structural Mutation
**First seen:** Changing the head from inside a helper function.
**Reused in:** Tree rotations (AVL/Red-Black), Union-Find path compression, in-place linked structure surgery where multiple levels of pointers need atomic updates.

### 10.8 Multiple Pointers Racing at Different Speeds/Offsets
**First seen:** "Nth node from end" (gap of N).
**Reused in:** Array problems needing a fixed window offset, cycle-start detection (Floyd's second phase).

### 10.9 Pointer Comparison for Identity (not Value)
**Important distinction:** `p1 == p2` compares *addresses* (are they the same node?), not values.
```cpp
ListNode* a = new ListNode(5);
ListNode* b = new ListNode(5);
a == b;        // false! different nodes, even though a->val == b->val is true
a->val == b->val;  // true
```
This matters constantly in problems like "detect intersection of two linked lists" — you're comparing *node identity*, not value equality.

---

## 11. Pointers in Function Signatures — The Full Decision Tree

When designing a function that touches a pointer-based structure, ask in order:

1. **Do I need to modify the actual node's data?** → pass `Node*` (pointer lets you reach through and modify via `->`)
2. **Do I need to modify what the caller's pointer variable points to (i.e., reassign it)?** → pass `Node*&` or return the new pointer (strongly prefer returning — cleaner)
3. **Do I just need to read data, and want to signal "I promise not to modify anything"?** → pass `const Node*`
4. **Is the object large and read-only (like a vector), unrelated to pointer structures?** → pass `const vector<int>&` to avoid a copy

```cpp
void printVal(const ListNode* node);          // read-only access
void setVal(ListNode* node, int v);           // modify node's data
ListNode* insertAtHead(ListNode* head, int v); // may need new head — return it
```

---

## 12. CP-Specific Pointer Knowledge (Beyond Typical Interview DSA)

### 12.1 Passing large structures by reference for speed
In competitive programming, time limits are tight. Passing `vector<vector<int>>` (a 2D grid) by value copies the *entire* grid every function call — brutal for recursion/DFS. Always pass by reference:
```cpp
void dfs(vector<vector<int>>& grid, int i, int j) { ... }   // reference, no copy
```

### 12.2 Pointers to arrays for manual memory-critical code
Rare in LC-style problems, more common in raw competitive programming (especially with C-style arrays for speed):
```cpp
int arr[100005];  // global array — faster than vector in some tight-TLE scenarios, avoids dynamic allocation overhead
```

### 12.3 Function pointers / comparators
```cpp
bool cmp(int a, int b) { return a > b; }  // custom comparator
sort(v.begin(), v.end(), cmp);             // cmp decays to a function pointer here
```
More commonly you'll use lambdas (`[](int a, int b){ return a > b; }`), but know that under the hood, function pointers are exactly the same "store an address" idea, just pointing at *code* instead of *data*.

### 12.4 `this` pointer (once you write classes)
Inside any non-static member function, `this` is an implicit pointer to the current object:
```cpp
class Node {
    int val;
    void setVal(int v) { this->val = v; }  // "this" = pointer to the current object
};
```

---

## 13. The Mastery Ladder — How Your Pointer Understanding Should Evolve

| Stage | You should be comfortable with |
|---|---|
| **Stage 0 (now)** | `*`, `&`, `->`, `nullptr` checks, basic traversal, `new` for single nodes |
| **Stage 1 (Linked Lists)** | Dummy nodes, prev/curr/next rewiring, slow/fast, recursive list manipulation |
| **Stage 2 (Trees)** | Recursive pointer rewiring returning new subtree roots, `nullptr` as "no child," parent pointers if needed |
| **Stage 3 (Graphs)** | Adjacency lists (vectors of pointers or indices), visited-tracking without pointer confusion, avoiding infinite loops via cycles |
| **Stage 4 (Advanced CP)** | Pointer-to-pointer for DSU path compression, function pointers/lambdas for comparators, raw arrays for TLE-sensitive code, awareness of smart pointers for larger C++ projects |
| **Stage 5 (Systems-level, optional)** | Manual memory management discipline (matching every `new`/`delete`), smart pointers (`unique_ptr`, `shared_ptr`, `weak_ptr`) for leak-free real-world code |

---

## 14. Self-Test — Do Not Skip

Before moving further into Linked Lists, answer these without a compiler:

1. What's the difference between a dangling pointer and a null pointer?
2. Why does `arr[i]` on a raw array work in O(1), but you can't do the equivalent on a linked list?
3. If you `delete node` and then later do `if (node == nullptr)`, is that check reliable? (Trick question — think carefully.)
4. Why must `delete[]` be used instead of `delete` for arrays allocated with `new[]`?
5. In `a == b` for two `ListNode*` pointers, what exactly is being compared?
6. Why is `const ListNode*` different from `ListNode* const`?
7. When would you choose `Node*&` over just returning a new `Node*` from a function?

If any answer feels shaky, that's your next 10 minutes of study — not the next LC problem yet.

---

## What's Next

With this pointer foundation, go finish Phase 1 of the Linked List module (LC 206, 21, 876, etc.). Every pattern in Section 10 of this doc will show up again, almost unchanged, when we get to Trees and Graphs — so what you build now compounds.
