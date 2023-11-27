#pragma once

#include <cstdint>
#include <string>

namespace Bridge
{
    class TimeImp
    {
    public:
        TimeImp(std::uint16_t, std::uint16_t, std::uint16_t);

        virtual std::string GetFormattedTime() const = 0;

    protected:
        std::uint16_t hours_;
        std::uint16_t minutes_;
        std::uint16_t seconds_;
    };
}