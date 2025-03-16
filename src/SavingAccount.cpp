#include "../inc/SavingAccount.h"
#include <iostream>

SavingAccount::SavingAccount(std::string holder, double balance, double interestRate)
    : Account(holder, balance), interestRate(interestRate) {}

void SavingAccount::calculateInterest() {
    double interest = balance * interestRate;
    balance += interest;
    transactions.push_back(Transaction(Transaction::Type::Deposit, interest, balance));
    std::cout << "利息: " << interest << ", 新余额: " << balance << std::endl;
}