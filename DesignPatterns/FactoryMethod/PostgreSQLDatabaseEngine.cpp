#include "PostgreSQLDatabaseEngine.h"

namespace FactoryMethod
{
    bool PostgreSQLDatabaseEngine::Connect()
    {
        // Connecting to db
        return true;
    }

    Table PostgreSQLDatabaseEngine::ExecuteQuery(const std::string& query)
    {
        // Query executing
        return Table();
    }
}