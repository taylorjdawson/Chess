/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _ROOK_H
#define _ROOK_H

#include "RestrictedPiece.h"


class Rook: public RestrictedPiece {
public:
  Rook(const string &color, Square *location);

  int getValue() override;
    
    /**
     * @param location
     */
    bool canMoveTo(Square& location) override;
    string getPieceSymbol() override;
};

#endif //_ROOK_H