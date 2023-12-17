#include <list>
#include <stdexcept>
#include <cstddef>

namespace Iterator
{
    template <class ContElementType>
    class Iterator
    {
    public:
        virtual ~Iterator() = default;

        virtual bool IsDone() = 0;
        virtual void First() = 0;
        virtual void Next() = 0;
        virtual ContElementType& GetElement() = 0;
    };

    template <class ContElementType> class ListForwardIterator;

    template <class ElementType>
    class ListContainer
    {
    private:
        friend class ListForwardIterator<ElementType>;

    public:
        ListContainer() = default;

        std::size_t Size()
        {
            return list_.size();
        }

        ElementType& Get(std::size_t index)
        {
            if (index >= Size())
            {
                throw std::out_of_range("Invalid index value.");
            }

            auto currIt = list_.begin();
            for (std::size_t i{}; i < index; ++i, ++currIt)
            {
            }
            return *currIt;
        }

        void PushFront(const ElementType& element)
        {
            list_.push_front(element);
        }
        void PushBack(const ElementType& element)
        {
            list_.push_back(element);
        }

        template <class UnaryPred>
        void RemoveIf(UnaryPred unaryPred)
        {
            list_.remove_if(unaryPred);
        }
        void Remove(const ElementType& element)
        {
            list_.remove(element);
        }

        Iterator<ElementType> CreateIterator() // factory method
        {
            return ListForwardIterator<ElementType>(*this);
        }

    private:
        std::list<ElementType> list_;
    };

    template <class ContElementType>
    class ListForwardIterator : public Iterator<ContElementType>
    {
    public:
        ListForwardIterator(const ListContainer<ContElementType>& listContainer)
            : listContainer_(listContainer)
            , currIt_(listContainer_.list_.begin())
        {
        }

        bool IsDone() override
        {
            return currIt_ == listContainer_.list_.end();
        }

        void First() override
        {
            currIt_ = listContainer_.list_.begin();
        }

        void Next() override
        {
            if (IsDone())
            {
                return;
            }
            ++currIt_;
        }

        ContElementType& GetElement() override
        {
            return *currIt_;
        }

    private:
        ListContainer<ContElementType> listContainer_;
        typename decltype(ListContainer<ContElementType>::list_)::iterator currIt_;
    };
}