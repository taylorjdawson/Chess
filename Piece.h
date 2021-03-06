/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _PIECE_H
#define _PIECE_H

#include <ostream>
#include <string>
#include "Square.h"
#include "Color.h"

using namespace std;

class Player;
class Square;

class Piece {
 public:

  Piece(Color color, Square *location);

  Piece();

  virtual int getValue();

  Color getColor();

  /**
   * Returns the Square object of where the piece currently resides
   * @return the Square object of where the piece currently resides
   */
  Square *getLocation();

  /**
   * @param location
   */
  void setLocation(Square *location);

  /**
   *
   * @return
   */
  bool isOnSquare();

  /**
   * @param location
   */
  virtual bool canMoveTo(Square &location);

  /**
   * @param location
   * @param byPlayer
   */
  bool moveTo(Square &location, Player &byPlayer);

  /**
  * @param os
  */
  virtual void display(ostream &os); //TODO: maybe private

  friend ostream &operator<<(ostream &os, Piece &piece);

 private:
  Color _color;
  Square *_location;
  virtual string getPieceSymbol(); //TODO: Determine private or public? Only will be used in subclasses
  bool operator==(const Piece &piece) const {
    return (_color == piece._color && _location == piece._location);
  }
};

#endif //_PIECE_H