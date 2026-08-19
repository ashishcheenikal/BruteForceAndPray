# Ways to Pass a `vector<int>` to a Function

## 1. `const vector<int>& vec` (Constant Reference)

### What it does
Passes the original vector directly **without making a copy**, but makes it **read-only**.

### Behavior
- ✅ No copying (very fast)
- ✅ Saves memory
- ❌ Cannot modify the vector

If you try to modify it:

```cpp
vec[0] = 5;   // ❌ Compilation Error
```

### Use When
- You only need to **read** the vector.
- This is the **recommended default** for DSA and Competitive Programming.

---

## 2. `vector<int>& vec` (Reference)

### What it does
Passes the original vector directly **without making a copy**, while keeping it **read-write**.

### Behavior
- ✅ No copying (very fast)
- ✅ Any modification affects the original vector

Example:

```cpp
vec[0] = 5;   // ✅ Original vector changes
```

### Use When
- The function is supposed to **modify** the original vector.

---

## 3. `vector<int> vec` (Pass by Value)

### What it does
Creates a **completely new copy** of the vector.

### Behavior
- ❌ Copies every element
- ❌ Extra memory usage
- ❌ Slower for large vectors
- ✅ Changes do **not** affect the original vector

### Use When
- You intentionally need a separate copy.
- The function should modify the copy while leaving the original unchanged.

---

# Quick Comparison

| Method | Copy Made? | Can Modify Original? | Speed | Recommended |
|---------|------------|----------------------|-------|-------------|
| `const vector<int>&` | ❌ No | ❌ No | ⭐⭐⭐⭐⭐ | ✅ Default choice |
| `vector<int>&` | ❌ No | ✅ Yes | ⭐⭐⭐⭐⭐ | ✅ When modification is required |
| `vector<int>` | ✅ Yes | ❌ No | ⭐⭐☆☆☆ | ⚠️ Only when a copy is needed |



# How to use auto in vector
```
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40};

    // 1. Read and Modify (Pass by reference)
    for (auto& num : numbers) {
        num *= 2; 
    }

    // 2. Read-Only (Pass by const reference - Highly Recommended)
    for (const auto& num : numbers) {
        std::cout << num << " "; // Outputs: 20 40 60 80
    }
}
```


```
for (auto it = arr.begin(); it != arr.end(); ++it) {
    cout << *it << " ";
}
```