#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

bool nameCheck(const string& checkName){
    ifstream inFile("accounts.txt");
    string line, name;

    while(getline(inFile, line)){
        istringstream iss(line);
        iss >> name;
        if(name == checkName){
            return true;
        }
    }
    return false;
}

bool login(const string& loginname, const string& loginpass){
    ifstream loginFile("accounts.txt");
    string line, ncheck, pcheck;

    while(getline(loginFile, line)){
        istringstream iss(line);
        iss >> ncheck >> pcheck;
        if(ncheck == loginname && pcheck == loginpass){
            return true;
        }
    }
    return false;
}

bool receiverCheck(const string& receivernam){
    ifstream receiverFile("accounts.txt");
    string line, rcheck;

    while(getline(receiverFile, line)){
        istringstream iss(line);
        iss >> rcheck;
        if(rcheck == receivernam){
            return true;
        }
    }
    return false;
}


struct Account {
    string name;
    string password;
    double balance;
};

vector<Account> readAccounts(const string& filename){
    vector<Account> accounts;
    ifstream file(filename);
    string line, name, password;
    double balance;

    while(getline(file, line)){
        istringstream iss(line);
        if (iss >> name >> password >> balance){
            accounts.push_back({name, password, balance});
        }
    }
    return accounts;
}

void writeAccounts(const vector<Account>& accounts, const string& filename){
    ofstream file(filename);
    for(const auto& acc : accounts){
        file<<acc.name<<" "<<acc.password<<" "<<acc.balance<<endl;
    }
}

void depositMoney(const string& username, double amount){
    string filename = "accounts.txt";
    vector<Account> account = readAccounts(filename);
    bool found = false;

    for(auto& acc : account){
        if(acc.name == username){
            acc.balance += amount;
            ofstream outFile("transactions.txt", ios::app);
            outFile<<username<<" | Deposit | "<<amount<<" | "<<acc.balance<<endl;
            outFile.close();
            cout<<"Deposited "<<amount<<". New Balance: "<<acc.balance<<endl;
            found = true;
            break;
        }
    }

    if(found){
        writeAccounts(account, filename);
    }
}

void withdrawMoney(const string username, double amount){
    string filename = "accounts.txt";
    vector<Account> account = readAccounts(filename);
    bool found = false;

    for(auto& acc : account){
        if(acc.name == username){
            if(amount < acc.balance){
                acc.balance -= amount;
                ofstream outFile("transactions.txt", ios::app);
                outFile<<username<<" | Withdraw | "<<amount<<" | "<<acc.balance<<endl;
                outFile.close();
                cout<<"Withdrawn "<<amount<<". New Balance: "<<acc.balance<<endl;
                found = true;
                break;
            }else{
                cout<<"Insufficient Balace!"<<endl;
            }
        }
    }

    if(found){
        writeAccounts(account, filename);
    }
}

void checkBalance(const string& username){
    vector<Account> accounts = readAccounts("accounts.txt");

    for(const auto& acc : accounts){
        if(acc.name == username){
            cout<<"Current Balance: "<<acc.balance<<endl;
            return;
        }
    }
}

void viewTransactions(const string& username){
    ifstream file("transactions.txt");
    string line;

    cout<<"---- Transaction History ----"<< endl;
    while(getline(file, line)){
        if(line.find(username + " |") == 0){  
            cout<<line<<endl;
        }
    }
    cout<<"-----------------------------"<<endl;
}

void transferMoney(const string username,const string receivername, double amount){
    string filename = "accounts.txt";
    double origamount = amount;
    vector<Account> account = readAccounts(filename);
    double senderBalance = 0.0, receiverBalance = 0.0;
    bool found1 = false, found2 = false;

    for(auto& acc : account){
       if(acc.name == username){
           if(amount < acc.balance){
               acc.balance -= amount;
               senderBalance = acc.balance;
               found1 = true;
               ofstream outFile("transactions.txt", ios::app);
               outFile<<username<<" | Transfer to "<<receivername<<" | "<<origamount<<" | "<<acc.balance<<endl;
               outFile.close();
               cout<<"Transferred "<<origamount<<" to "<<receivername<<". New Balance: "<<acc.balance<<endl;
            }
        }
    }
    for(auto& acc : account){
       if(acc.name == receivername){
            acc.balance += amount;
            receiverBalance = acc.balance;
            found2 = true;
            ofstream outtFile("transactions.txt", ios::app);
            outtFile<<receivername<<" | Transfer from "<<username<<" | "<<origamount<<" | "<<acc.balance<<endl;
            outtFile.close();
        }
    }
    if(found1 && found2){
        writeAccounts(account, filename);
    }
}


int main(){
    while(true){
        int option;
        string name, password, lname, lpassword;
        double balance = 0.0;
        cout<<"========== OFFLINE BANKING SYSTEM=========="<<endl;
        cout<<"1. Register"<<endl;
        cout<<"2. Login"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Choose an option: ";
        cin>>option;
        if(option == 1){
            cout<<"Enter a username: ";
            cin>>name;
            if(nameCheck(name)){
                cout<<"The name already exists! Try another."<<endl;
                return 0;
            }
            cout<<"Enter a password: ";
            cin>>password;  
            
            ofstream outFile("accounts.txt", ios::app);
            outFile<<name<<" "<<password<<" "<<balance<<endl;
            outFile.close();

            cout<<"registration Successful!"<<endl;
        }else if(option == 2){
            cout<<"Enter username: ";
            cin>>lname;
            cout<<"Enter Password: ";
            cin>>lpassword;
            if(login(lname, lpassword)){
                cout<<"Welcome, "<<lname<<"!"<<endl;
                while(true){
                    int option2;
                    double amount, withdraw, transfer;
                    string recname;
                    cout<<"========== OFFLINE BANKING SYSTEM=========="<<endl;
                    cout<<"Logged in as: "<<lname<<endl;
                    cout<<"3. Deposit"<<endl;
                    cout<<"4. Withdraw"<<endl;
                    cout<<"5. Transfer"<<endl;
                    cout<<"6. Check Balance"<<endl;
                    cout<<"7. View Transactions"<<endl;
                    cout<<"8. Logout"<<endl;
                    cout<<"9. Exit"<<endl; 
                    cout<<"Choose an option: ";
                    cin>>option2; 
                    if(option2 == 3){
                        cout<<"enter amount to deposit: ";
                        cin>>amount;
                        depositMoney(lname, amount);
                    }else if(option2 == 4){
                        cout<<"Enter amount to withdraw: ";
                        cin>>withdraw;
                        withdrawMoney(lname, withdraw);
                    }else if(option2 == 5){
                        cout<<"Enter receiver's username: ";
                        cin>>recname;
                        if(!receiverCheck(recname)){
                            cout<<"Receiver not found!"<<endl;
                            return 0;
                        }
                        cout<<"Enter amount to transfer: ";
                        cin>>transfer;
                        transferMoney(lname, recname, transfer);
                    }else if(option2 == 6){
                        checkBalance(lname);
                    }else if(option2 == 7){
                        viewTransactions(lname);
                    }else if(option2 == 8){
                        cout<<"Logged out."<<endl;
                        break;
                    }
                }
            }else{
                cout<<"Invalid Username or Password"<<endl;
            }
            
        }else if(option == 9){
            cout<<"Good bye!"<<endl;
            break;
        }  
    }
    return 0;
}