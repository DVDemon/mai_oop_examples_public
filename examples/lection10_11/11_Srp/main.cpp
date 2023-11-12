#include <cstdlib>
#include <iostream>
#include <string>

class ConnectionEnded {
};

// абстракция для работы с соединением
class IConnection {
protected:
    bool connected;
    std::string number;
public:

    IConnection() : connected(false), number("") {
    }

    virtual bool Deal(const char* value) {
        number = value;
        connected = true;
        return connected;
    }

    virtual bool Connected() {
        return connected;
    }

    virtual void Hangup() {
        number = "";
        connected = false;
    }

};

// абстракция для передачи символов
class ICharModem {
protected:
    std::string buffer;
public:

    virtual void Send(char Data) {
        buffer.push_back(Data);
    }

    virtual bool NotEmpty() {
        return !buffer.empty();
    }

    virtual char Receive() {
        if (buffer.empty()) throw ConnectionEnded();
        char res = buffer.front();
        buffer.erase(buffer.begin());

        return res;
    }
};

bool Connect(IConnection *connection) {
    connection->Deal("8-800-1234567");
    if (!connection->Connected()) {
        std::cout << "Error: not connected" << std::endl;
        return false;
    }
    return true;
}

// тестируем связь
void Test(ICharModem *char_modem) {
    std::string test_message = "Test message to modem";
    for (auto i : test_message) char_modem->Send(i);
    std::cout << std::endl;

    std::string test_answer;
    while (char_modem->NotEmpty()) test_answer.push_back(char_modem->Receive());


    if (test_message != test_answer) std::cout << "Error: Answer was" << test_answer << std::endl;
    else std::cout << "Sent:" << test_message << std::endl << "Received:" << test_answer << std::endl;

}

void Disconnect(IConnection *connection) {
    connection->Hangup();
}

// сам модем
class Modem : public IConnection, 
              public ICharModem {
};

auto main() -> int {

    Modem modem;

    if (Connect(&modem)) {
        Test(&modem);
        Disconnect(&modem);
    }

    return 0;
}

