#include <Qbit.h>
#include "Qbit/Core/EntryPoint.h"
#include "QbitAppLayer.h"

class Sandbox : public Qbit::Application
{
public:
    Sandbox(const Qbit::ApplicationSpecification& specification)
        : Qbit::Application(specification)
    {
        PushLayer(new QbitAppLayer());
    }

    ~Sandbox() = default;
};

Qbit::Application* Qbit::CreateApplication(Qbit::ApplicationCommandLineArgs args)
{
    Qbit::ApplicationSpecification spec;
    spec.Name = "QbitApp";
    spec.WorkingDirectory = "../QbitApp";
    spec.CommandLineArgs = args;

    return new Sandbox(spec);
}
