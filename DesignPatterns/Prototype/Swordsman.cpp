#include "Swordsman.h"

namespace Prototype
{
    std::unique_ptr<IWarrior> Swordsman::Clone()
    {
        return std::make_unique<Swordsman>(*this);
    }

    std::size_t Swordsman::MakeDamage()
    {
        return DAMAGE;
    }
}