#pragma once

#include "BaseCommand.h"
#include "BankAccount.h"

namespace Command
{
    class TakeCashCommand : public BaseCommand
    {
    public:
        TakeCashCommand(std::shared_ptr<BankAccount> bankAccount);

        bool Execute(std::size_t cash) override;
    };
}