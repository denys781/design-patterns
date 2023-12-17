#include "Person.h"
#include <algorithm>

namespace Observer
{
    Person::Person(
        const std::string& firstName,
        const std::string& lastName
    )
        : firstName_(firstName)
        , lastName_(lastName)
    {
    }

    std::string Person::GetFirstName()
    {
        return firstName_;
    }

    void Person::SetFirstName(const std::string& firstName)
    {
        firstName_ = firstName;
        Notify("first name", firstName_);
    }

    std::string Person::GetLastName()
    {
        return lastName_;
    }

    void Person::SetLastName(const std::string& lastName)
    {
        lastName_ = lastName;
        Notify("last name", lastName_);
    }

    void Person::Subscribe(std::shared_ptr<PersonObserver> observer)
    {
        const auto it = std::find(observers_.begin(), observers_.end(), observer);

        if (it == observers_.end())
        {
            observers_.push_back(observer);
        }
    }

    void Person::Unsunscribe(std::shared_ptr<PersonObserver> observer)
    {
        observers_.remove(observer);
    }

    void Person::Notify(
        const std::string& propertyName,
        const std::string& propertyVal
    )
    {
        for (auto& observer : observers_)
        {
            observer->PersonUpdated(shared_from_this(), propertyName, propertyVal);
        }
    }
}