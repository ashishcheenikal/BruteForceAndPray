#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node
{
    int data;
    Node *next;
};

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

    return 0;
}