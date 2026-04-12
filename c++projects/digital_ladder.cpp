#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

void specialNumber(int nums, int& score){
    char ans;
    cout<<"\nIs this a special number? (y/n): ";
    cin>>ans;

    bool sumProd = false, ispalindrome = false;
    int sum = 0, prod = 1;
    char myAns;

    int orig = nums;
    while(nums > 0){
        int remd = nums % 10;
        nums /= 10;
        sum += remd;
        prod *= remd;
    }

    if(sum == prod){
        sumProd = true;
    }

    string numd = to_string(orig);
    string rev = numd;
    reverse(rev.begin(), rev.end());
    if(rev == numd){
        ispalindrome = true;
    }

    if(sumProd || ispalindrome){
        myAns = 'y';
    }else{
        myAns = 'n';
    }

    if(ans == myAns){
        if(myAns == 'y'){
            cout<<"this is a special number"<<endl;
            cout<<"Correct guess! +3 bonus points"<<endl;
        }else if(myAns == 'n'){
            cout<<"this is not a special number"<<endl;
            cout<<"Correct guess! +3 bonus points"<<endl;
        }
        score += 3;
    }else{
        cout<<"Wrong Answer!"<<endl;
    }

}

void checkDigitalRoot(int num, int& score){
    cout<<"Number: "<<num<<endl;
    int dig, sum = 0, count = 0;
    cout<<"What will be the digital root? ";
    cin>>dig;

    vector<int> number;
    number.push_back(num);

    int original = num;

    while(num >= 10){
        int sum = 0;
        while(num > 0){
            int rem = num % 10;
            num /= 10;
            sum += rem;
        }
        num = sum;
        number.push_back(num);
    }
    if(dig == num){
        cout<<"Correct! +5 points"<<endl;
        score += 5;
        cout<<"\nHere's how we get there:"<<endl;
        for(int i=0; i<number.size()-1; i++){
            cout<<number[i]<<" -> "<<number[i+1]<<endl;
        }
        cout<<"Final digital root: "<<num<<endl;
    }else{
        cout<<"Wrong! The digital root is: "<<num<<endl;
        cout<<"\nHere's how we get there:"<<endl;
        for(int i=0; i<number.size()-1; i++){
            cout<<number[i]<<" -> "<<number[i+1]<<endl;
        }
        cout<<"Final digital root: "<<num<<endl;
    }

    specialNumber(original, score);

}

int main(){
    int score = 0;
    srand(time(0));
    cout<<"Welcome to Digital Ladder Challenge!"<<endl;
    cout<<"Try to predict digital roots and identify special numbers!"<<endl;

    int i=0;
    while(i < 3){
        cout<<"\nRound "<<(i + 1)<<endl;
        int randomNum;
        if(i == 0){
            randomNum = (rand() % 100) + 100;   
        }else if(i == 1){
            randomNum = (rand() % 100) + 200;
        }else{
            randomNum = (rand() % 100) + 300;
        }
        checkDigitalRoot(randomNum, score);
        i++;
    }

    cout<<"\nGame Over!"<<endl;
    cout<<"Final Score: "<<score<<"/24"<<endl;
    

    return 0;
}