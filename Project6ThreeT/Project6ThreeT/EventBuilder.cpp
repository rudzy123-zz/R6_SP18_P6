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
        std::cout<<"Enter a file name again \n";
        std::cin>>name;
//        std::getline(std::cin,name);
        inputFile.open(name);
    }
}

Event EventBuilder::createArrivalEvent(int number, int lineNumber){
    Event arrival;
    int readTime;
    int readDuration;
    arrival.setType(EventType::ARRIVAL);
    if(inputFile >> readTime >> readDuration){
        arrival.setTime(readTime);
        arrival.setNumber(number);
        arrival.setDuration(readDuration);
        arrival.setLineNumber(lineNumber);
    }
    else{
        arrival.setNumber(0);
        arrival.setType(EventType::NONE);
        arrival.setLineNumber(1);
    }
    return arrival;
}

Event EventBuilder::createDepartureEvent(const Time& currentEventTime,
                                         const Time& transactionLength,
                                         int number, int lineNumber){
    Event departure;
    departure.setType(EventType::DEPARTURE);
    departure.setTime(currentEventTime+transactionLength);
    departure.setNumber(number);
    departure.setLineNumber(lineNumber);
    
    return departure;
}
