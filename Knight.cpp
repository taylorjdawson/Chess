/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include "Knight.h"

/**
 * Knight implementation
 */
Knight::Knight(Color color, Square *location) : Piece(color, location) {}

int Knight::getValue() {
  return 0;
}

bool Knight::canMoveTo(Square &location) {
  return false;
}

string Knight::getPieceSymbol() {
  return this->getColor() == Color::Black ? "♞" : "♘";
}

