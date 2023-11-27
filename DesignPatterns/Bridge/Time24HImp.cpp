#include "Time24HImp.h"
#include <sstream>

namespace Bridge
{
    Time24HImp::Time24HImp(std::uint16_t hours, std::uint16_t minutes, std::uint16_t seconds)
        : TimeImp(
              hours >= 0 && hours < 24 ? hours : throw std::runtime_error("Invalied hour value"),
              minutes,
              seconds
          )
    {
    }

    std::string Time24HImp::GetFormattedTime() const
    {
        std::ostringstream os;

        os << hours_ << ':' << minutes_ << ':' << seconds_;
        return os.str();
    }
}