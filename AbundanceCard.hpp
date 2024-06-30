//bookliat@gmail.com
#include "card.hpp"
#include <iostream>
using namespace std;
using namespace ariel;
using std::cout;
using std::endl;

class AbundanceCard : public Card {
    public:
        AbundanceCard(TYPE_OF_CARDS a) : Card(a) {}
        void display() override  {
        cout<< "Abundance Card" << endl;  
    }
};

        
