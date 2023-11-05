#pragma once

#include "IWarrior.h"
#include "IWarriorPrototype.h"

namespace Prototype
{
    class Swordsman : public IWarrior, public IWarriorPrototype
    {
    public:
        std::unique_ptr<IWarrior> Clone() override;
        std::size_t MakeDamage() override;

    private:
        constexpr static std::size_t DAMAGE = 75;
    };
}