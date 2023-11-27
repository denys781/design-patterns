#pragma once

#include "TimeImp.h"

namespace Bridge
{
    class Time24HImp : public TimeImp
    {
    public:
        Time24HImp(std::uint16_t, std::uint16_t, std::uint16_t);

        std::string GetFormattedTime() const override;
    };
}