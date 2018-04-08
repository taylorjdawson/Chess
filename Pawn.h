/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _PAWN_H
#define _PAWN_H

#include "RestrictedPiece.h"

class Square;

/**
 * A Pawn object
 */
class Pawn : public RestrictedPiece {
 public:

  /**
   *
   * @param color
   * @param location
   */
  Pawn(const string &color, Square *location);

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

#endif //_PAWN_H