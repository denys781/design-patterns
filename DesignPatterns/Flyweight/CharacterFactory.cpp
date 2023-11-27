#include "CharacterFactory.h"

namespace Flyweight
{
    CharacterFactory::CharacterFactory()
    {
    }

    std::shared_ptr<Character> CharacterFactory::GetCharacter(char character)
    {
        const auto characterIt = characters_.find(character);

        if (characterIt == characters_.end())
        {
            const auto characterPtr = std::make_shared<Character>(character);

            characters_.emplace(std::make_pair(character, characterPtr));
            return characterPtr;
        }
        return characterIt->second;
    }

    CharacterFactory& CharacterFactory::GetInstance()
    {
        static CharacterFactory factory;
        return factory;
    }
}