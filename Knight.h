/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
 public:

  /**
   *
   * @param color
   * @param location
   */
  Knight(Color color, Square *location);

  /**
   *
   * @return
   */
  int getValue() override;

  /**
   * @param location
   */
  bool canMoveTo(Square &location) override;

  /**
   *
   * @return
   */
  string getPieceSymbol() override;
};

#endif //_KNIGHT_H