//bookliat@gmail.com
#include "board.hpp"
#include "player.hpp"
#include "catan.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace ariel;
using std::string;
using std::vector;
using std::cout;
using std::endl;

int main(){
    Player p1("A");
    Player p2("B");
    Player p3("C");
    Catan game(p1,p2,p3);
    game.ChooseStartingPlayer();
   

    //first round 
    p1.place_init(22, 23, game.getBoard());
    p2.place_init(12, 13, game.getBoard());
    p3.place_init(15, 25, game.getBoard());
    p3.place_init(19, 20, game.getBoard());
    p2.place_init(32, 42, game.getBoard());
    p1.place_init(30, 29, game.getBoard());
    game.print_res_players();
    cout<<"finish first round!"<<endl<<endl<<endl;

     //second round
    game.rollDice();
    game.rollDice();
    game.rollDice();                                                                             
    game.print_res_players();
    cout<<"finish second round!"<<endl<<endl<<endl;

    //third round
    game.rollDice();
    game.rollDice();  
    p2.placeRoad(42, 43, game.getBoard());
    p2.buyDevelopmentCard(game.get_card());
    game.useDevelopmentCard(1,&p2);
    game.get_card()->display();
    cout<<"p2: "<<p2.get_points()<<endl;
    game.rollDice();
    p3.placeSettelemnt(19,game.getBoard());
    cout<<"finish third round!"<<endl<<endl<<endl;

    //fourth round
    game.rollDice();
    game.print_res_players();
    game.traid(&p1,&p3,3,0);
    game.traid(&p1,&p3,1,0);
    p1.placeRoad(23, 24, game.getBoard());
    p1.placeSettelemnt(24, game.getBoard());
    game.print_res_players();
    game.rollDice();
    game.print_res_players();
    game.rollDice();
    game.print_res_players();
    
    return 0;
    
}