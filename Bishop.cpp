/**
 * Project Chess
 * @author Taylor J. Dawson
 */

#include "Bishop.h"

/**
 * Bishop implementation
 */
Bishop::Bishop(Color color, Square *location) : Piece(color, location) {}

int Bishop::getValue() {
  return 0;
}

bool Bishop::canMoveTo(Square &location) {
  return false;
}

string Bishop::getPieceSymbol() {
  return this->getColor() == Color::Black ? "♝" : "♗";
}
