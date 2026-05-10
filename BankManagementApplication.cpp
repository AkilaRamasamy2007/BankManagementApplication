#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class BankAccount {

public:

    // Create Account
    void createAccount() {

        int accountNumber;
        string customerName;
        float balance;

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        ofstream file("accounts.txt", ios::app);

        file << accountNumber << "|"
             << customerName << "|"
             << balance << endl;

        file.close();

        cout << "\nAccount Created Successfully!\n";
    }

    // Display All Accounts
    void displayAccounts() {

        ifstream file("accounts.txt");

        string line;

        cout << "\n========== ACCOUNT DETAILS ==========\n";

        while(getline(file, line)) {

            stringstream ss(line);

            string accNo, name, bal;

            getline(ss, accNo, '|');
            getline(ss, name, '|');
            getline(ss, bal, '|');

            cout << "----------------------------------\n";
            cout << "Account Number : " << accNo << endl;
            cout << "Customer Name  : " << name << endl;
            cout << "Balance        : " << bal << endl;
            cout << "----------------------------------\n";
        }

        file.close();
    }

    // Deposit Money
    void depositMoney() {

        int searchAccNo;
        float amount;

        cout << "Enter Account Number: ";
        cin >> searchAccNo;

        cout << "Enter Amount to Deposit: ";
        cin >> amount;

        ifstream file("accounts.txt");
        ofstream temp("temp.txt");

        string line;

        bool found = false;

        while(getline(file, line)) {

            stringstream ss(line);

            string accNo, name, bal;

            getline(ss, accNo, '|');
            getline(ss, name, '|');
            getline(ss, bal, '|');

            int acc = stoi(accNo);
            float balance = stof(bal);

            if(acc == searchAccNo) {

                balance += amount;

                found = true;

                cout << "Amount Deposited Successfully!\n";
            }

            temp << acc << "|"
                 << name << "|"
                 << balance << endl;
        }

        file.close();
        temp.close();

        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");

        if(!found) {
            cout << "Account Not Found!\n";
        }
    }

    // Withdraw Money
    void withdrawMoney() {

        int searchAccNo;
        float amount;

        cout << "Enter Account Number: ";
        cin >> searchAccNo;

        cout << "Enter Amount to Withdraw: ";
        cin >> amount;

        ifstream file("accounts.txt");
        ofstream temp("temp.txt");

        string line;

        bool found = false;

        while(getline(file, line)) {

            stringstream ss(line);

            string accNo, name, bal;

            getline(ss, accNo, '|');
            getline(ss, name, '|');
            getline(ss, bal, '|');

            int acc = stoi(accNo);
            float balance = stof(bal);

            if(acc == searchAccNo) {

                if(amount > balance) {

                    cout << "Insufficient Balance!\n";

                } else {

                    balance -= amount;

                    cout << "Amount Withdrawn Successfully!\n";
                }

                found = true;
            }

            temp << acc << "|"
                 << name << "|"
                 << balance << endl;
        }

        file.close();
        temp.close();

        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");

        if(!found) {
            cout << "Account Not Found!\n";
        }
    }

    // Check Balance
    void checkBalance() {

        int searchAccNo;

        cout << "Enter Account Number: ";
        cin >> searchAccNo;

        ifstream file("accounts.txt");

        string line;

        bool found = false;

        while(getline(file, line)) {

            stringstream ss(line);

            string accNo, name, bal;

            getline(ss, accNo, '|');
            getline(ss, name, '|');
            getline(ss, bal, '|');

            int acc = stoi(accNo);

            if(acc == searchAccNo) {

                cout << "\nCurrent Balance: " << bal << endl;

                found = true;

                break;
            }
        }

        file.close();

        if(!found) {
            cout << "Account Not Found!\n";
        }
    }
};

int main() {

    BankAccount bank;

    int choice;

    do {

        cout << "\n=====================================\n";
        cout << "      BANK MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";

        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                bank.createAccount();
                break;

            case 2:
                bank.depositMoney();
                break;

            case 3:
                bank.withdrawMoney();
                break;

            case 4:
                bank.checkBalance();
                break;

            case 5:
                bank.displayAccounts();
                break;

            case 6:
                cout << "Thank You for Using Bank Management System!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}