#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayBoard(){
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"----------"<<endl;
    cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"----------"<<endl;
    cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}

void Game(int select, char ch){
    char chh = select + '0';
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == chh){
                board[i][j] = ch;
            }
        }
    }
    displayBoard();
}

bool checkWin(char ch1){
    bool win = false;
    for(int i=0; i<3; i++){
        int count = 0;
        for(int j=0; j<3; j++){
            if(board[i][j] == ch1){
                count++;
            }
        }
        if(count == 3){
            win = true;
            break;
        }
    }

    for(int j=0; j<3; j++){
        int count = 0;
        for(int i=0; i<3; i++){
            if(board[i][j] == ch1){
                count++;
            }
        }
        if(count == 3){
            win = true;
            break;
        }
    }

    int count = 0;
    for(int i = 0; i < 3; i++){
        if(board[i][i] == ch1){
            count++;
        }
    }
    if(count == 3){
        win = true;
    }

    count = 0;
    for(int i = 0; i < 3; i++){
        if(board[i][2 - i] == ch1){
            count++;
        }
    }
    if(count == 3){
        win = true;
    }
    return win;
    
}

int main(){
    cout<<"Welcome to Tick Tack Toe"<<endl;
    cout<<"Player 1 will be X"<<endl;
    cout<<"Player 2 will be O\n\n";

    displayBoard();
    bool tie = false;
    int i=0;

    while(i < 9){
        int ch;
        cout<<"\nPlayer X, Choose a position (1-9): ";
        cin>>ch;
        Game(ch, 'X');
        if(checkWin('X')){
            cout<<"Player X wins!!"<<endl;
            break;
        }
        i++;
        if(i == 9) break;
        cout<<"\nPlayer O, Choose a position (1-9): ";
        cin>>ch;
        Game(ch, 'O');
        if(checkWin('O')){
            cout<<"Player O wins!!"<<endl;
            break;
        }
        i++;

    }
    if(i == 9){
        cout<<"It's a draw!"<<endl;
    }

    return 0;
}