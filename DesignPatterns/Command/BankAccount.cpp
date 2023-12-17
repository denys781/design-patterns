#include "BankAccount.h"

namespace Command
{
    BankAccount::BankAccount(std::size_t cash)
        : cash_(cash)
    {
    }

    bool BankAccount::Put(std::size_t cash)
    {
        cash_ += cash;
        return true;
    }

    bool BankAccount::Take(std::size_t cash)
    {
        if (!(cash_ >= cash))
            return false;
        cash_ -= cash;
        return true;
    }
}