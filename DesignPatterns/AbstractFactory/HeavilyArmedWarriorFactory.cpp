#include "HeavilyArmedWarriorFactory.h"
#include "HeavilyArmedArcher.h"
#include "HeavilyArmedSwordsman.h"

namespace AbstractFactory
{
    std::unique_ptr<Prototype::IWarrior> HeavilyArmedWarriorFactory::CreateArcherWarrior()
    {
        return std::make_unique<HeavilyArmedArcher>();
    }

    std::unique_ptr<Prototype::IWarrior> HeavilyArmedWarriorFactory::CreateSwordsmanWarrior()
    {
        return std::make_unique<HeavilyArmedSwordsman>();
    }
}