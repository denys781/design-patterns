#include "Archer.h"

namespace Prototype
{
    std::unique_ptr<IWarrior> Archer::Clone()
    {
        return std::make_unique<Archer>(*this);
    }

    std::size_t Archer::MakeDamage()
    {
        return DAMAGE;
    }
}