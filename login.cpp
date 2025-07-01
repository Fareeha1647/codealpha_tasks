#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Utility to clear input errors
void clearInput() {
    cin.clear();
    cin.ignore(10000, '\n');
}

// Register new user
void registerUser() {
    string username, password;
    cout << "\n--- User Registration ---" << endl;
    cout << "Enter Username: ";
    cin >> username;

    string filename = username + ".txt";

    ifstream checkFile(filename.c_str());  // FIXED
    if (checkFile.good()) {
        cout << "Username already exists!" << endl;
        checkFile.close();
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream outFile(filename.c_str());  // FIXED
    if (!outFile) {
        cout << "Error creating user file!" << endl;
        return;
    }

    outFile << password;
    outFile.close();

    cout << "User registered successfully!" << endl;
}

// Reset password
void resetPassword(const string& username) {
    string newPassword;
    cout << "Enter new password: ";
    cin >> newPassword;

    ofstream outFile((username + ".txt").c_str());  // FIXED
    if (!outFile) {
        cout << "Error updating password!" << endl;
        return;
    }

    outFile << newPassword;
    outFile.close();

    cout << "Password reset successfully!" << endl;
}

// Login user
void loginUser() {
    string username, password;
    cout << "\n--- User Login ---" << endl;
    cout << "Enter Username: ";
    cin >> username;

    string filename = username + ".txt";

    ifstream inFile(filename.c_str());  // FIXED
    if (!inFile) {
        cout << "User not found!" << endl;
        return;
    }

    string storedPassword;
    getline(inFile, storedPassword);
    inFile.close();

    cout << "Enter Password: ";
    cin >> password;

    if (password == storedPassword) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Incorrect password!" << endl;
        char choice;
        cout << "Forgot password? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            resetPassword(username);
        } else {
            cout << "Returning to main menu..." << endl;
        }
    }
}

// Main menu
void showMenu() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\n=== Main Menu ===" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}

// Entry point
int main() {
    showMenu();
    return 0;
}

