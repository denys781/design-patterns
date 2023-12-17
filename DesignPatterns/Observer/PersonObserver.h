#pragma once

#include <memory>
#include <string>
#include <any>

namespace Observer
{
    class Person;

    class PersonObserver
    {
    public:
        virtual ~PersonObserver() = default;

        virtual void PersonUpdated(
            std::shared_ptr<Person> person,
            const std::string& propertyName,
            const std::string& propertyVal
        ) = 0;

    protected:
        PersonObserver() = default;
    };
}