#pragma once

#include "BankAccount.h"
#include <memory>

namespace Command
{
    class BaseCommand
    {
    public:
        virtual bool Execute(std::size_t cash) = 0;

    protected:
        BaseCommand(std::shared_ptr<BankAccount> bankAccount);

    protected:
        std::shared_ptr<BankAccount> bankAccount_;
    };
}