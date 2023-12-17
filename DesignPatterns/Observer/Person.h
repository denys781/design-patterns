#pragma once

#include "PersonObserver.h"
#include <memory>
#include <string>
#include <cstdint>
#include <list>

namespace Observer
{
    class Person : public std::enable_shared_from_this<Person>
    {
    public:
        Person(
            const std::string& firstName,
            const std::string& lastName
        );

        std::string GetFirstName();
        void SetFirstName(const std::string& firstName);

        std::string GetLastName();
        void SetLastName(const std::string& lastName);

        void Subscribe(std::shared_ptr<PersonObserver> observer);
        void Unsunscribe(std::shared_ptr<PersonObserver> observer);

    private:
        void Notify(
            const std::string& propertyName,
            const std::string& propertyVal
        );

    private:
        std::string firstName_;
        std::string lastName_;

        std::list<std::shared_ptr<PersonObserver>> observers_;
    };
}