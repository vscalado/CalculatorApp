#include <lcm/lcm-cpp.hpp>
#include "messages/Operation.hpp"
#include "messages/Result.hpp"
#include <iostream>
#include <functional>

std::function<void(const messages::Result&)> resultCallback;

class ClientHandler {
public:
    void handleMessage(const lcm::ReceiveBuffer* rbuf,
                       const std::string& chan,
                       const messages::Result* msg) {
        if (resultCallback) resultCallback(*msg);
    }
};

void sendOperation(const std::string& op, double a, double b) {
    lcm::LCM lcm;
    messages::Operation msg;
    msg.op = op;
    msg.a = a;
    msg.b = b;
    lcm.publish("OP_CHANNEL", &msg);
}