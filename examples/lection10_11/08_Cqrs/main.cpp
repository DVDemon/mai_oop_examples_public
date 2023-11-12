#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>



class MessageStore {
protected:
    std::vector<std::string> messages;
public:
    void Save(size_t index, const char* msg) {

        std::cout << "size:" << messages.size();
        std::cout << " index:" << index << " ";
        if (index >= messages.size()) {

            while (index >= messages.size()) messages.push_back(std::string());
            std::cout << "inserted" << std::endl;
            messages[index] = std::string(msg);
        } else if (messages[index].empty()) {
            messages[index] = std::string(msg);
            std::cout << "replaced" << std::endl;
        } else std::cout << "Not empty" << std::endl;
    }

    const std::string  Read(size_t index) {
        if (index < messages.size())
            return messages[index];
        
        throw std::string("Index out of bounds");
    }
};

auto main() -> int {


    MessageStore store;

    store.Save(3, "Message 3");
    if(store.Read(3)==std::string("Message 3")) 
       std::cout << "Added" << std::endl;

    store.Save(2, "Message 2");
    if(store.Read(2)==std::string("Message 2")) std::cout << "Added" << std::endl;
    store.Save(1, "Message 1");
    if(store.Read(1)==std::string("Message 1")) std::cout << "Added" << std::endl;
    store.Save(0, "Message 0");
    if(store.Read(0)==std::string("Message 0")) std::cout << "Added" << std::endl;
    store.Save(3, "Message New");
    if(store.Read(3)==std::string("Message New")) std::cout << "Added" << std::endl;

    
    try{
        for (int i = 0; i < 10; i++) std::cout << store.Read(i) << std::endl;
    }catch(std::string ex){
        std::cout << "Exception:" << ex << std::endl;
    }

    return 0;
}

