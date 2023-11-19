#include "CrossbowAdapter.h"

namespace Adapter
{
    std::size_t CrossbowAdapter::MakeDamage() const
    {
        return Shoot();
    }

    std::string CrossbowAdapter::GetName() const
    {
        return GetID();
    }
}