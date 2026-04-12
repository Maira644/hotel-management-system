#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>
#include <chrono>
#include<ctime>     
#include<cstdlib>
using namespace std;
using namespace chrono;

int main(){
    ifstream file("text.txt");
    vector<string> lines;
    string line;

    while(getline(file,line)){
        lines.push_back(line);
    }
    file.close();

    srand(time(0));

    int linesCount = 0, wordGivenCount = 0, wordTypedCount = 0, correctch = 0, totalCh = 0;

    cout<<"Welcome to the speed typing test!"<<endl;
    cout<<"You will have 60 seconds to type as many lines as you can"<<endl;
    cout<<"Press Enter to start...";
    cin.ignore();

    auto start = high_resolution_clock::now();

    while(true){
        int index = rand() % lines.size();
        string randomLine = lines[index];

        auto now = high_resolution_clock::now();
        auto elapsed = duration_cast<seconds>(now - start).count();
        int timeLeft = 60 - elapsed;
        if(timeLeft < 0) break;

        totalCh += randomLine.length();

        for(int i=0; i<randomLine.length(); i++){
            if(randomLine[i] == ' '){
                wordGivenCount++;
            }
        }
        wordGivenCount++;

        cout<<"\nType the following test as fast as you can:"<<endl;
        cout<<randomLine<<endl;
        linesCount++;
 
        cout<<"Time left: "<<timeLeft<<"s"<<endl;
        cout<<"start typing here:"<<endl;
        string typedLine;
        getline(cin,typedLine);

        
        for(int i=0; i<typedLine.length(); i++){
            if(typedLine[i] == ' '){
                wordTypedCount++;
            }
        }
        wordTypedCount++;
        
        int minSize = min(randomLine.length(), typedLine.length());
        for(int j=0; j<minSize; j++){
            if(randomLine[j] == typedLine[j]){
                correctch++;
            }
        }
        
    }
    auto end = high_resolution_clock::now(); 
    auto elapsed = duration_cast<seconds>(end - start).count(); 
    double minutes = elapsed / 60.0; 

    double WPM = wordTypedCount / minutes;
    double accuracy = (double(correctch) / totalCh) * 100;
    cout<<fixed<<setprecision(2)<<endl;

    cout<<"\n-----RESULT-----\n";
    cout<<"Lines Given: "<<linesCount<<endl;
    cout<<"Words Given: "<<wordGivenCount<<endl;
    cout<<"Words Typed: "<<wordTypedCount<<endl;
    cout<<"Your WPM(words per minute): "<<WPM<<endl;
    cout<<"Your accuracy: "<<accuracy<<"%"<< endl;

    return 0;
}