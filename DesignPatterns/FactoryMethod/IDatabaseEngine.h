#pragma once

#include <string>
#include <map>
#include <vector>

namespace FactoryMethod
{
    using Caption = const std::string;
    using Cell = std::string;
    using Row = std::map<Caption, Cell>;
    using Table = std::vector<Row>;

    class IDatabaseEngine
    {
    public:
        virtual ~IDatabaseEngine() = default;

        virtual bool Connect() = 0;
        virtual Table ExecuteQuery(const std::string& query) = 0;
    };
}