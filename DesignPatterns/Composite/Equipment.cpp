#include "Equipment.h"
#include <stdexcept>

namespace Composite
{
    Equipment::Equipment(const std::string& name, double price)
        : name_(name)
        , price_(price)
    {
    }

    void Equipment::Add(std::shared_ptr<Equipment>)
    {
        throw std::runtime_error("Regular equipment cannot add others to itself.");
    }

    void Equipment::Remove(std::shared_ptr<Equipment>)
    {
        throw std::runtime_error("Regular equipment cannot remove others from itself.");
    }

    double Equipment::GetPrice() const
    {
        return price_;
    }

    std::string Equipment::GetName() const
    {
        return name_;
    }
}