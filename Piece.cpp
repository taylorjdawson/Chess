/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include "Piece.h"

/**
 * Piece implementation
 */

Piece::Piece(const string &color, Square *location)
    : _color(color), _location(location) {}

Piece::Piece() = default;

/**
 * @return int
 */
int Piece::getValue() {
  return 0;
}

/**
 * @return string
 */
string Piece::getColor() {
  return _color;
}

/**
 * @return Square*
 */
Square *Piece::getLocation() {
  return _location;
}

/**
 * @param location
 */
void Piece::setLocation(Square *location) {
  _location = location;
}

/**
 * @return bool
 */
bool Piece::isOnSquare() {
  return false;
}

/**
 * @param location
 * @return bool
 */
bool Piece::canMoveTo(Square &location) {
  return false;
}

/**
 * @param location
 * @param byPlayer
 * @return bool
 */
bool Piece::moveTo(Square &location, Player &byPlayer) {
  return false;
}

string Piece::getPieceSymbol() { return ""; }

/**
 * @param os
 */
void Piece::display(ostream &os) {
  os << getColor() /*+ getPieceSymbol()*/;
}

ostream &operator<<(ostream &os, Piece &piece) {
  piece.display(os);
  return os;
}




