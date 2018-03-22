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

Queen::Queen(const string &color, Square *location) : Piece(color,
                                                            location) {}
string Queen::getPieceSymbol() {
  return PIECE_SYMBOL;
}