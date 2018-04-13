/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _BISHOP_H
#define _BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
 public:

  /**
   *
   * @param color
   * @param location
   */
  Bishop(Color color, Square *location);

  /**
   *
   * @return
   */
  int getValue() override;

  /**
   * @param location
   */
  bool canMoveTo(Square &location) override;

  /**
   *
   * @return
   */
  string getPieceSymbol() override;

 private:
  const string _piece;
};

#endif //_BISHOP_H