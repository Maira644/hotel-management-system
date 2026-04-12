#include<iostream>
#include<vector>
using namespace std;

vector<string> prod = {"shampoo", "dishwash", "soap"};
vector<int> quantity = {3, 1, 2};

struct Node{
    int prod;
    Node* next;
    Node* prev;
};

void insertAtEnd(Node*& head, int prod) {
    Node* newNode = new Node;
    newNode->prod = prod;
    newNode->next = NULL; 
    newNode->prev = NULL; 

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteprod(Node*& head, int prod) {
    if (head == NULL) return;

    Node* temp = head;

    while (temp != NULL && temp->prod != prod)
        temp = temp->next;

    if (temp == NULL) return;
    
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void displayDLL(Node* head) {
    cout << "Doubly Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->prod << "<=>";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
}

Node* convertToCircular(Node* head) {
    if (head == NULL) return NULL;

    Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = head;
    head->prev = tail;

    return head;
}

int partitionVec(vector<int>& quantity, int l, int r) {
    int pivot = quantity[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++) {
        if (quantity[j] <= pivot) {
            i++;
            swap(quantity[i], quantity[j]);
        }
    }
    swap(quantity[i + 1], quantity[r]);
    return i + 1;
}

void quickSort(vector<int>& quantity, int l, int r) {
    if (l < r) {
        int pi = partitionVec(quantity, l, r);
        quickSort(quantity, l, pi - 1);
        quickSort(quantity, pi + 1, r);
    }
}

void displayCircular(Node* head) {
    if (head == NULL) return;
    cout << "Circular List: ";

    Node* temp = head;
    do {
        cout << temp->prod << "<=>";
        temp = temp->next;
    } while (temp != head);

    cout << "back to start"<<endl;
}

void displayInventory(vector<string> prod){
    for(int i=0; i<quantity.size(); i++){
        cout<<quantity[i]<<" "<<prod[i]<<endl;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    displayDLL(head);

    deleteprod(head, 3);
    displayDLL(head);

    convertToCircular(head);
    displayCircular(head);

    int result = partitionVec(quantity, 0, 2);
    cout<<"After sorting by using Quick Sort, The first element is: "<<result<<endl;

    displayInventory(prod);

    return 0;
}