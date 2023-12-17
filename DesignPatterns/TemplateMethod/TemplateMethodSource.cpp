#include <cstdint>
#include <iostream>

namespace
{
    const std::uint16_t DEFAULT_CHESS_PLAYERS_COUNT = 2;
    const std::uint16_t CHESS_MAX_TURNS_COUNT = 4;
}

namespace TemplateMethod
{
    class BaseGame
    {
    public:
        void Run()
        {
            Start();

            while (!HaveWinner())
            {
                TakeTurn();
            }
            std::cout << "Player " << GetWinner() << " wins.\n";
        }

    protected:
        explicit BaseGame(std::uint16_t playersCount)
            : playersCount_(playersCount)
            , currPlayer_(0)
        {
        }

    protected:
        virtual void Start() = 0;
        virtual bool HaveWinner() = 0;
        virtual void TakeTurn() = 0;
        virtual std::uint16_t GetWinner() = 0;

    protected:
        std::uint16_t playersCount_;
        std::uint16_t currPlayer_;
    };

    class ChessGame : public BaseGame
    {
    public:
        ChessGame()
            : BaseGame(DEFAULT_CHESS_PLAYERS_COUNT)
            , turnsCount_(0)
        {
        }

    protected:
        void Start() override
        {
            std::cout << "Starting chess game with " << playersCount_ << " players.\n";
        }

        bool HaveWinner() override
        {
            return turnsCount_ == CHESS_MAX_TURNS_COUNT;
        }

        void TakeTurn() override
        {
            std::cout << "Turn " << turnsCount_ << " taken by player " << currPlayer_ << ".\n";
            ++turnsCount_;
            currPlayer_ = (currPlayer_ + 1) % playersCount_;
        }

        std::uint16_t GetWinner() override
        {
            return currPlayer_;
        }

    private:
        std::uint16_t turnsCount_;
    };
}