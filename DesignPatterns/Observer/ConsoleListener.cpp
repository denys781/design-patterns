#include "ConsoleListener.h"
#include <iostream>

namespace Observer
{
    void ConsoleListener::PersonUpdated(
        std::shared_ptr<Person> person,
        const std::string& propertyName,
        const std::string& propertyVal
    )
    {
        std::cout << "Person changed " << propertyName << " on " << propertyVal << ".\n";
    }
}