//
//  main.cpp
//  Event. cpp
//  Implementation of Event class
//  Created by Shakya Don
//  40263686

#include <iostream>
#include "Event.h"

// Default constructor
Event::Event() : eventName("Comp 218 Event"), eventDate("2025-03-15"), locationType(0), attendeeCount(50) {}

// Constructor with name
Event::Event(string n) : eventName(n), eventDate("2025-03-15"), locationType(1), attendeeCount(10) {}

// Constructor with attributed through user input
Event::Event(string n, string d, int t, int c) : eventName(n), eventDate(d), locationType(t), attendeeCount(c) {}

// Gets
string Event::getName() const {return eventName;}
string Event::getDate() const {return eventDate;}
int Event::getLocationType() const {return locationType;}
int Event::getAttendeeCount()const {return attendeeCount;}

// sets
void Event::setName(string n) {eventName = n;}
void Event::setDate(string d) {eventDate = d;}
void Event::setLocationType(int t) {locationType = t;}
void Event::setAttendeeCount(int c) {attendeeCount = c;}

//check if event is virtual
bool Event::isVirtual() const {return locationType == 1;}

//change event to virtual
void Event::changeToVirtual(int number){
    locationType = 1;
}
// checks if events are the same
bool Event::equals(const Event &e)const{
    return eventName == e.eventName && eventDate == e.eventDate && locationType == e.locationType;
}
// event postpone
void Event::postpone(string newDate) {eventDate = newDate;}

//print details
void Event::printInfo() const{
    cout<<"Event "<<eventName<<endl;
    cout<<"Date "<<eventDate<<endl;
    cout<<"Number of attendees "<<" "<<attendeeCount<<" "<<(attendeeCount==1 ? "person" : "people")<<endl; // to ensure proper comprehension
    cout<<"Location: "<<(isVirtual()?"Virtual":"In person")<<endl;
}
    
