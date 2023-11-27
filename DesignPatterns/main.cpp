#include "Singleton\Logger.h"
#include "Prototype\WarriorsPrototypeRegistry.h"
#include "Builder\HttpRequestPackageBuilder.h"
#include "Builder\HttpResponsePackageBuilder.h"
#include "FactoryMethod\PostgreSQLApplicationsRepository.h"
#include "AbstractFactory\LightlyArmedWarriorFactory.h"
#include "Proxy\ImageProxy.h"
#include "Decorator\StreamWriter.h"
#include "Decorator\XorStreamWriterDecorator.h"
#include "Adapter\CrossbowAdapter.h"
#include "Composite\CompositeEquipment.h"
#include "Facade\MediaPlayer.h"
#include <iostream>

void ShowSingletonPattern()
{
    std::cout << "\>\>\> Singleton pattern \<\<\<\n";

    using namespace Singleton;

    auto& loggerInst = Logger::GetInstance();
    loggerInst.SetStream(&std::cout);

    loggerInst.Log(LogLevel::Info, "Info log");
    loggerInst.Log(LogLevel::Warn, "Warn log");
    loggerInst.Log(LogLevel::Error, "Error log");
}

void ShowPrototypePattern()
{
    std::cout << "\n\>\>\> Prototype pattern \<\<\<\n";

    using namespace Prototype;

    auto& prototypeRegistryInst = WarriorsPrototypeRegistry::GetInstance();
    auto archerPtr = prototypeRegistryInst.GetArcherWarrior();
    auto swordsmanPtr = prototypeRegistryInst.GetSwordsmanWarrior();

    std::cout << "Archer's prototype damage is " << archerPtr->MakeDamage() << '\n';
    std::cout << "Swordsman's prototype damage is " << swordsmanPtr->MakeDamage() << '\n';
}

void ShowBuilderPattern()
{
    std::cout << "\n\>\>\> Builder pattern \<\<\<\n";

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
        << "Body:\t\t" << httpRequestPackage.body_ << "\n\n";

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
}

void ShowFactoryMethodPattern()
{
    std::cout << "\n\>\>\> Factory Method pattern \<\<\<\n";

    using namespace FactoryMethod;

    PostgreSQLApplicationsRepository repository;
    ApplicationsList applicationsList = repository.GetAvailableApplications();

    // any usage of applicationsList
    std::cout << "NO CONSOLE OUTPUT FOR PATTERN\n";
}

void ShowAbstractFactoryPattern()
{
    std::cout << "\n\>\>\> Abstract Factory pattern \<\<\<\n";

    using namespace AbstractFactory;

    std::unique_ptr<IWarriorFactory> warriorsFactoryPtr =
        std::make_unique<LightlyArmedWarriorFactory>();
    auto archerPtr = warriorsFactoryPtr->CreateArcherWarrior();
    auto swordsmanPtr = warriorsFactoryPtr->CreateSwordsmanWarrior();

    std::cout << "Archer's damage is " << archerPtr->MakeDamage() << '\n';
    std::cout << "Swordsman's damage is " << swordsmanPtr->MakeDamage() << '\n';
}

void ShowProxyPattern()
{
    std::cout << "\n\>\>\> Proxy pattern \<\<\<\n";

    using namespace Proxy;

    std::unique_ptr<IImage> imageProxyPtr =
        std::make_unique<ImageProxy>("ascii_image.txt");
    imageProxyPtr->PrintImage(&std::cout);
}

void ShowDecoratorPattern()
{
    std::cout << "\n\n\>\>\> Decorator pattern \<\<\<\n";

    using namespace Decorator;

    const std::uint8_t key = 1;
    std::shared_ptr<IStreamWriter> xorStreamWriterPtr =
        std::make_shared<XorStreamWriterDecorator>(
            std::make_shared<StreamWriter>(&std::cout),
            key
        );

    std::cout << "Xor-encrypted \'Hello World\':\t";
    (*xorStreamWriterPtr)
        .Write("Hello World!")
        .Flush();
}

void ShowAdapterPattern()
{
    std::cout << "\n\n\>\>\> Adapter pattern \<\<\<\n";

    using namespace Adapter;

    std::shared_ptr<IWeapon> crossbowAdapterPtr =
        std::make_shared<CrossbowAdapter>();

    std::cout
        << "Old legacy \'Crossbow\' class has been adapted by its own adapter \'CrossbowAdapter\' "
        << "and now it has modern interface'.\n";
    std::cout
        << "Crossbow name is \'" << crossbowAdapterPtr->GetName() << "\'\n"
        << "Crossbow damage is " << crossbowAdapterPtr->MakeDamage();
}

void ShowCompositePattern()
{
    std::cout << "\n\n\>\>\> Composite pattern \<\<\<\n";

    using namespace Composite;

    auto cpuEqPtr = std::make_shared<Equipment>("Intel processor", 3000.);
    auto biosChipEqPtr = std::make_shared<Equipment>("BIOS chip", 1000.);
    auto memorySlotEqPtr = std::make_shared<Equipment>("Memory slot", 1500.);

    std::shared_ptr<Equipment> motherBoardEqPtr =
        std::make_shared<CompositeEquipment>("Motherboard", 800.);

    motherBoardEqPtr->Add(cpuEqPtr);
    motherBoardEqPtr->Add(biosChipEqPtr);
    motherBoardEqPtr->Add(memorySlotEqPtr);

    std::cout << motherBoardEqPtr->GetName() << " with its components costs " << motherBoardEqPtr->GetPrice();
}

void ShowFacadePattern()
{
    std::cout << "\n\n\>\>\> Facade pattern \<\<\<\n";

    using namespace Facade;

    auto mediaPlayerPtr = std::make_unique<MediaPlayer>();

    mediaPlayerPtr->PlayAudio("path_to_audio");
    mediaPlayerPtr->PlayVideo("path_to_video");

    std::cout << "NO CONSOLE OUTPUT FOR PATTERN\n";
}

int main(int, char**)
{
    ShowSingletonPattern();
    ShowPrototypePattern();
    ShowBuilderPattern();
    ShowFactoryMethodPattern();
    ShowAbstractFactoryPattern();
    ShowProxyPattern();
    ShowDecoratorPattern();
    ShowAdapterPattern();
    ShowCompositePattern();
    ShowFacadePattern();

    return std::cin.get();
}