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

Piece::Piece(Color &color, Square *location)
    : _Color(color), _location(location) {}

Piece::Piece() = default;


int Piece::getValue() {
  return 0;
}


string Piece::getColor() {
  return _color;
}


Square *Piece::getLocation() {
  return _location;
}

void Piece::setLocation(Square *location) {
  _location = location;
}


bool Piece::isOnSquare() {
  return _location != nullptr;
}


bool Piece::canMoveTo(Square &location) {
  return false;
}

bool Piece::moveTo(Square &location, Player &byPlayer) {
  return false;
}

string Piece::getPieceSymbol() { return ""; }


void Piece::display(ostream &os) {
  os << getPieceSymbol();
}

ostream &operator<<(ostream &os, Piece &piece) {
  piece.display(os);
  return os;
}




