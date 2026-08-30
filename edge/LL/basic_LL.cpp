#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Insert a node at position pos
void insert(Node *&head, int pos, int value)
{
    // FIX 1:
    // Invalid position check.
    // For insertion, valid positions are 0 <= pos <= length.
    if (pos < 0)
    {
        return;
    }

    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    // Insert at beginning
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *ptr = head;

    // Move to the node at position pos - 1
    for (int i = 0; i < pos - 1; i++)
    {
        // FIX 2:
        // Prevent ptr from becoming nullptr.
        if (ptr == nullptr)
        {
            delete newNode;
            return;
        }

        ptr = ptr->next;
    }

    // FIX 3:
    // ptr can be nullptr if pos is beyond the valid insertion range.
    if (ptr == nullptr)
    {
        delete newNode;
        return;
    }

    // Insert newNode between ptr and ptr->next
    newNode->next = ptr->next;
    ptr->next = newNode;
}

// Delete a node at position pos
void deleteLL(Node *&head, int pos)
{
    // FIX 4:
    // Cannot delete from an empty list.
    if (head == nullptr)
    {
        return;
    }

    // FIX 5:
    // Invalid position.
    if (pos < 0)
    {
        return;
    }

    // Delete first node
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *ptr = head;

    // Move to node at position pos - 1
    for (int i = 0; i < pos - 1; i++)
    {
        // FIX 6:
        // Prevent dereferencing nullptr.
        if (ptr == nullptr)
        {
            return;
        }

        ptr = ptr->next;
    }

    // FIX 7:
    // ptr must exist, and ptr->next must exist
    // because ptr->next is the node we want to delete.
    if (ptr == nullptr || ptr->next == nullptr)
    {
        return;
    }

    Node *temp = ptr->next;

    ptr->next = temp->next;

    delete temp;
}

// Print linked list
void printList(Node *head)
{
    Node *ptr = head;

    while (ptr != nullptr)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL\n";
}

// Delete entire linked list
void deleteList(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // =========================================================
    // 1. Manually creating a linked list
    // =========================================================

    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = nullptr;

    cout << "first: " << first->data << '\n';
    cout << "second: " << first->next->data << '\n';
    cout << "third: " << first->next->next->data << '\n';

    // Traversal
    Node *current = first;

    while (current != nullptr)
    {
        cout << "Traversal: " << current->data << '\n';
        current = current->next;
    }

    // FIX 8:
    // Delete the manually created list.
    //
    // No need for:
    // delete current;
    //
    // current is already nullptr after traversal.
    delete third;
    delete second;
    delete first;

    // =========================================================
    // 2. Creating a linked list using a loop
    // =========================================================

    Node *head = new Node;

    head->data = -10;
    head->next = nullptr;

    Node *ptr = head;

    int n = 10;

    for (int i = 1; i <= n; i++)
    {
        Node *temp = new Node;

        temp->data = i * 10;
        temp->next = nullptr;

        ptr->next = temp;
        ptr = temp;
    }

    cout << "\nSecond list:\n";

    printList(head);

    // =========================================================
    // 3. Testing insertion
    // =========================================================

    Node *head1 = new Node;

    head1->data = -100;
    head1->next = nullptr;

    cout << "\nInitial head1:\n";
    printList(head1);

    // Insert at position 0
    insert(head1, 0, 0);

    cout << "\nAfter insert(head1, 0, 0):\n";
    printList(head1);

    // Insert at position 1
    insert(head1, 1, -1);

    cout << "\nAfter insert(head1, 1, -1):\n";
    printList(head1);

    // Insert at position 2
    insert(head1, 2, -2);

    cout << "\nAfter insert(head1, 2, -2):\n";
    printList(head1);

    // Insert at position 3
    insert(head1, 3, -3);

    cout << "\nAfter insert(head1, 3, -3):\n";
    printList(head1);

    // Insert at position 4
    insert(head1, 4, -4);

    cout << "\nAfter insert(head1, 4, -4):\n";
    printList(head1);

    // Current list:
    //
    // 0 -> -1 -> -2 -> -3 -> -4 -> -100 -> NULL

    // =========================================================
    // 4. Testing deletion
    // =========================================================

    deleteLL(head1, 1);

    // 0 -> -2 -> -3 -> -4 -> -100

    deleteLL(head1, 2);

    // 0 -> -2 -> -4 -> -100

    cout << "\nAfter deletions:\n";
    printList(head1);

    // =========================================================
    // 5. Clean up dynamically allocated memory
    // =========================================================

    deleteList(head);
    deleteList(head1);

    return 0;
}