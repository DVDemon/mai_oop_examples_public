#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <exception>

// хранилище каких-то строк с доступом по индексу
class MessageStore {
protected:
    std::vector<std::string> messages;
public:

    // Command?
    const std::string Save(size_t index, const char* msg) {
        std::cout << "size:" << messages.size();
        std::cout << " index:" << index << " ";
        if (index >= messages.size()) {
            while (index >= messages.size()) messages.push_back(std::string());
            std::cout << "inserted" << std::endl;;
            messages[index] = std::string(msg);
        } else if (messages[index].empty()) {
            messages[index] = std::string(msg);
            std::cout << "replaced" << std::endl;;
        } else std::cout << "Not empty" << std::endl;
        return messages[index]; // Why it return?
    }

    // Query?
    void Read(size_t index) {
        if (index < messages.size()){
            std::cout << "Msg:" << messages[index] << std::endl;// Side effect?
            return;
        }

        throw std::logic_error("Out of bounds");
    }
};

auto main() -> int {

    MessageStore store;

    if(store.Save(3, "Message 3")==std::string("Message 3")) std::cout << "Added" << std::endl;
    if(store.Save(2, "Message 2")==std::string("Message 2")) std::cout << "Added" << std::endl;
    if(store.Save(1, "Message 1")==std::string("Message 1")) std::cout << "Added" << std::endl;
    if(store.Save(0, "Message 0")==std::string("Message 0")) std::cout << "Added" << std::endl;
    if(store.Save(3, "Message New")==std::string("Message New")) std::cout << "Added" << std::endl;

    try{
    for (int i = 0; i < 10; i++) store.Read(i);
    }catch(...){
        std::cout << "Ops" << std::endl;
    }
    return 0;
}

