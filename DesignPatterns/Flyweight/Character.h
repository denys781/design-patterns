#pragma once

#include <string>
#include <cstdint>

namespace Flyweight
{
    class Character
    {
    public:
        explicit Character(char character);

        void Display(
            const std::string& font,
            std::uint16_t size,
            std::uint16_t line,
            std::uint16_t column
        ) const;

    private:
        char character_;
    };
}