#include<iostream>
using namespace std;

int main(){
    int n;
    string ans;
    while(true){
        cout<<"Enter a number between 1 and 8: ";
        cin>>n;
        if(n < 1 || n > 8){
            cout<<"Invalid Input.. enter a number between 1 to 8"<<endl;
        }else{
            for(int i=1; i<=n; i++){
                for(int j=i; j<n; j++){
                    cout<<".";
                }
                for(int j=1; j<=i; j++){
                    cout<<"#";
                }
                for(int j=1; j<=1; j++){
                    cout<<" ";
                }
                for(int j=1; j<=n; j++){
                    if(i == 1){
                        cout<<"=";
                    }else{
                        cout<<".";
                    }
                }
                for(int j=1; j<=1; j++){
                    cout<<" ";
                }
                for(int j=1; j<=i; j++){
                    cout<<"#";
                }
                for(int j=i; j<n; j++){
                    cout<<".";
                }
                cout<<endl;
            }
            cout<<"Do you want to continue..(yes/no) ";
            cin>>ans;
            if(ans == "yes"){
                continue;
            }else{
                cout<<"Program ended....";
                    break;
            }
        }
    }
    return 0;
    
}
