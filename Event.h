#ifndef EVENT_
#define EVENT_
#include <iostream>
#include <string>



class Event {
private:
    int arrivalTime = 0;
    int durationTime = 0;
    char eventType = 'A';
    
public:
    Event();
    Event(int arrival, int duration);
    Event(int arrival, int duration, char type);
    int getArrival() const;
    int getDuration()const;
    char getType()const;
};


#endif