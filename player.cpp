//bookliat@gmail.com
#include <string>
#include <iostream>
#include "board.hpp"
#include "player.hpp"
static int i=100;
using std::string;
using std::endl;
using std::cout;
using namespace ariel;


    Player::Player(const string& name){
        this->name=name;
        this->id=i;
        this->points=0;
        i+=100;
        this->resources.resize(6,0);  
        this->development_cards.resize(5,0);
    }

    string Player::get_name() const{
        return name;
    }
    
    void Player::place_init(int ver,int edge,Board& board){
        int what_player_rec=0;;
        if(ver==edge){
            cout<<"this isn't road, it is one vertex"<<endl;
            return;
        }
        
        if(board.get_board()[ver][ver]!=0){
            cout<<"Your vertex already taken"<<endl;
            return;
        }
        
        for(int i=0;i<54;i++){
            
            if(board.get_board()[ver][i]==1 || board.get_board()[i][ver]==1){
                
                if(board.get_board()[i][i]!=0){
                    
                    cout<<"Your neighbor vertex already taken"<<endl;
                    return;
                }
                
                if(board.get_board()[ver][edge]==1 || board.get_board()[edge][ver]==1){
                    
                     points++;
                     places.push_back(ver);
                     board.set_board(ver,ver,get_id());
                     board.set_board(std::min(ver,edge),std::max(ver,edge),get_id());
                    for(int j=0;j<3;j++){
                        int s=places.size()-1;    
                            what_player_rec=(board.get__board()[places[s]][j]).first;
                            set_resources(what_player_rec,1);
                            if(board.get__board()[places[s]][j].first!=5){
                                cout<<name<<" received "<<board.get__board()[places[s]][j].first<<endl;
                            }
                    }

                     cout<<"You build neighbor and road:)"<<endl;
                     return;
                     }
                                
                                
                        
                
        }
       }
                cout<<"You don't build neighbor,error"<<endl;
    }
        
    void Player::placeSettelemnt(int ver,Board& board){
        if(board.get_board()[ver][ver]==get_id()){
            if(resources[ORE]>=3 && resources[WHEAT]>=2){
                board.set_board(ver,ver,get_id()+1);
                resources[WHEAT]-=2;
                resources[ORE]-=3;
                points++;
                cout<<"You build city"<<endl;
                return;
             }
            else{
                 cout<<"You don't have enough resources"<<endl;
                 return;
             }
        }
        if(board.get_board()[ver][ver]!=0){
            cout<<"Your vertex already taken"<<endl;
            return;
        }
        for(int i=0;i<54;i++){
            if(board.get_board()[ver][i]==1 || board.get_board()[i][ver]==1){
                if(board.get_board()[i][i]!=0){
                    cout<<"Your neighbor vertex already taken"<<endl;
                    return;
                }
            }
            if(board.get_board()[ver][i]==get_id() || board.get_board()[i][ver]==get_id()){
                for(int j=0;j<54;j++){
                    if((board.get_board()[j][i]==get_id() && j!=ver)|| (board.get_board()[i][j]==get_id() && j!=ver)){
                        
                             if(resources[WOOD]>=1 && resources[BRICK]>=1 && resources[SHEEP]>=1 && resources[WHEAT]>=1){
                                board.set_board(ver,ver,get_id());
                                resources[WOOD]--;
                                resources[BRICK]--;
                                resources[SHEEP]--;
                                resources[WHEAT]--;
                                points++;
                                places.push_back(ver);
                                cout<<"You build neighbor"<<endl;
                                return;
                                }
                                else{
                                    cout<<"You don't have enough resources"<<endl;
                                    return;
                                    }
                                
                        
                            }
                    
                }
            
        }
        }
        cout<<"You can't build"<<endl;
    }
    
    void Player:: placeRoad(int ver_1,int ver_2, Board& board){
        if(resources[WOOD]>=1 && resources[BRICK]>=1){
            if(ver_1==ver_2){
                cout<<"this isn't road, it is one vertex"<<endl;
                return;
            }
            if(ver_1>ver_2){
                int temp=ver_1;
                ver_1=ver_2;
                ver_2=temp;
            }

            if(board.get_board()[ver_1][ver_2]!=1){
                 cout<<"this road is already taken"<<endl;
                return;
            }
            else if(board.get_board()[ver_1][ver_1]==get_id() ||board.get_board()[ver_2][ver_2]==get_id() ||
                    board.get_board()[ver_1][ver_1]==get_id()+1 ||board.get_board()[ver_2][ver_2]==get_id() +1)
                 {
                    board.set_board(ver_1,ver_2,get_id());
                    resources[WOOD]--;
                    resources[BRICK]--;
                    cout<<"Your road build successful"<<endl;
                    return;
                 }
                else{
                    int flag=0;
                    for(int i=0;i<54;i++){
                        if(board.get_board()[ver_1][i]==get_id() || board.get_board()[ver_2][i]==get_id() ||
                            board.get_board()[i][ver_1]==get_id() || board.get_board()[i][ver_2]==get_id() ){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        cout<<"this road isn't connection for your build"<<endl;
                        return;
                    }
                    board.set_board(ver_1,ver_2,get_id());
                    resources[WOOD]--;
                    resources[BRICK]--;
                    cout<<"Your road build successful"<<endl;
                }
        
        }
        else{
            cout<<"You don't have enough resources"<<endl;
            return;
        }
    }
          
    void Player::printPoints(){
        cout<<points<<endl;
    }
    
    
    void Player::buyDevelopmentCard(Card* card){
        if(resources[ORE]>=1 && resources[SHEEP]>=1 && resources[WHEAT]>=1){
            resources[ORE]--;
            resources[SHEEP]--;
            resources[WHEAT]--;
            cout<<"You buy development card"<<endl;
            if(card->gettype()==KNIGHT){
                development_cards[0]+=1;
            }
            if(card->gettype()==TRIUMPH){
                development_cards[1]+=1;
            }
            if(card->gettype()==MONOPOL){
                development_cards[2]+=1;
            }
            if(card->gettype()==ABUNDANCE){
                development_cards[3]+=1;
            }
            if(card->gettype()==ROAD_CONSTRUCTION){
                development_cards[4]+=1;
            }
    
        }
  
        else{
            cout<<"You don't have enough resources"<<endl;
        }
    }
    int Player::get_points()const
    {
        return points;
    }
    void Player::set_points(int p){
        points+=p;
    }
     int Player::get_id(){
        return id;
    }
     vector<int>& Player::get_resources(){
        return resources;
     }

    
    void Player::set_resources(int what_add,int how_much){
        resources[what_add]+=how_much;
    }
     vector<int>& Player::get_places(){
        return places;
    }
    
    void Player::set_development_cards(int what_change,int how_much){
        development_cards[what_change]+=how_much;
    }
    vector<int> & Player::get_development_cards(){
        return development_cards;
    }
    Player::~Player(){
        i=100;
        places.clear();


    }