#include "Time12HImp.h"
#include <sstream>
#include <cstring>

namespace
{
    const std::string AM = "AM";
    const std::string PM = "PM";
}

namespace Bridge
{
    Time12HImp::Time12HImp(std::uint16_t hours, std::uint16_t minutes, std::uint16_t seconds, Meridiem meridiem)
        : TimeImp(
            hours >= 0 && hours < 12 ? hours : throw std::runtime_error("Invalied hour value"),
            minutes,
            seconds
        )
        , meridiem_(meridiem)
    {
    }

    std::string Time12HImp::GetFormattedTime() const
    {
        const std::string meridiem(meridiem_ == Meridiem::AM ? AM : PM);
        std::ostringstream os;

        os << hours_ << ':' << minutes_ << ':' << seconds_ << ' ' << meridiem;
        return os.str();
    }
}