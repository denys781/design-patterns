#include <iostream>
#include "Singleton/Logger.h"

void ShowSingletonPattern()
{
    using namespace Logging;

    auto& logger = Logger::GetInstance();
    logger.SetStream(&std::cout);

    logger.Log(LogLevel::Info, "Simple info log");
    logger.Log(LogLevel::Warn, "Wary warn log");
    logger.Log(LogLevel::Error, "Crazy error log");
}

int main(int, char**)
{
    ShowSingletonPattern();

    return std::cin.get();
}