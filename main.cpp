#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <filesystem>
#include <string>
#include "inc/Account.h"
#include "inc/SavingAccount.h"
#include "inc/CreditAccount.h"

// 从文件中读取账户信息
std::vector<std::shared_ptr<Account>> readAccountsFromFile(const std::string& filename) {
    std::vector<std::shared_ptr<Account>> accounts;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return accounts;
    }

    std::string type, holder;
    double balance, extraParam;

    while (file >> type >> holder >> balance) {
        if (type == "Account") {
            accounts.push_back(std::make_shared<Account>(holder, balance));
        } else if (type == "SavingAccount") {
            if (file >> extraParam) {
                accounts.push_back(std::make_shared<SavingAccount>(holder, balance, extraParam));
            } else {
                std::cerr << "SavingAccount 缺少利率参数: " << holder << std::endl;
            }
        } else if (type == "CreditAccount") {
            if (file >> extraParam) {
                accounts.push_back(std::make_shared<CreditAccount>(holder, balance, extraParam));
            } else {
                std::cerr << "CreditAccount 缺少信用额度参数: " << holder << std::endl;
            }
        } else {
            std::cerr << "未知账户类型: " << type << std::endl;
        }
    }

    file.close();
    return accounts;
}

// 显示账户信息
void showAccounts(const std::vector<std::shared_ptr<Account>>& accounts) {
    for (const auto& account : accounts) {
        account->showbalance();
    }
}

// 获取账户
std::shared_ptr<Account> getAccountByHolder(std::vector<std::shared_ptr<Account>>& accounts, const std::string& holder) {
    for (auto& account : accounts) {
        if (account->getHolder() == holder) {
            return account;
        }
    }
    std::cerr << "找不到账户: " << holder << std::endl;
    return nullptr;
}

int main() {
    std::vector<std::shared_ptr<Account>> accounts = readAccountsFromFile("input.txt");

    int choice = 0;
    std::string holder;
    double amount;
    std::string toHolder;

    while (true) {
        std::cout << "\n菜单选项：\n";
        std::cout << "1. 显示所有账户余额\n";
        std::cout << "2. 存款\n";
        std::cout << "3. 取款\n";
        std::cout << "4. 转账\n";
        std::cout << "5. 退出\n";
        std::cout << "请选择操作：";
        std::cin >> choice;

        switch (choice) {
            case 1:
                showAccounts(accounts);
                break;
            case 2:
                std::cout << "请输入账户持有人姓名：";
                std::cin >> holder;
                std::cout << "请输入存款金额：";
                std::cin >> amount;
                {
                    auto account = getAccountByHolder(accounts, holder);
                    if (account) {
                        account->deposit(amount);
                    }
                }
                break;
            case 3:
                std::cout << "请输入账户持有人姓名：";
                std::cin >> holder;
                std::cout << "请输入取款金额：";
                std::cin >> amount;
                {
                    auto account = getAccountByHolder(accounts, holder);
                    if (account) {
                        account->withdraw(amount);
                    }
                }
                break;
            case 4:
                std::cout << "请输入转出账户持有人姓名：";
                std::cin >> holder;
                std::cout << "请输入转入账户持有人姓名：";
                std::cin >> toHolder;
                std::cout << "请输入转账金额：";
                std::cin >> amount;
                {
                    auto fromAccount = getAccountByHolder(accounts, holder);
                    auto toAccount = getAccountByHolder(accounts, toHolder);
                    if (fromAccount && toAccount) {
                        fromAccount->transfer(*toAccount, amount);
                    }
                }
                break;
            case 5:
                std::cout << "程序退出。\n";
                return 0;
            default:
                std::cout << "无效的选择，请重新输入。\n";
        }
    }

    return 0;
}
