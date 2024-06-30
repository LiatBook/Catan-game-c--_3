//bookliat@gmail.com
#include <string>
#include <iostream>
#include "catan.hpp"
#include "player.hpp"
#include <vector>
#include <cstdlib>
using std::string;
using std::cout;
using std::endl;
using namespace ariel;

    
    void Catan::ChooseStartingPlayer(){
        cout<<players[0]->get_name()<<" starting:)"<<endl;
    }
    void Catan::printWinner(){
    if(players[0]->get_points()==10){
            cout<<players[0]->get_name()<<"is winner";
    }
    else if(players[1]->get_points()==10){
        cout<<players[1]->get_name()<<"is winner";
    }
    else if(players[2]->get_points()==10){
        cout<<players[2]->get_name()<<"is winner";
    }
    else{
        cout<<"No winner yet";
    }
    }
    Board& Catan::getBoard(){
       return catan_board;
    }
     bool operator==(const pair<ResourceType, int>& p1, int x){
                    return p1.second==x;
                }
   
     void Catan::rollDice(){
   
        int dice=rand()%11+2;

        // std::cout<<"ad matai "<<catan_board.board[22][22] ;
        if(dice==7){
            cout<<"~~~~~~~~~~You rolled 7~~~~~~~~~~"<<endl;
            int cards=0;
            for(int i=0;i<3;i++){
                cards=0;
                for(int j=0;j<5;j++){
                    cards+=get_players()[i]->get_resources()[j];
                }
                if(cards>7){
                    int sum=0;
                    cout<<get_players()[i]->get_name()<<"must discard half of his resources"<<endl;
                    cout<<"Please enter the resources you want to discard. number of wood and after"
                    <<" brick,sheep,wheat,ore and between click enter."
                    <<" you must the sum will be half from your number of cards now,"
                    <<"put attention you choose number resources <=from the number resources that you have in this type"<<endl;
                    for(int r=0;r<5;r++){
                         std::cin>>sum;
                         get_players()[i]->get_resources()[r]-=sum;
                         
                    }
                }
            }
        }
        else{
            // std::cout<<"ad matai2 "<<catan_board.get_board()[22][22] <<endl;
            cout<<"~~~~~~~~~~You rolled "<<dice<<"~~~~~~~~~~"<<endl;
            vector<int> places=get_players()[2]->get_places();
            for(size_t i=0;i<places.size();i++){
                for(int j=0;j<3;j++){
                    if(catan_board.get__board()[places[i]][j]==dice){
                    int x=catan_board.get__board()[places[i]][j].first;
                    string s="";

                     switch (x) {
                         case 0: s="WOOD";
                            break; 
                        case 1: s="BRICK";
                            break;
                        case 2: s="SHEEP";
                            break;
                        case 3: s="WHEAT";
                            break;
                        case 4: s="ORE";
                            break;
                        default:
                            break;
                     }

                        if(catan_board.get_board()[places[i]][places[i]]==PLAYER_1){
                             get_players()[0]->set_resources(x,1);
                             cout<<get_players()[0]->get_name()<<" received "<<s<<endl;
                        }

                         else if(catan_board.get_board()[places[i]][places[i]]==PLAYER_1+1){
                            get_players()[0]->set_resources(x,2);
                            cout<<get_players()[0]->get_name()<<" received "<<s<<"twice"<<endl;
                        }
                        else if(catan_board.get_board()[places[i]][places[i]]==PLAYER_2){
                             get_players()[1]->set_resources(x,1);
                            cout<<get_players()[1]->get_name()<<" received "<<s<<endl;
                        }
                         else if(catan_board.get_board()[places[i]][places[i]]==PLAYER_2+1){
                            get_players()[1]->set_resources(x,2);
                            cout<<get_players()[1]->get_name()<<" received "<<s<<"twice"<<endl;
                        }
                        else if(catan_board.board[places[i]][places[i]]==PLAYER_3){
                             get_players()[2]->set_resources(x,1);
                             cout<<get_players()[2]->get_name()<<" received "<<s<<endl;
                        }
                         else if(catan_board.get_board()[places[i]][places[i]]==PLAYER_3+1){
                            get_players()[2]->set_resources(x,2);
                            cout<<get_players()[2]->get_name()<<" received "<<s<<"twice"<<endl;
                        }
                }
               
            }
            }
            }
          
    }
    void Catan::useDevelopmentCard(int x,Player* p){
        if(x<0 || x>4){
            throw runtime_error("choose a real card");
        }
        if(p->get_development_cards()[x]==0){
           throw runtime_error("you dont have this card"); 
        }
        
        switch (x) {
        case 0:{
            if(p->get_development_cards()[x]==3){
                p->set_points(2);
                p->set_development_cards(0,-2);
                // AbundanceCard a;
                // a.display();
                // cards.display();
            }
            else{throw runtime_error("you dont KNIGHT 3 yet "); }
        }
            break;
        case 1:
            p->set_points(1);
            // TriumphCard* t=new TriumphCard(TRIUMPH);  
            // t->display();
            // delete t;
            break;
        case 2:{
            int min=0;
            for(int i=0;i<5;i++){
                if(p->get_resources()[min]>p->get_resources()[i]){
                    min=i;
                }
            }
            for(int i=0;i<3;i++){
                if(players[i]->get_id() != p->get_id()){
                    int how_much=players[i]->get_resources()[min];
                    p->set_resources(min,how_much);
                    players[i]->set_resources(min,-how_much);
                }

            }
        }
           break; 
        case 3:{
            int res1=rand()%5;
            int res2=rand()%5;
            p->set_resources(res1,1);
            p->set_resources(res2,1);
        }
            break;
        case 4:{
            p->set_resources(WOOD,2);
            p->set_resources(BRICK,2);
        }
            break;
        default:
            break;
        
    }
    p->set_development_cards(x,-1);
    }

    void Catan::traid(Player* p1,Player* p2,int res_p1,int res_p2){
        if(res_p1<0 || res_p1>4 ||res_p2<0 || res_p2>4 ){
            throw runtime_error("this not a real card");
        }
        if(p1->get_resources()[res_p1]<1 || p2->get_resources()[res_p2]<1 ){
            throw runtime_error("you dont have enough cards");   
        }
        p1->set_resources(res_p1,-1);
        p2->set_resources(res_p2,-1);
        p1->set_resources(res_p2,1);
        p2->set_resources(res_p1,1);
    }

    void Catan::print_res_players(){
    cout<<endl;
    cout<<"THE RESOURCES CURRENTLY:"<<endl; 
    cout<<"A:"<<endl;
    cout<< "WOOD: " <<players[0]->get_resources()[0]<<endl;
    cout<< "BRICK: "<<players[0]->get_resources()[1]<<endl;
    cout<< "SHEEP: "<<players[0]->get_resources()[2]<<endl;
    cout<< "WHEAT: "<<players[0]->get_resources()[3]<<endl;
    cout<< "ORE: "<<players[0]->get_resources()[4]<<endl;
    cout<< "B:" <<endl;
    cout<< "WOOD: "<<players[1]->get_resources()[0]<<endl;
    cout<< "BRICK: "<<players[1]->get_resources()[1]<<endl;
    cout<< "SHEEP: "<<players[1]->get_resources()[2]<<endl;
    cout<< "WHEAT: "<<players[1]->get_resources()[3]<<endl;
    cout<< "ORE: "<<players[1]->get_resources()[4]<<endl;
    cout<< "C:"<<endl;
    cout<< "WOOD: " <<players[2]->get_resources()[0]<<endl;
    cout<< "BRICK: "<<players[2]->get_resources()[1]<<endl;
    cout<< "SHEEP: "<<players[2]->get_resources()[2]<<endl;
    cout<< "WHEAT: "<<players[2]->get_resources()[3]<<endl;
    cout<< "ORE: "<<players[2]->get_resources()[4]<<endl;
    }