#include <iostream>
#include <sstream>
#include <windows.h>
#include "FooEngine.h"
#include "FooCmdReceiver.h"

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FooEngine engine;
    FooCmdReceiver receiver;

    receiver.startInteractiveMode();
    engine.turnOn();

    std::cout << "Доступные команды: forward <ms>, left <ms>, right <ms>, stop, exit\n";

    while (true) {
        std::string input = receiver.receive();

        if (input.empty()) {
            continue;
        }

        std::istringstream iss(input);
        std::string command;
        int time_ms = 0;

        iss >> command;

        if (command == "forward") {
            iss >> time_ms;
            engine.forward(time_ms);
        } else if (command == "left") {
            iss >> time_ms;
            engine.left(time_ms);
        } else if (command == "right") {
            iss >> time_ms;
            engine.right(time_ms);
        } else if (command == "stop") {
            engine.stop();
        } else if (command == "exit") {
            engine.turnOff();
            std::cout << "Выход из программы\n";
            break;
        } else {
            std::cout << "Неизвестная команда\n";
        }
    }

    return 0;
}