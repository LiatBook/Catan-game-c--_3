
//bookliat@gmail.com
#include "card.hpp"
#include <iostream>
using namespace std;
using namespace ariel;
using std::cout;
using std::endl;

class RoadConstructionCard : public Card {
    public:
        RoadConstructionCard(TYPE_OF_CARDS r) : Card(r) {}
        void display() override  {
        cout<< "RoadConstruction Card" << endl;  
    }
};

        
