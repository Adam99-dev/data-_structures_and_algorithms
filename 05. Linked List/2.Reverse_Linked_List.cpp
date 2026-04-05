// problem link: https://www.naukri.com/code360/problems/reverse-the-singly-linked-list_799897?source=youtube&campaign=Lovebabbarcodestudio_24thJan&leftPanelTabValue=SUBMISSION

#include <iostream>
using namespace std;

// Linked List Node Definition
template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T>* next;

    LinkedListNode(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Recursive reverse function
LinkedListNode<int>* reverseFunction(LinkedListNode<int>* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    LinkedListNode<int>* newHead = reverseFunction(head->next);

    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

// Wrapper function
LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head) {
    return reverseFunction(head);
}

// Print Linked List
void printList(LinkedListNode<int>* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Predefined Linked List: 1 -> 2 -> 3 -> 4 -> 5
    LinkedListNode<int>* head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->next = new LinkedListNode<int>(4);
    head->next->next->next->next = new LinkedListNode<int>(5);

    cout << "Original List: ";
    printList(head);

    head = reverseLinkedList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}