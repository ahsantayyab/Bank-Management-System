#include<iostream>
#include<fstream>
#include<string>


using namespace std;

 
//----------------------------------------------------------------------------------------------------------------------------------------------------//
//Main Objectives...
void account();
void transaction();
void reporting();


//---------------------------------------------------------------------------------------------------------------------------------------------------
//1.
void newaccount();
//2.
void info();
//---------------------------------------------------------------------------------------------------------------------------------------------------
//Information...
int searchACC();
void updateData();

//3.
void closeaccount();

//----------------------------------------------------------------------------------------------------------------------------------------------------//
//Transaction processing...
int deposit();
void withdrawal();


//--------------------------------------------------------------------------------------------------------------------------------------------------
//Reporting...
void account_summeries();

//Global Variable
int ID;

struct Account{
    int id;
    string name;
    string fname;
    string dob;
};



//---------------------------------------------------------------------------------------------------------------------------------------------------
int main(){
    int n;
    
    cout<<endl<<"                                                         Banking Management System  "<<endl<<endl<<endl;
    
    cout<<"1. Customer account management..."<<endl;
    cout<<"2. Transaction processing..."<<endl;
    cout<<"3. Reporting..."<<endl;
    
    cout<<"Select (1-3)"<<endl;
    cout<<"Enter  ";cin>>n;
    
    switch (n) {
        case 1:
            account();
            break;
        case 2:
            transaction();
            break;
        case 3:
            reporting();
            break;
        default:
            cout<<"You Entered Invalid input"<<endl;
            break;
    }
     
    cout<<endl;
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------//
void account(){
    int n;
    cout<<"Customer account management:"<<endl<<endl;
    cout<<"                            1. Create New Account."<<endl;
    cout<<"                            2. View & Update Information."<<endl;
    cout<<"                            3. Close Existing Account."<<endl;
    cout<<"                            4. Back"<<endl;
    
    cout<<"Select (1-4)"<<endl;
    cout<<"Enter  ";cin>>n;
    cout<<endl<<endl<<endl;
    switch (n) {
        case 1:
            cout<<"Create New Account:"<<endl;
            newaccount();
            break;
        case 2:
            cout<<"View & Update Information:"<<endl;
            info();
            break;
        case 3:
            cout<<"Close Existing Account:"<<endl;
            closeaccount();
            break;
        case 4:
            main();
            break;
        default:
            cout<<"You Entered Invalid input"<<endl;
            break;
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------//
void transaction(){
    int n;
    cout<<"Transaction processing:"<<endl<<endl;
    cout<<"                            1. Deposit."<<endl;
    cout<<"                            2. Withdrawal."<<endl;
    cout<<"                            3. Back"<<endl;
    
    cout<<"Select (1-3)"<<endl;
    cout<<"Enter  ";cin>>n;
    cout<<endl<<endl<<endl;
    switch (n) {
        case 1:
            cout<<"Deposit:"<<endl;
            deposit();
            break;
        case 2:
            cout<<"Withdrawal:"<<endl;
            withdrawal();
            break;
        case 3:
            main();
            break;
        default:
            cout<<"You Entered Invalid input"<<endl;
            break;
    }
}


//----------------------------------------------------------------------------------------------------------------------------------------------------//
void reporting(){
    int n;
    cout<<"Reporting:"<<endl<<endl;
    cout<<"                            1. Customer Account Summaries."<<endl;
    cout<<"                            2. Back"<<endl;
    
    cout<<"Select (1-2)"<<endl;
    cout<<"Enter  ";cin>>n;
    cout<<endl<<endl<<endl;
    switch (n) {
        case 1:
            cout<<"Customer Account Summaries:"<<endl;
            account_summeries();
            break;
        case 2:
            main();
            break;
        default:
            cout<<"You entered Invalid input"<<endl;
            break;
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------/
//----------------------------------------------------------------------------------------------------------------------------------------------------/

void newaccount(){
    Account acc;
    cout << "\n\tEnter User name : ";
    cin.get();
    getline(cin, acc.name);
    cout<<endl;
    cout<<"\n\t Enter User Father Name : ";
    getline(cin, acc.fname);
    cout<<endl;
    cout<<"\n\t Enter Date of birth dd-mm-yyyy    :";
    getline(cin, acc.dob);
    cout<<endl;
    ID++;

    ofstream write;
    write.open("data.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << acc.name ;
    write << "\n" << acc.fname ;
    write << "\n" << acc.dob ;
    
    write.close();
    write.open("max_acc.txt");
    write << ID;
    write.close();
    cout << "\n\tAccount Created SuceessFully";
    cout<<"\n\n\tYour Account Number is  "<<ID;
    
    main();
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void info(){
    int n;
    cout<<"View & Update Information :"<<endl<<endl;
    cout<<"                            1. Veiw Or Search Account"<<endl;
    cout<<"                            2. Update User Acoount"<<endl;
    cout<<"                            3. Back"<<endl;
    
    cout<<"Select (1-3)"<<endl;
    cout<<"Enter  ";cin>>n;
    cout<<endl<<endl<<endl;
    switch (n) {
        case 1:
            cout<<"Veiw Or Search Account:"<<endl;
            searchACC();
            break;
        case 2:
            cout<<"Update User Acoount:"<<endl;
            updateData();
            break;
        case 3:
            main();
            break;
        default:
            cout<<"You entered Invalid input"<<endl;
            break;
    }
}



//--------------------------------------------------------------------------------------------------------------------------------//

void print(Account s) {
    cout << "\n\t---Account Information---";
    cout << "\n\tID is : " << s.id;
    cout << "\n\tName is : " << s.name;
    cout << "\n\tFather Name is : " << s.fname;
    cout << "\n\tDate of Birth is : " << s.dob;

}

void readData() {
    Account acc;
    ifstream read;
    read.open("data.txt");
    while (!read.eof()) {
        read >> acc.id;
        read.ignore();
        getline(read, acc.name);
        getline(read, acc.fname);
        getline(read, acc.dob);
        print(acc);
    }
    read.close();
}

int searchACC() {
    int id;
    cout << "\n\tEnter Account ID to search : ";
    cin >> id;
    Account acc;
    ifstream read;
    read.open("data.txt");
    while (!read.eof()) {
        read >> acc.id;
        getline(read, acc.name);
        getline(read, acc.fname);
        getline(read, acc.dob);
        if (acc.id == id) {
            print(acc);
            return id;
        }
        else{
            cout<<"Invalid Account No";
        }
    
    main();
    return 0;
    
}

void updateData(){
    int id = searchACC();
    cout << "\n\tYou want to update Account (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Account newAcc;
        cout << "\n\tEnter User name : ";
        cin.get();
        getline(cin, newAcc.name);
        cout<<"\t\t\t\t Enter User Father Name:";
        getline(cin, newAcc.fname);
        cout<<endl;
        cout<<"\t\t\t\t Enter Date of birth dd-mm-yyyy    :";
        getline(cin, newAcc.dob);
        cout<<endl;
        
        Account acc;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("data.txt");
        while (!read.eof()) {
            read >> acc.id;
            getline(read, acc.name);
            getline(read, acc.fname);
            getline(read, acc.dob);
            if (acc.id != id) {
                tempFile << "\n" << acc.id;
                tempFile << "\n" << acc.name;
                tempFile << "\n" << acc.fname;
                tempFile << "\n" << acc.dob;
            }
            else {
                tempFile << "\n"<< acc.id;
                tempFile << "\n"<< newAcc.name;
                tempFile << "\n"<< newAcc.fname;
                tempFile << "\n"<< newAcc.dob;
            }
        }
        read.close();
        tempFile.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    main();
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void closeaccount(){
    int id = searchACC();
    cout << "\n\tYou want to delete Account (Y/N) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Account acc;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("data.txt");
        while (!read.eof()) {
            read >> acc.id;
            read.ignore();
            getline(read, acc.name);
            getline(read, acc.fname);
            getline(read, acc.dob);
            if (acc.id != id) {
                tempFile <<endl<< acc.id;
                tempFile <<endl<< acc.name;
                tempFile <<endl<< acc.fname;
                tempFile <<endl<< acc.dob;
            }
        }
        read.close();
        tempFile.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");
        cout << "\n\tData deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    main();
}

///                                                          Transaction processing...
///---------------------------------------------------------------
///-------------------------------------------------------------------------------------------------------------------    2

int deposit(){
    int id;
    cout << "\n\tEnter Account ID to search : ";
    cin >> id;
    Account acc;
    ifstream read;
    read.open("data.txt");
    while (!read.eof()) {
        read >> acc.id;
        getline(read, acc.name);
        getline(read, acc.fname);
        getline(read, acc.dob);
        if (acc.id == id) {
            int amt;
            cout<<"Enter Amount : ";
            cin>>amt;
            ofstream write;
            write.open("cash_acc.txt",ios::app);
            write<<id<<endl;
            write<<amt<<endl;
            cout<<"Amount Entered Successfully :";
            
        }
        else{
            cout<<"Invalid Account No";
        }
    }
    main();
    return 0;
}
void withdrawal(){
    int id;
    cout << "\n\tEnter Account ID to search : ";
    cin >> id;
    Account acc;
    ifstream read;
    read.open("data.txt");
    while (!read.eof()) {
        read >> acc.id;
        read.ignore();
        getline(read, acc.name);
        getline(read, acc.fname);
        getline(read, acc.dob);
        if (acc.id == id) {
            int amt;
            cout<<"Enter Amount : ";
            cin>>amt;
            ofstream write;
            write.open("cash_acc.txt");
            write<<id<<endl;
            write<<amt<<endl;
            cout<<"Amount Entered Successfully :";
            
        }
        else{
            cout<<"Invalid Account No";
        }
    }
    main();
}


///                                                           Reporting...
///---------------------------------------------------------------
///---------------------------------------------------------------------------------------------------------------    3

    void account_summeries(){
        int id,n,a;
        cout << "\t\t\tAre you want to see All Accounts Details : "<<endl<<endl;
        cout << "\t\t\tPress 1 to continue : "<<endl<<endl;
        cout << "\t\t\tPress 0 to Back : "<<endl;
        cin>>n;
        if(n==1){
            cout<<"Enter Password :";
            cin>>id;
            a=123;
            if(id == a){
                Account acc;
                ifstream read;
                read.open("data.txt");
                while (!read.eof()) {
                    read >> acc.id;
                    read.ignore();
                    getline(read, acc.name);
                    getline(read, acc.fname);
                    getline(read, acc.dob);
                    
                    cout<<"\t\t\t\t\tAccount Number : "<<acc.id<<endl;
                    cout<<"\t\tUser Name : "<<acc.name<<endl;
                    cout<<"\t\tUser Father Name : "<<acc.fname<<endl;
                    cout<<"\t\tUser Date of Birth : "<<acc.dob<<endl<<endl<<endl<<endl;
                    
                }
            }
            main();
            
        }
        
    }
