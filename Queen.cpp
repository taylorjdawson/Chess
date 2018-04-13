/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include "Queen.h"
#define PIECE_SYMBOL ("Q")

/**
 * Queen implementation
 */


/**
 * @return int
 */
int Queen::getValue() {
  return 0;
}

/**
 * @param location
 * @return boolean
 */
bool Queen::canMoveTo(Square &location) {
  return false;
}

string Queen::getPieceSymbol() {
  return this->getColor() == Color::Black  ? "♛" : "♕";
}

Queen::Queen(Color color, Square *location) : Piece(color, location) {}
