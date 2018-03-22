/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include "Rook.h"
#define PIECE_SYMBOL ("R")

/**
 * Rook implementation
 */


/**
 * @return int
 */
int Rook::getValue() {
  return 0;
}

/**
 * @param location
 * @return boolean
 */
bool Rook::canMoveTo(Square &location) {
  return false;
}

string Rook::getPieceSymbol() {
  return PIECE_SYMBOL;
}
Rook::Rook(const string &color, Square *location) : RestrictedPiece(color,
                                                                    location) {}
