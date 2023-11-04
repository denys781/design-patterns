#pragma once

#include "Archer.h"
#include "Swordsman.h"
#include <map>
#include <memory>

namespace Prototype
{
    enum class PrototypeType : std::uint8_t
    {
        Archer,
        Swordsman
    };

    class WarriorsPrototypeRegistry final
    {
    private:
        WarriorsPrototypeRegistry(const WarriorsPrototypeRegistry&) = delete;
        WarriorsPrototypeRegistry(WarriorsPrototypeRegistry&&) = delete;

        WarriorsPrototypeRegistry();

    public:
        std::unique_ptr<IWarrior> GetArcherPrototype();
        std::unique_ptr<IWarrior> GetSwordsmanPrototype();

        static WarriorsPrototypeRegistry& GetInstance();

    private:
        std::map<PrototypeType, std::unique_ptr<IWarrior>> prototypes_;
    };
}