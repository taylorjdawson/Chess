/**
 * Project Chess
 * @author Taylor J. Dawson
 */
#include "Rook.h"
#define ROOK_BLACK ("♜")
#define ROOK_WHITE ("♖")

/**
 * Rook implementation
 */

int Rook::getValue() {
  return 0;
}

bool Rook::canMoveTo(Square &location) {
  return false;
}

string Rook::getPieceSymbol() {
  return this->getColor() == Color::Black ? ROOK_BLACK : ROOK_WHITE;
}

Rook::Rook(Color color, Square *location) : RestrictedPiece(color, location) {}
