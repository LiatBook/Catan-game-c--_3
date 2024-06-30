#include "card.hpp"
#include <iostream>
using namespace std;
using namespace ariel;
using std::cout;
using std::endl;

class TriumphCard : public Card {
    public:
        TriumphCard(TYPE_OF_CARDS t) : Card(t) {}
        void display() override  {
        cout<< "Triumph Card" << endl;  
    }
};

        
