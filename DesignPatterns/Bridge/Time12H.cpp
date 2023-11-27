#include "Time12H.h"
#include "Time12HImp.h"

namespace Bridge
{
    Time12H::Time12H(std::uint16_t hours, std::uint16_t minutes, std::uint16_t seconds, Meridiem meridiem)
        : Time(std::make_unique<Time12HImp>(hours, minutes, seconds, meridiem))
    {
    }
}