#include <memory>
#include <stack>
#include <string>

namespace Memento
{
    class Document;

    class DocumentMemento
    {
    private:
        friend class Document;

    private:
        DocumentMemento(const std::string& body)
            : body_(body)
        {
        }

    private:
        std::string body_;
    };

    class Document
    {
    public:
        std::string GetBody() const
        {
            return body_;
        }

        void SetBody(const std::string& body)
        {
            body_ = body;
        }

        std::shared_ptr<DocumentMemento> CreateMemento() const
        {
            auto memento = std::shared_ptr<DocumentMemento>(
                new DocumentMemento(body_)
            );
            return memento;
        }

        void Restore(std::shared_ptr<DocumentMemento> memento)
        {
            body_ = memento->body_;
        }

    private:
        std::string body_;
    };

    class DocumentEditor
    {
    public:
        DocumentEditor(std::shared_ptr<Document> document)
            : document_(document)
        {
        }

        void Save()
        {
            history_.push(document_->CreateMemento());
        }

        void Return()
        {
            if (!history_.empty())
            {
                document_->Restore(history_.top());
                history_.pop();
            }
        }

    private:
        std::shared_ptr<Document> document_;
        std::stack<std::shared_ptr<DocumentMemento>> history_;
    };
}