#include "TimeImp.h"
#include "stdexcept"

namespace Bridge
{
    TimeImp::TimeImp(std::uint16_t hours, std::uint16_t minutes, std::uint16_t seconds)
        : hours_(hours)
        , minutes_(minutes >= 0 && minutes < 60 ? minutes : throw std::runtime_error("Invalied minute value"))
        , seconds_(seconds >= 0 && seconds < 60 ? seconds : throw std::runtime_error("Invalied second value"))
    {
    }
}