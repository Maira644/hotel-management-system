#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class CircularLinkedList{
private:
    Node* head;

public:
    CircularLinkedList(){
        head = NULL;
    }

    // ==============================================qno1
    void insertAtPosition(int value, int pos){
        Node* newNode = new Node(value);
        if (head == NULL){
            head = newNode;
            head->next = head;
            return;
        }
        if (pos == 1){
            Node* temp = head;
            while(temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head){
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // ==================================================qno3
    bool search(int value) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return false;
        }

        Node* temp = head;
        int pos = 1;

        while (true) {
            if (temp->data == value) {
                cout << "Value " << value << " found at position " << pos << ".\n";
                return true;
            }
            temp = temp->next;
            pos++;
            if (temp == head) break;
        }

        cout << "Value " << value << " not found in the list.\n";
        return false;
    }

    // =============================================qno4
    void deleteFirst() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == head) { // Only one node
            delete head;
            head = NULL;
            return;
        }

        Node* tail = head;
        while (tail->next != head) { // Find last node
            tail = tail->next;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }


    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        cout << head->data << "->";   
        Node* temp = head->next;     

        while (temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "back to head\n";
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtPosition(10, 1);
    cll.insertAtPosition(20, 2);
    cll.insertAtPosition(30, 3);
    cll.insertAtPosition(5, 1);

    cll.display(); 

    cll.search(20);  
    cll.search(100);

    cll.deleteFirst();
    cll.display(); 

    return 0;
}

 

// ====================================================qno2
// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node* prev;

//     Node(int value) {
//         data = value;
//         next = NULL;
//         prev = NULL;
//     }
// };

// class DoublyCircularLinkedList {
// private:
//     Node* head;

// public:
//     DoublyCircularLinkedList() {
//         head = NULL;
//     }

//     void insertAtPosition(int value, int pos) {
//         Node* newNode = new Node(value);

//         if (head == NULL) {
//             head = newNode;
//             head->next = head;
//             head->prev = head;
//             return;
//         }

//         if (pos == 1) {
//             Node* tail = head->prev;
//             newNode->next = head;
//             newNode->prev = tail;
//             tail->next = newNode;
//             head->prev = newNode;
//             head = newNode;
//             return;
//         }

//         Node* temp = head;
//         int count = 1;
//         while (count < pos - 1 && temp->next != head) {
//             temp = temp->next;
//             count++;
//         }

//         newNode->next = temp->next;
//         newNode->prev = temp;
//         temp->next->prev = newNode;
//         temp->next = newNode;
//     }

//     void display() {
//         if (head == NULL) {
//             cout << "List is empty.\n";
//             return;
//         }

//         Node* temp = head;
//         while (true) {
//             cout << temp->data << "<=>";
//             temp = temp->next;
//             if (temp == head) break;
//         }
//         cout << "back to head\n";
//     }
// };

// int main() {
//     DoublyCircularLinkedList dcll;
//     dcll.insertAtPosition(10, 1);
//     dcll.insertAtPosition(20, 2);
//     dcll.insertAtPosition(30, 3);
//     dcll.insertAtPosition(5, 1);
//     dcll.insertAtPosition(15, 3);
//     dcll.display();
//     return 0;
// }
