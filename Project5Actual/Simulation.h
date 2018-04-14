//
//  Simulation.h
//  Project5Actual
//
//  Created by Rudolf Musika on 4/4/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#ifndef Simulation_h
#define Simulation_h
#include "EventType.h"
#include "Time.h"
#include "Event.h"
#include "EventBuilder.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"
#include "Statistics.h"

class Simulation {
private:
    Event currentEvent;
    EventBuilder eventBuilder;
    LinkedQueue<Event> line1;
//    LinkedQueue<Event> line2;
//    LinkedQueue<Event> line3;
    PriorityQueue<Event> events;
    Statistics stats;
    void processArrival();
    void processDeparture();
    
public:
    Simulation();
    virtual ~Simulation() = default;
    void simulate();
    
 
};

#endif /* Simulation_h */
