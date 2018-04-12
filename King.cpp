/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include "King.h"
#define PIECE_SYMBOL ("K")

/**
 * King implementation
 */


/**
 * @return int
 */
int King::getValue() {
  return 0;
}

/**
 * @param location
 * @return boolean
 */
bool King::canMoveTo(Square &location) {
  return false;
}

string King::getPieceSymbol() {
  return this->getColor() == "B" ? "♚" : "♔";
}

King::King(const string &color, Square *location) : RestrictedPiece(color,
                                                                    location) {}