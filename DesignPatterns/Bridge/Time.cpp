#include "Time.h"

namespace Bridge
{
    Time::Time(std::unique_ptr<TimeImp>&& timeImp)
        : timeImp_(std::move(timeImp))
    {
    }

    std::string Time::GetFormattedTime() const
    {
        return timeImp_->GetFormattedTime();
    }
}