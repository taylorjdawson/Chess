/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include <iomanip>
#include "Board.h"


/**
 * Board implementation
 */

using namespace std;

/**
 * @return Board&
 */
//Board *Board::getInstance() {
//
//  /* Check to see if instance has already been created.*/
//  if(_instance == nullptr)
//  {
//    /*Instance has yet to be created, therefore create new instance.*/
//    _instance = new Board();
//  }
//
//  return _instance;
//}

/**
 * @param rank
 * @param file
 * @return Square&
 */
//Square& Board::getSquareAt(int rank, int file) {
//  return *_squares[rank][file];
//}

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
  const string row_divider = "+----+----+----+----+----+----+----+----+";

//  os << setw()

  for(int rank = 0; rank < DIMENSION; rank++)
  {
    os << row_divider;
    for(int file = 0; file < DIMENSION; file++)
    {

    }
  }
}



