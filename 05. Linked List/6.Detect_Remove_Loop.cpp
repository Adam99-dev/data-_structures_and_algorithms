// problem link: https://www.naukri.com/code360/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_codestudio_lovebabbar28thjan



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


Node *removeLoop(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    bool loopExists = false;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    if (loopExists) {
        slow = head;

        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }

    return head;
}
// ------------------------------------------------

// Utility: Print list safely
void printList(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // ---------- Test Case 1: Loop in middle ----------
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // Create loop (5 -> 3)
    head1->next->next->next->next->next = head1->next->next;

    head1 = removeLoop(head1);

    cout << "List after removing loop (case 1): ";
    printList(head1);


    // ---------- Test Case 2: Loop at head ----------
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);

    // Create loop (30 -> 10)
    head2->next->next->next = head2;

    head2 = removeLoop(head2);

    cout << "List after removing loop (case 2): ";
    printList(head2);


    // ---------- Test Case 3: No loop ----------
    Node* head3 = new Node(100);
    head3->next = new Node(200);
    head3->next->next = new Node(300);

    head3 = removeLoop(head3);

    cout << "List after removing loop (case 3): ";
    printList(head3);


    // ---------- Test Case 4: Single node ----------
    Node* head4 = new Node(999);

    head4 = removeLoop(head4);

    cout << "List after removing loop (case 4): ";
    printList(head4);


    return 0;
}