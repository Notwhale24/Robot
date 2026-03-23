#pragma once
#include <string>

class ACmdReceiver {
public:
    virtual std::string receive() = 0;
    virtual ~ACmdReceiver() {}
    
    void startInteractiveMode() {
        
    }
};