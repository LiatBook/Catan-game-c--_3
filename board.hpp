//bookliat@gmail.com
#include <string>
#include <iostream>
#include <vector>
#pragma once
using std::string;
using std::pair;
using std::vector;
enum ResourceType {
    WOOD,
    BRICK,
    SHEEP,
    WHEAT,
    ORE,//rock
    DESERT
};
namespace ariel{
class Board{
    
    private:
    
    vector<vector<pair<ResourceType, int>>> _board;

    public:
    vector<vector<int>> board;
    Board(){
        board.resize(54);
        for(int i=0;i<54;i++){
            board[i].resize(54);
        }
        _board.resize(54);
        for(int i=0;i<54;i++){
            _board[i].resize(54);
        }
        initializeBoard(_board,board);
    }
    void initializeBoard (vector<vector<pair<ResourceType, int>>>& _board, vector<vector<int>>& board);
    // void printCatanBoard(const vector<vector<int>>& board);
    const vector<vector<int>>& get_board() const{
      return board;
    }
     void set_board(int ver_1,int ver_2,int x) {
        if(ver_1>53 || ver_2>53 || ver_1<0 || ver_2<0){
            throw std::runtime_error ("Its not real vertex");
            
        }
        board[ver_1][ver_2]=x;
    }
    const vector<vector<pair<ResourceType, int>>>& get__board() const{
        return _board;
    }
   
    

};
}