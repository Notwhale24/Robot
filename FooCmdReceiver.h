#pragma once
#include "ACmdReceiver.h"
#include <iostream>
#include <string>

class FooCmdReceiver : public ACmdReceiver {
private:
    bool interactiveMode;
    
public:
    FooCmdReceiver() : interactiveMode(false) {}
    
    void startInteractiveMode() {
        interactiveMode = true;
        std::cout << "Интерактивный режим включен. Введите команду (help для справки)" << std::endl;
    }
    
    std::string receive() override {
        if (interactiveMode) {
            std::string cmd;
            std::cout << "> ";
            std::getline(std::cin, cmd);
            return cmd;
        }
        return "";
    }
};