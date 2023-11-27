#include "Time24H.h"
#include "Time24HImp.h"

namespace Bridge
{
    Time24H::Time24H(std::uint16_t hours, std::uint16_t minutes, std::uint16_t seconds)
        : Time(std::make_unique<Time24HImp>(hours, minutes, seconds))
    {
    }
}