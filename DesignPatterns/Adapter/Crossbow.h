#pragma once

#include <cstddef>

namespace Adapter
{
    // old weapon class from legacy code
    class Crossbow
    {
    public:
        std::size_t Shoot() const;
        const char* GetID() const;

    private:
        const static std::size_t DAMAGE = 15;
    };
}