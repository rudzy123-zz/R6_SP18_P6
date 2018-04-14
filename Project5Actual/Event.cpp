//
//  Event.cpp
//  Project5Actual
//
//  Created by Rudolf Musika on 4/4/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#include "Event.h"

Event::Event(){
    time = 0;
    duration = 0;
}

EventType Event::getType() const {
    return type;
}

Time Event::getTime() const{
    return time;
}

Time Event::getDuration() const{
    return duration;
}

int Event::getNumber() const{
    return number;
}

void Event::setType(const EventType &aType){
    type = aType;
}

void Event::setTime(const Time &aTime){
    time = aTime;
}

void Event::setDuration(const Time &aDuration){
    duration = aDuration;
}

void Event::setNumber(const int &aNumber){
    number = aNumber;
}

bool Event::operator<(const Event& rhs) const {
    
    return time < rhs.getTime();
}

bool Event::operator>(const Event& rhs) const {
    
    return time > rhs.getTime();
}

bool Event::operator<=(const Event& rhs) const {
    
    return time <= rhs.getTime();
}

bool Event::operator>=(const Event& rhs) const{
    return time >= rhs.getTime();
}

bool Event::operator==(const Event& rhs) const {
    
    return time == rhs.getTime();
}

bool Event::operator!=(const Event& rhs) const {
    
    return time != rhs.getTime();
}
