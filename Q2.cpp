//
//  main.cpp
//  Q2. cpp
//
//  Written by Shakya Don
//  40263686

#include <iostream>
#include <string>
#include "Event.h"
#include <sstream>

using namespace std;

int main () {
    string name, date;
    int type, count;
    
    Event event1;
    
    //welcome message
    cout<<"----------------------------------------------"<<endl;
    cout<<"Welcome to the Event Information program!"<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
    
    //create event 2 using second constructor
    cout<<"Please enter the name of event 2: ";
    getline(cin, name); //prompting user input for name
    Event event2(name);
    
    //create event 3 using third constructor
    string singleLine;
    cout<<"Please enter the name, date, location type (1 for virtual, 0 for in person), and attendees of event 3: ";
    getline(cin, singleLine);
    stringstream ss(singleLine);
    ss>>name>>date>>type>>count;
    Event event3(name, date, type, count);
    cout<<endl; //leave spaces to make output clearer
    //print event details
    event1.printInfo();
    cout<<endl;
    event2.printInfo();
    cout<<endl;
    event3.printInfo();
    
    // check if the events are virtual and prompt user input if not
    if(!event1.isVirtual()){
        cout<<"Would you like to change event 1 to virtual?(y/n): ";
        char choice;
        cin>>choice;
        if (tolower(choice)== 'y'){
            event1.changeToVirtual(1);
        }
    }
    if(!event2.isVirtual()){
        cout<<"Would you like to change event 2 to virtual?(y/n): ";
        char choice;
        cin>>choice;
        if (tolower(choice)== 'y'){
            event1.changeToVirtual(2);
        }
    }
    if(!event3.isVirtual()){
        cout<<"Would you like to change event 3 to virtual?(y/n): ";
        char choice;
        cin>>choice;
        if (tolower(choice)== 'y'){
            event1.changeToVirtual(3);
        }
    }
    
    //attendee counts
    int attendees[3]={
        event1.getAttendeeCount(),
        event2.getAttendeeCount(),
        event3.getAttendeeCount()
    };
    
    //total attendee count
    int totalAttendees= attendees[0]+attendees[1]+attendees[2];
    cout<<"\nTotal number of attendees for all event: "<<totalAttendees<<endl;
    
    //update event 2 attendee count to sum of event1 and event 3
    int updatedCount= event1.getAttendeeCount()+event3.getAttendeeCount();event2.setAttendeeCount(updatedCount);
    
    //recalculate new total
    attendees[1]=updatedCount;
    totalAttendees= attendees[0]+attendees[1]+attendees[2];
    cout<<"Updating count for event 2..."<<endl;
    cout<<"Total number of attendees after update: "<<totalAttendees<<endl;
    cout<<endl; //leave spaces to make output clearer
    //prompting user to postpone event 1
    cout<<"Would you like to postpone event 1?(y/n): ";
    char choiceTwo;
    cin>>choiceTwo;
    if (tolower(choiceTwo)== 'y'){
        cout<<"Enter new date: ";
        cin.ignore(); //get rid of leftover newline after input
        getline(cin, date);
        event1.postpone(date);
    }
    cout<<endl; //leave spaces to make output clearer
    // event comparision
    cout<<"Event 1 and Event 2: "<<(event1.equals(event2) ? "Equal." : "Not Equal.")<<endl;
    cout<<"Event 2 and Event 3: "<<(event2.equals(event3) ? "Equal." : "Not Equal.")<<endl;
    cout<<"Event 1 and Event 3: "<<(event1.equals(event3) ? "Equal." : "Not Equal.")<<endl;
    cout<<endl;
    // print final event details
    event1.printInfo();
    event2.printInfo();
    event3.printInfo();
    cout<<endl;//leave spaces to make output clearer

    cout<<"Thank you for using the Event Information System!"<<endl;
    return 0;
    
}
