/**
 * Project Chess
 * @author Brian R. Snider
 */


#include "Pawn.h"
#define PIECE_SYMBOL ("P")

/**
 * Pawn implementation
 */


/**
 * @return int
 */
int Pawn::getValue() {
    return 0;
}

/**
 * @param location
 * @return boolean
 */
bool Pawn::canMoveTo(Square& location) {
    return false;
}

/**
 * @param os
 */
void Pawn::display(ostream& os) {

}

string Pawn::getPieceSymbol(){
    return PIECE_SYMBOL;
}
Pawn::Pawn(const string &color, Square *location) : RestrictedPiece(color, location) {}
Pawn::Pawn() = default;

