#include <lcm/lcm-cpp.hpp>
#include "messages/Operation.hpp"
#include "messages/Result.hpp"
#include <iostream>

class ServerHandler {
public:
    void handleMessage(const lcm::ReceiveBuffer* rbuf,
                       const std::string& chan,
                       const messages::Operation* msg) {
        messages::Result result;
        if (msg->op == "add") {
            result.value = msg->a + msg->b;
            result.status = "ok";
        } else if (msg->op == "sub") {
            result.value = msg->a - msg->b;
            result.status = "ok";
        } else {
            result.value = 0;
            result.status = "invalid operation";
        }

        lcm::LCM lcm;
        lcm.publish("RESULT_CHANNEL", &result);
        std::cout << "Processed: " << msg->op << " " << msg->a << " " << msg->b << std::endl;
    }
};

int main() {
    lcm::LCM lcm;
    if (!lcm.good()) return 1;

    ServerHandler handler;
    lcm.subscribe("OP_CHANNEL", &ServerHandler::handleMessage, &handler);

    while (0 == lcm.handle());
    return 0;
}