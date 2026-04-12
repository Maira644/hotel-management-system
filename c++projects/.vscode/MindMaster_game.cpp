#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include<map>
#include<tuple>
using namespace std;

bool checkValid(char ch){
    ch = toupper(ch);
    if(ch == 'R' || ch == 'G' || ch == 'B') return true;
    return false;
}

vector<char> generatePattern(){
    vector<char> colors = {'R', 'G', 'B'};
    vector<char>pattern;

    srand(time(0));
    for(int i=0; i<4; i++){
        int randomIndex = rand() % colors.size();
        pattern.push_back(colors[randomIndex]);
    }
    return pattern;
}

tuple<int, int, int> evaluateGuess(vector<char> pattern, vector<char> guess){
    int points = 0, correctPosition = 0, wrongPosition = 0;

    vector<char> leftguess, rightguess;
    
    for(int i=0; i<4; i++){
        if(pattern[i] == guess[i]){
            points += 2;
            correctPosition++;
        }else{
            leftguess.push_back(pattern[i]);
            rightguess.push_back(guess[i]);
        }
    }   

    for(int i=0; i<leftguess.size(); i++){
        for(int j=0; j<rightguess.size(); j++){
            if(leftguess[i] == rightguess[j]){
                wrongPosition++;
                points++;
                break;
            }
        }
    }
    
    return make_tuple(correctPosition, wrongPosition, points);
}

void previousResult(const string& guess, const map<string, tuple<int, int, int>>& history) {
    tuple<int, int, int> result = history.at(guess);
    int prevCorrect = get<0>(result);
    int prevWrong = get<1>(result);
    int prevPoints = get<2>(result);

    cout<<"\nYou already guessed "<<guess<<"!"<<endl;
    cout<<"Correct Positions: "<<prevCorrect<<endl;
    cout<<"Correct Color (Wrong Position): "<<prevWrong<<endl;
    cout<<"Coins earned for this guess: "<<prevPoints<<endl;
}

void revealPattern(vector<char>& pattern) {
    cout<<"\nYou chose to quit the game."<<endl;
    cout<<"This is the pattern."<<endl;
    for (char val : pattern) {
        cout << val << " ";
    }
}

int main(){
    string guess;
    char quit;
    int total = 0;

    map<string, tuple<int, int, int>> guessHistory;
    vector<char> pattern = generatePattern();

    cout<<"Welcome to Mind Master Game!"<<endl;
    cout<<"\nGuess the secret pattern of 4 colors."<<endl;
    cout<<"You can select from the folllowing colors"<<endl;
    cout<<"R (Red), G(Green), B (Blue)"<<endl;

    while(true){
        cout<<"\nEnter your guess (4 letters): ";
        getline(cin, guess);

        for (char& ch : guess) ch = toupper(ch);

        if(guess.length() != 4){
            cout<<"Invalid Input! Enter only 4 letters"<<endl;
            continue;
        }

        bool isValid = true;
        for(int i = 0; i < guess.length(); i++){
            if(!checkValid(guess[i])){
                cout << "Invalid Input! Enter only R, G or B" << endl;
                isValid = false;
                break;
            }
        }

        if (!isValid) continue;


        if (guessHistory.count(guess)) {
            previousResult(guess, guessHistory);
        }else {
            vector<char> Guess(guess.begin(), guess.end());
            int correctPos, wrongPos, points;
            tuple<int, int, int> result = evaluateGuess(pattern, Guess);
            correctPos = get<0>(result);
            wrongPos = get<1>(result);
            points = get<2>(result);
 
            cout<<"Correct Positions: "<< correctPos<<endl;
            cout<<"Correct Color (Wrong Position): "<< wrongPos<<endl;
            cout<<"Coins earned for this guess: "<<points<<endl;

            guessHistory[guess] = make_tuple(correctPos, wrongPos, points);
            total += points;

            if(correctPos == 4){
                cout<<"\nCongratulations! You guessed the correct pattern!"<<endl;
                cout<<"Total coins earned: "<<total<<endl;
                break;
            }
        }

        cout<<"Total: "<<total<<endl;

        cout<<"\nDo you want to quit (y/n): ";
        cin>>quit;
        cin.ignore(); 
        if (quit == 'y' || quit == 'Y') {
            revealPattern(pattern);
            break;
        }
    }

    return 0;
}