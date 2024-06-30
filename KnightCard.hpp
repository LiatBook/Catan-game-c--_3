//bookliat@gmail.com
#include "card.hpp"
#include <iostream>
using namespace std;
using namespace ariel;
using std::cout;
using std::endl;

class KnightCard : public Card {
    public:
        KnightCard(TYPE_OF_CARDS k) : Card(k) {}
        void display() override  {
        cout<< "Knight Card" << endl;  
    }
       
};
