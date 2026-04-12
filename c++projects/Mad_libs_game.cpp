#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
    ofstream clearFile("story.txt", ios::out);
    clearFile.close();

    string inputStory;
    cout<<"Enter a story: ";
    getline(cin, inputStory);

    ofstream saveFile("story.txt");
    saveFile<<inputStory;
    saveFile.close();

    ifstream file("story.txt");
    string story, str = "";
    getline(file, story, '\0');
    file.close();
    
    for(int i=0; i<story.length(); i++){
        str += story[i];
    }

    vector<string> myString;
    for(int j=0; j<str.length(); j++){
        if(str[j] == '<'){
            string temp = "";
            temp += str[j];
            int k = j+1;
            while(str[k] != '>'){
                temp += str[k];
                k++;
            }
            temp += '>';
            myString.push_back(temp);
        }
    }

    int l = 0;
    while(l < myString.size()){
        string word;
        int index = str.find(myString[l]);
        cout<<"Enter a word for "<<myString[l]<<": ";
        cin>>word;
        str.replace(index, myString[l].length(), word);
        l++;
    }

    cout<<"\nModified string:"<<endl;
    for(char ch : str){
        cout<<ch;
    }
    cout<<endl;

    ofstream myfile("story.txt", ios::app);
    myfile<<"\n\nModified story: "<<endl;
    for(int m=0; m<str.length(); m++){
        myfile<<str[m];
    }
    myfile.close();

    return 0;
}