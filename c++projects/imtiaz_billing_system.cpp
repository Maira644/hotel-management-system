#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

string toUpperCase(string str){
    for(char& ch : str){
        ch = toupper(ch);
    }
    return str;
}

int main(){
    vector<string> menu = {"TORTILLA", "TACO", "BURRITO"};
    vector<float> price = {8.00, 3.00, 7.50};
    vector<int> quantity;
    vector<string> items;
    string item;
    float total = 0, amount, change;

    cout<<"This is the menu!\n";
    for(string val : menu){
        cout<<val<<" ";
    }
    cout<<endl;
    while(true){
        cout<<"Item: ";
        cin>>item;

        string upperItem = toUpperCase(item);

        if(item == "CTRL+"){
            break;
        }else if(((find(menu.begin(), menu.end(), upperItem) != menu.end()))){
            items.push_back(upperItem);
        }else{
            cout<<"Not Available..."<<endl;
            continue;
        }
    }

    for(int i=0; i<menu.size(); i++){
        int count = 0;
        for(int j=0; j<items.size(); j++){
            if(menu[i] == items[j]){
                count++;
            }
        }
        quantity.push_back(count);
    }
    cout<<"\n---FINAL BILL---\n";
    cout<<fixed<<setprecision(2);
    for(int i=0; i<quantity.size(); i++){
        float bill = quantity[i] * price[i];
        total += bill;
        if(quantity[i] > 0){
            cout<<menu[i]<<" x"<<quantity[i]<<" @ $"<<price[i]<<" = $"<<bill<<endl;
        }
    }
    cout<<"\n--------------------------------\n";
    cout<<"Total Due: $"<<total<<endl;

    cout<<"Enter payment amount: ";
    cin>>amount;
    if(amount > total){
        change = amount - total;
    }
    cout<<"Change: $"<<change<<endl;

    cout<<"\n---RECEIPT---\n";

    cout<<"Paid: $"<<amount<<endl;
    cout<<"Total: $"<<total<<endl;
    cout<<"Change: $"<<change<<endl;
    cout<<"Thank you for shopping at Imtiaz Supermarket!"<<endl;

    return 0;
}