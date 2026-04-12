// PART A
#include<iostream>
#include<vector>
#include <cstdlib>  
#include <ctime>
#include<fstream>
#include<algorithm>
using namespace std;

class Player{
public: 
    int coins;
    int lives;
    vector<string>party;
    bool win;

public:
    Player(){
        coins = 50;
        lives = 3;
        party = {};
        win = false;
    }

int addCoins(int amount){
    coins = coins + amount;
    return coins;
}

int loseCoins(int amount){
    coins = coins - amount;
    return coins;
}

int loseLife(int life){
    lives = lives - life; 
    return lives;
}

void checkWinCondition(){
    bool found = find(party.begin(), party.end(), "Warrior") != party.end();
    if(coins >= 100 && found){
        cout<<"Congratulations! you have won the game."<<endl;
        win = true;
    }else if(coins >= 100 && !found){
        cout<<"You don't have Warrior."<<endl;        
    }else if(coins < 100 && found){
        cout<<"You have the warrior and "<<coins<<"coins."<<endl;
        cout<<"But you need at least 100 coins to claim the treasure."<<endl;
        cout<<"\nYou can't win yet!"<<endl;
    }else if(coins < 100 && !found){
        cout<<"Neither have enough coins nor the warrior."<<endl;
    }
    
}

bool checkLoseCondition(){
    if(lives <= 0){
        cout<<"Player lost the game...."<<endl;
        return true;
    }
    return false;
}

// PART B
void Tavern(){
    int choose;
    char pay;
    cout<<"\nDo you want to talk to the warrior?"<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No"<<endl;
    cout<<"Enter your choice: ";
    cin>>choose;

    if(choose == 1){
        int chance = rand() % 2;

        if(chance == 0){
            cout<<"Hurrah! Warrior will join your party for free"<<endl;
            party.push_back("Warrior");
            ofstream file("game_log.txt",ios::app);
            file<<"Location: Tavern"<<endl;
            file<<"Action: Warrior joined for free"<<endl;
            file<<"Coins: "<<coins<<" Lives: "<<lives<<endl;
            file<<"Party: ";
            for(string ch: party){
                file<<ch<<" ";
            }
            file<<endl;
            file<<"\n\n";
            file.close();
        }else{
            cout<<"The warrior agrees to join your party for 10 coins."<<endl;
            cout<<"Do you want to pay? (y/n): "<<endl;
            cin >>pay;

            if(pay == 'y'){
                cout<<"Warrior joins your party!"<<endl;
                party.push_back("Warrior");
                loseCoins(10);

                ofstream file("game_log.txt", ios::app);
                file<<"Location: Tavern"<<endl;
                file<<"Action: Talked to warrior"<<endl;
                file<<"Result: Warrior joined the party for 10 coins"<<endl;
                file<<"Coins: "<<coins<<" Lives: "<<lives<<endl;
                file<<"Party: ";
                for(string ch: party){
                    file<<ch<<" ";
                }
                file<<endl;
                file<<"\n\n";
                file.close();
            }else{
                ofstream file("game_log.txt", ios::app);
                file<<"Location: Tavern"<<endl;
                file<<"Action: Talked to warrior"<<endl;
                file<<"Warrior did not join the party."<<endl;
                file<<"Coins: "<<coins<<" Lives: "<<lives<<endl;
                file<<"Party: ";
                for(string ch: party){
                    file<<ch<<" ";
                }
                file<<endl;
                file<<"\n\n";
                file.close();
            }
        }
        cout<<"Lives: "<<lives<<"  Coins: "<<coins<<endl;
        cout<<"party: ";
        for(string val : party){
            cout<<val<<endl;
        }
        
    }else{
        cout<<"You exit from Tavern."<<endl;
        ofstream file("game_log.txt", ios::app);
        file<<"Location: Tavern"<<endl;
        file<<"Action: Exit from Tavern"<<endl;
        file<<"Coins: "<<coins<<" Lives: "<<lives<<endl;
        file<<"Party: ";
        for(string ch: party){
            file<<ch<<" ";
        }
        file<<endl;
        file<<"\n\n";
        file.close();
    }
    cout<<"Returning to the Village..."<<endl;
}

void Forest(){
    cout<<"\nYou walk into the Forest and find a mysterious chest..."<<endl;
    cout<<"Opening the chest..."<<endl;

    int chances = rand() % 2;

    if(chances == 0){
        cout<<"\nIt's a trap! you lose one life."<<endl;
        loseLife(1);
        ofstream file("game_log.txt", ios::app);
        file<<"Location: Forest"<<endl;
        file<<"Action: Opened chest"<<endl;
        file<<"Result: Lost 1 life"<<endl;
        file<<"Lives: "<<lives<<" Coins: "<<coins<<endl;
        file<<"\n\n";
        file.close();
    }else{
        cout<<"\nCongratulations! you got 20 coins."<<endl;
        addCoins(20);
        ofstream file("game_log.txt", ios::app);
        file<<"Location: Forest"<<endl;
        file<<"Action: Opened chest"<<endl;
        file<<"Result: Got 20 coins"<<endl;
        file<<"Lives: "<<lives<<" Coins: "<<coins<<endl;
        file<<"\n\n";
        file.close();
    }
    cout<<"Lives: "<<lives<<"  Coins: "<<coins<<endl;
    cout<<"party: ";
    for(string val : party){
        cout<<val;
    }
    if(party.empty()){
        cout<<"Empty"<<endl;
    }else{
        cout<<endl;
    }
    cout<<"Returning to the Village..."<<endl;

}

void Mountain(){
    cout<<"\nThe weather looks uncertain as you climb the Mountains..."<<endl;
    int chanc = rand() % 2;

    if(chanc == 0){
        cout<<"\nIt's sunny! You find 20 coins at the peak."<<endl;
        addCoins(20);
        ofstream file("game_log.txt", ios::app);
        file<<"Location: Mountain"<<endl;
        file<<"Action: Climbed"<<endl;
        file<<"Result: sunny, Got 20 coins"<<endl;
        file<<"Lives: "<<lives<<" Coins: "<<coins<<endl;
        file<<"\n\n";
        file.close();
    }else{
        cout<<"\nBad luck! It rains and you slip while climbing."<<endl;
        cout<<"You lose 1 life."<<endl;
        loseLife(1);
        ofstream file("game_log.txt", ios::app);
        file<<"Location: Mountain"<<endl;
        file<<"Action: Slipped"<<endl;
        file<<"Result: rainy - Lost 1 life"<<endl;
        file<<"Lives: "<<lives<<" Coins: "<<coins<<endl;
        file<<"\n\n";
        file.close();
    }
    cout<<"Lives: "<<lives<<"  Coins: "<<coins<<endl;
    cout<<"party: ";
    for(string val : party){
        cout<<val;
    }
    if(party.empty()){
        cout<<"Empty"<<endl;
    }else{
        cout<<endl;
    }
    cout<<"Returning to the Village..."<<endl;
}

void Treasure(){
    cout<<"\nYou enter the Treasure Room..."<<endl;
    cout<<"\nChecking win condition..."<<endl;
    checkWinCondition();
}

};

int main(){
    ofstream clearFile("game_log.txt", ios::out);
    clearFile.close();
    srand(time(0));
    int choice;
    Player player;
    cout<<"Welcome to the village!"<<endl;
    cout<<"You have 3 lives and 50 coins"<<endl;
    cout<<"Your party is currently empty"<<endl;

    while(true){
        if(player.checkLoseCondition()){
            break;
        }
        cout<<"\nWhere would you like to go?"<<endl;
        cout<<"1. Go to Tavern"<<endl;
        cout<<"2. Go to Forest"<<endl;
        cout<<"3. Go to Mountain"<<endl;
        cout<<"4. Go to Treasure room"<<endl;
        cout<<"5. Exit game"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;


        if(choice == 1){
            player.Tavern();
        }else if(choice == 2){
            player.Forest();
        }else if(choice == 3){
            player.Mountain();
        }else if(choice == 4){
            player.Treasure();
            if(player.win){
                break;
            }
        }else{
            break;
        }
    }

    return 0;
}