#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        if (temp->prev != NULL)
            temp->prev->next = NULL;
        else
            head = NULL; // Only one node

        delete temp;
    }

   
    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

       
        for (int i = 0; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range.\n";
            return;
        }

        if (temp->prev == NULL) {
            head = temp->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            return;
        }

        if (temp->next == NULL) {
            temp->prev->next = NULL;
            delete temp;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void deleteAll(int value){
        if (head == NULL){
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;

        while (temp != NULL){
            Node* nextNode = temp->next;

            if (temp->data == value){

                if (temp->prev == NULL){
                    head = temp->next;
                    if (head != NULL)
                        head->prev = NULL;
                }
                else if (temp->next == NULL){
                    temp->prev->next = NULL;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
            }
            temp = nextNode;  
        }
    }

    void clear() {
        Node* temp = head;

        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;          
            temp = nextNode;      
        }

        head = NULL;  
        cout << "List cleared successfully.\n";
    }

    int countNodes(){
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "Back to head"<<endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    dll.insertAtEnd(20);

    dll.deleteAtBeginning();
    cout<<"Nodes after deletion: "<<dll.countNodes()<<endl;

    dll.deleteAtEnd();
    cout<<"Nodes after deletion: "<<dll.countNodes()<<endl;

    dll.deleteAtPosition(2);
    cout<<"Nodes after deletion: "<<dll.countNodes()<<endl;
    return 0;
}
