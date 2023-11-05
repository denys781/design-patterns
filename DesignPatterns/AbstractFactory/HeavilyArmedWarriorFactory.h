#pragma once

#include "IWarriorFactory.h"

namespace AbstractFactory
{
    class HeavilyArmedWarriorFactory : public IWarriorFactory
    {
    public:
        std::unique_ptr<Prototype::IWarrior> CreateArcherWarrior() override;
        std::unique_ptr<Prototype::IWarrior> CreateSwordsmanWarrior() override;
    };
}