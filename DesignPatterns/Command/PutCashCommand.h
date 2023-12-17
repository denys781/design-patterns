#pragma once

#include "BaseCommand.h"
#include "BankAccount.h"

namespace Command
{
    class PutCashCommand : public BaseCommand
    {
    public:
        PutCashCommand(std::shared_ptr<BankAccount> bankAccount);

        bool Execute(std::size_t cash) override;
    };
}