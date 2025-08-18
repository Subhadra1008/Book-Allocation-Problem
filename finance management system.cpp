#include <iostream>
using namespace std;

int main() {
    int income = 0, expense = 0, choice;

    while (true) {
        cout << "\nFinance Management System\n"
             << "==========================\n"
             << "1. Add Income\n"
             << "2. Add Expense\n"
             << "3. Balance Inquiry\n"
             << "4. Exit\n"
             << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            int amt;
            cout << "Enter Income: ";
            cin >> amt;
            income += amt;
            cout << "Income Added to your account\n";
        } 
        else if (choice == 2) {
            int amt;
            cout << "Enter Expense: ";
            cin >> amt;
            expense += amt;
            cout << "Expense Added to your amount\n";
        } 
        else if (choice == 3) {
            int balance = income - expense;
            if (balance > 0) 
                cout << "You are in Profit of " << balance << " $!\n";
            else if (balance < 0) 
                cout << "You are in Loss of " << -balance << " $!\n";
            else 
                cout << "You are at Break-Even.\n";
        } 
        else if (choice == 4) {
            cout << "Best of Luck!\n";
            break;
        } 
        else {
            cout << "Error: Invalid Input!\n";
        }
    }
}
