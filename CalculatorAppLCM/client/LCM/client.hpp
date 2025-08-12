
#pragma once

#include <string>
#include <functional>
#include "messages/Result.hpp"

void startLCMListener();
void sendOperation(const std::string& op, double a, double b);

extern std::function<void(const messages::Result&)> resultCallback;
