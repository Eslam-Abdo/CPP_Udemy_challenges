#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name , double balance)
: Account{name,balance}
{

}
bool Checking_Account::withdraw(double amount)
{
    amount += def_fee;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account)
{
    os << "[Chacking_Account: " << account.name << ": " << account.balance << "]";
    return os;
}