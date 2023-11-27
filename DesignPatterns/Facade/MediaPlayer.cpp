#include "MediaPlayer.h"

namespace Facade
{
    MediaPlayer::MediaPlayer()
        : audioPlayer_(std::make_unique<Players::AudioPlayer>())
        , videoPlayer_(std::make_unique<Players::VideoPlayer>())
    {
    }

    void MediaPlayer::PlayAudio(const std::string& audioPath)
    {
        audioPlayer_->Load(audioPath);
        audioPlayer_->PlayAudio();
    }

    void MediaPlayer::PlayVideo(const std::string& videoPath)
    {
        videoPlayer_->Load(videoPath);
        videoPlayer_->PlayVideo();
    }
}