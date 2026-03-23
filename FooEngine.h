#pragma once
#include "AEngine.h"
#include <iostream>
#include <thread>
#include <chrono>

class FooEngine : public AEngine {
private:
    std::string lastCommand;
    int lastCommandTime;
    bool engineOn;
    
public:
    FooEngine() : lastCommand("none"), lastCommandTime(0), engineOn(false) {}
    
    void turnOn() {
        engineOn = true;
        std::cout << "[FooEngine] ДВИГАТЕЛЬ ВКЛЮЧЕН" << std::endl;
    }
    
    void turnOff() {
        engineOn = false;
        std::cout << "[FooEngine] ДВИГАТЕЛЬ ВЫКЛЮЧЕН" << std::endl;
    }
    
    bool isEngineOn() const {
        return engineOn;
    }
    
    void forward(int time_ms) override {
        if (!engineOn) {
            std::cout << "[FooEngine] ОШИБКА: двигатель выключен!" << std::endl;
            return;
        }
        std::cout << "[FooEngine] ВПЕРЕД " << time_ms << " мс" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time_ms));
        lastCommand = "forward";
        lastCommandTime = time_ms;
    }
    
    void backward(int time_ms) override {
        if (!engineOn) {
            std::cout << "[FooEngine] ОШИБКА: двигатель выключен!" << std::endl;
            return;
        }
        std::cout << "[FooEngine] НАЗАД " << time_ms << " мс" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time_ms));
        lastCommand = "backward";
        lastCommandTime = time_ms;
    }
    
    void left(int time_ms) override {
        if (!engineOn) {
            std::cout << "[FooEngine] ОШИБКА: двигатель выключен!" << std::endl;
            return;
        }
        std::cout << "[FooEngine] ВЛЕВО " << time_ms << " мс" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time_ms));
        lastCommand = "left";
        lastCommandTime = time_ms;
    }
    
    void right(int time_ms) override {
        if (!engineOn) {
            std::cout << "[FooEngine] ОШИБКА: двигатель выключен!" << std::endl;
            return;
        }
        std::cout << "[FooEngine] ВПРАВО " << time_ms << " мс" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time_ms));
        lastCommand = "right";
        lastCommandTime = time_ms;
    }
    
    void stop() override {
        if (!engineOn) {
            std::cout << "[FooEngine] ОШИБКА: двигатель выключен!" << std::endl;
            return;
        }
        std::cout << "[FooEngine] СТОП" << std::endl;
        lastCommand = "stop";
        lastCommandTime = 0;
    }
    
    void printStatus() {
        std::cout << "[FooEngine] Статус: двигатель " << (engineOn ? "ВКЛЮЧЕН" : "ВЫКЛЮЧЕН");
        std::cout << ", последняя команда = " << lastCommand;
        if (lastCommandTime > 0) {
            std::cout << " (" << lastCommandTime << " мс)";
        }
        std::cout << std::endl;
    }
};