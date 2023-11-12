#include <cstdlib>
#include <iostream>
#include <string>

class Modem {
protected:
    bool connected;
    std::string number;
    std::string buffer;
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
        buffer = "";
        connected = false;
    }

    void Send(char Data) {
        buffer.append(1, Data);
    }

    char Receive() {
        char res = 0;
        if (buffer.size() > 0) {
            res = buffer.front();
            buffer.erase(buffer.begin());
        }


        return res;
    }
};

auto main() -> int {

    Modem modem;

    modem.Deal("8-800-1234567");

    if (!modem.Connected()) {
        std::cout << "Error: not connected" << std::endl;
        return 0;
    }

    std::string test_message="Test message to modem";
    for (auto i : test_message) modem.Send(i);
    std::cout << std::endl;

    std::string test_answer;
    while (char b = modem.Receive()) {
        test_answer.push_back(b);
    }
    
    if(test_message!=test_answer) std::cout << "Error: Answer was" << test_answer << std::endl;
    else std::cout << "Sent:" << test_message << std::endl << "Received:" << test_answer << std::endl;

    modem.Hangup();
    return 0;
}

