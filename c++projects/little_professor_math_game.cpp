#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

void generateInteger10(){
    int correct = 0;
    srand(time(0));
    for(int i=0; i<10; i++){
        int ans;
        int count = 0;
        int num1 = (rand()%10+1);
        int num2 = (rand()%10+1);
        int sum = num1 + num2;
        cout<<"Problem "<<i+1<<": "<<num1<<" + "<<num2<<" = ";
        cin>>ans;
        if(ans == sum) correct++; 
        while(ans != sum){
            cout<<"EEE"<<endl;
            count++;
            if(count == 3){
                cout<<"Answer: "<<sum<<endl;
                break;
            }
            cout<<"Problem "<<i+1<<": "<<num1<<" + "<<num2<<" = ";
            cin>>ans;  
            if(ans == sum) correct++;
        }
    }
    cout<<"\nYour final score: "<<correct<<"/10"<<endl;

}

void generateInteger100(){
    int correct = 0;
    srand(time(0));
    for(int i=0; i<10; i++){
        int ans;
        int count = 0;
        int num1 = (rand()%90+10);
        int num2 = (rand()%90+10);
        int sum = num1 + num2;
        cout<<"Problem "<<i+1<<": "<<num1<<" + "<<num2<<" = ";
        cin>>ans;
        if(ans == sum) correct++; 
        while(ans != sum){
            cout<<"EEE"<<endl;
            count++;
            if(count == 3){
                cout<<"Answer: "<<sum<<endl;
                break;
            }
            cout<<"Problem "<<i+1<<": "<<num1<<" + "<<num2<<" = ";
            cin>>ans;  
            if(ans == sum) correct++;
        }
    }
    cout<<"\nYour final score: "<<correct<<"/10"<<endl;

}

void generateInteger1000(){
    int correct = 0;
    srand(time(0));
    for(int i=0; i<10; i++){
        int ans;
        int count = 0;
        int num1 = (rand()%900+100);
        int num2 = (rand()%900+100);
        int sum = num1 + num2;
        cout<<"Problem "<<i+1<<": "<<num1<<" + "<<num2<<" = ";
        cin>>ans;
        if(ans == sum) correct++; 
        while(ans != sum){
            cout<<"EEE"<<endl;
            count++;
            if(count == 3){
                cout<<"Answer: "<<sum<<endl;
                break;
            }
            cout<<"Problem "<<i+1<<": "<<num1<<" + "<<num2<<" = ";
            cin>>ans;  
            if(ans == sum) correct++;
        }
    }
    cout<<"\nYour final score: "<<correct<<"/10"<<endl;

}

void getLevel(int num){
    if(num == 1){
       generateInteger10(); 
    }else if(num == 2){
        generateInteger100();
    }else if(num == 3){
        generateInteger1000();
    }
}

int main(){
    int num, ans;
    cout<<"Select a level(1, 2, 3): ";
    cin>>num;
    while(num > 3){
        cout<<"choose the levels from 1 to 3...";
        cin>>num;
    }
    getLevel(num);

    return 0;
}