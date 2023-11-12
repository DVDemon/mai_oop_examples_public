// Абстрактная фабрика (Abstract factory)

#include <iostream>

enum class Env {
    cloud, local
};

// Config

struct IConfig {
    virtual ~IConfig() = default;

    virtual void read() = 0;
};

class ConsulConfig : public IConfig {
    void read() override
    {
        std::cout << "connect to consul" << std::endl;
    }
};
class LocalConfig : public IConfig {
    void read() override
    {
        std::cout << "open local file" << std::endl;
    }
};

// Metric

struct IMetric {
    virtual ~IMetric() = default;

    virtual void send() = 0;
};

struct PrometheusMetric : public IMetric {
    void send() override
    {
        std::cout << "push to prometheus" << std::endl;
    }
};

struct LocalMetric : public IMetric {
    void send() override
    {
        std::cout << "write to log" << std::endl;
    }
};

//

struct EnvironmentFactory {
    virtual ~EnvironmentFactory() = default;

    virtual IConfig* CreateConfig() = 0;
    virtual IMetric* CreateMetric() = 0;
};

class CloudFactory : public EnvironmentFactory {
    IConfig* CreateConfig() override
    {
        return new ConsulConfig();
    }

    IMetric* CreateMetric() override
    {
        return new PrometheusMetric();
    }
};

class LocalFactory : public EnvironmentFactory {
    IConfig* CreateConfig() override
    {
        return new LocalConfig();
    }

    IMetric* CreateMetric() override
    {
        return new LocalMetric();
    }
};

int main(int argc, char* [])
{
    auto environment = (argc==1) ? Env::cloud : Env::local;

    EnvironmentFactory* factory;
    switch (environment) {
    case Env::cloud:factory = new CloudFactory();
        break;

    case Env::local:factory = new LocalFactory();
        break;
    }

    //

    auto config = factory->CreateConfig();
    auto metric = factory->CreateMetric();

    config->read();
    metric->send();

    delete metric;
    delete config;

    delete factory;

    return 0;
}
