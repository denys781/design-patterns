#pragma once

#include <cstddef>
    
namespace Command
{
    class BankAccount
    {
    public:
        BankAccount(std::size_t cash = 0);

        bool Put(std::size_t cash);
        bool Take(std::size_t cash);

    private:
        std::size_t cash_;
    };
}