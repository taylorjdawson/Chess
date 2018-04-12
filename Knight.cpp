/**
 * Project Chess
 * @author Brian R. Snider
 */


#include "Knight.h"
#define PIECE_SYMBOL ("N")

/**
 * Knight implementation
 */

Knight::Knight(const string &color, Square *location) : Piece(color, location) {}

/**
 * @return int
 */
int Knight::getValue() {
    return 0;
}

/**
 * @param location
 * @return boolean
 */
bool Knight::canMoveTo(Square& location) {
    return false;
}

string Knight::getPieceSymbol(){
    return this->getColor() == "B" ? "♞" : "♘";
}

