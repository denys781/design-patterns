#include "PutCashCommand.h"

namespace Command
{
    PutCashCommand::PutCashCommand(std::shared_ptr<BankAccount> bankAccount)
        : BaseCommand(bankAccount)
    {
    }

    bool PutCashCommand::Execute(std::size_t cash)
    {
        return bankAccount_->Put(cash);
    }
}