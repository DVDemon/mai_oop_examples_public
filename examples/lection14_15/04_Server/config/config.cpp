#include "config.h"

Config::Config()
{
        _host = std::getenv("DB_HOST");
        _port = std::getenv("DB_PORT");
        _login = std::getenv("DB_LOGIN");
        _password = std::getenv("DB_PASSWORD");
        _database = std::getenv("DB_DATABASE");
}

Config &Config::get()
{
    static Config _instance;
    return _instance;
}

const std::string &Config::get_port() const
{
    return _port;
}

const std::string &Config::get_host() const
{
    return _host;
}

const std::string &Config::get_login() const
{
    return _login;
}

const std::string &Config::get_password() const
{
    return _password;
}
const std::string &Config::get_database() const
{
    return _database;
}

std::string &Config::port()
{
    return _port;
}

std::string &Config::host()
{
    return _host;
}

std::string &Config::login()
{
    return _login;
}

std::string &Config::password()
{
    return _password;
}

std::string &Config::database()
{
    return _database;
}