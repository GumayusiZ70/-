#include "../inc/Transaction.h"

Transaction::Transaction(Type type, double amount, double balance)
    : type(type), amount(amount), balance(balance) {}

void Transaction::printTransaction() {
    std::string typeStr = (type == Type::Deposit) ? "Deposit" :
                          (type == Type::Withdrawal) ? "Withdrawal" : "Transfer";
    std::cout << "交易记录: " << typeStr << ", 交易金额: " << amount << ", 交易后账户金额: " << balance << std::endl;
}