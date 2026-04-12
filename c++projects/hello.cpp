#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyList{
    Node* head;
    Node* tail;

public:
    DoublyList(){
        head = tail = NULL;
    }

    void insertAtBeginning(Node*& head, int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print(Node* head){
        Node* temp = head;
        cout << "NULL <=> ";
        while(temp != NULL){
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void backwardTraverse(){
        Node* temp = tail;
        cout << "NULL <=> ";
        while(temp != NULL){
            cout << temp->data << " <=> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    void searchTarget(int tar){
        Node* temp = head;
        bool found = false;

        while(temp != NULL){
            if(temp->data == tar){
                cout << "Found the target!\n";
                found = true;
                break;
            }
            temp = temp->next;
        }
        if(!found)
            cout << "Target not found.\n";
    }

    int countTheNodes(){
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void reverse(){
        Node* curr = head;
        Node* temp = NULL;

        if(curr == NULL || curr->next == NULL) return;

        tail = head;
        while(curr != NULL){
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if(temp != NULL)
            head = temp->prev;
    }

    void insertAtPosition(Node*& head, int pos, int value){
        if(pos == 0){
            insertAtBeginning(head, value);
            return;
        }

        Node* ptr = head;
        int count = 0;

        while(count < pos - 1 && ptr != NULL){
            ptr = ptr->next;
            count++;
        }

        if(ptr == NULL){
            cout << "Position out of range\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = ptr->next;
        newNode->prev = ptr;

        if(ptr->next != NULL)
            ptr->next->prev = newNode;

        ptr->next = newNode;
    }

    void delAtBeginning(Node*& head){
        if(head == NULL){
            cout << "DLL is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
    }

    void delAtEnd(Node*& head){
        if(head == NULL){
            cout << "DLL is empty\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if(tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        delete temp;
    }

    Node* mergeDll(Node* head1, Node* head2){
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;

        Node* tail = head1;
        while(tail->next != NULL){
            tail = tail->next;
        }

        tail->next = head2;
        head2->prev = tail;

        return head1;
    }

    Node*& getHead() { return head; }  // helper to access private head
    Node*& getTail() { return tail; }  // helper to access private tail
};


int main(){
    DoublyList dll;
    Node* head = dll.getHead();

    int option, val, pos, target;
    while(true){
        cout<<"\n======= Doubly Linked List Menu =======\n";
        cout<<"1. Traverse the DLL forward\n";
        cout<<"2. Traverse the DLL backward\n";
        cout<<"3. Insert at beginning\n";
        cout<<"4. Insert at end\n";
        cout<<"5. Insert at position\n";
        cout<<"6. Delete from beginning\n";
        cout<<"7. Delete from end\n";
        cout<<"8. Count the nodes\n";
        cout<<"9. Reverse DLL\n";
        cout<<"10. Merge two DLLs\n";
        cout<<"11. Search a target\n";
        cout<<"12. Exit\n";
        cout<<"Enter your choice: ";
        cin>>option;

        if(option == 1){
            dll.print(head);
        }
        else if(option == 2){
            dll.backwardTraverse();
        }
        else if(option == 3){
            cout<<"Enter value: ";
            cin>>val;
            dll.insertAtBeginning(head, val);
        }
        else if(option == 4){
            cout<<"Enter value: ";
            cin>>val;
            dll.insertAtEnd(val);
        }
        else if(option == 5){
            cout<<"Enter position and value: ";
            cin>>pos>>val;
            dll.insertAtPosition(head, pos, val);
        }
        else if(option == 6){
            dll.delAtBeginning(head);
        }
        else if(option == 7){
            dll.delAtEnd(head);
        }
        else if(option == 8){
            cout<<"Total nodes: "<<dll.countTheNodes()<<endl;
        }
        else if(option == 9){
            dll.reverse();
            cout<<"DLL reversed!\n";
        }
        else if(option == 10){
            Node* head1 = NULL;
            Node* head2 = NULL;
            DoublyList d1, d2;

            d1.insertAtBeginning(head1, 2);
            d1.insertAtBeginning(head1, 1);

            d2.insertAtBeginning(head2, 4);
            d2.insertAtBeginning(head2, 3);

            Node* merged = dll.mergeDll(head1, head2);
            cout<<"Merged DLL: ";
            dll.print(merged);
        }
        else if(option == 11){
            cout<<"Enter target: ";
            cin>>target;
            dll.searchTarget(target);
        }
        else if(option == 12){
            cout<<"Exiting...\n";
            break;
        }
        else{
            cout<<"Invalid option! Try again.\n";
        }
    }

    return 0;
}
