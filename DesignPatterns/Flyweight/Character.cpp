#include "Character.h"

namespace Flyweight
{
    Character::Character(char character)
        : character_(character)
    {
    }

    void Character::Display(
        const std::string& font,
        std::uint16_t size,
        std::uint16_t line,
        std::uint16_t column
    ) const
    {
        // TODO: implement real character displaying
    }
}