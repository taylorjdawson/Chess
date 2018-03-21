/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "Piece.h"


class Knight: public Piece {
public:

  Knight(const string &color, Square *location);

  int getValue() override;
    
    /**
     * @param location
     */
    bool canMoveTo(Square& location) override;
  string getPieceSymbol() override;
};

#endif //_KNIGHT_H