/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _BOARD_H
#define _BOARD_H
#define DIMENSION (8)

#include <map>
#include "Square.h"

typedef map<int, map<int, Square>> Squares;

class Board {
 public:

  static Board *getInstance();

  /**
   * @param rank
   * @param file
   */
  Square &getSquareAt(int rank, int file);

  /**
   * @param from
   * @param to
   */
  bool isClearRank(Square &from, Square &to);

  /**
   * @param from
   * @param to
   */
  bool isClearFile(Square &from, Square &to);

  /**
   * @param from
   * @param to
   */
  bool isClearDiagonal(Square &from, Square &to);

  /**
   * @param os
   */
  void display(std::ostream &os);

 private:
  static Board *_instance;
  static Squares _squares;
  Board() = default;
  static void initializeBoard();
};

#endif //_BOARD_H