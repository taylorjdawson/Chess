/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _PLAYER_H
#define _PLAYER_H



#include <string>
#include <vector>
#include <set>


class Piece;
class King;
using namespace std;

class Player { // g++ -std=c++11 -Wall -g -Og
public: 
    
    /**
     * @param name
     * @param king
     * @param pieces
     */
  Player(const string &_name, King &_king, set<Piece *> &_pieces);

  string getName();
    
    King& getKing();
    
    set<Piece*>& getPieces();
    
    bool makeMove();
    
    /**
     * @param piece
     */
    void capture(Piece& piece);
    
    int calculateScore();
private: 
    string _name;
    King& _king;
    //TODO: Use hashset (unordered_set)
    set<Piece*>& _pieces;
    set<Piece *> _capturedPieces;
};

#endif //_PLAYER_H