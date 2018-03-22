/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _SQUARE_H
#define _SQUARE_H

#include "Piece.h"

class Piece;

class Square {
 public:

  Square(int _rank, int _file);
  Square();

  int getRank();

  int getFile();

  bool isOccupied();

  Piece *getOccupant();

  void setOccupant(Piece *occupant);

  bool operator==(const Square &square) const;
 private:
  int _rank;
  int _file;
  Piece *_occupant;
};

#endif //_SQUARE_H