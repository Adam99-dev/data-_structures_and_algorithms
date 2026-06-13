#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Safe destructor
    ~Node()
    {
        cout << "Deleted node: " << data << endl;
    }
};

// Insert at head
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

// Insert at tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

// Insert at position
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // Empty list
    if (head == NULL)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // Insert at head
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp->next != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    // Insert at tail
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // Insert in middle
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Delete node
void deleteNode(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    // Delete head
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        if (head == NULL)
            tail = NULL;

        temp->next = NULL;
        delete temp;
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;

    while (cnt < position && curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    // Invalid position
    if (curr == NULL)
    {
        cout << "Position out of range\n";
        return;
    }

    prev->next = curr->next;

    // Update tail if needed
    if (curr->next == NULL)
        tail = prev;

    curr->next = NULL;
    delete curr;
}

// Print list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtPosition(head, tail, 1, 5);
    insertAtPosition(head, tail, 2, 15);
    insertAtPosition(head, tail, 3, 25);
    insertAtPosition(head, tail, 4, 35);
    insertAtPosition(head, tail, 5, 45);

    print(head); // 5 15 25 35 45

    deleteNode(head, tail, 3);
    print(head); // 5 15 35 45

    deleteNode(head, tail, 1);
    print(head); // 15 35 45

    deleteNode(head, tail, 3);
    print(head); // 15 35

    return 0;
}