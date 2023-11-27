#pragma once

#include <string>

namespace Facade
{
    namespace Players // hidden subsystem interface
    {
        class AudioPlayer
        {
        public:
            void Load(const std::string&);
            void PlayAudio();
        };
    }
}