/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _PAWN_H
#define _PAWN_H

#include "RestrictedPiece.h"

class Square;

class Pawn : public RestrictedPiece {
 public:
  Pawn(const string &color, Square *location);

  int getValue() override;

  /**
   * @param location
   */
  bool canMoveTo(Square &location) override;

  string getPieceSymbol() override;
};

#endif //_PAWN_H