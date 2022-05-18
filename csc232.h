/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    csc232.h
 * @author  Daniel Abbott <dsa808@missouristate.edu>
 * @brief   Macros, declarations and definitions for use in this assignment.
 */

#ifndef MSU_CSC232_H
#define MSU_CSC232_H

#define FALSE 0
#define TRUE 1
#define EXECUTE_BLOCK FALSE
#define SIMULATE_FUNCTION_IMPLEMENTED TRUE
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <queue>
#include "Event.h"






void Simulate(const std::string &fileName)
{
   int events = 0;
   int totalArrival = 0;
   int totalDeparture = 0;
   int totalWaitTime = 0;
   double averageWaitingTime;

   
   std::ifstream data{fileName};
   std::queue<int> bankLine;
   std::priority_queue<Event> eventList;
   
   bool tellerAvailable = true;
   if (data.is_open())
   {
       int eventTime, eventDuration;
       while (data >> eventTime >> eventDuration)
       {
           Event newArrivalEvent(eventTime, eventDuration);
           eventList.push(newArrivalEvent);
           std::cout << "time " << std::setw(3) << newArrivalEvent.getArrival() << std::endl << "duration" << std::setw(3) << newArrivalEvent.getDuration();
       }
   }
   else
   {
       std::cerr << "Couldn't open \"demoData.txt\"" << std::endl;
   }

   if (data.is_open())
   {
       std::cout << "\nClosing file: \"demoData.txt\"" << std::endl;
       data.close();
   }
  
   std::cout << "Simulation Begins" << std::endl;

   while (!eventList.empty())
   {
       Event newEvent = eventList.top();

       int currentTime = newEvent.getArrival();
       if (newEvent.getType() == 'A')
       {
           eventList.pop();
           Event customer = newEvent;
           if (bankLine.empty() && tellerAvailable)
           {
               int departureTime = currentTime + newEvent.getDuration();
               Event newDepartureEvent(departureTime, 0, 'D');
               eventList.push(newDepartureEvent);
               tellerAvailable = false;
           }
           else
           {
                eventList.push(customer);
           }

           std::cout << "Processing an arrival event at time:\t" << customer.getArrival() << std::endl;
           events++;
           totalArrival += customer.getArrival();
           totalWaitTime += customer.getDuration();
       }
       else
       {
           eventList.pop();

           if (!bankLine.empty())
           {
               Event customer = eventList.top();
               bankLine.pop();
               int departureTime = currentTime + customer.getDuration();
               Event newDepartureEvent(departureTime, 0, 'D');
               eventList.push(newDepartureEvent);
           }
           else
           {
               tellerAvailable = true;
           }

           std::cout << "Processing a departure event at time:\t" << currentTime << std::endl;
           totalDeparture += currentTime;
       }
   }

   averageWaitingTime = (double)(totalDeparture - totalWaitTime - totalArrival) / events;
  
   std::cout << "Simulation Ends" << std::endl;
   std::cout << "Final Statistics:" << std::endl;
   std::cout << "\tTotal number of people processed: " << events << std::endl;
   std::cout << "\tAverage amount of time spent waiting: " << averageWaitingTime << std::endl;

} 

#endif  //MSU_CSC232_H
