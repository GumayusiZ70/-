#include "../inc/CreditAccount.h"
#include <iostream>

CreditAccount::CreditAccount(std::string holder, double balance, double creditLimit)
    : Account(holder, balance), creditLimit(creditLimit) {}

bool CreditAccount::withdraw(double amount) {
    if (balance + creditLimit >= amount) {
        balance -= amount;
        transactions.push_back(Transaction(Transaction::Type::Withdrawal, amount, balance));
        return true;
    } else {
        std::cout << "取款失败 (超过信用额度!)" << std::endl;
        return false;
    }
}