#include <iostream>
#include <set>
using namespace std;
/* Name: Miguel Angel Prado
 * Date: 02/20/2026
 * Purpose: Implement a BankAccount class to simulate basic banking operations for multiple accounts.
 * Assignment: Lab Activities: Advanced Objects and Classes II
 */

class BankAccount {
    public:
        BankAccount();
        BankAccount(const string& number, const string& name, double bal);
        void SetName(const string& name);
        string GetNumber() const;
        string GetName() const;
        double GetBal() const;
        void deposit(double amount);
        void withdraw(double amount);
        BankAccount (const BankAccount& other);
        BankAccount& operator=(const BankAccount& other);
        ~BankAccount();
        BankAccount& operator+=(double amount);
        BankAccount& operator-=(double amount);
        bool operator==(const BankAccount& other) const;
        bool operator<(const BankAccount& other) const;
        bool operator>(const BankAccount& other) const;
        static void printAccount(const BankAccount& account);
        static BankAccount createAccountFromInput();

    private:
        string accountNumber;
        string accountHolderName;
        double balance;
};
BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    balance = -1.0;
}
BankAccount::BankAccount(const string& number, const string& name, double bal) {
    accountNumber = number;
    accountHolderName = name;
    balance = bal;
}
void BankAccount::SetName(const string& name) {
    accountHolderName = name;
}
string BankAccount::GetNumber() const {
    return accountNumber;
}
string BankAccount::GetName() const {
    return accountHolderName;
}
double BankAccount::GetBal() const {
    return balance;
}
void BankAccount::deposit(double amount) {
    balance += amount;
}
void BankAccount::withdraw(double amount) {
    balance -= amount;
}
BankAccount::BankAccount (const BankAccount& other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    balance = other.balance;
}
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;
    }
    return *this;
}
BankAccount::~BankAccount() {
}
BankAccount& BankAccount::operator+=(double amount) {
    while (amount < 0) {
        cout << "Invalid amount, must be > 0, try again." << endl;
        cout << "Enter amount: " << endl;
        cin >> amount;
        cin.clear();
        cin.ignore();
    }
    if (amount > 0) {
        this->balance += amount;
        cout << "$" << amount << " deposited successfully" << endl;
    }
    return *this;
}
BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0) {
        if (this->balance >= amount) {
            this->balance -= amount;
            cout << "$" << amount << " withdrawn successfully" << endl;
        }
        else {
            cout << "Insufficient balance, must be > amount" << endl;
        }
    }
    else {
        cout << "Invalid amount, must be > 0" << endl;
    }
    return *this;
}
bool BankAccount::operator==(const BankAccount& other) const {
    if (this->GetNumber() == other.GetNumber()) {
        return true;
    }
    else {
        return false;
    }
}
bool BankAccount::operator<(const BankAccount& other) const {
    if (this->GetBal() < other.GetBal()) {
        return true;
    }
    else {
        return false;
    }
}
bool BankAccount::operator>(const BankAccount& other) const {
    if (this->GetBal() > other.GetBal()) {
        return true;
    }
    else {
        return false;
    }
}
void BankAccount::printAccount(const BankAccount& account) {
    cout << "Account Info: " << endl;
    cout << "Account Number: " << account.GetNumber() << endl;
    cout << "Account Holder's Name: " << account.GetName() << endl;
    cout << "Account Balance: $" << account.GetBal() << endl;
}
BankAccount BankAccount::createAccountFromInput() {
    string number;
    string name;
    double bal;
    cout << "Enter account number: " << endl;
    cin >> number;
    cin.clear();
    cin.ignore();
    cout << "Enter account holder name: " << endl;
    getline(cin, name);
    cin.clear();
    cout << "Enter initial balance: " << endl;
    cin >> bal;
    cin.clear();
    while (bal < 0) {
        cout << "Invalid amount, must be >= 0, try again." << endl;
        cout << "Enter initial balance: " << endl;
        cin >> bal;
        cin.clear();
        cin.ignore();
    }
    BankAccount tempAccount(number, name, bal);
    return tempAccount;
}

int main() {
    vector<BankAccount> accounts;
    int choice;
    do {
        cout << "Select an option: " << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. View Account Info" << endl;
        cout << "5. Quit" << endl;

        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input, try again" << endl;
        }
        switch (choice) {
            case 1: {
                BankAccount tempAccount = BankAccount::createAccountFromInput();
                accounts.push_back(tempAccount);
                break;
            }
            case 2: {
                string number;
                int tempIndex = -1;
                double amount;
                while (tempIndex == -1) {
                    cout << "Enter account number: " << endl;
                    cin >> number;
                    cin.clear();
                    cin.ignore();
                        for (int i = 0; i < accounts.size(); i++) {
                            if (number == accounts.at(i).GetNumber()) {
                                tempIndex = i;
                                break;
                            }
                        }
                        if (tempIndex == -1) {
                            cout << "Invalid account number, try again" << endl;
                        }
                    }
                cout << "Enter amount you wish to deposit: " << endl;
                cin >> amount;
                cin.clear();
                cin.ignore();
                accounts.at(tempIndex)+=amount;
                break;
            }
            case 3: {
                string number;
                int tempIndex = -1;
                double amount;
                while (tempIndex == -1) {
                    cout << "Enter account number: " << endl;
                    cin >> number;
                    cin.clear();
                    cin.ignore();
                    for (int i = 0; i < accounts.size(); i++) {
                        if (number == accounts.at(i).GetNumber()) {
                            tempIndex = i;
                            break;
                        }
                    }
                    if (tempIndex == -1) {
                        cout << "Invalid account number, try again" << endl;
                    }
                }
                cout << "Enter amount you wish to withdraw: " << endl;
                cin >> amount;
                cin.clear();
                cin.ignore();
                accounts.at(tempIndex)-=amount;
                break;
            }
            case 4: {
                string number;
                int tempIndex = -1;
                while (tempIndex == -1) {
                    cout << "Enter account number: " << endl;
                    cin >> number;
                    cin.clear();
                    cin.ignore();
                    for (int i = 0; i < accounts.size(); i++) {
                        if (number == accounts.at(i).GetNumber()) {
                            tempIndex = i;
                            break;
                        }
                    }
                    if (tempIndex == -1) {
                        cout << "Invalid account number, try again" << endl;
                    }
                }
                BankAccount::printAccount(accounts.at(tempIndex));
                break;
            }
            case 5: {
                cout << "5. Quit:" << endl << "Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid input, try again" << endl;
            }
        }
    } while (choice != 5);
    return 0;
}