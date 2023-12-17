#include "BankClient.h"
namespace Command
{
    BankClient::BankClient(CommandPtr putCashCommand, CommandPtr takeCashCommand)
        : putCashCommand_(std::move(putCashCommand))
        , takeCashCommand_(std::move(takeCashCommand))
    {
    }

    bool BankClient::PutCash(std::size_t cash)
    {
        return putCashCommand_->Execute(cash);
    }

    bool BankClient::TakeCash(std::size_t cash)
    {
        return takeCashCommand_->Execute(cash);
    }
}