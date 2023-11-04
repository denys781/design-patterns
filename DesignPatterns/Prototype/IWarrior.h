#pragma once

#include <memory>

namespace Prototype
{
    class IWarrior
    {
    public:
        virtual ~IWarrior() = default;

        virtual std::unique_ptr<IWarrior> Clone() = 0;
        virtual std::size_t MakeDamage() = 0;
    };
}