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

/**
 * @return Board&
 */
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

/**
 * @param rank
 * @param file
 * @return Square&
 */
Square &Board::getSquareAt(int rank, int file) {
  return _squares[rank][file];
}

/**
 * @param from
 * @param to
 * @return bool
 */
bool Board::isClearRank(Square &from, Square &to) {
  return false;
}

/**
 * @param from
 * @param to
 * @return bool
 */
bool Board::isClearFile(Square &from, Square &to) {
  return false;
}

/**
 * @param from
 * @param to
 * @return bool
 */
bool Board::isClearDiagonal(Square &from, Square &to) {
  return false;
}

/**
 * @param os
 */
void Board::display(ostream &os) {
  const string board_header_letters = "   a   b   c   d   e   f   g   h";
  const string board_header = "  ┌───┬───┬───┬───┬───┬───┬───┬───┐";
  const string row_divider = "  ├───┼───┼───┼───┼───┼───┼───┼───┤";
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
      os << "\n" <<row_divider << endl;
    }
  }
  os << "\n" << board_footer << endl;
  os << board_header_letters << endl;
}

void Board::initializeBoard() {
  for (int rank = 0; rank < 2; rank++) {
    for (int file = 0; file < 8; file++) {
      _squares[rank][file] = Square(rank, file);
    }
  }
}




