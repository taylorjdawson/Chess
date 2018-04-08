/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include "RestrictedPiece.h"


/**
 * RestrictedPiece implementation
 */


/**
 * @param location
 * @param byPlayer
 * @return boolean
 */
bool RestrictedPiece::moveTo(Square &location, Player &byPlayer) {
  return false;
}

/**
 * @return boolean
 */
bool RestrictedPiece::hasMoved() {
  return _moved;
}

RestrictedPiece::RestrictedPiece(const string &color, Square *location)
    : Piece::Piece(color, location) {}
