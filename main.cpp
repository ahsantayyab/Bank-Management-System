
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    

    ifstream source_file("q6.txt");
    ofstream target_file("q7.txt");
    string line;

    if (source_file.is_open() && target_file.is_open()) {
        while (getline(source_file, line)) {
            target_file << line << endl;
        }
        source_file.close();
        target_file.close();
        cout << "File contents successfully copied." << endl;
    } else {
        cout << "Unable to open file for reading or writing." << endl;
    }

    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    ifstream file;
    file.open("q6.txt");

    if (file.is_open()) {
        int count = 0;
        int number;
        while (file >> number && count < 10) {
            cout << number << endl;
            count++;
        }
        file.close();

        if (count < 10) {
            cout << "The file is finished." << endl;
        }
    } else {
        cout << "Unable to open file for reading." << endl;
    }

    return 0;
}




#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    ofstream file;
    file.open("22arid713.txt", ios::app);

    if (file.is_open()) {
        string input;
        cout << "Enter few lines about your favorite subject:" << endl;
        getline(cin, input);
        file << input << endl;
        
        file.close();
        cout << "Data written to file successfully." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }

    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string word;
    int count = 0;

    cout << "Enter the word to search: ";
    cin >> word;

    ifstream file("q3.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = 0;
            while ((pos = line.find(word, pos)) != string::npos) {
                count++;
                pos += word.length();
            }
        }
        file.close();
        cout << "The word '" << word << "' appeared " << count << " times in the file." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }

    return 0;
}



#include <iostream>
#include <fstream>

using namespace std;
int main() {
    string word;
    int count = 0;

    cout << "Enter the word to search: ";
    cin >> word;

    ifstream file("q3.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = 0;
            while ((pos = line.find(word, pos)) != string::npos) {
                count++;
                pos += word.length();
            }
        }
        file.close();
        cout << "The word '" << word << "' appeared " << count << " times in the file." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }

    return 0;
}






//________________________________________________________________________________________________________________________________/


//2
int main(){
    string fileName;
    ofstream x;
    x.open("data.txt");
              string line;
              int lineCount = 0;
              int wordCount = 0;
              int charCount = 0;
              if (x.is_open()) {
                  while(x.is_open()){
                      lineCount++;
                      int words = 0;
                      for(int i = 0; line.length(); i++) {
                          if (line[i] == wordCount){
                              words++;
                          }
                      }
                      wordCount += words + 1;
                      charCount += line.length();
                  }
                  x.close();
                  cout<<wordCount;
                  cout<<lineCount;
                  cout<<charCount;
                }
                else {
                    cout<<"file not found";
               }
        return 0;
}
                                        //3
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string word;
    int count = 0;

    cout << "Enter the word to search: ";
    cin >> word;

    ifstream file("q3.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = 0;
            while ((pos = line.find(word, pos)) != string::npos) {
                count++;
                pos += word.length();
            }
        }
        file.close();
        cout << "The word '" << word << "' appeared " << count << " times in the file." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }

    return 0;
}


















const int ROW = 3;
const int COL = 3;

int main() {
    int arr1[ROW][COL] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int arr2[ROW][COL] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int res[ROW][COL] = {0};

    // Multiply the two arrays
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            for (int k = 0; k < ROW; k++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    // Print the result
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/













/*
int main(){
    int a;
    cout<<"Enter a Number : ";
    cin>>a;
    int* ptr = &a;
    cout<<"Address of Your Number is :"<<ptr<<endl;
    cout<<"Address of Your Number is :"<<&ptr<<endl;
    cout<<"Address of Your Number is :"<<&a<<endl;
    cout<<"Address of ";
    return 0;
}




void sum();
int a;
int main(){
    int n[0];
    int a=0,i,j;
    cout<<"How many Numbers You Want to Enter : ";
    cin>>i;
    cout<<"\n\nEnter Numbers :";
    for(j=1;j<=i;j++)
    {
        cin>>n[i];
    }
    
    sum();
    return 0;
}
void sum(){
    {
        for(int j=1;j<=i;j++)
        {
            
        }
        cout<<"Sum of all numbers is "<<a;

    }
}
*/





























/*#include<iostream>
#include<fstream>
#include<string>


using namespace std;

 
//----------------------------------------------------------------------------------------------------------------------------------------------------//
//Main Objectives...
void account();
void transaction();
void reporting();


//----------------------------------------------------------------------------------------------------------------------------------------------------//
///. Account
//1.
void newaccount();
//2.
void info();
//----------------------------------------------------------------------------------------------------------------------------------------------------//
//Information...
int searchACC();
void updateData();

//3.
void closeaccount();

//----------------------------------------------------------------------------------------------------------------------------------------------------//
//Transaction processing...
int deposit();
void withdrawal();


//----------------------------------------------------------------------------------------------------------------------------------------------------//
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



//----------------------------------------------------------------------------------------------------------------------------------------------------//
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



void updateData() {
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




//----------------------------------------------------------------------------------------------------------------------------------------------------//
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


//----------------------------------------------------------------------------------------------------------------------------------------------------//

*/




