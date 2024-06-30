
//bookliat@gmail.com
#include "doctest.h"
 #include "board.hpp"
#include "player.hpp"
#include "catan.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace ariel;
using std::string;
using std::vector;
using std::cout;
using std::endl;

//BOARD TEST
TEST_CASE("get__board") 
    {
        Board b;
        int x=b.get__board()[22][0].first==BRICK && b.get__board()[22][0].second==2;
        CHECK(x);
        x=b.get__board()[22][0].first==WOOD && b.get__board()[22][0].second==2;
        CHECK_FALSE(x);
        x=b.get__board()[22][0].first==BRICK && b.get__board()[22][0].second==3;
        CHECK_FALSE(x);
        x=b.get__board()[42][2].first==SHEEP && b.get__board()[42][2].second==12;
        CHECK(x);
        x=b.get__board()[42][2].first==SHEEP && b.get__board()[42][2].second==13;
        CHECK_FALSE(x);
    }
TEST_CASE("set_board, get_board") 
    {
        Board b;
        b.set_board(22, 23, 2);
        CHECK(b.get_board()[22][23]==2);
        CHECK_FALSE(b.get_board()[22][23]==3);
        b.set_board(22, 23, 3);
        CHECK(b.get_board()[22][23]==3);
        CHECK_THROWS(b.set_board(54, 23, 3));
    }
TEST_CASE("initializeBoard") 
    {
        Board b;
        int x=b.get__board()[22][0].first==BRICK && b.get__board()[22][0].second==2;
        CHECK(x);
        x=b.get__board()[22][0].first==WOOD && b.get__board()[22][0].second==2;
        CHECK_FALSE(x);
        x=b.get__board()[22][0].first==BRICK && b.get__board()[22][0].second==3;
        CHECK_FALSE(x);
        x=b.get__board()[42][2].first==SHEEP && b.get__board()[42][2].second==12;
        CHECK(x);
        x=b.get__board()[42][2].first==SHEEP && b.get__board()[42][2].second==13;
        CHECK_FALSE(x);
    }

//PLAYER TEST
TEST_CASE("get_name") 
    {
        Player p("A");
        CHECK(p.get_name()=="A");
        CHECK_FALSE(p.get_name()=="B");
        Player p2("A");
        CHECK(p.get_name()==p2.get_name());
    }
TEST_CASE("get_points") 
    {
        Player p("A");
        CHECK(p.get_points()==0);
        CHECK_FALSE(p.get_points()==1);
    }
TEST_CASE("set_points") 
    {
        Player p("A");
        p.set_points(2);
        CHECK(p.get_points()==2);
        CHECK_FALSE(p.get_points()==0);
        p.set_points(2);
        CHECK_FALSE(p.get_points()==2);
        CHECK(p.get_points()==4);
    }
TEST_CASE("set_resources") 
    {
        Player p("A");
        p.set_resources(1, 2);
        CHECK(p.get_resources()[1]==2);
        CHECK_FALSE(p.get_resources()[1]==0);
        p.set_resources(1, 0);
        CHECK(p.get_resources()[1]==2);
        CHECK_FALSE(p.get_resources()[1]==0);
    }
TEST_CASE("get_resources") 
    {
        Player p("A");
        CHECK(p.get_resources()[1]==0);
        CHECK_FALSE(p.get_resources()[1]==2);
    }
TEST_CASE("buyDevelopmentCard") 
    {
        Player p1("A");
        Player p2("B");
        Player p3("C");
        Catan game(p1, p2, p3);
        p1.set_resources(1,1) ;
        p1.set_resources(2,1) ;
        p1.set_resources(3,1) ;
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        p1.buyDevelopmentCard(game.get_card());
        std::string buf_data = newBuffer.str();
        CHECK(buf_data=="You buy development card\n");
        cout.rdbuf(originalBuffer);
        newBuffer.str("");  
    }
TEST_CASE("place_init- build settelemnt on the board") 
    {
        Player p("A");
        Board b;
        p.place_init(22, 23, b);
        CHECK(b.get_board()[22][23]==100);
        CHECK(b.get_board()[22][22]==100);
        CHECK_FALSE(b.get_board()[23][23]==100);
        CHECK_FALSE(b.get_board()[22][23]==200);
        CHECK_FALSE(b.get_board()[22][23]==300);
    }
TEST_CASE("place_init- try build city on the board") 
    {
        Player p("A");
        Board b;
        p.place_init(22, 23, b);
        CHECK(b.get_board()[22][23]==100);
        CHECK(b.get_board()[22][22]==100);
        p.place_init(22, 23, b);
        CHECK(b.get_board()[22][23]==100);
        CHECK(b.get_board()[22][22]==100);
        
    }
TEST_CASE("place_init- two player try build on same place") 
    {
        Player p("A");
        Board b;
        p.place_init(22, 23, b);
        CHECK(b.get_board()[22][23]==100);
        CHECK_FALSE(b.get_board()[22][23]==200);
        CHECK_FALSE(b.get_board()[22][23]==300);
        Player p2("B");
        p2.place_init(22, 23, b);
        CHECK(b.get_board()[22][23]==100);
        CHECK_FALSE(b.get_board()[22][23]==200);
    }
TEST_CASE("placeSettelemnt-build settelemnt without enough resources") 
    {
        Player p("A");
        Board b;
        p.place_init(11, 21, b);
        p.set_resources(0,1);
        p.set_resources(1,1);
        p.placeRoad(21,22,b);
        p.placeSettelemnt(22, b);
        CHECK_FALSE(b.get_board()[22][22]==100);
        CHECK_FALSE(b.get_board()[22][22]==200);
        CHECK_FALSE(b.get_board()[22][22]==300);
    }
TEST_CASE("placeSettelemnt-try build city when player no have resources") 
    {
        Player p("A");
        Board b;
        p.place_init(11, 21, b);
        p.placeSettelemnt(11, b);
        CHECK_FALSE(b.get_board()[11][11]==101);
        p.set_resources(3, 2);
        p.set_resources(4, 3);
        p.placeSettelemnt(11, b);
        CHECK(b.get_board()[11][11]==101);
    }
TEST_CASE("placeSettelemnt-build settelemnt when player can build settelemnt")
    {
        Player p("A");
        Board b;
        p.place_init(11, 21, b);
        p.set_resources(0,1);
        p.set_resources(1,1);
        p.placeRoad(21,22,b);
        p.set_resources(0,1);
        p.set_resources(1,1);
        p.set_resources(2,1);
        p.set_resources(3,1);
        p.placeSettelemnt(22, b);
        CHECK(b.get_board()[22][22]==100);
        CHECK_FALSE(b.get_board()[22][22]==101);
    }
TEST_CASE("placeSettelemnt-build city when player can build city")
    {
        Player p("A");
        Board b;
        p.place_init(11, 21, b);
        p.set_resources(3, 2);
        p.set_resources(4, 3);
        p.placeSettelemnt(11, b);
        CHECK(b.get_board()[11][11]==101);
        CHECK_FALSE(b.get_board()[11][11]==100);
        CHECK_FALSE(b.get_board()[11][11]==200);
        Player p2("B");
        p2.set_resources(0,1);
        p2.set_resources(1,1);
        p2.set_resources(2,1);
        p2.set_resources(3,1);
        p2.placeSettelemnt(11, b);
        CHECK(b.get_board()[11][11]==101);
        CHECK_FALSE(b.get_board()[11][11]==200);
    }
TEST_CASE("placeSettelemnt-build city when player cant build (not have settelemnt in the place)")
    {
        Player p("A");
        Board b;
        p.set_resources(3, 2);
        p.set_resources(4, 3);
        p.placeSettelemnt(22, b);
        CHECK_FALSE(b.get_board()[22][22]==101);
        CHECK_FALSE(b.get_board()[22][22]==102);
    }
TEST_CASE("placeRoad- build road near another road that belongs to you")
    {
        Player p("A");
        Board b;
        p.place_init(11, 21, b);
        p.set_resources(0,1);
        p.set_resources(1,1);
        p.placeRoad(21,22,b);
        CHECK(b.get_board()[21][22]==100);
        CHECK_FALSE(b.get_board()[21][22]==200);
        CHECK_FALSE(b.get_board()[21][22]==300);
    }
    TEST_CASE("placeRoad- build road near settelment that belongs to you")
    {
        Player p("A");
        Board b;
        p.place_init(11, 21, b);
        p.set_resources(0,1);
        p.set_resources(1,1);
        p.placeRoad(10,11,b);
        CHECK(b.get_board()[10][11]==100);
        CHECK_FALSE(b.get_board()[10][11]==200);
        CHECK_FALSE(b.get_board()[10][11]==300);
    }
    TEST_CASE("placeRoad- try build road when no have settelment\road near.")
    {
        Player p("A");
        Board b;
        p.set_resources(0,1);
        p.set_resources(1,1);
        p.placeRoad(10,11,b);
        CHECK_FALSE(b.get_board()[10][11]==100);
        CHECK_FALSE(b.get_board()[10][11]==200);
        CHECK_FALSE(b.get_board()[10][11]==300);
    }
    TEST_CASE("placeRoad- build road near another road that belongs to another player")
    {
        Player p("A");
        Board b;
        p.place_init(11, 10, b);
        Player p2("B");
        p2.place_init(21, 11, b);
        CHECK_FALSE(b.get_board()[11][21]==100);
        CHECK_FALSE(b.get_board()[11][21]==200);
        CHECK(b.get_board()[10][11]==100);
    }
    TEST_CASE("placeRoad- build road near another road that belongs to you and another player")
    {
        Player p("A");
        Board b;
        p.place_init(11, 21, b);
        p.set_resources(0,1);
        p.set_resources(1,1);
        p.placeRoad(21,22,b);
        CHECK(b.get_board()[21][22]==100);
        CHECK_FALSE(b.get_board()[21][22]==200);
        CHECK_FALSE(b.get_board()[21][22]==300);
        Player p2("B");
        p2.place_init(21, 11, b);
        CHECK(b.get_board()[11][21]==100);
        CHECK_FALSE(b.get_board()[21][11]==100);
        CHECK_FALSE(b.get_board()[21][11]==200);
        CHECK_FALSE(b.get_board()[21][11]==300);
    }

    TEST_CASE("get_places") 
    {
        Player p("A");
        Board b;
        CHECK(p.get_places().size()==0);
        CHECK_FALSE(p.get_places().size()==1);
        p.place_init(49, 50, b);
        CHECK(p.get_places().size()==1);
        CHECK_FALSE(p.get_places().size()==0);
        Player p2("B");
        CHECK(p.get_places().size()==1);
        CHECK_FALSE(p.get_places().size()==0);

    }
    TEST_CASE("set/get_development_cards") 
    {
        Player p("A");
        p.set_development_cards(1, 2);
        CHECK(p.get_development_cards()[1]==2);
        CHECK_FALSE(p.get_development_cards()[1]==0);
        p.set_development_cards(1, 0);
        CHECK(p.get_development_cards()[1]==2);
        CHECK_FALSE(p.get_development_cards()[1]==0);
    }
    TEST_CASE("printPoints") 
    {
        Player p("A");
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        p.printPoints();
        std::string buf_data = newBuffer.str();
        CHECK(buf_data=="A: 0\n");
        cout.rdbuf(originalBuffer);
        newBuffer.str("");  
    }

    //CARD TEST
    TEST_CASE("gettype") 
    {
        Player p("A");
        Card* c=new TriumphCard(TRIUMPH);
        CHECK(c->gettype()==TRIUMPH);
        CHECK_FALSE(c->gettype()==KNIGHT);
        CHECK_FALSE(c->gettype()==MONOPOL);
        CHECK_FALSE(c->gettype()==ABUNDANCE);
        CHECK_FALSE(c->gettype()==ROAD_CONSTRUCTION);
        CHECK_FALSE(c->gettype()==0);
        Player p2("B");
        Card* c2=new KnightCard(KNIGHT);
        CHECK(c2->gettype()==KNIGHT);
        CHECK(c2->gettype()==0);
    }
    TEST_CASE("display") 
    {
        Player p("A");
        Card* c=new TriumphCard(TRIUMPH);
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        c->display();
        std::string buf_data = newBuffer.str();
        CHECK(buf_data=="Triumph\n");
        cout.rdbuf(originalBuffer);
        newBuffer.str("");  
    }

    //CATAN TEST
    TEST_CASE("get_players") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        vector<Player*> v=game.get_players();
        CHECK(v[0]->get_name()=="A");
        CHECK(v[1]->get_name()=="B");
        CHECK(v[2]->get_name()=="C");
        CHECK_FALSE(v[0]->get_name()=="B");
        CHECK_FALSE(v[1]->get_name()=="C");
        CHECK_FALSE(v[2]->get_name()=="A");
    }
    TEST_CASE("get_card") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        Card* c=game.get_card();
        CHECK(c->gettype()==TRIUMPH);
        CHECK_FALSE(c->gettype()==KNIGHT);
        CHECK_FALSE(c->gettype()==MONOPOL);
        CHECK_FALSE(c->gettype()==ABUNDANCE);
        CHECK_FALSE(c->gettype()==ROAD_CONSTRUCTION);
        CHECK_FALSE(c->gettype()==0);
    }
    TEST_CASE("ChooseStartingPlayer") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        game.ChooseStartingPlayer();
        std::string buf_data = newBuffer.str();
        CHECK(buf_data== p.get_name());
        cout.rdbuf(originalBuffer);
        newBuffer.str("");   
    }
    TEST_CASE("printWinner- no one won") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        game.printWinner();
        std::string buf_data = newBuffer.str();
        CHECK(buf_data=="The winner is: ");
        cout.rdbuf(originalBuffer);
        newBuffer.str("");   
    }
    TEST_CASE("printWinner- A won") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        p.set_points(10);
        Catan game(p, p2, p3);
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        game.printWinner();
        std::string buf_data = newBuffer.str();
        CHECK(buf_data=="The winner is: A");
        cout.rdbuf(originalBuffer);
        newBuffer.str("");   
    }
    TEST_CASE("print_res_players") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        game.print_res_players();
        std::string buf_data = newBuffer.str();
        CHECK(buf_data=="THE RESOURCES CURRENTLY:\n");
        CHECK(buf_data=="A:\n");
        CHECK(buf_data=="WOOD: 0\n");
        CHECK_FALSE(buf_data=="BRICK: 1\n");
        cout.rdbuf(originalBuffer);
        newBuffer.str("");   
    }
    TEST_CASE("traid- traid with invalid card") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        CHECK_THROWS(game.traid(&p, &p2, 6, 0));
        CHECK_THROWS(game.traid(&p, &p2, -4, 5));
        CHECK_THROWS(game.traid(&p, &p2, 8, 8));
    }
    TEST_CASE("traid- traid with valid card") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        p.set_resources(0,1);
        p2.set_resources(1,1);
        game.traid(&p, &p2, 0, 1);
        CHECK(p.get_resources()[0]==0);
        CHECK(p2.get_resources()[0]==1);
        CHECK(p.get_resources()[1]==1);
        CHECK(p2.get_resources()[1]==0);
    }
    TEST_CASE("traid- traid with non cards") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        CHECK_THROWS(game.traid(&p, &p2, 0, 1));
        CHECK_THROWS(game.traid(&p, &p2, 1, 0));
        CHECK_THROWS(game.traid(&p, &p2, 0, 0));
    }
    TEST_CASE("useDevelopmentCard- use development card with invalid card") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        CHECK_THROWS(game.useDevelopmentCard(6, &p));
        CHECK_THROWS(game.useDevelopmentCard(-4, &p));
        CHECK_THROWS(game.useDevelopmentCard(8, &p));
    }
    TEST_CASE("useDevelopmentCard- use KNIGHT when no have 3 to player") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        p.set_development_cards(0,1);
        CHECK_THROWS(game.useDevelopmentCard(0, &p));
        CHECK(p.get_development_cards()[0]==1);
    }
    TEST_CASE("useDevelopmentCard- use KNIGHT when have 3 to player") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        p.set_development_cards(0,3);
        game.useDevelopmentCard(0, &p);
        CHECK(p.get_development_cards()[0]==0);
        CHECK(p.get_points()==2);
    }
    TEST_CASE("useDevelopmentCard- use MONOPOL when no have 3 to player") 
    {
        Player p("A");
        Player p2("B");
        Player p3("C");
        Catan game(p, p2, p3);
        p.set_development_cards(0,1);
        CHECK_THROWS(game.useDevelopmentCard(0, &p));
        CHECK(p.get_development_cards()[0]==1);
        CHECK_FALSE(p.get_development_cards()[1]==1);
        p.set_development_cards(1,1);
        CHECK(p.get_development_cards()[1]==1);
        CHECK(p.get_development_cards()[0]==1);
    }







