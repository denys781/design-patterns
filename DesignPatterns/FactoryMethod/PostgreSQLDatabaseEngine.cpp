#include "PostgreSQLDatabaseEngine.h"

namespace FactoryMethod
{
    bool PostgreSQLDatabaseEngine::Connect()
    {
        return true; // TODO: implement real connecting to db
    }

    Table PostgreSQLDatabaseEngine::ExecuteQuery(const std::string& query)
    {
        return Table(); // TODO: implement real query executing
    }
}