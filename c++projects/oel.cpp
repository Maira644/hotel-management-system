#include <iostream>
#include <string>
using namespace std;

#define SIZE 5   

// Array
string books[SIZE] = {"C++", "Data Structures", "OOP", "Python", "DBMS"};

void displayBooks(){
    cout << "\nList of Available Books:\n";
    
    for (int i = 0; i < SIZE; i++) {
        if (books[i] != "") {
            cout<<i + 1<< ". " << books[i] << endl;
        }
    }

}

int bookFind(string bookName) {
    for(int i = 0; i < SIZE; i++){
        if(books[i] == bookName)
            return i;
    }
    return -1;  
}

// Queue
struct QNode {
    string name;
    QNode* next;
};

QNode* front = NULL;
QNode* rear = NULL;

void enqueue(string name) {
    QNode* newNode = new QNode;
    newNode->name = name;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue() {
    if (front == NULL) {
        return "";
    }
    string name = front->name;
    QNode* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
    return name;
}

void displayQueue() {
    cout << "\nStudents Waiting (Queue): ";
    if (front == NULL) {
        cout << "None\n";
        return;
    }

    QNode* temp = front;
    while (temp != NULL) {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Stack
struct StackNode {
    string book;
    StackNode* next;
};

StackNode* top = NULL;

void push(string bookName) {
    StackNode* newNode = new StackNode;
    newNode->book = bookName;
    newNode->next = top;
    top = newNode;
}

string pop() {
    if (top == NULL)
        return "";

    string book = top->book;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return book;
}

void displayStack() {
    cout << "\nBorrow History (Stack): ";
    if (top == NULL) {
        cout << "Empty\n";
        return;
    }

    StackNode* temp = top;
    while (temp != NULL) {
        cout << temp->book << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Linked list
struct Borrower {
    string student;
    string book;
    Borrower* next;
};

Borrower* head = NULL;

void addBorrower(string student, string book) {
    Borrower* newNode = new Borrower;
    newNode->student = student;
    newNode->book = book;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Borrower* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void removeBorrower(string student) {
    if (head == NULL) return;

    Borrower* temp = head;
    Borrower* prev = NULL;

    while (temp != NULL && temp->student != student) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
}

void displayBorrowers() {
    cout << "\nActive Borrowers (Linked List): ";
    if (head == NULL) {
        cout << "None\n";
        return;
    }

    Borrower* temp = head;
    while (temp != NULL) {
        cout << "[" << temp->student << " -> " << temp->book << "] ";
        temp = temp->next;
    }
    cout << endl;
}

// -------------------- 5. MAIN OPERATIONS --------------------
void issueBook() {
    string student, book;
    cout << "\nEnter student name: ";
    cin >> student;
    cout << "Enter book name: ";
    cin.ignore();
    getline(cin, book);

    int index = findBook(book);
    if (index != -1) {
        cout << "Book issued to " << student << " successfully.\n";
        push(book);                     
        addBorrower(student, book);     
        books[index] = "";               
    } else {
        cout << "Book not available. Added " << student << " to waiting list.\n";
        enqueue(student);
    }
}

void returnBook() {
    if (topS == NULL) {
        cout << "\nNo borrowed books in history.\n";
        return;
    }

    string lastBook = pop();  
    cout << "\nReturning book: " << lastBook << endl;

    // return book to available list
    for (int i = 0; i < SIZE; i++) {
        if (books[i] == "") {
            books[i] = lastBook;
            break;
        }
    }

    // check waiting queue
    if (frontQ != NULL) {
        string nextStudent = dequeue();
        cout << "Issuing " << lastBook << " to waiting student: " << nextStudent << endl;
        push(lastBook);
        addBorrower(nextStudent, lastBook);
        for (int i = 0; i < SIZE; i++) {
            if (books[i] == lastBook)
                books[i] = "";
        }
    }
}

void displayAll() {
    displayBooks();
    displayQueue();
    displayStack();
    displayBorrowers();
}

// -------------------- MAIN FUNCTION --------------------
int main() {
    int choice;
    cout << "===== Library Management System =====\n";
    displayBooks();

    do {
        cout << "\n\nMenu:\n";
        cout << "1. Display Available Books\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display All Structures\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayBooks();
                break;
            case 2:
                issueBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                displayAll();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

