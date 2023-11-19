#pragma once

#include <string>

namespace Adapter
{
    // interface for creating modern weapon classes
    class IWeapon
    {
    public:
        virtual ~IWeapon() = default;

        virtual std::size_t MakeDamage() const = 0;
        virtual std::string GetName() const = 0;
    };
}