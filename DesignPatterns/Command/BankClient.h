#pragma once

#include "BaseCommand.h"

namespace Command
{
    using CommandPtr = std::unique_ptr<BaseCommand>;

    class BankClient
    {
    public:
        BankClient(CommandPtr putCashCommand, CommandPtr takeCashCommand);

        bool PutCash(std::size_t cash);
        bool TakeCash(std::size_t cash);

    private:
        CommandPtr putCashCommand_;
        CommandPtr takeCashCommand_;
    };
}