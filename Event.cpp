#include <iostream>
#include <string>
#include "Event.h"

 
Event::Event() {
	arrivalTime = 0;
	durationTime = 0;
	eventType = 'A';

}
 
Event::Event(int arrival, int duration) {
	arrivalTime = arrival;
	durationTime = duration;
	eventType = 'A';

}
 
Event::Event(int arrival, int duration, char type) {
	arrivalTime = arrival;
	durationTime = duration;
	eventType = type;

}
 
int Event::getArrival() const {
	return arrivalTime;
}
 
int Event::getDuration() const {
	return durationTime;
}
 
char Event::getType() const {
	return eventType;
}