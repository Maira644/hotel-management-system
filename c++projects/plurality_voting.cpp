#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int cand, vot, winner=0, num=0;
    string name, candName, finalWinner;
    bool isRight = true;

    vector<string> candidates;
    vector<string> voters;
    vector<int> freq;

    cout<<"Enter number of candidates: ";
    cin>>cand;

    if(cand <= 9){
        int i=1;
        while(i <= cand){
            cout<<"Enter name of candidate "<<i<<": ";
            cin>>name;
            candidates.push_back(name);
            i++;
        }

        cout<<"\nEnter the numbers of voters: ";
        cin>>vot;

        int j=1;
        while(j <= vot){
            cout<<"Voter "<<j<<", enter the name of candidate you vote for: ";
            cin>>candName;
            if(find(candidates.begin(), candidates.end(), candName) != candidates.end()){
                voters.push_back(candName);
            }else{
                cout<<"Your vote is wasted!"<<endl;
                j++;
                continue;
            }
            j++;
        }

        for(int i=0; i<candidates.size(); i++){
            int count = 0;
            for(int j=0; j<voters.size(); j++){
                if(candidates[i] == voters[j]){
                    count++;
                }
            }
            freq.push_back(count);
        }

        cout<<"\n---Votes received by each candidate---\n";
        int k=0;
        while(k < candidates.size()){
            winner = max(winner, freq[k]);
            cout<<candidates[k]<<": "<<freq[k]<<" votes"<<endl;
            k++;
        }
        
        int l = 0;
        while(l < freq.size()){
            if(winner == freq[l]){
                num++;
            }
            l++;
        }
        if(num > 1){
            cout<<"\nIt's a tie!"<<endl;
            for(int val=0; val<freq.size(); val++){
            if(winner == freq[val]){
                cout<<candidates[val]<<endl;
            }
        }
        }else{
            for(int val=0; val<freq.size(); val++){
                if(winner == freq[val]){
                    finalWinner = candidates[val];
                }
            }
            cout<<"\nWinnner(s): "<<endl;
            cout<<finalWinner<<endl;
        }  
    }

    return 0;
}