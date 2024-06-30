//bookliat@gmail.com
#include <string>
#include "player.hpp"
#include <iostream>
#include "card.hpp"
#include "TriumphCard.hpp"
#include "KnightCard.hpp"
#include "MonopolyCard.hpp"
#include "AbundanceCard.hpp"
#include "RoadConstructionCard.hpp"
#pragma once
static int i=0;
using std::string;
using std::vector;
namespace ariel{
class Catan{
    
    private:
    vector<Player*> players;
    Board catan_board;
    vector<Card*> cards;
    

    public:
    // Catan(const Player& p1,const Player& p2, const Player& p3);
    Catan( Player& p1,  Player& p2,  Player& p3){
        players.push_back(&p1);
        players.push_back(&p2);
        players.push_back(&p3);
        catan_board=Board();
        cards.push_back(new TriumphCard(TRIUMPH));
        cards.push_back(new MonopolyCard(MONOPOL));
        cards.push_back(new TriumphCard(TRIUMPH));
        cards.push_back(new TriumphCard(TRIUMPH));
        cards.push_back(new TriumphCard(TRIUMPH));
        cards.push_back(new KnightCard(KNIGHT));
        cards.push_back(new AbundanceCard(ABUNDANCE));
        cards.push_back(new KnightCard(KNIGHT));
        cards.push_back(new KnightCard(KNIGHT));
        cards.push_back(new RoadConstructionCard(ROAD_CONSTRUCTION));
        
    }
    void ChooseStartingPlayer();
    Board& getBoard();
    void printWinner();
    vector<Player*>& get_players(){
        return players;
     }
     Card* get_card(){
        return cards[i];
        i++;
     }
     void rollDice();
     void useDevelopmentCard(int x,Player* p);
     void traid(Player* p1,Player* p2,int res_p1,int res_p2);
     void print_res_players();
     ~Catan(){
        i=0;
     }

};
}