/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include "Square.h"

/**
 * Square implementation
 */

/**
 *
 * @param _rank
 * @param _file
 * @param _occupant
 */
Square::Square(int _rank, int _file) : _rank(_rank), _file(_file) {_occupant =
                                                                       nullptr;}
Square::Square() = default;

/**
 * @return int
 */
int Square::getRank() {
  return _rank;
}

/**
 * @return int
 */
int Square::getFile() {
  return _file;
}

/**
 * @return bool
 */
bool Square::isOccupied() {
  return _occupant != nullptr;
}

/**
 * @return Piece*
 */
Piece *Square::getOccupant() {
  return _occupant;
}

/**
 * @param occupant
 */
void Square::setOccupant(Piece *occupant) {
  _occupant = occupant;
}

/*
 * TODO: Can two square exists with same rank and file??
 */
bool Square::operator==(const Square &square) const {
  return (_file == square._file && _rank == square._rank);
}

