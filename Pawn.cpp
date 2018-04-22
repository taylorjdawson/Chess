/**
 * Project Chess
 * @author Taylor J. Dawson
 */

//TODO: Clean this file up
#include <iostream>
#include "Pawn.h"
#include "Board.h"
#define PAWN_BLACK ("♟")
#define PAWN_WHITE ("♙")
#define LEFT_DIAG (0)
#define RIGHT_DIAG (2)
#define ONE_FORWARD (1)
#define TWO_FORWARD (3)

/**
 * Pawn implementation
 */

int Pawn::getValue() {
  return 0;
}

bool Pawn::canMoveTo(Square &location) {
  //ASK: to use 'this' or not yo use 'this' that is the question...

  bool canMove = false;

  int rankDir = 0; //TODO: Change name; possibly remove later

  /*If pawn is Black it can only move rank - 1*/
  /*If pawn is White it can only move rank + 1*/
  rankDir =
      (this->getColor() == Color::Black) ? 1
                                         : -1;

  int pieceRank = getLocation()->getRank();
  int pieceFile = getLocation()->getFile();

  //CONSIDER: Excessive param variables vs just calling the 'get' functions inside the methods
  /* Check that location it is within the valid rank and file */
  if (isWithinRank(pieceRank,
                   location.getRank(),
                   pieceFile,
                   location.getFile(),
                   rankDir)
      &&
          isWithinFile(pieceFile, location.getFile())) {
    //TODO: Explain
    switch (getLocationIndex
        (pieceRank,
         pieceFile,
         location.getRank(),
         location.getFile(),
         rankDir)) {
      case LEFT_DIAG:
      case RIGHT_DIAG:

        /* Can only move here if the square is occupied by the opposing players
         * piece. */
        canMove = location.isOccupied() &&
            location.getOccupant()->getColor() != getColor();
        break;
      case ONE_FORWARD:
      case TWO_FORWARD:
        canMove = Board::getInstance()->isClearRank(*getLocation(), location);
        break;
      default:break;
    }
  }

  /*Check that location it is within the correct rank*/


  /*Check that location is with in +-1 of the file to the upper left or right*/

  return canMove;
}

bool Pawn::isWithinFile(int pawnFile, int file) {
  return abs(pawnFile - file) <= 1;
}

//TODO: Possibly rename params
bool Pawn::isWithinRank(int pawnRank,
                        int rank,
                        int pawnFile,
                        int file,
                        int rankDir) {
  return (rankDir * (rank - pawnRank)) == 1 || (!hasMoved() &&
      (rankDir * (rank - pawnRank)) == 2 && pawnFile - file == 0);
}

int Pawn::getLocationIndex(int pawnRank,
                           int pawnFile,
                           int rank,
                           int file,
                           int rankDir) {
  int locationIndex = 0;
  //TODO: Explain
  if (rankDir * (rank - pawnRank) == 1) {
    switch (rankDir * (file - pawnFile)) {
      case 1: locationIndex = 0;
        break;
      case 0: locationIndex = 1;
        break;
      case -1: locationIndex = 2;
        break;
      default:break;
    }
  } else { /*next location is two squares forward*/
    locationIndex = 3;
  }
  return locationIndex;
}

string Pawn::getPieceSymbol() {
  //TODO: Change to enum later
  return this->getColor() == Color::Black ? PAWN_BLACK : PAWN_WHITE;
}

Pawn::Pawn(Color color, Square *location) : RestrictedPiece(color,
                                                            location) {}





