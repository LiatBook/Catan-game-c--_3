//bookliat@gmail.com
#pragma once
#include <iostream>
#include <string>
 enum TYPE_OF_CARDS { 
    KNIGHT,//אביר
    TRIUMPH,//ניצחון
    MONOPOL,//מונופול
    ABUNDANCE,//שפע
    ROAD_CONSTRUCTION//בניית דרכים

    }; 

using namespace std;

namespace ariel {

    class Card {
    private:
    TYPE_OF_CARDS type;
    public:
        Card(TYPE_OF_CARDS t) : type(t) {}
        
        TYPE_OF_CARDS gettype() const {
            return type;
        }
        virtual void display() = 0;  // Pure virtual function for displaying card details
        
    };
}

