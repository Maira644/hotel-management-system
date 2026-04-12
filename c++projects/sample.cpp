#include <iostream>
#include <string>
using namespace std;

#define SIZE 5   

// -------------------- 1. ARRAY (Available Books) --------------------
string books[SIZE] = {"C++", "Data Structures", "OOP", "Python", "DBMS"};

void displayBooks() {
    cout << "\nList of Available Books:\n";
    
    for (int i = 0; i < SIZE; i++) {
        if (books[i] != "") {
            cout << i + 1 << ". " << books[i] << endl;
            
        }
    }

}

int findBook(string bookName) {
    for (int i = 0; i < SIZE; i++) {
        if (books[i] == bookName)
            return i;
    }
    return -1;  
}

// -------------------- 2. QUEUE (Waiting Students) --------------------
struct QNode {
    string name;
    QNode* next;
};

QNode* frontQ = NULL;
QNode* rearQ = NULL;

void enqueue(string name) {
    QNode* newNode = new QNode;
    newNode->name = name;
    newNode->next = NULL;

    if (rearQ == NULL) {
        frontQ = rearQ = newNode;
    } else {
        rearQ->next = newNode;
        rearQ = newNode;
    }
}

string dequeue() {
    if (frontQ == NULL) {
        return "";
    }
    string name = frontQ->name;
    QNode* temp = frontQ;
    frontQ = frontQ->next;

    if (frontQ == NULL)
        rearQ = NULL;

    delete temp;
    return name;
}

void displayQueue() {
    cout << "\nStudents Waiting (Queue): ";
    if (frontQ == NULL) {
        cout << "None\n";
        return;
    }

    QNode* temp = frontQ;
    while (temp != NULL) {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout << endl;
}

// -------------------- 3. STACK (Borrow History) --------------------
struct StackNode {
    string book;
    StackNode* next;
};

StackNode* topS = NULL;

void push(string bookName) {
    StackNode* newNode = new StackNode;
    newNode->book = bookName;
    newNode->next = topS;
    topS = newNode;
}

string pop() {
    if (topS == NULL)
        return "";

    string book = topS->book;
    StackNode* temp = topS;
    topS = topS->next;
    delete temp;
    return book;
}

void displayStack() {
    cout << "\nBorrow History (Stack): ";
    if (topS == NULL) {
        cout << "Empty\n";
        return;
    }

    StackNode* temp = topS;
    while (temp != NULL) {
        cout << temp->book << " ";
        temp = temp->next;
    }
    cout << endl;
}

// -------------------- 4. LINKED LIST (Active Borrowers) --------------------
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
