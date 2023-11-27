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
    public:
        WarriorsPrototypeRegistry(const WarriorsPrototypeRegistry&) = delete;
        WarriorsPrototypeRegistry(WarriorsPrototypeRegistry&&) = delete;

        WarriorsPrototypeRegistry& operator=(const WarriorsPrototypeRegistry&) = delete;
        WarriorsPrototypeRegistry& operator=(WarriorsPrototypeRegistry&&) = delete;

    public:
        std::unique_ptr<IWarrior> GetArcherWarrior();
        std::unique_ptr<IWarrior> GetSwordsmanWarrior();

        static WarriorsPrototypeRegistry& GetInstance();

    private:
        WarriorsPrototypeRegistry();

    private:
        std::map<PrototypeType, std::unique_ptr<IWarriorPrototype>> prototypes_;
    };
}