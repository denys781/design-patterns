#pragma once

#include "Time.h"
#include "Meridiem.h"
#include <cstdint>

namespace Bridge
{
    class Time12H : public Time
    {
    public:
        Time12H(std::uint16_t, std::uint16_t, std::uint16_t, Meridiem);
    };
}