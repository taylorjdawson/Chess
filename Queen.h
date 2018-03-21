/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _QUEEN_H
#define _QUEEN_H

#include "Piece.h"


class Queen: public Piece {
public:

  Queen(const string &color, Square *location);
  int getValue() override;
    
    /**
     * @param location
     */
    bool canMoveTo(Square& location) override;
  string getPieceSymbol();
};

#endif //_QUEEN_H