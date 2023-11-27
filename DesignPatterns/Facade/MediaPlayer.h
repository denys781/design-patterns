#pragma once

#include "AudioPlayer.h"
#include "VideoPlayer.h"
#include <memory>
#include <string>

namespace Facade // open subsystem interface
{
    class MediaPlayer
    {
    public:
        MediaPlayer();

        void PlayAudio(const std::string&);
        void PlayVideo(const std::string&);

    private:
        std::unique_ptr<Players::AudioPlayer> audioPlayer_;
        std::unique_ptr<Players::VideoPlayer> videoPlayer_;
    };
}