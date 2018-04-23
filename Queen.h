/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _QUEEN_H
#define _QUEEN_H

#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"

class Queen : public Piece {
 public:

  Queen(Color color, Square *location);
  int getValue() override;

  /**
   * @param location
   */
  bool canMoveTo(Square &location) override;
  string getPieceSymbol();
 private:
  Piece *rookDelegate;
  Piece *bishopDelegate;
};

#endif //_QUEEN_H