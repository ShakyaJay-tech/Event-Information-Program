//
//  Event.h
//  Event. h
//
//  Written by Shakya Don
//  40263686

#ifndef Event_h
#define Event_h

#include <iostream>
#include <string>

using namespace std;

class Event {
private:
    string eventName;
    string eventDate;
    int locationType; // 1 for virtual, 0 for in person
    int attendeeCount;
    
public:
    // constructors
    Event();
    Event(string n);
    Event(string n, string d, int t, int c);
    
    // gets
    string getName() const;
    string getDate() const;
    int getLocationType() const;
    int getAttendeeCount() const;
    
    //sets
    void setName(string n);
    void setDate(string d);
    void setAttendeeCount(int c);
    void setLocationType(int t);
    
    //member functions
    bool isVirtual() const;
    bool equals (const Event &e)const;
    void changeToVirtual(int number);
    void postpone(string newDate);
    void printInfo()const;
    
    
};

#endif /* Event_h */
