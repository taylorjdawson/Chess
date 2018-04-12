/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _PAWN_H
#define _PAWN_H

#include "RestrictedPiece.h"

class Square;

/**
 * A Pawn object
 */
class Pawn : public RestrictedPiece {
 public:

  /**
   *
   * @param color
   * @param location
   */
  Pawn(const string &color, Square *location);

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

  /**
   * Returns true if the toSquare's file is within the valid file and
   * false otherwise.
   * @param pawnFile the file of the pawn's current location
   * @param file the file of the pawn's potential future location
   * @return true if the toSquare's file is within the valid file and
   * false otherwise.
   */
  bool isWithinFile(int pawnFile, int file);

  /**
   * Returns true if the toSquare's rank is within the valid rank and
   * false otherwise.
   * @param pawnRank the rank of the pawn's current location
   * @param pawnFile the file of the pawn's current location
   * @param rank the rank of the pawn's potential future location
   * @param file the file of the pawn's potential future location
   * @return true if the toSquare's rank is within the valid rank and
   * false otherwise.
   */
  bool isWithinRank(int pawnRank, int rank, int pawnFile, int file);

  /**
   * Fabricates a location index 0-3 corresponding to the 4 possible
   * positions that a pawn can move:
   * 0 - forward left
   * 1 - forward
   * 2 - forward right
   * 3 - forward twice
   *
   * @param pawnRank the rank of the pawn's current location
   * @param pawnFile the file of the pawn's current location
   * @param rank the rank of the pawn's potential future location
   * @param file the file of the pawn's potential future location
   * @return the location index between 0 - 3
   */
  int getLocationIndex(int pawnRank, int pawnFile, int rank, int file);
};

#endif //_PAWN_H