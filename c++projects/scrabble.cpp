// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;

// int computeScore(string word){
//     vector<char> player(word.begin(), word.end());

//     vector<char> character = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
//     vector<int> points = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 8, 4, 10};

//     int score = 0;
//     for(int i=0; i<player.size(); i++){
//         for(int j=0; j<character.size(); j++){
//             int find;
//             if(toupper(player[i]) == character[j]){
//                 find = j;
//                 score += points[j];
//             }
//         }
//     }
//     return score;
// }

// int main(){
//     string word1, word2;
//     cout<<"Enter your string player 1: ";
//     cin>>word1;

//     cout<<"Enter your string player 2: ";
//     cin>>word2;

//     int player1 = computeScore(word1);
//     int player2 = computeScore(word2);

//     cout<<"\n========RESULT========\n"<<endl;

//     if(player1 > player2){
//         cout<<"Player 1 wins!"<<endl;
//     }else if(player1 < player2){
//         cout<<"Player 2 wins!"<<endl;
//     }else{
//         cout<<"Tie!";
//     }
//     return 0;
// }