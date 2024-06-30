//bookliat@gmail.com
#include "card.hpp"
#include <iostream>
using namespace std;
using namespace ariel;
using std::cout;
using std::endl;

class MonopolyCard : public Card {
    public:
        MonopolyCard(TYPE_OF_CARDS m) : Card(m) {}
        void display() override  {
        cout<< "Monopol Card" << endl;  
    }
};

  