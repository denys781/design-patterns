#pragma once

#include "TimeImp.h"
#include <memory>

namespace Bridge
{
    class Time
    {
    public:
        std::string GetFormattedTime() const;

    protected:
        Time(std::unique_ptr<TimeImp>&&);

    private:
        std::unique_ptr<TimeImp> timeImp_;
    };
}