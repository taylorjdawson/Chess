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

  /*Determine if it is a rank/file move (Rook) */

  return false;
}

string Queen::getPieceSymbol() {
  return this->getColor() == Color::Black  ? "♛" : "♕";
}

Queen::Queen(Color color, Square *location) : Piece(color, location) {
//  rookDelegate = new Rook(color, location);
//  bishopDelegate = new Bishop
}
