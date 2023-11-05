#include "LightlyArmedWarriorFactory.h"
#include "LightlyArmedArcher.h"
#include "LightlyArmedSwordsman.h"

namespace AbstractFactory
{
    std::unique_ptr<Prototype::IWarrior> LightlyArmedWarriorFactory::CreateArcherWarrior()
    {
        return std::make_unique<LightlyArmedArcher>();
    }

    std::unique_ptr<Prototype::IWarrior> LightlyArmedWarriorFactory::CreateSwordsmanWarrior()
    {
        return std::make_unique<LightlyArmedSwordsman>();
    }
}