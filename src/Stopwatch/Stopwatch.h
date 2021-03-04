#include <Arduino.h>

#ifndef INFOB3IT_STOPWATCH_H
#define INFOB3IT_STOPWATCH_H

class Stopwatch{ 

private:

    unsigned int startTime;     
    unsigned int stopTime;
    bool isCounting;            

public:
    // Constructor
    Stopwatch();
    // Methods
    unsigned int getTime();
    void start();
    void stop();
    void reset(); 
};

#endif //INFOB3IT_STOPWATCH_H