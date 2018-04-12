/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#ifndef _GAME_H
#define _GAME_H

#include <bitset>
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"

class Game {

 public:

  /**
   * Initializes the boards
   */
  static void initialize();

  /**
   * Returns the next player
   * @return the next player
   */
  static Player *getNextPlayer();

  /**
   * Gets the opponent of the specifed player
   * @param player the player whose opponent is sought
   * @return the opponent of the specified player
   */
  Player &getOpponentOf(Player &player);
  static Player* _player;
  enum Color {Black, White};

 private:
  static bool gameInitialized;
  static Player* _nextPlayer;

  static Board *_board;
  static set<Piece *> _whitePieces;
  static set<Piece *> _blackPieces;
};

#endif //_GAME_H
static const int NUMBER_OF_CHESS_ROWS = 2;
static const int NUMBER_OF_CHESS_COLS = 8;
