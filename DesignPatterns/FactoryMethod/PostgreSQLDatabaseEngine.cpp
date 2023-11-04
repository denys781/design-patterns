#include "PostgreSQLDatabaseEngine.h"

namespace FactoryMethod
{
    bool PostgreSQLDatabaseEngine::Connect()
    {
        return true;
    }

    Table PostgreSQLDatabaseEngine::ExecuteQuery(const std::string& query)
    {
        return Table();
    }
}