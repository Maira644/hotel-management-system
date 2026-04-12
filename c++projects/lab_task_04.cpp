#include<iostream>
using namespace std;

#define size 5

int stack[size];
int top = -1;

void Push(int val){
    if(top == size -1){
        cout<<"Stack Overflow"<<endl;
        return;
    }

    top += 1;
    stack[top] = val;
}

void PUSH(char c) {
    if (top == size - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    stack[top] = c;
}

void Pop(){
    if(top == -1){
        cout<<"Stack Underflow"<<endl;
        return;
    }

    cout<<"Deleted Element "<<stack[top]<<endl;
    top -= 1;
}

char POP() {
    if (top == -1) {
        return '\0'; // return null if empty
    }
    char temp = stack[top];
    top--;
    return temp;
}

void Peek(){
    if(top == -1){
        cout<<"stack is empty"<<endl;
        return;
    }

    cout<<"The element at the peek is: "<<stack[top]<<endl;
}

bool isBalanced(string str) {
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            PUSH(str[i]);
        } 
        
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if(top == -1){
                return false; 
            }

            if((stack[top] == '(' && str[i] == ')') ||
                (stack[top] == '{' && str[i] == '}') ||
                (stack[top] == '[' && str[i] == ']')){
                POP();
            } 
            else{
                return false; 
            }
        }
    }
    return (top == -1);
}


void Display(){
    if(top == -1){
        cout<<"Stack is empty"<<endl;
        return;
    }
     
    cout<<"Stack Elements are:"<<endl;
    for(int i=top; i>=0; i--){
        cout<<stack[i]<<endl;
    }
}

int main(){
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);

    Display();

    return 0;
}

// cout<<"Do you want to pop the top most element from stack? (Y/N)";
//     cin>>ans;

//     if(ans == 'Y'){
//         Pop();
//     }

//     Display();