#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <vector>

#include <cassert>

enum class EventCode {
    start = 0,
    new_doc, 
    quit
};

struct Event {
    EventCode code;
    std::string data;
};


struct  Handler {
    virtual bool event(const Event &) = 0;
};

struct PrintHandler :  Handler {
    bool event(const Event& event) override {
        std::cout << "Handle next event:\ncode = " << static_cast<int>(event.code) 
            << "\ndata = " << event.data << std::endl;
        return true;
    }
};

class EventLoop {
public:
    void send(const Event& event) {
        m_event_queue.push(event);
    }

    void addHandler(Handler *handler) {
        m_handlers.push_back(handler);
    }

    int exec() {
        while (!m_quit) {
            if (!m_event_queue.empty()) {
                auto ev = m_event_queue.front();
                m_event_queue.pop();

                switch (ev.code) {
                	// Special event for stopping
                    case EventCode::quit:
                        m_quit = true;
                        break;
                    // All other events are handled by handlers
                    default:
                        for (auto handler : m_handlers) {
                        	assert(handler);
                        	if (handler->event(ev))
                        		break;
                        }
                }
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }

        return 0;
    }
private:
	bool m_quit = false;
    std::queue<Event> m_event_queue;
    std::vector<Handler *> m_handlers;
    std::thread m_eventLoopThread;
};

void userThread(EventLoop& loop) {
    for(int i=0; i<10; ++i) {
        loop.send({
            EventCode::new_doc,
            std::to_string(i)
        });
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    loop.send({
        EventCode::quit,
        "quit"
    });
}

auto main() -> int {
    PrintHandler printHandler;
    EventLoop eventLoop;

    eventLoop.addHandler(&printHandler);
    
    eventLoop.send({
        EventCode::start,
        "starting"});
        
    std::thread workerThread{userThread, std::ref(eventLoop)};

    eventLoop.exec();

    workerThread.join();

	return 0;
}
