/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <vector>
#include <set>
#include "Board.h"

class Piece;
class King;
using namespace std;

class Player {
 public:

  /**
   * Contructs a player object
   * @param _name
   * @param _king
   * @param _pieces
   */
  Player( Color color, const string &_name, King &_king, set<Piece *> &_pieces);

  /**
   *
   * @return
   */
  string getName();

  /**
   *
   * @return
   */
  King &getKing();

  /**
   *
   * @return
   */
  set<Piece *> &getPieces();

  /**
   * Prompts the player to make a move and returns true if the move was
   * successful.
   * @return true if the move was successful.
   */
  bool makeMove();

  /**
   * @param piece
   */
  void capture(Piece &piece);

  int calculateScore();
  void display(ostream &os);
  friend ostream& operator<<(ostream& os, Piece& piece);

 private:
  string _name;
  Color _color;
  King &_king;
  //TODO: Use hashset (unordered_set)
  set<Piece *> &_pieces;
  set<Piece *> _capturedPieces;
  Color getColor();
};

#endif //_PLAYER_H