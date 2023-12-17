#include "TakeCashCommand.h"

namespace Command
{
    TakeCashCommand::TakeCashCommand(std::shared_ptr<BankAccount> bankAccount)
        : BaseCommand(bankAccount)
    {
    }

    bool TakeCashCommand::Execute(std::size_t cash)
    {
        return bankAccount_->Take(cash);
    }
}