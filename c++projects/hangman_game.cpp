#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    char letter, ans = 'n';
    
    while(ans != 'y'){
        set<char> seen;
        int score = 0;
        cout<<"\nWelcome to Hangman!"<<endl;
        cout<<"Guess the letter by letter\n";
        srand(time(0));
        
        vector<string> words = {"apple", "book", "table", "python", "plant"};
        vector<char> alpha;

        int idx = rand() % words.size();
        string singleWord = words[idx];
        int dashes = words[idx].length();

        for(int i=0; i<dashes; i++){
            alpha.push_back('_');
        }
        while(find(alpha.begin(), alpha.end(), '_') != alpha.end()){
            bool found = false;
            cout<<"\nword: ";
            for(char vals : alpha){
                cout<<vals<<" ";
            }
            cout<<endl;
            cout<<"Score: "<<score<<endl;

            cout<<"Enter a single letter: ";
            cin>>letter;
            if(letter >= 'a' && letter <= 'z'){
                if(seen.find(letter) != seen.end()){
                    cout<<"You already guessed that letter."<<endl;
                    score--;
                }else{
                    seen.insert(letter);
                    for(int j=0; j<dashes; j++){
                        if(letter == singleWord[j] && alpha[j] == '_'){
                            score++;
                            found = true;
                            alpha[j] = singleWord[j];
                        }
                    }
                    if(found){
                        cout<<"Good Guess!"<<endl;
                    }else{
                        score--;
                        cout<<"Wrong Guess."<<endl;
                    }
                }
            }else{
                cout<<"Guess only letters!"<<endl;
            }   
        }
        cout<<"\nYou guessed the word: "<<singleWord<<endl;
        cout<<"Final Score: "<<score<<endl;
        cout<<"Do you want to quit? (y/n)";
        cin>>ans;
    }

    return 0;
}
