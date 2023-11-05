#pragma once

#include "../Prototype/IWarrior.h"

namespace AbstractFactory
{
    class LightlyArmedSwordsman : public Prototype::IWarrior
    {
    public:
        std::size_t MakeDamage() override;

    private:
        constexpr static std::size_t DAMAGE = 35;
    };
}