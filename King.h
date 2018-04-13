/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _KING_H
#define _KING_H

#include "RestrictedPiece.h"

class Square;

class King : public RestrictedPiece {
 public:

  /**
   *
   * @param color
   * @param location
   */
  King(Color color, Square *location);

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

#endif //_KING_H