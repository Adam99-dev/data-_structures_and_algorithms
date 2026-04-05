#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        cout << "Deleted node: " << data << endl;
    }
};

// Print DLL
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

// Insert at Head
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
    head->prev = temp;
    head = temp;
}

// Insert at Tail
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
    temp->prev = tail;
    tail = temp;
}

// Insert at Position
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, tail, data);
        return;
    }

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

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);

    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;

    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
}

// Delete Node
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

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL; // list becomes empty

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

    if (curr == NULL)
    {
        cout << "Position out of range\n";
        return;
    }

    // If deleting tail
    if (curr->next == NULL)
    {
        prev->next = NULL;
        tail = prev;
    }
    else
    {
        prev->next = curr->next;
        curr->next->prev = prev;
    }

    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 15);
    insertAtTail(head, tail, 25);
    insertAtPosition(head, tail, 2, 100);

    print(head);

    deleteNode(head, tail, 1); // test delete head
    print(head);

    deleteNode(head, tail, 3); // test delete tail
    print(head);

    return 0;
}