#pragma once

#include "Time.h"
#include <cstdint>

namespace Bridge
{
    class Time24H : public Time
    {
    public:
        Time24H(std::uint16_t, std::uint16_t, std::uint16_t);
    };
}