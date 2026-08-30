#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node
{
    int data;
    Node *next;
};

Node *insert(Node *&head, int pos, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *ptr = head;
    for (int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Dynamic memory allocated for the Node struct by cpp and that address is stored in first variable.
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = nullptr;

    cout << "first->" << first->data << '\n';
    cout << "second->" << first->next->data << '\n';
    cout << "third->" << first->next->next->data << '\n';

    Node *current = first;
    while (current != nullptr)
    {
        cout << "Traversal:" << current->data << '\n';
        current = current->next;
    }

    delete third;
    delete second;
    delete first;
    delete current;

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
        ptr = ptr->next;
    }

    insert(head, 3, 13452345);
    insert(head, 0, 45674567);

    ptr = head;
    while (ptr != nullptr)
    {
        cout << "T: " << ptr->data << '\n';
        ptr = ptr->next;
    }

    return 0;
}