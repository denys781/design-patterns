#include "WarriorsPrototypeRegistry.h"

namespace Prototype
{
    WarriorsPrototypeRegistry::WarriorsPrototypeRegistry()
    {
        prototypes_[PrototypeType::Archer] = std::make_unique<Archer>();
        prototypes_[PrototypeType::Swordsman] = std::make_unique<Swordsman>();
    }

    std::unique_ptr<IWarrior> WarriorsPrototypeRegistry::GetArcherWarrior()
    {
        return prototypes_[PrototypeType::Archer]->Clone();
    }

    std::unique_ptr<IWarrior> WarriorsPrototypeRegistry::GetSwordsmanWarrior()
    {
        return prototypes_[PrototypeType::Swordsman]->Clone();
    }

    WarriorsPrototypeRegistry& WarriorsPrototypeRegistry::GetInstance()
    {
        static WarriorsPrototypeRegistry registry;
        return registry;
    }
}