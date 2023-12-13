#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <memory>
#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/MySQL/MySQLException.h>
#include <Poco/Data/SessionFactory.h>
#include <Poco/Data/SessionPool.h>

namespace database{
    class Database{
        private:
            std::string _connection_string;
            std::unique_ptr<Poco::Data::SessionPool> _pool;
            Database();
        public:
            static Database& get();
            Poco::Data::Session create_session();
    };
}
#endif