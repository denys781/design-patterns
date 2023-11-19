#include "Crossbow.h"

namespace Adapter
{
    std::size_t Crossbow::Shoot() const
    {
        return DAMAGE;
    }

    const char* Crossbow::GetID() const
    {
        return "Crossbow";
    }
}