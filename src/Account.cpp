#include "../inc/Account.h"
#include <iostream>

Account::Account(std::string holder, double balance)
    : holder(holder), balance(balance) {}

void Account::deposit(double amount) {
    balance += amount;
    transactions.push_back(Transaction(Transaction::Type::Deposit, amount, balance));
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        transactions.push_back(Transaction(Transaction::Type::Withdrawal, amount, balance));
        return true;
    } else {
        std::cout << "余额不足!" << std::endl;
        return false;
    }
}

void Account::showbalance() const {
    std::cout << "账户持有人的姓名: " << holder << ", 余额: " << balance << std::endl;
}

std::string Account::getHolder() const {
    return holder;
}

bool Account::transfer(Account& toacc, double amount) {
    if (this->withdraw(amount)) {
        toacc.deposit(amount);
        std::cout << "转账给用户: " << toacc.getHolder() << std::endl;
        return true;
    }
    std::cout << "转账失败!" << std::endl;
    return false;
}