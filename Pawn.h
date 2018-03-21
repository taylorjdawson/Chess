/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _PAWN_H
#define _PAWN_H

#include "RestrictedPiece.h"
#include "Square.h"

class Pawn: public RestrictedPiece {
public:
  Pawn(const string &color, Square *location);
  Pawn();
  int getValue() override;
    
    /**
     * @param location
     */
    bool canMoveTo(Square& location) override;
    
    /**
     * @param os
     */
    void display(ostream& os) override;
  string getPieceSymbol() override;
};

#endif //_PAWN_H