// =====================================================================1
// #include<iostream>
// #include<stack>
// #include<string>
// using namespace std;

// bool isvalid(string str){
//     stack<int> st;

//     for(int i=0; i<str.size(); i++){
//         if(str[i] == '(' || str[i] == '{' || str[i] == '['){
//             st.push(str[i]);
//         }else{
//             if(st.size() == 0){
//                 return false;
//             }

//             if((st.top() == '(' && str[i] == ')') ||
//                 (st.top() == '{' && str[i] == '}')  ||
//                 (st.top() == '[' && str[i] == ']')){
//                     st.pop();
//             }else{
//                 return false;
//             }
//         }
//     }
//     return st.size() == 0;
// }

// int main(){
//     string str = "({[]}";

//     cout<<isvalid(str)<<endl;

//     return 0;
// }

// ==================================================================2
// #include<iostream>
// #include<stack>
// #include<vector>
// using namespace std;

// int main(){
//     vector<int> price = {100, 80, 60, 70, 60, 75, 85};

//     vector<int> ans(price.size(), 0);
//     stack<int> s;

//     for(int i=0; i<price.size(); i++){
//         while(s.size() > 0 && price[s.top()] <= price[i]){
//             s.pop();
//         }

//         if(s.empty()){
//             ans[i] = i + 1;
//         }else{
//             ans[i] = i - s.top();
//         }
//         s.push(i);
//     }

//     for(int val : ans){
//         cout<<val<<" ";
//     }
//     cout<<endl;

//     return 0;
// }

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

    void insertAtBeginning(Node* & head,int val){
        Node* newNode = new Node (val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void forwardTraverse(Node*& head){
        Node* temp = head;

        cout<<"NULL <=> ";
        while(temp != NULL){
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

    void print(Node* head){
        Node* temp = head;

        cout<<"NULL <=> ";
        while(temp != NULL){
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

    void backwardTraverse(){
        Node* temp = tail;

        cout<<"NULL <=> ";
        while(temp != NULL){
            cout<<temp->data<<" <=> ";
            temp = temp->prev;
        }
        cout<<"NULL\n";
    }

    void searchTarget(int tar){
        Node* temp = head;
        bool found = false;

        while(temp != NULL){
            if(temp->data == tar){
                cout<<"Found the target"<<endl;
                found = true;
                break;
            }else{
                temp = temp->next;
            }
        }
        if(!found){
            cout<<"Did not found the target"<<endl;
        }
    }

    int countTheNodes(){
        int count = 0;
        if(head == NULL &&  tail == NULL){
            cout<<"DoublyList is empty"<<endl;
            return 0;
        }else{
            Node* temp = head;

            while(temp != NULL){
                count++;
                temp = temp->next;
            }
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
        if(temp != NULL){
            head = temp->prev;
        }
    }

    void insertAtPosition(Node*& head, int pos, int value) {
    if (pos == 0) {
        insertAtBeginning(head, value);
        return;
    }

    Node* ptr = head;
    int count = 0;

    while (count < pos - 1 && ptr != NULL) {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        cout << "Position out of range" << endl;
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = ptr->next;
    newNode->prev = ptr;

    if (ptr->next != NULL)
        ptr->next->prev = newNode;

    ptr->next = newNode;

    }

    void delAtBeginning(Node*& head){
        if(head == NULL){
            cout<<"Dll is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;

        if(head != NULL){
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void delAtEnd(Node*& head){
        if(head == NULL){
            cout<<"Dll is empty\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;

        if(tail != NULL){
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }

    void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List Empty" << endl;
        return;
    }

    if(pos == 0){
        delAtBeginning(head);
    }

    Node* ptr = head;
    int count = 0;

    while (count < pos && ptr != NULL) {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        cout << "Position out of range" << endl;
        return;
    }

    if (ptr->prev != NULL){
        ptr->prev->next = ptr->next;
    }
    else{
        head = ptr->next; 
    } 

    if (ptr->next != NULL){
        ptr->next->prev = ptr->prev;
    }

    delete ptr;  

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

};  

int main(){
    int option;
    while (true){
       cout<<"\nChoose from the Menu:\n";
       cout<<"1. Traverse the Dll forward"<<endl;
       cout<<"2. Traverse the Dll backward"<<endl;
       cout<<"3. Insert at beginning"<<endl;
       cout<<"4. Insert at end"<<endl;
       cout<<"5. Insert at position"<<endl;
       cout<<"6. Delete from beginning"<<endl;
       cout<<"7. Delete from end"<<endl;
       cout<<"8. Count the nodes"<<endl;
       cout<<"9. Reverse Dll"<<endl;
       cout<<"10. Merge Dll"<<endl;
       cout<<"11. Search a target"<<endl;

       cin>>option;
    }
    
    return 0;
}

 