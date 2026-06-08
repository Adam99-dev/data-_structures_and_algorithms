// 1. Remove Duplicates from Sorted List
// problem link: https://www.naukri.com/code360/problems/unique-sorted-list_2420283?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_Lovebabbar29thJan


/*#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Insert at tail
void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Print DLL
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Remove duplicates (sorted DLL)
Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* curr = head;

    while (curr != NULL) {
        if (curr->next != NULL && curr->data == curr->next->data) {
            Node* nodeToDelete = curr->next;
            Node* next_next = nodeToDelete->next;

            curr->next = next_next;

            if (next_next != NULL) {
                next_next->prev = curr;
            }

            delete nodeToDelete;
        } else {
            curr = curr->next;
        }
    }

    return head;
}

int main() {
    Node* head = NULL;

    // Test Case 1
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 3);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    // Test Case 2
    Node* head2 = NULL;
    insertAtTail(head2, 5);
    insertAtTail(head2, 5);
    insertAtTail(head2, 5);

    cout << "\nOriginal List 2: ";
    printList(head2);

    head2 = removeDuplicates(head2);

    cout << "After Removing Duplicates: ";
    printList(head2);

    // Test Case 3
    Node* head3 = NULL;
    insertAtTail(head3, 1);
    insertAtTail(head3, 2);
    insertAtTail(head3, 3);

    cout << "\nOriginal List 3: ";
    printList(head3);

    head3 = removeDuplicates(head3);

    cout << "After Removing Duplicates: ";
    printList(head3);

    return 0;
}*/









// 2. Remove Duplicates from Unsorted List
// problem link: https://www.naukri.com/code360/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan

/*#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at tail
void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Remove duplicates (unsorted LL using hashmap)
Node* removeDuplicates(Node* head) {
    unordered_map<int, bool> visited;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (visited[temp->data]) {
            Node* nextNode = temp->next;
            delete temp;
            prev->next = nextNode;
            temp = nextNode;
        } else {
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

int main() {
    Node* head = NULL;

    // Test Case 1
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 4);
    insertAtTail(head, 1);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    // Test Case 2
    Node* head2 = NULL;
    insertAtTail(head2, 5);
    insertAtTail(head2, 5);
    insertAtTail(head2, 5);

    cout << "\nOriginal List 2: ";
    printList(head2);

    head2 = removeDuplicates(head2);

    cout << "After Removing Duplicates: ";
    printList(head2);

    // Test Case 3
    Node* head3 = NULL;
    insertAtTail(head3, 1);
    insertAtTail(head3, 2);
    insertAtTail(head3, 3);

    cout << "\nOriginal List 3: ";
    printList(head3);

    head3 = removeDuplicates(head3);

    cout << "After Removing Duplicates: ";
    printList(head3);

    return 0;
}*/