#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void show() {
        cout << type << ": Rs. " << amount << endl;
    }
};

class Account {
public:
    int accNo;
    double balance;
    vector<Transaction> record;

    Account(int no) {
        accNo = no;
        balance = 0;
    }

    void addMoney(double amount) {
        balance += amount;
        record.push_back(Transaction("Deposit", amount));
    }

    void takeMoney(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            record.push_back(Transaction("Withdraw", amount));
        }
    }

    void sendMoney(Account &user, double amount) {
        if (amount > balance) {
            cout << "Transfer failed: Not enough balance.\n";
        } else {
            balance -= amount;
            user.balance += amount;
            record.push_back(Transaction("Sent to " + user.getID(), amount));
            user.record.push_back(Transaction("Received from " + getID(), amount));
        }
    }

    string getID() {
        return to_string(accNo);
    }

    void showAll() {
        cout << "Account No: " << accNo << "\n";
        cout << "Balance: Rs. " << balance << "\n";
        cout << "Transactions:\n";
        for (auto x : record) {
            x.show();
        }
    }
};

class User {
public:
    string name;
    Account acc;

    User(string n, int number) : acc(number) {
        name = n;
    }

    void showUser() {
        cout << "\nUser: " << name << endl;
        acc.showAll();
    }
};

int main() {
    string name1, name2;
    int no1, no2;

    cout << "Enter username 1: ";
    cin >> name1;
    cout << "Enter account number 1: ";
    cin >> no1;

    cout << "Enter username 2: ";
    cin >> name2;
    cout << "Enter account number 2: ";
    cin >> no2;

    User u1(name1, no1);
    User u2(name2, no2);

    int choice;
    while (true) {
        cout << "\n1. Deposit\n2. Withdraw\n3. Transfer\n4. Show Details\n5. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            double amt;
            cout << "Deposit amount: ";
            cin >> amt;
            u1.acc.addMoney(amt);
        } else if (choice == 2) {
            double amt;
            cout << "Withdraw amount: ";
            cin >> amt;
            u1.acc.takeMoney(amt);
        } else if (choice == 3) {
            double amt;
            cout << "Amount to transfer: ";
            cin >> amt;
            u1.acc.sendMoney(u2.acc, amt);
        } else if (choice == 4) {
            u1.showUser();
            u2.showUser();
        } else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        } else {
            cout << "Invalid choice. Please select from 1 to 5.\n";
        }
    }

    return 0;
}
