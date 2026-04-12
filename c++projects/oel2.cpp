#include <iostream>
#include <string>
using namespace std;

#define SIZE 5   

string doctors[SIZE] = {"Dr.Raheela", "Dr.Amjad", "Dr.Farzana", "Dr.Saif", "Dr.Insha"};

void displayDoctors(){
    cout << "\nList of Available Doctors:\n";
    for (int i = 0; i < SIZE; i++) {
        if (doctors[i] != "") {
            cout<<i + 1<< ". " << doctors[i] << endl;
        }
    }
}

int findDoctor(string doctorname) {
    for(int i = 0; i < SIZE; i++){
        if(doctors[i] == doctorname)
            return i;
    }
    return -1;  
}

struct Node{
    string name;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(string name) {
    Node* newNode = new Node;
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
    Node* temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete temp;
    return name;
}

void displayQueue() {
    cout << "\nPatients waiting for consultation: ";
    if(front == NULL){
        cout<<"None"<<endl;
        return;
    }
    Node* temp = front;
    while(temp != NULL) {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout<<endl;
}

struct StackNode {
    string patient;
    StackNode* next;
};

StackNode* top = NULL;

void push(string patientName) {
    StackNode* newNode = new StackNode;
    newNode->patient = patientName;
    newNode->next = top;
    top = newNode;
}

string pop() {
    if (top == NULL)
        return "";
    string Patient = top->patient;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return Patient;
}

void displayStack() {
    cout << "\nDoctor Assignment History (Stack): ";
    if (top == NULL) {
        cout << "Empty\n";
        return;
    }
    StackNode* temp = top;
    while (temp != NULL) {
        cout << temp->patient << " ";
        temp = temp->next;
    }
    cout << endl;
}

struct Admittedpatient{
    string patient;
    string consult;
    Admittedpatient* next;
};

Admittedpatient* head = NULL;

void addPatient(string patient, string doctor) {
    Admittedpatient* newNode = new Admittedpatient;
    newNode->patient = patient;
    newNode->consult = doctor;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Admittedpatient* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void removePatient(string patient) {
    if (head == NULL) return;
    Admittedpatient* temp = head;
    Admittedpatient* prev = NULL;
    while (temp != NULL && temp->patient != patient) {
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

void displayadmittedpatients() {
    cout << "\nAdmitted Patients: ";
    if (head == NULL) {
        cout << "None\n";
        return;
    }
    Admittedpatient* temp = head;
    while (temp != NULL) {
        cout << "[" << temp->patient << " -> " << temp->consult << "] ";
        temp = temp->next;
    }
    cout << endl;
}

void assignDoctor() {
    string patient, Doctor;
    cout << "\nEnter patient name: ";
    cin >> patient;
    cout << "Enter Doctor name: ";
    cin.ignore();
    getline(cin, Doctor);
    int index = findDoctor(Doctor);
    if (index != -1) {
        cout << "Doctor assigned to " << patient << " successfully.\n";
        push(Doctor);                     
        addPatient(patient, Doctor);      
        doctors[index] = "";              
    } else {
        cout << "Doctor not available. Added " <<  patient << " to waiting list.\n";
        enqueue(patient);
    }
}

void returnDoctor() {
    if (top == NULL) {
        cout << "\nNo doctor available.\n";
        return;
    }
    string lastDoctor = pop();  
    for (int i = 0; i < SIZE; i++) {
        if (doctors[i] == "") {
            doctors[i] = lastDoctor;
            break;
        }
    }
    if (front != NULL) {
        string nextpatient = dequeue();
        cout << "Assigning " << lastDoctor << " to waiting patient: " << nextpatient << endl;
        push(lastDoctor);
        addPatient(nextpatient, lastDoctor);
        for (int i = 0; i < SIZE; i++) {
            if (doctors[i] == lastDoctor)
                doctors[i] = "";
        }
    }
}

void displayAll() {
    displayDoctors();
    displayQueue();
    displayStack();
    displayadmittedpatients();
}

int main() {
    int choice;
    cout << "===== Doctor-Patient Management System =====\n";
    displayDoctors();
    do {
        cout << "\n\nMenu:\n";
        cout << "1. Display Available Doctors\n";
        cout << "2. Assign Doctor\n";
        cout << "3. Return Doctor\n";
        cout << "4. Display All Structures\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                displayDoctors();
                break;
            case 2:
                assignDoctor();
                break;
            case 3:
                returnDoctor();
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
