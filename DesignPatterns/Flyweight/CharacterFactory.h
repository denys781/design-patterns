#pragma once

#include "Character.h"
#include <memory>
#include <unordered_map>

namespace Flyweight
{
    class CharacterFactory
    {
    public:
        CharacterFactory(const CharacterFactory&) = delete;
        CharacterFactory(CharacterFactory&&) = delete;

        CharacterFactory& operator=(const CharacterFactory&) = delete;
        CharacterFactory& operator=(CharacterFactory&&) = delete;

    public:
        std::shared_ptr<Character> GetCharacter(char);
        static CharacterFactory& GetInstance();

    private:
        CharacterFactory();

    private:
        std::unordered_map<char, std::shared_ptr<Character>> characters_;
    };
}