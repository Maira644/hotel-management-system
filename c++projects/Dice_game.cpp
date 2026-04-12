#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

void twoPlayer(int num2){
    vector<int> scores;
    int score1 = 0, score2 = 0, maxNum = 10;
    while(true){
        cout<<"\nPlayer number 1 turn has just started!"<<endl;
        cout<<"Your total score is: "<<score1<<endl;

        while(true){
            char ans1;
            cout<<"\nWould you like to roll (y/n)? ";
            cin>>ans1;
            if(ans1 == 'y'){
                int roll1 = (rand() % 6) + 1;
                if(roll1 == 1){
                    cout<<"You rolled: 1! Turn done!"<<endl;
                    score1 = 0;
                    cout<<"Your total score is: "<<score1<<endl;
                    break;
                }
                cout<<"You rolled: "<<roll1<<endl;
                score1 += roll1;
                cout<<"Your score is: "<<score1<<endl;
            }else if(ans1 == 'n'){
                cout<<"Your total score is: "<<score1<<endl;
                break;
            }
        }
        cout<<"\nPlayer number 2 turn has just started!"<<endl;
        cout<<"Your total score is: "<<score2<<endl;

        while(true){
            char ans2;
            cout<<"\nWould you like to roll (y/n)? ";
            cin>>ans2;
            if(ans2 == 'y'){
                int roll2 = (rand() % 6) + 1;
                if(roll2 == 1){
                    cout<<"You rolled: 1! Turn done!"<<endl;
                    score2 = 0;
                    cout<<"Your total score is: "<<score2<<endl;
                    break;
                }
                cout<<"You rolled: "<<roll2<<endl;
                score2 += roll2;
                cout<<"Your score is: "<<score2<<endl;
            }else if(ans2 == 'n'){
                cout<<"Your total score is: "<<score2<<endl;
                break;
            }
        }
        scores.clear();
        scores.push_back(score1);
        scores.push_back(score2);
    
        cout<<"\nScores after this round:"<<endl;
        for(int i=0; i<scores.size(); i++){
            cout<<"Player number "<<i+1<<" has a score of: "<<scores[i]<<endl;
        }
        if(score1 >= maxNum || score2 >= maxNum) break;
    }
    if(score1 >= maxNum && score1 > score2){
        cout<<"\nPlayer 1 is the winner with the score of: "<<score1<<endl;
    }else if(score2 >= maxNum && score2 > score1){
        cout<<"\nPlayer 2 is the winner with the score of: "<<score2<<endl;
    }

}
void fourPlayer(int num4){
    vector<int> scores;
    int score1 = 0, score2 = 0, score3 = 0, score4 = 0, maxNum = 10;
    while(true){
        cout<<"\nPlayer number 1 turn has just started!"<<endl;
        cout<<"Your total score is: "<<score1<<endl;

        while(true){
            char ans1;
            cout<<"\nWould you like to roll (y/n)? ";
            cin>>ans1;
            if(ans1 == 'y'){
                int roll1 = (rand() % 6) + 1;
                if(roll1 == 1){
                    cout<<"You rolled: 1! Turn done!"<<endl;
                    score1 = 0;
                    cout<<"Your total score is: "<<score1<<endl;
                    break;
                }
                cout<<"You rolled: "<<roll1<<endl;
                score1 += roll1;
                cout<<"Your score is: "<<score1<<endl;
            }else if(ans1 == 'n'){
                cout<<"Your total score is: "<<score1<<endl;
                break;
            }
        }
        cout<<"\nPlayer number 2 turn has just started!"<<endl;
        cout<<"Your total score is: "<<score2<<endl;

        while(true){
            char ans2;
            cout<<"\nWould you like to roll (y/n)? ";
            cin>>ans2;
            if(ans2 == 'y'){
                int roll2 = (rand() % 6) + 1;
                if(roll2 == 1){
                    cout<<"You rolled: 1! Turn done!"<<endl;
                    score2 = 0;
                    cout<<"Your total score is: "<<score2<<endl;
                    break;
                }
                cout<<"You rolled: "<<roll2<<endl;
                score2 += roll2;
                cout<<"Your score is: "<<score2<<endl;
            }else if(ans2 == 'n'){
                cout<<"Your total score is: "<<score2<<endl;
                break;
            }
        }
        cout<<"\nPlayer number 3 turn has just started!"<<endl;
        cout<<"Your total score is: "<<score3<<endl;

        while(true){
            char ans3;
            cout<<"\nWould you like to roll (y/n)? ";
            cin>>ans3;
            if(ans3 == 'y'){
                int roll3 = (rand() % 6) + 1;
                if(roll3 == 1){
                    cout<<"You rolled: 1! Turn done!"<<endl;
                    score3 = 0;
                    cout<<"Your total score is: "<<score3<<endl;
                    break;
                }
                cout<<"You rolled: "<<roll3<<endl;
                score3 += roll3;
                cout<<"Your score is: "<<score3<<endl;
            }else if(ans3 == 'n'){
                cout<<"Your total score is: "<<score3<<endl;
                break;
            }
        }
        cout<<"\nPlayer number 4 turn has just started!"<<endl;
        cout<<"Your total score is: "<<score4<<endl;

        while(true){
            char ans4;
            cout<<"\nWould you like to roll (y/n)? ";
            cin>>ans4;
            if(ans4 == 'y'){
                int roll4 = (rand() % 6) + 1;
                if(roll4 == 1){
                    cout<<"You rolled: 1! Turn done!"<<endl;
                    score4 = 0;
                    cout<<"Your total score is: "<<score4<<endl;
                    break;
                }
                cout<<"You rolled: "<<roll4<<endl;
                score4 += roll4;
                cout<<"Your score is: "<<score4<<endl;
            }else if(ans4 == 'n'){
                cout<<"Your total score is: "<<score4<<endl;
                break;
            }
        }

        scores.clear();
        scores.push_back(score1);
        scores.push_back(score2);
        scores.push_back(score3);
        scores.push_back(score4);

        cout<<"\nScores after this round:"<<endl;
        for(int i=0; i<scores.size(); i++){
            cout<<"Player number "<<i+1<<" has a score of: "<<scores[i]<<endl;
        }
        if(score1 >= maxNum || score2 >= maxNum || score3 >= maxNum || score4 >= maxNum) break;
    }
    if(score1 >= maxNum && score1 > score2 && score1 > score3 && score1 > score4){
        cout<<"\nPlayer 1 is the winner with the score of: "<<score1<<endl;
    }else if(score2 >= maxNum && score2 > score1 && score2 > score3 && score2 > score4){
        cout<<"\nPlayer 2 is the winner with the score of: "<<score2<<endl;
    }
    else if(score3 >= maxNum && score3 > score1 && score3 > score2 && score3 > score4){
        cout<<"\nPlayer 3 is the winner with the score of: "<<score3<<endl;
    }
    else if(score4 >= maxNum && score4 > score1 && score4 > score2 && score4 > score3){
        cout<<"\nPlayer 4 is the winner with the score of: "<<score4<<endl;
    }
}

int main(){
    srand(time(0));
    int num;
    cout<<"Enter the number of players(2 - 4): ";
    cin>>num;

    if(num == 2){
        twoPlayer(num);

    }else if(num == 4){
        fourPlayer(num);
    }else{
        cout<<"Invalid entry.."<<endl;
    }
    
    return 0;
}