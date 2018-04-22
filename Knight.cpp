/**
 * Project Chess
 * @author Taylor J. Dawson
 */

//TODO: Make constant
int moves [8][2] = {
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1}
};


#include "Knight.h"

#define RANK (0)
#define FILE (1)

/**
 * Knight implementation
 */
Knight::Knight(Color color, Square *location) : Piece(color, location) {}

int Knight::getValue() {
  return 0;
}
//TODO: ADD comments here
bool Knight::canMoveTo(Square &location) {
  bool canMoveTo = false;

  //TODO: Replace with constants
  for(int i = 0; i < 8 && !canMoveTo; i++)
  {
      canMoveTo = getLocation()->getRank() + moves[i][RANK] == location.getRank()
          && getLocation()->getFile() + moves[i][FILE] == location.getFile();
  }

  return canMoveTo;
}

string Knight::getPieceSymbol() {
  return this->getColor() == Color::Black ? "♞" : "♘";
}

