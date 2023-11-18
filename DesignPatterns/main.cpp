#include "Singleton\Logger.h"
#include "Prototype\WarriorsPrototypeRegistry.h"
#include "Builder\HttpRequestPackageBuilder.h"
#include "Builder\HttpResponsePackageBuilder.h"
#include "FactoryMethod\PostgreSQLApplicationsRepository.h"
#include "AbstractFactory\LightlyArmedWarriorFactory.h"
#include "Proxy\ImageProxy.h"
#include <iostream>

void ShowSingletonPattern()
{
    std::cout << "===== Singleton pattern\n";

    using namespace Singleton;

    auto& loggerInst = Logger::GetInstance();
    loggerInst.SetStream(&std::cout);

    loggerInst.Log(LogLevel::Info, "Info log");
    loggerInst.Log(LogLevel::Warn, "Warn log");
    loggerInst.Log(LogLevel::Error, "Error log");

    std::cout << "Singleton pattern =====\n\n";
}

void ShowPrototypePattern()
{
    std::cout << "===== Prototype pattern\n";

    using namespace Prototype;

    auto& prototypeRegistryInst = WarriorsPrototypeRegistry::GetInstance();
    auto archerPtr = prototypeRegistryInst.GetArcherWarrior();
    auto swordsmanPtr = prototypeRegistryInst.GetSwordsmanWarrior();

    std::cout << "Archer's prototype damage is " << archerPtr->MakeDamage() << '\n';
    std::cout << "Swordsman's prototype damage is " << swordsmanPtr->MakeDamage() << '\n';

    std::cout << "Prototype pattern =====\n\n";
}

void ShowBuilderPattern()
{
    std::cout << "===== Builder pattern\n";

    using namespace Builder;

    auto httpRequestBuilderPtr = std::make_shared<HttpRequestPackageBuilder>();
    std::shared_ptr<IHttpPackageBuilder> httpBuilderPtr = httpRequestBuilderPtr;

    (*httpBuilderPtr)
        .SetRequest("POST /archieve/script.bat HTTP/1.1")
        .SetHeaders({"Host: foo.example"})
        .SetBody("script as plain text");
    HttpRequestPackage httpRequestPackage = httpRequestBuilderPtr->GetConstructedHttpRequestPackage();

    std::cout
        << "Request:\t" << httpRequestPackage.request_ << '\n'
        << "Headers:\t" << *httpRequestPackage.headers_.begin() << '\n'
        << "Body:\t\t" << httpRequestPackage.body_ << '\n';

    std::cout << "---------------------\n";

    auto httpResponseBuilderPtr = std::make_shared<HttpResponsePackageBuilder>();
    httpBuilderPtr = httpResponseBuilderPtr;

    (*httpBuilderPtr)
        .SetStatus("HTTP/1.1 200 OK")
        .SetHeaders({"Server: Apache"});
    HttpResponsePackage httpResponsePackage = httpResponseBuilderPtr->GetConstructedHttpResponsePackage();

    std::cout
        << "Status:\t\t" << httpResponsePackage.status_ << '\n'
        << "Headers:\t" << *httpResponsePackage.headers_.begin() << '\n'
        << "Body:\t\t" << httpResponsePackage.body_ << '\n';

    std::cout << "Builder pattern =====\n\n";
}

void ShowFactoryMethodPattern()
{
    std::cout << "===== Factory Method pattern\n";

    using namespace FactoryMethod;

    PostgreSQLApplicationsRepository repository;
    ApplicationsList applicationsList = repository.GetAvailableApplications();

    // any usage of applicationsList

    std::cout << "Factory Method pattern =====\n\n";
}

void ShowAbstractFactoryPattern()
{
    std::cout << "===== Abstract Factory pattern\n";

    using namespace AbstractFactory;

    std::unique_ptr<IWarriorFactory> warriorsFactoryPtr =
        std::make_unique<LightlyArmedWarriorFactory>();
    auto archerPtr = warriorsFactoryPtr->CreateArcherWarrior();
    auto swordsmanPtr = warriorsFactoryPtr->CreateSwordsmanWarrior();

    std::cout << "Archer's damage is " << archerPtr->MakeDamage() << '\n';
    std::cout << "Swordsman's damage is " << swordsmanPtr->MakeDamage() << '\n';

    std::cout << "Abstract Factory pattern =====\n\n";
}

void ShowProxyPattern()
{
    std::cout << "===== Proxy pattern\n";

    using namespace Proxy;

    std::unique_ptr<IImage> imageProxyPtr =
        std::make_unique<ImageProxy>("ascii_image.txt");
    imageProxyPtr->PrintImage(&std::cout);

    std::cout << "\nProxy pattern =====\n\n";
}

int main(int, char**)
{
    ShowSingletonPattern();
    ShowPrototypePattern();
    ShowBuilderPattern();
    ShowFactoryMethodPattern();
    ShowAbstractFactoryPattern();
    ShowProxyPattern();

    return std::cin.get();
}