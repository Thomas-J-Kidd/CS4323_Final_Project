/*
Author: Ben Sailor
Name: Account
Date written: 04/14/2024
Updated:
    - By: Ben Sailor on 04/14/2024
*/

#include "Account.h"
#include "File.h"

#include <iostream>
#include <mutex>
#include <string>

Account::Account() {}                       // Default constructor

Account::Account(std::string account_id) {  // Constructor to initialize the account
    this-> file = File(account_id);         // Initialize the file with the account id
    if (exists(account_id)) return;         // Return if the account exists
    this->file.create();                    // Create the file
    if (this->file.write(0.00)) return;     // Write the initial balance to the file and return if successful
    std::cout << "Error Creating File for "  << account_id << std::endl;    // Print an error message if not
}

bool Account::deposit(std::string amount) { // Function to deposit money
    double amm = std::stod(amount);     // Convert the amount to double 
    double balance = this->getBalance();          // Get the current balance
    if (!(this->file.write(balance + amm))) return false;    // Write the new balance
    return true;                            // Return true if the balance is updated
}

bool Account::withdraw(double amount) {     // Function to withdraw money
    double balance = this->getBalance();    // Get the current balance
    if (balance < amount) return false;     // Return false if the balance is less than the amount
    if (this->file.write(balance - amount)) return true;    // Write the new balance and return True if successful
    return false;                           // Return false if the balance is not updated
}

double Account::getBalance() {              // Function to get the balance
    return this->file.read();               // Read the balance from the file
}

void Account::close() {                     // Function to Close the account
    this->file.deleteFile();                // Delete the file
}