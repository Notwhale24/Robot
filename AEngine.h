#pragma once

class AEngine {
public:
    virtual void forward(int time_ms) = 0;
    virtual void backward(int time_ms) = 0;
    virtual void left(int time_ms) = 0;
    virtual void right(int time_ms) = 0;
    virtual void stop() = 0;
    
    virtual void turnOn() = 0; 
    virtual void turnOff() = 0;   
    virtual bool isEngineOn() const = 0;  
    
    virtual ~AEngine() {}
};