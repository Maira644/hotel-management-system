#include <iostream>
#define SIZE 5
using namespace std;

int queueArr[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return rear == SIZE - 1;
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow!\n";
        return;
    }
    if (front == -1) front = 0; // First element
    queueArr[++rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!\n";
        return;
    }

    front++;
    
    if (front > rear) {
        front = rear = -1;
    }
}


void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << queueArr[i] << " ";
    cout << endl;
}

void peek() {
    if(front == -1 || front > rear){
        cout<<"Queue is empty. Nothing to peek.\n";
        return;
    }
    cout<< "Front element is: "<<queueArr[front]<<endl;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    int ans1 = isFull();
    if(ans1 == 1){
        cout<<"The Queue is Full"<<endl;
    }else{
        cout<<"The Queue is not Full"<<endl;
    }

    dequeue();
    dequeue();
    dequeue();

    int ans2 = isEmpty();
    if(ans2 == 1){
        cout<<"The Queue is empty"<<endl;
    }else{
        cout<<"The Queue is not empty"<<endl;
    }

    return 0;
}

// #include <iostream>
// #define SIZE 5
// using namespace std;

// int queueArr[SIZE];
// int front = -1, rear = -1;

// void enqueue(int value) {
//     if((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front){
//         cout<<"Queue Overflow! (Circular Queue is full)\n";
//         return;
//     }

//     if(front == -1){
//         front = rear = 0;
//     }
//     else{
//         rear = (rear + 1) % SIZE;  
//     }

//     queueArr[rear] = value;  
// }

// void dequeue(){
//     if(front == -1){
//         cout << "Queue Underflow! (Circular Queue is empty)\n";
//         return;
//     }

//     if (front == rear)
//         front = rear = -1;
//     else
//         front = (front + 1) % SIZE;  
// }

// void display(){
//     if(front == -1) {
//         cout<<"Circular Queue is empty.\n";
//         return;
//     }

//     cout<<"Circular Queue elements: ";
//     int i = front;
//     while(true){
//         cout<<queueArr[i] << " ";
//         if(i == rear){
//             break;
//         }
//         i = (i + 1) % SIZE;
//     }
//     cout<<endl;
// }


// int main(){
//     enqueue(10);
//     enqueue(20);
//     enqueue(30);
//     enqueue(40);
//     enqueue(50);
//     display();

//     dequeue();
//     dequeue();
//     display();

//     enqueue(60);  
//     enqueue(70);
//     display();

//     return 0;
// }

