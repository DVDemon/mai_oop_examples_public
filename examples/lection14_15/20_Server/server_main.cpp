#include <iostream>
#include <cstdlib>
#include <httplib.h>

auto main() -> int
{
    httplib::Server svr;
    std::string content = "Hello world!";
    svr.Get("/hi", [&content](const httplib::Request &req, httplib::Response &res)
            {       
                res.set_content(content, "text/plain"); 
            });
    
    std::cout << "starting server .." << std::endl;
    svr.listen("0.0.0.0", 8080);
    return 0;
}