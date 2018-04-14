//
//  Event.hpp
//  Project5Actual
//
//  Created by Rudolf Musika on 4/4/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#include <iostream>
#include "EventType.h"
#include "Time.h"

class Event {
private:
    EventType type;
    Time time;
    Time duration;
    int number = 0;
    int lineNumber = 1;
public:
    Event();
    
    virtual ~Event() = default;
   
    virtual EventType getType() const ;
    virtual Time getTime() const;
    virtual Time getDuration() const;
    virtual int getNumber() const;
    virtual int getLine() const;
    
    void setType(const EventType& aType);
    void setTime(const Time& aTime);
    void setDuration(const Time& aDuration);
    void setNumber(const int& aNumber);
    void setLineNumber(const int& aLineNumber);
    
    bool operator<(const Event& rhs) const;
    bool operator>(const Event& rhs) const;
    bool operator<=(const Event& rhs) const;
    bool operator>=(const Event& rhs) const;
    bool operator==(const Event& rhs) const;
    bool operator!=(const Event& rhs) const;
};
#endif /* Event_hpp */
