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

  King(const string &color, Square *location);

  int getValue() override;

  /**
   * @param location
   */
  bool canMoveTo(Square &location) override;
  string getPieceSymbol() override;
};

#endif //_KING_H