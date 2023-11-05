#pragma once

#include "../Prototype/IWarrior.h"
#include <memory>

namespace AbstractFactory
{
    class IWarriorFactory
    {
    public:
        virtual ~IWarriorFactory() = default;

        virtual std::unique_ptr<Prototype::IWarrior> CreateArcherWarrior() = 0;
        virtual std::unique_ptr<Prototype::IWarrior> CreateSwordsmanWarrior() = 0;
    };
}