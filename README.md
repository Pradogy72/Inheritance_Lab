# Bank Account Class

A C++ class for simulating basic banking operations for multiple Bank Accounts

## Data Dictionary

| Attribute           | Data Type     | Description               |
|---------------------|---------------|---------------------------|
| 'accountNumber'     | 'std::string' | The account's Number      |
| 'accountHolderName' | 'std::string' | The account Holder's Name |
| 'balance'           | 'std::double' | The account's balance     |

## Methods List

| Method Signature                 | Return Type   | Description                  |
|----------------------------------|---------------|------------------------------|
| 'BankAccount()'                  | (Constructor) | Default constructor.         |
| 'BankAccount(number, name, bal)' | (Constructor) | Parameterized constructor.   |
| 'SetName(name)'                  | 'void'        | Sets account holder's name   |
| 'GetNumber() const'              | 'std::string' | Gets account's number.       |
| 'GetName() const'                | 'std::string' | gets account holder's name   |
| 'GetBal() const'                 | 'double'      | gets account's balance       |
| 'deposit(amount)'                | 'void'        | deposits money to account    |
| 'withdraw(amount)'               | 'void         | withdraws money from account |
