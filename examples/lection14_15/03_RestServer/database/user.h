#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <vector>
#include <optional>
#include "Poco/JSON/Object.h"

namespace database
{
    class User{
        private:
            long _id{0};
            std::string _first_name;
            std::string _last_name;
            std::string _email;
            std::string _title;
            std::string _login;
            std::string _password;

        public:
            User() = default;
            User(long _id,
                    const std::string _first_name,
                    const std::string _last_name,
                    const std::string _email,
                    const std::string _title,
                    const std::string _login,
                    const std::string _password);
            static User fromJSON(const std::string & str);

            long             get_id() const;
            const std::string &get_first_name() const;
            const std::string &get_last_name() const;
            const std::string &get_email() const;
            const std::string &get_title() const;
            const std::string &get_login() const;
            const std::string &get_password() const;

            long&        id();
            std::string &first_name();
            std::string &last_name();
            std::string &email();
            std::string &title();
            std::string &login();
            std::string &password();

            static void init();
            static std::optional<User> read_by_id(long id);
            static std::vector<User> search(std::string first_name,std::string last_name);
            void save_to_mysql();

            Poco::JSON::Object::Ptr toJSON() const;

    };
}

#endif