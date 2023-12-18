#include <memory>

namespace State
{
    class Player;

    namespace details
    {
        class BasePlayerState
        {
        public:
            virtual ~BasePlayerState() = default;

            virtual void Play()
            {
            }
            virtual void Pause()
            {
            }
            virtual void Stop()
            {
            }

        protected:
            explicit BasePlayerState(Player* player)
                : player_(player)
            {
            }

        protected:
            Player* player_;
        };

        class StoppedPlayerState;
        class PlayingPlayerState;
        class PausedPlayerState;
    }

    class Player
    {
    private:
        friend class details::StoppedPlayerState;
        friend class details::PlayingPlayerState;
        friend class details::PausedPlayerState;

    public:
        Player();

        void Play() 
        {
            currentState_->Play();
        }
        void Pause()
        {
            currentState_->Pause();
        }
        void Stop()
        {
            currentState_->Stop();
        }

    private:
        std::unique_ptr<details::BasePlayerState> currentState_;
    };

    class details::StoppedPlayerState : public details::BasePlayerState
    {
    public:
        StoppedPlayerState(Player* player)
            : BasePlayerState(player)
        {
        }

        void Play() override;
    };

    Player::Player()
        : currentState_(std::make_unique<details::StoppedPlayerState>(this))
    {
    }

    class details::PlayingPlayerState : public details::BasePlayerState
    {
    public:
        PlayingPlayerState(Player* player)
            : BasePlayerState(player)
        {
        }

        void Pause() override;
        void Stop() override
        {
            auto thisState = std::move(player_->currentState_);
            player_->currentState_ = std::make_unique<StoppedPlayerState>(player_);
        }
    };

    void details::StoppedPlayerState::Play()
    {
        auto thisState = std::move(player_->currentState_);
        player_->currentState_ = std::make_unique<PlayingPlayerState>(player_);
    }

    class details::PausedPlayerState : public details::BasePlayerState
    {
    public:
        PausedPlayerState(Player* player)
            : BasePlayerState(player)
        {
        }

        void Play() override
        {
            auto thisState = std::move(player_->currentState_);
            player_->currentState_ = std::make_unique<PlayingPlayerState>(player_);
        }
        void Stop() override
        {
            auto thisState = std::move(player_->currentState_);
            player_->currentState_ = std::make_unique<StoppedPlayerState>(player_);
        }
    };

    void details::PlayingPlayerState::Pause()
    {
        auto thisState = std::move(player_->currentState_);
        player_->currentState_ = std::make_unique<PausedPlayerState>(player_);
    }
}