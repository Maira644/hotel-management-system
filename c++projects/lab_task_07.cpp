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

class Queue{
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int value){
        Node* newNode = new Node(value);

        if(rear == NULL){
            front = rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }

        cout<<value<<" enqueued into queue.\n";
    }

    void dequeue(){
        if(front == NULL){
            cout<<"Queue Underflow!\n";
            return;
        }

        Node* temp = front;
        cout<<temp->data<<" dequeued from queue.\n";
        front = front->next;

        if(front == NULL)
            rear = NULL;

        delete temp;
    }

    void display(){
        if(front == NULL){
            cout<<"Queue is empty.\n";
            return;
        }

        cout<<"Queue elements: ";
        Node* temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void peek(){
        if(front == NULL){
            cout<<"Queue is empty.\n";
        }else{
            cout<<"Front element is: "<<front->data<<endl;
        }
    }

    int countElements() {
        int count = 0;
        Node* temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void clear(){
        while (front != NULL){
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
        cout<<"All elements cleared from queue.\n";
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.clear();
    q.display();
    cout<<"Total elements in queue: "<<q.countElements()<<endl;

    return 0;
}

// #include <iostream>
// using namespace std;

// class Node{
// public:
//     int data;
//     Node* next;

//     Node(int value){
//         data = value;
//         next = NULL;
//     }
// };

// class CircularQueue{
// private:
//     Node* front;
//     Node* rear;

// public:
//     CircularQueue(){
//         front = rear = NULL;
//     }

//     void enqueue(int value){
//         Node* newNode = new Node(value);

//         if (front == NULL){
//             front = rear = newNode;
//             rear->next = front;  
//         } else {
//             rear->next = newNode;
//             rear = newNode;
//             rear->next = front;  
//         }
//     }

//     void dequeue(){
//         if(front == NULL){
//             cout<<"Queue Underflow!\n";
//             return;
//         }

//         if (front == rear){
//             cout<<front->data<<" dequeued from circular queue.\n";
//             delete front;
//             front = rear = NULL;
//         } else {
//             Node* temp = front;
//             front = front->next;
//             rear->next = front; 
//             delete temp;
//         }
//     }

//     void display(){
//         if(front == NULL){
//             cout<<"Queue is empty.\n";
//             return;
//         }

//         cout<<"Circular Queue elements: ";
//         Node* temp = front;

//         while(true){
//             cout<<temp->data<<" ";
//             temp = temp->next;

//             if(temp == front)
//                 break;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     CircularQueue cq;

//     cq.enqueue(10);
//     cq.enqueue(20);
//     cq.enqueue(30);

//     cq.display();

//     cq.dequeue();
//     cq.display();

//     cq.enqueue(40);
//     cq.display();

//     return 0;
// }

