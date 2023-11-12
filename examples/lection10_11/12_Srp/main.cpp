#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class ConnectionEnded {
};

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

// просто добавляем новый класс для новых алгоритмов
class IIntModem {
protected:
    std::vector<int> buffer;
public:

    virtual void Send(int Data) {
        buffer.push_back(Data); 
    }

    virtual bool NotEmpty(){
      return !buffer.empty();    
    }
    
    virtual int  Receive() {
        int res = 0;
        if (buffer.size() > 0) {
            res = buffer.front();
            buffer.erase(buffer.begin());
        } else throw ConnectionEnded();
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

void Test(ICharModem *char_modem) {
    std::string test_message = "Test message to modem";
    for (auto i : test_message) char_modem->Send(i);
    std::cout << std::endl;

    std::string test_answer;
    while (char_modem->NotEmpty()) test_answer.push_back(char_modem->Receive());


    if (test_message != test_answer) std::cout << "Error: Answer was" << test_answer << std::endl;
    else std::cout << "Sent:" << test_message << std::endl << "Received:" << test_answer << std::endl;

}

void Test(IIntModem *int_modem) {
    int test_message[]={1,2,3,4,5,6,7,8,9};
    for (auto i : test_message) int_modem->Send(i);
    std::cout << std::endl;

    std::vector<int> test_answer;
    while (int_modem->NotEmpty()){
        test_answer.push_back(int_modem->Receive());
    }
    

    bool equal = (test_answer.size()==9);
    for(int i=0;i<9;i++) if(test_message[i]!=test_answer[i]) equal = false;
    if(!equal) std::cout << "Error: wrong answer" << std::endl;
    else std::cout << "Ok" << std::endl;

}

void Disconnect(IConnection *connection) {
    connection->Hangup();
}




class Modem : public IConnection, public IIntModem {
};

auto main() -> int {

    Modem modem;

    if (Connect(&modem)) {
        Test(&modem);
        Disconnect(&modem);
    }

    return 0;
}

