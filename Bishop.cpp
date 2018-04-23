/**
 * Project Chess
 * @author Taylor J. Dawson
 */

#include "Bishop.h"
#include "Board.h"

/**
 * Bishop implementation
 */
Bishop::Bishop(Color color, Square *location) : Piece(color, location) {}

int Bishop::getValue() {
  return 0;
}

bool Bishop::canMoveTo(Square &location) {
  int run = getLocation()->getFile() - location.getFile();
  int rise = getLocation()->getRank() - location.getRank();
//  printf("%d / %d = %d\n", rise, run, abs(rise/run));
  printf("isClearDiagonal = %d", abs(rise/run) == 1 && Board::getInstance()->isClearDiagonal
      (*getLocation(), location));
  return abs(rise/run) == 1 && Board::getInstance()->isClearDiagonal
      (*getLocation(), location);
}

string Bishop::getPieceSymbol() {
  return this->getColor() == Color::Black ? "♝" : "♗";
}
