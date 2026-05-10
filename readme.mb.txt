# Bank Management System

## Project Overview

The Bank Management System is a console-based application developed in C++ that simulates basic banking operations. The application allows users to create accounts, deposit money, withdraw money, check balances, and display account details.

The project is developed using Object-Oriented Programming (OOP) concepts and file handling techniques to securely manage and store customer records.

---

## Objectives

- To design and implement a banking application using C++
- To understand Object-Oriented Programming concepts
- To perform banking operations such as:
  - Account Creation
  - Deposit
  - Withdrawal
  - Balance Inquiry
  - Display Account Details
- To store and manage customer data using file handling

---

## Features

### Account Creation
Users can create multiple bank accounts with:
- Account Number
- Customer Name
- Initial Balance

### Deposit Money
Users can deposit money into a specific account.

### Withdraw Money
Users can withdraw money from their account with balance validation.

### Balance Check
Users can check the available balance of a selected account.

### Display Account Details
Displays:
- Account Number
- Customer Name
- Current Balance

### File Handling Support
Customer records are stored using file management to maintain persistent data even after the program exits.

---

## Technologies Used

- Programming Language: C++
- Concepts Used:
  - Classes and Objects
  - Encapsulation
  - Vectors
  - Functions
  - File Handling
  - Conditional Statements
  - Loops

---

## System Requirements

- Windows/Linux/MacOS
- C++ Compiler (G++)
- VS Code or any C++ IDE

---

## How to Compile and Run

### Compile

```bash
g++ BankManagementApplication.cpp -o BankManagementApplication
```

### Run

#### Windows

```bash
.\BankManagementApplication
```

#### Linux/Mac

```bash
./BankManagementApplication
```

---

## Sample Menu

```text
=====================================
      BANK MANAGEMENT SYSTEM
=====================================

1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Display Account Details
6. Exit
```

---

## Sample Output

```text
Enter Your Choice: 1

Enter Account Number: 101
Enter Customer Name: Akila
Enter Initial Balance: 5000

Account Created Successfully!
```

---

## Expected Outcome

The application successfully performs banking operations while maintaining customer records securely using file handling. The system demonstrates the practical implementation of Object-Oriented Programming concepts in C++.

---

## Future Enhancements

- Add login authentication
- Add transaction history
- Add interest calculation
- Add admin panel
- Improve data encryption and security
- GUI-based banking system

---

## Author

Akila Ramasamy

---

## License

This project is developed for educational purposes.