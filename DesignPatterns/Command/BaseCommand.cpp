#include "BaseCommand.h"
#include <stdexcept>

namespace Command
{
    BaseCommand::BaseCommand(std::shared_ptr<BankAccount> bankAccount)
    {
        if (!bankAccount)
        {
            throw std::runtime_error("No bank account passed.");
        }
        bankAccount_ = bankAccount;
    }
}