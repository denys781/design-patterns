#pragma once

#include "ApplicationsRepository.h"

namespace FactoryMethod
{
    class PostgreSQLApplicationsRepository final : public ApplicationsRepository
    {
    private:
        std::unique_ptr<IDatabaseEngine> GetDatabaseEngine() override;
    };
}