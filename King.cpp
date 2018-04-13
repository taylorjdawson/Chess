/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include "King.h"

/**
 * King implementation
 */


int King::getValue() {
  return 0;
}

bool King::canMoveTo(Square &location) {
  return false;
}

string King::getPieceSymbol() {
  return this->getColor() == Color::Black ? "♚" : "♔";
}

King::King(Color color, Square *location) : RestrictedPiece(color, location) {}