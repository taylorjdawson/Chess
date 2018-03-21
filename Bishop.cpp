/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include "Bishop.h"
#define PIECE_SYMBOL ("B")

/**
 * Bishop implementation
 */

Bishop::Bishop(const string &color,
               Square *location) : Piece(color, location) {}

/**
 * @return int
 */
int Bishop::getValue() {
  return 0;
}

/**
 * @param location
 * @return boolean
 */
bool Bishop::canMoveTo(Square &location) {
  return false;
}

string Bishop::getPieceSymbol() {
  return PIECE_SYMBOL;
}
