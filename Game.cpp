/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include "Game.h"
#define BLACK ("B")
#define WHITE ("W")

const string Game::BLACK_ROOK   = "♜";
const string Game::BLACK_KNIGHT = "♞";
const string Game::BLACK_BISHOP = "♝";
const string Game::BLACK_QUEEN  = "♛";
const string Game::BLACK_KING   = "♚";
const string Game::BLACK_PAWN   = "♟";
const string Game::WHITE_ROOK   = "♖";
const string Game::WHITE_KNIGHT = "♘";
const string Game::WHITE_BISHOP = "♗";
const string Game::WHITE_QUEEN  = "♕";
const string Game::WHITE_KING   = "♔";
const string Game::WHITE_PAWN   = "♙";

/**
 * Game implementation
 */


bool Game::gameInitialized = false;

Board *Game::_board = Board::getInstance();

void Game::initialize() {
  if (!gameInitialized) {

    /* Initialize the pieces */

    /* Initialize the board */

    /* Initialize the players */

    /* Hand off the pieces sets to the players */

    for (int rank = 0; rank < 2; rank++) {
      for (int file = 0; file < 8; file++) {
        Square &squareBlack = _board->getSquareAt(rank, file);
        Square &squareWhite = _board->getSquareAt((7 - rank), file);

        /*
         * The following operation will provide my
         * switch statement with 16 unique integers used
         * to determine which piece to place where.
         * Note:
         * */
        int piecePosition = ((rank << 3) | file);

        if (piecePosition == 0 || piecePosition == 7) {

          // Place Rook

          // Add black rook to list of blackpieces row-major
          //_blackPieces[/*rank * file + rank*/0] = new Rook(BLACK, &square);

          squareBlack.setOccupant(new Rook(BLACK_ROOK, &squareBlack));
          squareWhite.setOccupant(new Rook(WHITE_ROOK, &squareWhite));
        } else if (piecePosition == 1 || piecePosition == 6) {
          // Place Knight
          squareBlack.setOccupant(new Knight(BLACK_KNIGHT, &squareBlack));
          squareWhite.setOccupant(new Knight(WHITE_KNIGHT, &squareWhite));
        } else if (piecePosition == 2 || piecePosition == 5) {
          // Place Bishop
          squareBlack.setOccupant(new Bishop(BLACK_BISHOP, &squareBlack));
          squareWhite.setOccupant(new Bishop(WHITE_BISHOP, &squareWhite));
        } else if (piecePosition == 3) {
          // Place Queen
          squareBlack.setOccupant(new Queen(BLACK_QUEEN, &squareBlack));
          squareWhite.setOccupant(new Queen(WHITE_QUEEN, &squareWhite));
        } else if (piecePosition == 4) {
          // Place King
          squareBlack.setOccupant(new King(WHITE_KING, &squareBlack));
          squareWhite.setOccupant(new King(WHITE_KING, &squareWhite));
        } else { /* It is a Pawn */

          // Place Pawn
          squareBlack.setOccupant(new Pawn(BLACK_PAWN, &squareBlack));
          squareWhite.setOccupant(new Pawn(WHITE_PAWN, &squareWhite));

        }
      }
    }
  }
  _board->display(cout);
}

/**
 * @return Player&
 */
Player &Game::getNextPlayer() {
  return _nextPlayer;
}

/**
 * @param player
 * @return Player&
 */
Player &Game::getOpponentOf(Player &player) {
  return _player;
}


