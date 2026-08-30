// https://leetcode.com/problems/reverse-linked-list/description/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node
{
    int data;
    Node *next;
};

Node *reverseList(Node *head)
{
    Node *reverseHead = nullptr;

    while (head != nullptr)
    {

        Node *temp = head;        // 1. Save current node
        head = head->next;        // 2. Move original list forward
        temp->next = reverseHead; // 3. Point current node backward
        reverseHead = temp;       // 4. Move reversed-list head
    }
    return reverseHead;
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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

    printList(head);

    head = reverseList(head);

    printList(head);
    return 0;
}