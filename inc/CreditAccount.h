#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "Account.h"

class CreditAccount : public Account {
public:
    CreditAccount(std::string holder, double balance, double creditLimit);
    bool withdraw(double amount) override;

private:
    double creditLimit; // 信用额度
};

#endif // CREDITACCOUNT_H