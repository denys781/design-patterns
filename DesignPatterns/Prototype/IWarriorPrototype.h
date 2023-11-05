#pragma once

#include "IWarrior.h"
#include <memory>

namespace Prototype
{
    class IWarriorPrototype
    {
    public:
        virtual ~IWarriorPrototype() = default;

        virtual std::unique_ptr<IWarrior> Clone() = 0;
    };
}