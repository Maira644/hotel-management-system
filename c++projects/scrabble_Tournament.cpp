#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int computeScore(string word){
    vector<char> player(word.begin(), word.end());

    vector<char> character = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<int> points = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int score = 0;
    
    for(int i=0; i<player.size(); i++){
        for(int j=0; j<character.size(); j++){
            int find;
            if(toupper(player[i]) == character[j]){
                find = j;
                score += points[j];
                }
            }
        }
    
    return score;
}

int main(){
    string word1, word2, name1, name2;
    int num, total1 = 0, total2 = 0, highest1 = 0, highest2 = 0, longest1 = 0, longest2 = 0;
    cout<<"Enter your name Player 1: ";
    cin>>name1;
    
    cout<<"Enter your name Player 2: ";
    cin>>name2;

    cout<<"Number of rounds to play: ";
    cin>>num;

    int i=1;
    while(i <= num){
        cout<<"\nplayer 1: ";
        cin>>word1;

        cout<<"player 2: ";
        cin>>word2;

        int length1 = word1.length();
        longest1 = max(longest1, length1);

        int length2 = word2.length();
        longest2 = max(longest2, length2);

        int player1 = computeScore(word1);
        int player2 = computeScore(word2);

        total1 += player1;
        total2 += player2;

        highest1 = max(highest1, player1);
        highest2 = max(highest2, player2);

        cout<<"\n----ROUND "<<i<<"----"<<endl;

        cout<<name1<<" = "<<word1<<endl;
        cout<<name2<<" = "<<word2<<endl;

        cout<<"Scores: a = "<<player1<<" , c = "<<player2<<endl;

        if(player1 > player2){
            cout<<name1<<" wins this round!"<<endl;
        }else if(player1 < player2){
            cout<<name2<<" wins this round!"<<endl;
        }else{
            cout<<"Tie!";
        }
        i++;
    }

    cout<<"\n=====FINAL TOURNAMENT RESULT=====\n";
    cout<<name1<<": Total = "<<total1<<", Highest = "<<highest1<<", Longest = "<<longest1<<endl;
    cout<<name2<<": Total = "<<total2<<", Highest = "<<highest2<<", Longest = "<<longest2<<endl;

    if(total1 > total2){
        cout<<name1<<" wins the tournament!"<<endl;
    }else if(total1 < total2){
        cout<<name2<<" wins the tournament!"<<endl;
    }else{
        if(highest1 > highest2){
            cout<<name1<<" wins the tournament!"<<endl;
        }else if(highest1 < highest2){
            cout<<name2<<" wins the tournament!"<<endl;
        }else{
            if(longest1 > longest2){
                cout<<name1<<" wins the tournament!"<<endl;
            }else if(longest1 < longest2){
                cout<<name2<<" wins the tournament!"<<endl;
            }else{
                cout<<"There is a tie"<<endl;
            }
        }
    }
    cout<<"----END OF PROGRAM----"<<endl;
    return 0;
}