
//bookliat@gmail.com
#include <string>
#include <vector>
#include <iostream>
#include "board.hpp"
#include "card.hpp"
#pragma once
using std::string;
using std::vector;
 enum PlayerType{
        PLAYER_1=100,
        PLAYER_2=200,
        PLAYER_3=300
    };
namespace ariel{
static vector<int> places;
class Player{
    
    private:
    string name;
    int points;
    int id;
    vector<int> resources;
    vector<int> development_cards;
    
    
    public:
    int get_id();
    vector<int> & get_resources();
    int get_points()const;
    void set_points(int p);
    Player(const string& name);
    ~Player();
    void place_init(int ver,int edge,Board& board);
    void placeSettelemnt(int ver,Board& board);
    void placeRoad(int ver_1,int ver_2, Board& board);
    string get_name()const;
    void set_resources(int what_add,int how_much);
    void set_development_cards(int what_change,int how_much);
    vector<int> & get_development_cards();
    static vector<int>& get_places();
    void endTurn();
    void printPoints();
    void buyDevelopmentCard(Card* card);
};
}