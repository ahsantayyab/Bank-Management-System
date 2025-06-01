#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Customer {
private:
    string name;
    string address;
    string contactDetails;

public:
    Customer(const string& nm, const string& addr, const string& contact):
    name(nm), address(addr), contactDetails(contact) {
    }
    void display() const {
        cout << "Customer Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Contact Details: " << contactDetails << endl;
    }
};

class Account {
protected:
    string accountNumber;
    double balance;
    vector<string> transactionHistory;

public:
    Account(const string& accNum, double bal)
        : accountNumber(accNum), balance(bal) {}

    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs." << balance << endl;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        string transaction = "Deposit: +Rs." + to_string(amount);
        transactionHistory.push_back(transaction);
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            string transaction = "Withdrawal: -Rs." + to_string(amount);
            transactionHistory.push_back(transaction);
        }
        else {
            cout << "Insufficient funds." << endl;
        }
    }

    void displayTransactionHistory() const {
        cout << "Transaction History:" << endl;
        for (const string& transaction : transactionHistory) {
            cout << "- " << transaction << endl;
        }
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const string& accNum, double bal, double intRate)
        : Account(accNum, bal), interestRate(intRate) {}

    void display() const override {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

    void withdraw(double amount) override {
        double totalBalance = balance + (balance * interestRate / 100);
        if (totalBalance >= amount) {
            balance -= amount;
            string transaction = "Withdrawal: -Rs." + to_string(amount);
            transactionHistory.push_back(transaction);
        }
        else {
            cout << "Insufficient funds (including interest)." << endl;
        }
    }

};

class CurrentAccount : public Account {
public:
    CurrentAccount(const string& accNum, double bal)
        : Account(accNum, bal) {}

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            string transaction = "Withdrawal: -Rs." + to_string(amount);
            transactionHistory.push_back(transaction);
        }
        else {
            cout << "Insufficient funds." << endl;
        }
    }
};

void createAccount() {
    string name, address, contact;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Contact Details: ";
    getline(cin, contact);

    Customer customer(name, address, contact);

    double initialBalance;
    cout << "Enter Initial Balance: Rs.";
    cin >> initialBalance;

    string accountNumber;
    cout << "Enter Account Number: ";
    cin.ignore();
    getline(cin, accountNumber);

    int accountType;
    cout << "Select Account Type:" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Current Account" << endl;
    cout << "Enter Choice: ";
    cin >> accountType;

    Account* account;
    if (accountType == 1) {
        double interestRate;
        cout << "Enter Interest Rate (%): ";
        cin >> interestRate;
        account = new SavingsAccount(accountNumber, initialBalance, interestRate / 100.0);
        
    }
    else if (accountType == 2) {
        account = new CurrentAccount(accountNumber, initialBalance);
    }
    else {
        cout << "Invalid account type." << endl;
        return;
    }

    ofstream out("Account.txt", ios::app);
    if (out.is_open()) {
        out << name << "," << address << "," << contact << "," << accountNumber << "," << initialBalance << "," << accountType << endl;
        out.close();
        cout << "Account created successfully." << endl;
    }
    else {
        cout << "Error in creating account. Please try again." << endl;
    }
    delete account;
}
void displayAccount(const string& accountNumber) {
    ifstream in("Account.txt");
    if (in.is_open()) {
        string line;
        bool accountFound = false;

        while (getline(in, line)) {
            vector<string> accountDetails;
            string detail;
            stringstream ss(line);
            while (getline(ss, detail, ',')) {
                accountDetails.push_back(detail);
            }
            if (accountDetails[3] == accountNumber) {
                accountFound = true;
                Customer customer(accountDetails[0], accountDetails[1], accountDetails[2]);
                customer.display();

                int accountType = stoi(accountDetails[5]);
                double balance = stod(accountDetails[4]);
                double interestRate = 0.0;

                if (accountType == 1) {
                   interestRate = stod(accountDetails[6]);
                }

                Account* account;
                if (accountType == 1) {
                    account = new SavingsAccount(accountDetails[3], balance, interestRate);
                }
                else if (accountType == 2) {
                    account = new CurrentAccount(accountDetails[3], balance);
                }
                else {
                    cout << "Invalid account type." << endl;
                    return;
                }


                account->display();
                delete account;

                break;
            }
        }

        if (!accountFound) {
            cout << "Account not found." << endl;
        }

        in.close();
    }
    else {
        cout << "Error in opening account file." << endl;
    }
}


void performDeposit(const string& accountNumber) {
    double amount;
    cout << "Enter the amount to deposit: Rs.";
    cin >> amount;

    ifstream in("Account.txt");
    if (in.is_open()) {
        string line;
        bool accountFound = false;
        vector<string> accountLines;

        while (getline(in, line)) {
            vector<string> accountDetails;
            string detail;
            stringstream ss(line);
            while (getline(ss, detail, ',')) {
                accountDetails.push_back(detail);
            }
            if (accountDetails[3] == accountNumber) {
                accountFound = true;
                double balance = stod(accountDetails[4]) + amount;
                accountDetails[4] = to_string(balance);
            }
            accountLines.push_back(line);
        }

        in.close();

        if (accountFound) {
            ofstream out("Account.txt");
            if (out.is_open()) {
                for (const string& accountLine : accountLines) {
                    out << accountLine << endl;
                }
                out.close();
                cout << "Deposit successful." << endl;
            }
            else {
                cout << "Error in opening account file for deposit." << endl;
            }
        }
        else {
            cout << "Account not found." << endl;
        }
    }
    else {
        cout << "Error in opening account file." << endl;
    }
}

void performWithdrawal(const string& accountNumber) {
    double amount;
    cout << "Enter the amount to withdraw: Rs.";
    cin >> amount;

    ifstream in("Account.txt");
    if (in.is_open()) {
        string line;
        bool accountFound = false;
        vector<string> accountLines;

        while (getline(in, line)) {
            vector<string> accountDetails;
            string detail;
            stringstream ss(line);
            while (getline(ss, detail, ',')) {
                accountDetails.push_back(detail);
            }
            if (accountDetails[3] == accountNumber) {
                accountFound = true;
                double balance = stod(accountDetails[4]);
                int accountType = stoi(accountDetails[5]);

                if (accountType == 1) {
                    SavingsAccount account(accountDetails[3], balance, stod(accountDetails[4]));
                    account.withdraw(amount);
                    balance = account.getBalance();
                }
                else if (accountType == 2) {
                    CurrentAccount account(accountDetails[3], balance);
                    account.withdraw(amount);
                    balance = account.getBalance();
                }

                accountDetails[4] = to_string(balance);
            }
            accountLines.push_back(line);
        }

        in.close();

        if (accountFound) {
            ofstream outputFile("Account.txt");
            if (outputFile.is_open()) {
                for (const string& accountLine : accountLines) {
                    outputFile << accountLine << endl;
                }
                outputFile.close();
                cout << "Withdrawal successful." << endl;
            }
            else {
                cout << "Error in opening account file for withdrawal." << endl;
            }
        }
        else {
            cout << "Account not found." << endl;
        }
    }
    else {
        cout << "Error in opening account file." << endl;
    }
}
 
int main() {
    int choice;
    string accountNumber;
    
    while (true) {
        cout << " \n\n\t\t\t\t\t\t\t\t\t\t\tBanking System " << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Display Account Details" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        try {
            switch (choice) {
                case 1:
                    createAccount();
                    main();
                    break;
                case 2:
                    cout << "Enter Account Number: ";
                    cin.ignore();
                    getline(cin, accountNumber);
                    displayAccount(accountNumber);
                    main();
                    break;
                case 3:
                    cout << "Enter Account Number: ";
                    cin.ignore();
                    getline(cin, accountNumber);
                    performDeposit(accountNumber);
                    main();
                    break;
                case 4:
                    cout << "Enter Account Number: ";
                    cin.ignore();
                    getline(cin, accountNumber);
                    performWithdrawal(accountNumber);
                    main();
                    break;
                case 5:
                    cout << "Exiting program. Goodbye!" << endl;
                    break;
                default:
                    throw runtime_error("Invalid choice. Please try again.");
            }
        }
        catch (... ) {
            cerr << "Error: "<< endl;
            main();
        }
        
        return 0;
    }
    
}


