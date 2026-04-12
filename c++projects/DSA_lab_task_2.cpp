#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void print(){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

    //  question 2: 
    void pop_back(){
        if(head == NULL){
            cout<<"linked list is empty"<<endl;
            return;
        }

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // question 3:
    int count_nodes(){
        int count = 0;
        Node* temp = head;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    // question 4:
    void search(int key){
        Node* temp = head;
        int idx = 0;
        bool found = false;

        while(temp != NULL){
            if(temp->data == key){
                cout<<"found at index "<<idx<<endl;
                found = true;
            }

            temp = temp->next;
            idx++;
        }
        if(!found){
            cout<<"Did not found!!"<<endl;
        }
    }

    // question 5:
    void reverseList(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
            head = prev;
        }
        print();
    }

    // question 6:
    void ascendingSort(){
        if(head == NULL || head->next == NULL) return;

        Node* i;
        Node* j;
        int temp;

        for(i=head; i->next != NULL; i=i->next){
            for(j=i->next; j != NULL; j= j->next){
                if(i->data > j->data){
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

};

int main(){
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);

    ll.print();
    ll.ascendingSort();
    ll.print();
    return 0;
}

    // ll.pop_back();
    // ll.print();
    // cout<<"The total number of nodes in linked list is: "<<ll.count_nodes()<<endl;
    // ll.search(2);
    // ll.ascendingSort();
    //  ll.reverseList();

    