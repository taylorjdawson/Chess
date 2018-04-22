/**
 * Project Chess
 * @author Taylor J. Dawson
 */
#include "Rook.h"
#include "Board.h"
#define ROOK_BLACK ("♜")
#define ROOK_WHITE ("♖")

/**
 * Rook implementation
 */

int Rook::getValue() {
  return 0;
}

bool Rook::canMoveTo(Square &location) {
  bool canMoveTo = false;
  int run = getLocation()->getFile() - location.getFile();
  int rise = getLocation()->getRank() - location.getRank();

  if (run == 0 && Board::getInstance()->isClearFile(*getLocation(), location)) {
    canMoveTo = true;
  } else if (rise == 0
      && Board::getInstance()->isClearRank(*getLocation(), location)) {
    canMoveTo = true;
  }

  return canMoveTo;
}

string Rook::getPieceSymbol() {
  return this->getColor() == Color::Black ? ROOK_BLACK : ROOK_WHITE;
}

Rook::Rook(Color color, Square *location) : RestrictedPiece(color, location) {}
