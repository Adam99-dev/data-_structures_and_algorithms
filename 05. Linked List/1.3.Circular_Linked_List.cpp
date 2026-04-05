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

    ~Node()
    {
        cout << "Deleted node: " << data << endl;
    }
};

// Insert after a given element
void insert(Node *&tail, int element, int data)
{

    if (tail == NULL)
    {
        Node *temp = new Node(data);
        temp->next = temp;
        tail = temp;
        return;
    }

    Node *curr = tail;
    bool found = false;


    do
    {
        if (curr->data == element)
        {
            found = true;
            break;
        }
        curr = curr->next;
    } while (curr != tail);

    if (!found)
    {
        cout << "Element not found\n";
        return;
    }

    Node *temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;


    if (curr == tail)
        tail = temp;
}

void deleteNode(Node* &tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* curr = tail;
    Node* prev = NULL;
    bool found = false;

    // Safe traversal
    do
    {
        prev = curr;
        curr = curr->next;

        if (curr->data == value)
        {
            found = true;
            break;
        }

    } while (curr != tail);

    if (!found)
    {
        cout << "Value not found\n";
        return;
    }

    // Single node case
    if (curr == prev)
    {
        tail = NULL;
    }
    else
    {
        prev->next = curr->next;

        // If deleting tail → update tail
        if (curr == tail)
            tail = prev;
    }

    curr->next = NULL;
    delete curr;
}
// Print circular list
void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = tail->next; // start from head

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);

    cout << endl;
}

int main()
{
    Node *tail = NULL;

    cout << "----- Insertion Tests -----\n";

    insert(tail, 0, 10);   // first node
    insert(tail, 10, 20);
    insert(tail, 20, 30);
    insert(tail, 10, 15);

    print(tail);  // Expected: 10 15 20 30

    cout << "\n----- Delete Middle Node -----\n";
    deleteNode(tail, 15);
    print(tail);  // Expected: 10 20 30

    cout << "\n----- Delete Tail Node -----\n";
    deleteNode(tail, 30);
    print(tail);  // Expected: 10 20

    cout << "\n----- Delete Head Node -----\n";
    deleteNode(tail, 10);
    print(tail);  // Expected: 20

    cout << "\n----- Delete Last Remaining Node -----\n";
    deleteNode(tail, 20);
    print(tail);  // Expected: List is empty

    cout << "\n----- Delete from Empty List -----\n";
    deleteNode(tail, 100); // Expected: List is empty

    cout << "\n----- Insert After Non-existing Element -----\n";
    insert(tail, 50, 5);   // Expected: Element not found

    cout << "\n----- Rebuild List -----\n";
    insert(tail, 0, 1);
    insert(tail, 1, 2);
    insert(tail, 2, 3);
    print(tail);  // Expected: 1 2 3

    cout << "\n----- Delete Non-existing Value -----\n";
    deleteNode(tail, 99);  // Expected: Value not found

    print(tail);  // Expected: 1 2 3

    return 0;
}