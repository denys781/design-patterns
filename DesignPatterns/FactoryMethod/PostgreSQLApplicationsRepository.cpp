#include "PostgreSQLApplicationsRepository.h"
#include "PostgreSQLDatabaseEngine.h"

namespace FactoryMethod
{
    std::unique_ptr<IDatabaseEngine> PostgreSQLApplicationsRepository::GetDatabaseEngine()
    {
        return std::make_unique<PostgreSQLDatabaseEngine>();
    }
}