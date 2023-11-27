#pragma once

#include <string>

namespace Facade
{
    namespace Players // hidden subsystem interface
    {
        class VideoPlayer
        {
        public:
            void Load(const std::string&);
            void PlayVideo();
        };
    }
}