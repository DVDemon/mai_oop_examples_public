#include <iostream>

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>

//https://github.com/yhirose/cpp-httplib

auto main() -> int
{
    httplib::Client cli("localhost",8080);

    auto res = cli.Get("/hi");

    if (res)
    {
        std::cout << res->status << std::endl;
        std::cout << res->body << std::endl;
    }
    else
    {
        std::cout << "error: " << httplib::to_string(res.error()) << std::endl;
    }
    return 0;
}