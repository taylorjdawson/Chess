/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include <iostream>
#include "Board.h"


/**
 * Board implementation
 */

using namespace std;

Board *Board::_instance = nullptr;
Squares Board::_squares;

Board *Board::getInstance() {

  /* Check to see if instance has already been created.*/
  if (_instance == nullptr) {

    /* Initialize the board with Squares */
    Board::initializeBoard();

    /*Instance has yet to be created, therefore create new instance.*/
    _instance = new Board();
  }

  return _instance;
}
//ASK: Reference or pointer
Square &Board::getSquareAt(int rank, int file) {
  return _squares[rank][file];
}

bool Board::isClearRank(Square &from, Square &to) {
  bool isClearRank = true;

  /* CONSIDER: Edge case where from and to are same square.
   * CONSIDER: Edge case where the are not within the same rank.
   * Should it be a precondition for using this method? or should it be
   * checked for within the method? For now the will both be preconditions */

  /* Determine the direction i.e. +-1 when iterating through squares */
  int dir = ((to.getRank() - from.getRank()) > 0) -
      ((to.getRank() - from.getRank()) < 0);

  int rank = from.getRank();

  /* When the absolute value between the current rank and the toRank == 0
   * then we have checked all squares up to the destination square.*/
  while (isClearRank && abs(rank - to.getRank())) {
    rank += dir;
    isClearRank = !_squares[rank][from.getFile()].isOccupied();
  }
  return isClearRank;
}

bool Board::isClearFile(Square &from, Square &to) {
  bool isClearFile = true;

  /* Determine the direction i.e. +-1 when iterating through squares */
  int dir = ((to.getFile() - from.getFile()) > 0) -
      ((to.getFile() - from.getFile()) < 0);

  int file = from.getFile();

  /* When the absolute value between the current file and the toFile == 0
 * then we have checked all squares up to the destination square.*/
  while (isClearFile && abs(file - to.getFile())) {
    file += dir;
    isClearFile = !_squares[file][from.getRank()].isOccupied();
  }

  return false;
}

bool Board::isClearDiagonal(Square &from, Square &to) {
  return false;
}

void Board::display(ostream &os) {
  const string board_header_letters = "    a   b   c   d   e   f   g   h";
  const string board_header = "  ┌───┬───┬───┬───┬───┬───┬───┬───┐";
  const string row_divider =  "  ├───┼───┼───┼───┼───┼───┼───┼───┤";
  const string board_footer = "  └───┴───┴───┴───┴───┴───┴───┴───┘";
  int file = 0;
  os << board_header_letters << '\n' << board_header << endl;
  for (int rank = 0; rank < 8; rank++) {
    os << 8 - rank << " ";
    for (file = 0; file < 8; file++) {
      Square square = _squares[rank][file];

      if (square.isOccupied()) {
        Piece *piece = _squares[rank][file].getOccupant();
        os << "│ " << *piece << " ";
      } else { /*If the reference is null then just print a space*/
        os << "│   ";
      }
    }
    os << "│ " << 8 - rank;
    if (rank != 7) {
      os << "\n" << row_divider << endl;
    }
  }

  /*Print the board footer*/
  os << "\n" << board_footer << endl;
  os << board_header_letters << endl;
}

void Board::initializeBoard() {
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      _squares[rank][file] = Square(rank, file);
    }
  }
}

void Board::displayColored(std::ostream &os) {
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      if ((rank + file) % 2 == 0) {
        os << "\033[47m  ";
      } else {
        os << "\033[40m  ";
      }
    }
    os << "\033[40m" << endl;
  }

}




