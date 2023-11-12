#include <cstdlib>
#include <iostream>
#include <vector>
#include <vector>

class ConnectionEnded{
    
};

class Modem {
protected:
    bool connected;
    std::string number;
    std::vector<int> buffer; // теперь тут вектор а не строка
public:

    Modem() : connected(false), number("") {

    }

    bool Deal(const char* value) {
        number = value;
        connected = true;
        return connected;
    }

    bool Connected() {
        return connected;
    }

    void Hangup() {
        number = "";
        buffer.clear(); // buffer = "" was not a good idea
        connected = false;
    }

    void Send(int Data) {
        buffer.push_back(Data); // buffer.append(1,Data) - not a good idea
    }

    bool NotEmpty(){ //new method
      return !buffer.empty();    
    }
    
    int  Receive() {
        int res = 0;
        if (buffer.size() > 0) {
            res = buffer.front();
            buffer.erase(buffer.begin());
        } else throw ConnectionEnded();
        return res;
    }
};

auto main() -> int {

    // Start unchanged part
    Modem modem;

    modem.Deal("8-800-1234567");

    if (!modem.Connected()) {
        std::cout << "Error: not connected" << std::endl;
        return 0;
    }
    
    // start changed part
    int test_message[]={1,2,3,4,5,6,7,8,9};
    for (auto i : test_message) modem.Send(i);
    std::cout << std::endl;

    std::vector<int> test_answer;
    while (modem.NotEmpty()){
        int value = modem.Receive();
        std::cout << "Received: " << value << std::endl;
        test_answer.push_back(value);
    }
    

    bool equal = (test_answer.size()==9);
    for(int i=0;i<9;i++) if(test_message[i]!=test_answer[i]) equal = false;
    if(!equal) std::cout << "Error: wrong answer" << std::endl;
    else std::cout << "Ok" << std::endl;

    // start unchanged part
    modem.Hangup();
    return 0;
}

