/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _BISHOP_H
#define _BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
 public:

  Bishop(const string &color, Square *location);
  int getValue() override;

  /**
   * @param location
   */
  bool canMoveTo(Square &location) override;

  string getPieceSymbol() override;

 private:
  const string _piece;
};

#endif //_BISHOP_H