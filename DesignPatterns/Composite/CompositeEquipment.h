#pragma once

#include "Equipment.h"
#include <deque>

namespace Composite
{
    class CompositeEquipment : public Equipment
    {
    public:
        using Equipment::Equipment;

        void Add(std::shared_ptr<Equipment>) override;
        void Remove(std::shared_ptr<Equipment>) override;

        double GetPrice() const override;

    private:
        std::deque<std::shared_ptr<Equipment>> equipments_;
    };
}