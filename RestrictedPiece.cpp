/**
 * Project Chess
 * @author Taylor J. Dawson
 */

#include "RestrictedPiece.h"

/**
 * RestrictedPiece implementation
 */

bool RestrictedPiece::moveTo(Square &location, Player &byPlayer) {
  return false;
}

bool RestrictedPiece::hasMoved() {
  return false;
}

RestrictedPiece::RestrictedPiece(Color color, Square *location)
    : Piece::Piece(color, location) {}
