#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string uname, pass;
    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pass;

    ifstream check(uname + ".txt");
    if (check.is_open()) {
        cout << "User already exists.\n";
        return;
    }

    ofstream file(uname + ".txt");
    file << "Username: " << uname << "\n";
    file << "Password: " << pass << "\n";
    file.close();

    cout << "Registered successfully.\n";
}

void loginUser() {
    string uname, pass;
    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pass;

    ifstream file(uname + ".txt");
    if (!file.is_open()) {
        cout << "User not found.\n";
        return;
    }

    string line, savedUser = "", savedPass = "";
    getline(file, line);
    savedUser = line.substr(line.find(":") + 2);  // remove "Username: "
    getline(file, line);
    savedPass = line.substr(line.find(":") + 2);  // remove "Password: "
    file.close();

    if (uname == savedUser && pass == savedPass) {
        cout << "Login successful.\n";
    } else {
        cout << "Wrong password.\n";
    }
}

int main() {
    int ch;
    cout << "1. Register\n2. Login\nEnter: ";
    cin >> ch;

    if (ch == 1) {
        registerUser();
    } else if (ch == 2) {
        loginUser();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
