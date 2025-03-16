#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction {
public:
    enum class Type { Deposit, Withdrawal, Transfer }; // 存款、取款、转账
    Transaction(Type type, double amount, double balance);

    void printTransaction();

private:
    Type type;      // 交易类型
    double amount;  // 交易金额
    double balance; // 交易后账户余额
};

#endif // TRANSACTION_H