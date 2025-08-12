#include "client.hpp"
#include <lcm/lcm-cpp.hpp>
#include "messages/Operation.hpp"
#include "messages/Result.hpp"
#include <iostream>
#include <thread>

std::function<void(const messages::Result&)> resultCallback;

class ClientHandler {
public:
    void handleMessage(const lcm::ReceiveBuffer* rbuf,
                       const std::string& chan,
                       const messages::Result* msg) {
        if (resultCallback) resultCallback(*msg);
    }
};

lcm::LCM lcmInstance;
ClientHandler handler;

void startLCMListener() {
    if (!lcmInstance.good()) {
        std::cerr << "LCM is not initialized properly." << std::endl;
        return;
    }

    lcmInstance.subscribe("RESULT_CHANNEL", &ClientHandler::handleMessage, &handler);

    std::thread listener([] {
        while (0 == lcmInstance.handle());
    });
    listener.detach();
}

void sendOperation(const std::string& op, double a, double b) {
    messages::Operation msg;
    msg.op = op;
    msg.a = a;
    msg.b = b;
    lcmInstance.publish("OP_CHANNEL", &msg);
}
