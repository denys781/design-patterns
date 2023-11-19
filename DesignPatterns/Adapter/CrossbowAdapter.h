#include "IWeapon.h"
#include "Crossbow.h"

namespace Adapter
{
    // class adapter
    class CrossbowAdapter : public IWeapon, Crossbow
    {
    public:
        std::size_t MakeDamage() const override;
        std::string GetName() const override;
    };
}