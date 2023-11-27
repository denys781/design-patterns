#pragma once

#include "TimeImp.h"
#include "Meridiem.h"

namespace Bridge
{
    class Time12HImp : public TimeImp
    {
    public:
        Time12HImp(std::uint16_t, std::uint16_t, std::uint16_t, Meridiem);

        std::string GetFormattedTime() const override;

    private:
        Meridiem meridiem_;
    };
}