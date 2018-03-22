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

  static void initialize();

  Player &getNextPlayer();

  /**
   * @param player
   */
  Player &getOpponentOf(Player &player);

 private:
  static bool gameInitialized;
  static const string BLACK;
  Player _player;
  Player _nextPlayer;
  static Board *_board;
  static Piece *_whitePieces[];
  static Piece *_blackPieces[];
static const string BLACK_ROOK   ;
static const string BLACK_KNIGHT ;
static const string BLACK_BISHOP ;
static const string BLACK_QUEEN  ;
static const string BLACK_KING   ;
static const string BLACK_PAWN   ;
static const string WHITE_ROOK   ;
static const string WHITE_KNIGHT ;
static const string WHITE_BISHOP ;
static const string WHITE_QUEEN  ;
static const string WHITE_KING   ;
static const string WHITE_PAWN   ;

};

#endif //_GAME_H