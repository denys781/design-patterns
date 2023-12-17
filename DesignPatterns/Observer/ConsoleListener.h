#pragma once

#include "PersonObserver.h"

namespace Observer
{
    class ConsoleListener : public PersonObserver
    {
    public:
        ConsoleListener() = default;

        void PersonUpdated(
            std::shared_ptr<Person> person,
            const std::string& propertyName,
            const std::string& propertyVal
        ) override;
    };
} 