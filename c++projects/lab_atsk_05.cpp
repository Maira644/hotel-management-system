#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty(){
        return top == NULL;
    }

    void push(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        // cout << val << " pushed into stack.\n";
    }

    void pop() {
        if(top == NULL){
            cout<<"Stack Underflow!\n";
            return;
        }
        cout<<top->data<<" popped from stack.\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int POP() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    void peek(){
        if(top == NULL){
            cout<<"Stack is empty.\n";
        }else{
            cout<<"Top element is: "<<top->data<<endl;
        }
    }

    void display(){
        if(top == NULL){
            cout<<"Stack is empty.\n";
            return;
        }
        cout<<"Stack elements: ";
        Node* temp = top;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void reverse() {
        Stack tempStack;

        while (!isEmpty()) {
            int val = POP();
            tempStack.push(val);
        }
        top = tempStack.top;

    }

    bool isBalanced(string str) {
        Stack s;

        for(int i = 0; i < str.length(); i++){
            char ch = str[i];

            if(ch == '(' || ch == '{' || ch == '['){
                s.push(ch);
            }
            else if(ch == ')' || ch == '}' || ch == ']'){
                if(s.isEmpty()){
                    return false;
                }

                char topChar = s.POP();

                if((ch == ')' && topChar == '(') ||
                  (ch == '}' && topChar == '{') ||
                  (ch == ']' && topChar == '[')) {
                  return false; 
                }
            }
        }

        return s.isEmpty();
    }
};

int main(){
    Stack s;
    string str = "({]})";

    if(s.isBalanced(str))
        cout<<"Parentheses are balanced.\n";
    else
        cout<<"Parentheses are not balanced.\n";

    return 0;
}
