#pragma once

#include "IDatabaseEngine.h"

namespace FactoryMethod
{
    class PostgreSQLDatabaseEngine final : public IDatabaseEngine
    {
    public:
        bool Connect() override;
        Table ExecuteQuery(const std::string& query) override;
    };
}