// Фабричный метод (Factory method)

#include <iostream>

enum class Storage { mysql, postgres };

struct IStorage {
    virtual ~IStorage() = default;

    virtual void open() = 0;
    virtual void execute_query() = 0;
    virtual void close() = 0;
};

class MysqlStorage : public IStorage {
    void open() override
    {
        std::cout << "connect to mysql" << std::endl;
    }

    void execute_query() override
    {
        std::cout << "fetch mysql result" << std::endl;
    }

    void close() override
    {
        std::cout << "disconnect from mysql" << std::endl;
    }
};

class PostgresStorage : public IStorage {
    void open() override
    {
        std::cout << "connect to pg" << std::endl;
    }

    void execute_query() override
    {
        std::cout << "fetch pg result" << std::endl;
    }

    void close() override
    {
        std::cout << "disconnect from pg" << std::endl;
    }
};


struct Factory{
    IStorage* factory_method(const Storage& storage ){

        switch (storage) {
        case Storage::mysql: return new MysqlStorage();
            break;

        case Storage::postgres: return new PostgresStorage();
            break;
        }
    }
};

int main(int argc, char* [])
{
    Factory f;
    auto environment = (argc==1) ? Storage::postgres : Storage::mysql;

    IStorage* storage = f.factory_method(environment);

    storage->open();
    storage->execute_query();
    storage->close();

    delete storage;

    return 0;
}
