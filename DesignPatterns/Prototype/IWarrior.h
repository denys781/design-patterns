#pragma once

#include <cstddef>

namespace Prototype
{
    class IWarrior
    {
    public:
        virtual ~IWarrior() = default;

        virtual std::size_t MakeDamage() = 0;
    };
}