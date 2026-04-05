// problem link: https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbar_codestudio_26thjan


#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};


int cnt(Node* head){
    int cnt = 0;
    while(head != NULL){
        head = head->next;
        cnt++;
    }
    return cnt;
}

Node* kReverse(Node* head, int k) {
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL && cnt(next) >= k){
        head->next = kReverse(next, k);
    } else {
        head->next = next;
    }

    return prev;
}
// ------------------------------------------------

// Utility: Print list
void printList(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility: Create list from array
Node* createList(int arr[], int n) {
    if(n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

int main() {

    // ---------- Test Case 1 ----------
    int arr1[] = {1, 2, 3, 4, 5};
    Node* head1 = createList(arr1, 5);

    cout << "Original List 1: ";
    printList(head1);

    head1 = kReverse(head1, 2);

    cout << "Reversed in K=2: ";
    printList(head1);


    // ---------- Test Case 2 ----------
    int arr2[] = {10, 20, 30, 40, 50, 60};
    Node* head2 = createList(arr2, 6);

    cout << "\nOriginal List 2: ";
    printList(head2);

    head2 = kReverse(head2, 3);

    cout << "Reversed in K=3: ";
    printList(head2);


    // ---------- Test Case 3 ----------
    int arr3[] = {1, 2, 3, 4};
    Node* head3 = createList(arr3, 4);

    cout << "\nOriginal List 3: ";
    printList(head3);

    head3 = kReverse(head3, 5);  // k > length

    cout << "Reversed in K=5: ";
    printList(head3);


    return 0;
}