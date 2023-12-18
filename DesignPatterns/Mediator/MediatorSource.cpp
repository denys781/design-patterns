#include <memory>
#include <list>
#include <string>
#include <algorithm>

namespace Mediator
{
    class BaseUser;

    class IMediator
    {
    public:
        virtual ~IMediator() = default;

        virtual void AddUser(std::shared_ptr<BaseUser> user) = 0;
        virtual void RemoveUser(std::shared_ptr<BaseUser> user) = 0;
        virtual void SendMessage(
            std::shared_ptr<BaseUser> sender,
            const std::string& message
        ) = 0;
    };

    class BaseUser : public std::enable_shared_from_this<BaseUser>
    {
    public:
        virtual ~BaseUser() = default;

        virtual void SendMessage(const std::string& message) = 0;
        virtual void ReceiveMessage(const std::string& message) = 0;

    protected:
        BaseUser(
            std::shared_ptr<IMediator> mediator,
            const std::string& userName
        )
            : mediator_(mediator)
            , userName_(userName)
        {
        }

    protected:
        std::shared_ptr<IMediator> mediator_;
        std::string userName_;
    };

    class ChatUser : public BaseUser
    {
    public:
        ChatUser(
            std::shared_ptr<IMediator> mediator,
            const std::string& userName
        )
            : BaseUser(mediator, userName)
        {
        }

        void SendMessage(const std::string& message) override
        {
            mediator_->SendMessage(shared_from_this(), message);
        }

        void ReceiveMessage(const std::string& message) override
        {
            // TODO: any incoming message processing
        }
    };

    class ChatMediator : public IMediator
    {
    public:
        void AddUser(std::shared_ptr<BaseUser> user) override
        {
            const auto it = std::find(chatUsers_.begin(), chatUsers_.end(), user);
            if (it == chatUsers_.end())
            {
                chatUsers_.push_back(user);
            }
        }

        void RemoveUser(std::shared_ptr<BaseUser> user) override
        {
            chatUsers_.remove(user);
        }

        void SendMessage(
            std::shared_ptr<BaseUser> sender,
            const std::string& message
        ) override
        {
            for (auto& currUser : chatUsers_)
            {
                if (currUser != sender)
                {
                    currUser->ReceiveMessage(message);
                }
            }
        }

    private:
        std::list<std::shared_ptr<BaseUser>> chatUsers_;
    };
}