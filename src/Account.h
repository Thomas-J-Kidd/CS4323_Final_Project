/*
Author: Ben Sailor
Name: Account
Date written: 04/14/2024
Updated:
    - By: Ben Sailor on 04/14/2024
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <mutex>
#include <string>

#include "File.h"

class Account {
private: 
    File file;
    std::mutex mtx;

public:
    Account();
    Account(std::string accountNumber);
    bool deposit(std::string amount);
    bool withdraw(double amount);
    double getBalance();
    void close();
};

#endif