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
     * @param location
     * @param byPlayer
     */
  bool moveTo(Square &location, Player &byPlayer);
 protected:
  RestrictedPiece(const string &color, Square *location);
  bool hasMoved();
 private:

  bool _moved = false;
};

#endif //_RESTRICTEDPIECE_H