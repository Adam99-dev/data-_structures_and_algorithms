// problem link: https://www.naukri.com/code360/problems/middle-of-linked-list_973250?source=youtube&campaign=Lovebabbarcodestudio_24thJan

#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Function to find length
int lengthOfList(Node* head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find middle
Node* findMiddle(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    int len = lengthOfList(head);
    int mid = len / 2;

    Node* temp = head;
    int count = 0;

    while (count < mid) {
        temp = temp->next;
        count++;
    }

    return temp;
}

// Print Linked List
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Predefined Linked List: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Linked List: ";
    printList(head);

    Node* middle = findMiddle(head);

    if (middle != nullptr) {
        cout << "Middle Element: " << middle->data << endl;
    }

    return 0;
}