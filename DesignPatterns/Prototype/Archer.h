#pragma once

#include "IWarrior.h"

namespace Prototype
{
    class Archer : public IWarrior
    {
    public:
        std::unique_ptr<IWarrior> Clone() override;
        std::size_t MakeDamage() override;

    private:
        constexpr static std::size_t DAMAGE = 50;
    };
}