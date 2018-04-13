/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _RESTRICTEDPIECE_H
#define _RESTRICTEDPIECE_H

#include "Square.h"
#include "Piece.h"

class Player;

class RestrictedPiece : public Piece {
 public:

  /**
   *
   * @param location
   * @param byPlayer
   * @return
   */
  bool moveTo(Square &location, Player &byPlayer);
 protected:

  /**
   *
   * @param color
   * @param location
   */
  RestrictedPiece(Color color, Square *location);

  /**
   *
   * @return
   */
  bool hasMoved();
 private:

  bool _moved = false;
};

#endif //_RESTRICTEDPIECE_H