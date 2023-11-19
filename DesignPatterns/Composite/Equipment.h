#pragma once

#include <memory>
#include <string>

namespace Composite
{
    class Equipment
    {
    public:
        virtual ~Equipment() = default;
        Equipment(const std::string& name, double price);

        virtual void Add(std::shared_ptr<Equipment>);
        virtual void Remove(std::shared_ptr<Equipment>);

        virtual double GetPrice() const;

        std::string GetName() const;

    private:
        std::string name_;
        double price_;
    };
}