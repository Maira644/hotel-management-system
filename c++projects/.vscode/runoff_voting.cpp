#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

struct Candidate{
    string name;
    int votes;
    bool eliminated = false;
};

vector<vector<int>> preferences;
vector<Candidate> candidates;

int voters = 0, candidate = 0;

bool vote(int voter, int rank, string name){
    for(int i=0; i<candidates.size(); i++){
        if(candidates[i].name == name){
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

void tabulate(){
    for(int i=0; i<candidates.size(); i++){
        candidates[i].votes = 0;
    }
    for(int voter=0; voter<voters; voter++){
        for(int rank=0; rank<candidate; rank++){
            int candIndex = preferences[voter][rank];

            if(!candidates[candIndex].eliminated){
                candidates[candIndex].votes++;
                break; 
            }
        }
    }
}

bool printWinner(){
    for(int i=0; i<candidates.size(); i++){
        if(!candidates[i].eliminated && candidates[i].votes > voters / 2){
            cout<<"\nWinner: "<<candidates[i].name<<endl;
            return true;
        }
    }
    return false;
}

int findMin(){
    int minVotes = INT_MAX;

    for(int i=0; i<candidates.size(); i++){
        if(!candidates[i].eliminated && candidates[i].votes < minVotes){
            minVotes = candidates[i].votes;
        }
    }
    return minVotes;
}

bool isTie(int minVotes){
    for(int i=0; i<candidates.size(); i++){
        if(!candidates[i].eliminated && candidates[i].votes != minVotes){
            return false;  
        }
    }
    return true; 
}

void eliminate(int minVotes){
    for(int i=0; i<candidates.size(); i++){
        if(!candidates[i].eliminated && candidates[i].votes == minVotes){
            candidates[i].eliminated = true;
        }
    }
}

int main(){
    cout<<"Welcome to the Runoff Voting System"<<endl;
    cout<<"\nEnter number of candidates: ";
    cin>>candidate;

    int i=0;
    while(i < candidate){
        string candName;
        cout<<"Enter candidate "<<(i+1)<<" name: ";
        cin>>candName;
        candidates.push_back({candName, 0, false});
        i++;
    }

    cout<<"\nEnter number of voters: ";
    cin>>voters;

    preferences.resize(voters, vector<int>(candidate, -1));

    for(int voter = 0; voter < voters; voter++){
        cout<<"\n----- Voter "<<(voter + 1)<<" -----"<<endl;
        for(int rank=0; rank<candidate; rank++){
            string name;
            cout<<"Rank "<<(rank + 1)<<": ";
            cin>>name;

            if(!vote(voter, rank, name)){
                cout<<"Invalid vote. Try again."<<endl;
                rank--;  
            }
        }
    }
    
    while(true){
        tabulate();  

        if(printWinner()){  
            break;
        }
        int minVotes = findMin(); 

        if(isTie(minVotes)){  
            cout<<"\nIt's a tie between the following candidates:\n";
            for(Candidate c : candidates){
                if(!c.eliminated){
                    cout<<c.name<<endl;
                }
            }
            break;
        }
        eliminate(minVotes);  
    }
    return 0;
}

