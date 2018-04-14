//
//  EventBuilder.cpp
//  Project5Actual
//
//  Created by Rudolf Musika on 4/4/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#include "EventBuilder.h"
#include <fstream>
#include<string>


EventBuilder::EventBuilder(){
    std::string name = "";
    std::cout<<"What is the name of your file?\n";
    std::cin>>name;
    
    inputFile.open(name);
    while (inputFile.fail()){
        std::cout<<"Enter a file name\n";
//        std::cin>>name;
        std::getline(std::cin,name);
        inputFile.open(name);
    }
}

Event EventBuilder::createArrivalEvent(int number){
    Event arrival;
    int readTime;
    int readDuration;
    arrival.setType(EventType::ARRIVAL);
    if(inputFile >> readTime >> readDuration){
        arrival.setTime(readTime);
        arrival.setNumber(number);
        arrival.setDuration(readDuration);
    }
    else{
        arrival.setNumber(0);
        arrival.setType(EventType::NONE);
    }
    return arrival;
}

Event EventBuilder::createDepartureEvent(const Time& currentEventTime,
                                         const Time& transactionLength,
                                         int number){
    Event departure;
    departure.setType(EventType::DEPARTURE);
    departure.setTime(currentEventTime+transactionLength);
    departure.setNumber(number);
    
    return departure;
}
