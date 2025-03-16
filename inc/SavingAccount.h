#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "Account.h"

class SavingAccount : public Account {
public:
    SavingAccount(std::string holder, double balance, double interestRate);
    void calculateInterest();

private:
    double interestRate; // 储蓄账户的年利率
};

#endif // SAVINGACCOUNT_H