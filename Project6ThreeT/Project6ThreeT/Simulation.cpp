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
            bool isEmpty1 = line1.isEmpty();
            bool isEmpty2 = line2.isEmpty();
            bool isEmpty3 = line3.isEmpty();
            unsigned int teller = 1;
            unsigned int tellerReset = 2;

    if ((line3.getLength()<= line1.getLength())&&(line3.getLength()<= line2.getLength())){
        line3.enqueue(currentEvent);
                 events.dequeue();
    }
    else if ((line1.getLength()<= line2.getLength()) && (line1.getLength()<= line3.getLength())){
        line1.enqueue(currentEvent);
                 events.dequeue();
    }
    else if ((line2.getLength()<= line3.getLength()) && (line2.getLength()<= line1.getLength())){
        line2.enqueue(currentEvent);
                 events.dequeue();
    }
    if (isEmpty1){
        events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(), currentEvent.getDuration(), currentEvent.getNumber(), currentEvent.getLine()));
    }
    else if(isEmpty2){
        events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(), currentEvent.getDuration(), currentEvent.getNumber(), currentEvent.getLine()));
    }
    else if (isEmpty3){
        events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(), currentEvent.getDuration(), currentEvent.getNumber(), currentEvent.getLine()));
    }
    if (currentEvent.getLine()+teller > 3 ){
    Event newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber()+1, currentEvent.getLine()-tellerReset);
        if (EventType::NONE != newEvent.getType()){
            events.enqueue(newEvent);
        }
    }
    else {
    Event newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber()+1, currentEvent.getLine()+ teller);
        if (EventType::NONE != newEvent.getType()){
            events.enqueue(newEvent);
        }
    }

}

void Simulation::processDeparture(){
    if ((line3.getLength()<= line1.getLength())&&
        (line3.getLength()<= line2.getLength())){
        line3.dequeue();
    }
    else if ((line1.getLength()<= line2.getLength()) &&
             (line1.getLength()<= line3.getLength())){
        line1.dequeue();
    }
    else if((line2.getLength()<= line1.getLength()) &&
            (line2.getLength()<= line3.getLength())){
        line2.dequeue();
    }
            events.dequeue();
    bool isEmpty1 = line1.isEmpty();
    bool isEmpty2 = line2.isEmpty();
    bool isEmpty3 = line3.isEmpty();

    if(!isEmpty1 || !isEmpty2 || !isEmpty3){
    events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(), currentEvent.getDuration(), currentEvent.getNumber(), currentEvent.getLine()));
    }
}

void Simulation::simulate(){
   bool tellerAvailability = true;
   
    currentEvent = eventBuilder.createArrivalEvent(tellerAvailability,
                                                   currentEvent.getLine());
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











//    if(!isEmpty1){
//        Event DepartureEvent1 = line1.peekFront();
//        events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(), DepartureEvent1.getDuration(), currentEvent.getNumber(),
//                                                         currentEvent.getLine()));
//    }
//    else if (!isEmpty2){
//        Event DepartureEvent2 = line2.peekFront();
//        events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(), DepartureEvent2.getDuration(), currentEvent.getNumber(),
//                                                         currentEvent.getLine()));
//    }
//    else if (!isEmpty3){
//        Event DepartureEvent3 = line3.peekFront();
//        events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(), DepartureEvent3.getDuration(), currentEvent.getNumber(),
//                                                         currentEvent.getLine()));
//    }


//
//    else if((line1.getLength()<=line2.getLength())&&(line1.getLength()>=line3.getLength())){
//        line3.enqueue(currentEvent);
//    }
//    else if ((line2.getLength()<=line1.getLength())&&(line2.getLength()>=line3.getLength())){
//        line3.enqueue(currentEvent);
//    }
//    else if ((line3.getLength()<=line1.getLength())&&(line3.getLength()>=line2.getLength())){
//        line2.enqueue(currentEvent);
//    }
//
//
//    else if ((line2.getLength()<=line3.getLength())&&(line2.getLength()>=line1.getLength())){
//        line1.enqueue(currentEvent);
//    }
//    else if ((line1.getLength()<=line3.getLength())&&(line1.getLength()>=line2.getLength())){
//        line2.enqueue(currentEvent);
//    }
//    else if ((line3.getLength()<=line2.getLength())&&(line3.getLength()>=line1.getLength())){
//        line1.enqueue(currentEvent);
//    }
