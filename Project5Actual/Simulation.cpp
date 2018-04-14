//
//  Simulation.cpp
//  Project5Actual
//
//  Created by Rudolf Musika on 4/4/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//
#include "Simulation.h"
Simulation::Simulation(){
}

void Simulation::processArrival(){

    bool isEmpty = line1.isEmpty();
    
    //Put currentEvent at the end of the line
    line1.enqueue(currentEvent);
    
    //Delete currentEvent from eventList
    events.dequeue();
    
//    Event bankCustomer = currentEvent;
    if (isEmpty){
        events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(), currentEvent.getDuration(), currentEvent.getNumber()));
    }

    Event newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber()+1);
    
    if (EventType::NONE != newEvent.getType()){
        events.enqueue(newEvent);
    }
    
}

void Simulation::processDeparture(){
    line1.dequeue();
    events.dequeue();
    bool isEmpty = line1.isEmpty();
    if(!isEmpty){
        Event DepartureEvent = line1.peekFront();
        events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(), DepartureEvent.getDuration(), currentEvent.getNumber()));
    }
}
    
void Simulation::simulate(){
   bool tellerAvailability = true;
   //Create the initial arrival event
    currentEvent = eventBuilder.createArrivalEvent(tellerAvailability);
    
    if(EventType::ARRIVAL == currentEvent.getType()){
        events.enqueue(currentEvent);
    }
    
    while (!events.isEmpty()){
        currentEvent = events.peekFront();
        if(currentEvent.getType() == EventType::ARRIVAL){
            processArrival();
        }
        else{
            processDeparture();
        }
        stats.addEvent(currentEvent);
    }
           
    stats.reportStats();
}
