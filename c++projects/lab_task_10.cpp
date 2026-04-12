#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList() {
        head = NULL;
    }

    void insertAtPosition(int value, int pos) {
        Node* newNode = new Node(value);

        if (head == NULL) { 
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        if (pos == 0 || pos == 1) { 
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (temp->next == head && count < pos - 1) {
            cout << "Position out of range. Inserting at the end.\n";
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    int countNodes() {
        if (head == NULL)
            return 0;

        Node* temp = head;
        int count = 0;

        while (true) {
            count++;
            temp = temp->next;
            if (temp == head)
                break;
        }

        return count;
    }

    void reverse() {
        if (head == NULL || head->next == head)
            return; 

        Node* current = head;
        Node* temp = NULL;
        Node* start = head;

        while (true) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev; 
            if (current == start)
                break;
        }

        head = head->next; 
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (true) {
            cout << temp->data << "<=>";
            temp = temp->next;
            if (temp == head) break;
        }
        cout << "back to head\n";
    }
};

int main() {
    DoublyCircularLinkedList dcll;
    dcll.insertAtPosition(10, 1);
    dcll.insertAtPosition(20, 2);
    dcll.insertAtPosition(30, 3);
    dcll.insertAtPosition(5, 1);

    dcll.display(); 

    dcll.reverse();

    dcll.display();
    return 0;
}
