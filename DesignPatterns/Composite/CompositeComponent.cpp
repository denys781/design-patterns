#include "CompositeEquipment.h"
#include <algorithm>

namespace Composite
{
    void CompositeEquipment::Add(std::shared_ptr<Equipment> equipment)
    {
        if (equipment &&
            std::find(equipments_.begin(), equipments_.end(), equipment) == equipments_.end())
        {
            equipments_.push_back(equipment);
        }
    }

    void CompositeEquipment::Remove(std::shared_ptr<Equipment> equipment)
    {
        if (equipment)
        {
            equipments_.erase(
                std::remove(
                    equipments_.begin(),
                    equipments_.end(),
                    equipment
                ),
                equipments_.end()
            );
        }
    }

    double CompositeEquipment::GetPrice() const
    {
        double total_price = Equipment::GetPrice();

        for (auto equipment_it = equipments_.begin(); equipment_it != equipments_.end(); ++equipment_it)
        {
            total_price += (*equipment_it)->GetPrice();
        }
        return total_price;
    }
}