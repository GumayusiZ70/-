#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include <string>
#include <vector>

class Account {
public:
    Account(std::string holder, double balance);

    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual void showbalance() const;
    virtual ~Account() {}

    std::string getHolder() const;
    bool transfer(Account& toacc, double amount);

protected:
    std::string holder; // 账户持有人的姓名
    double balance;     // 账户的当前余额
    std::vector<Transaction> transactions; // 存储账户的所有交易记录
};

#endif // ACCOUNT_H