// problem link: https://www.naukri.com/code360/problems/circularly-linked_1070232?source=youtube&campaign=Lovebabbar_codestudio_26thjan



#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// ---------- YOUR FUNCTION (unchanged) ----------
bool isCircular(Node* head){

    if(!head) return true;

    if(!head->next) return false;

    Node *slow = head;
    Node *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            break;
        }
    }

    if(slow == head && slow == fast) return true;

    return false;
}
// ---------------------------------------------

// Utility: print limited nodes (to avoid infinite loop)
void printList(Node* head, int limit = 10) {
    int count = 0;
    while(head != nullptr && count < limit) {
        cout << head->data << " ";
        head = head->next;
        count++;
    }
    cout << endl;
}

int main() {

    // ---------- Test Case 1: Circular List ----------
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    // Make it circular (last node points to head)
    head1->next->next->next->next = head1;

    cout << "Test Case 1 (Circular): ";
    cout << (isCircular(head1) ? "Yes" : "No") << endl;


    // ---------- Test Case 2: Non-Circular List ----------
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);

    cout << "Test Case 2 (Non-Circular): ";
    cout << (isCircular(head2) ? "Yes" : "No") << endl;


    // ---------- Test Case 3: Single Node ----------
    Node* head3 = new Node(100);

    cout << "Test Case 3 (Single Node): ";
    cout << (isCircular(head3) ? "Yes" : "No") << endl;


    // ---------- Test Case 4: Empty List ----------
    Node* head4 = nullptr;

    cout << "Test Case 4 (Empty List): ";
    cout << (isCircular(head4) ? "Yes" : "No") << endl;


    return 0;
}