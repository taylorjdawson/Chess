/**
 * Project Chess
 * @author Taylor J. Dawson
 */

#include "Game.h"

static const char *const BLACK_ROOK = "♜";
static const char *const BLACK_KNIGHT = "♞";
static const char *const BLACK_BISHOP = "♝";
static const char *const BLACK_QUEEN = "♛";
static const char *const BLACK_KING = "♚";
static const char *const BLACK_PAWN = "♟";
static const char *const WHITE_ROOK = "♖";
static const char *const WHITE_KNIGHT = "♘";
static const char *const WHITE_BISHOP = "♗";
static const char *const WHITE_QUEEN = "♕";
static const char *const WHITE_KING = "♔";
static const char *const WHITE_PAWN = "♙";

/**
 * Game implementation
 */
bool Game::gameInitialized = false;

Board *Game::_board = Board::getInstance();
Player *Game::_player = nullptr;
Player *Game::_nextPlayer = nullptr;
set<Piece *> Game::_whitePieces;
set<Piece *> Game::_blackPieces;

// ASK: Good method? Just overwrite these temp variables when necessary
Piece *blackPiece;
Piece *whitePiece;

void Game::initialize() {

  /*Check to see that the game has not already been initialized*/
  if (!gameInitialized) {

    King *blackKing = nullptr;
    King *whiteKing = nullptr;

    for (int rank = 0; rank < NUMBER_OF_CHESS_ROWS; rank++) {
      for (int file = 0; file < NUMBER_OF_CHESS_COLS; file++) {

        Square &squareBlack = _board->getSquareAt(rank, file);

        /*The index (total_cols - 1) - rank will allow me to allow me to add
         * white and black squares simultaneously*/
        Square &squareWhite = _board->getSquareAt(((NUMBER_OF_CHESS_COLS - 1)
            - rank), file);

        /*
         * The below operation combines the rank and file numbers by right shift
         * -ing the rank by 3 and oring it with the file creating a number betwe
         * -en 0-15 
         *        rrr
         *           fff
         * (OR) + ______     
         *        rrrfff
         */
        int piecePosition = ((rank << 3) | file);
        
        //TODO: Clean up-- a LOT of repeated code
        if (piecePosition == 0 || piecePosition == 7) {

          /*Create a Black and White Rook and add them to the set and board*/
          blackPiece = new Rook(BLACK_ROOK, &squareBlack);
          whitePiece = new Rook(WHITE_ROOK, &squareWhite);

          /*  CONSIDER: Maybe change to one liner?
           * squareWhite.setOccupant(*(Game::_whitePieces.insert(new Rook(WHITE_ROOK, &squareWhite)).first));
           * */
          Game::_blackPieces.insert(blackPiece);
          Game::_whitePieces.insert(whitePiece);

          squareBlack.setOccupant(blackPiece);
          squareWhite.setOccupant(whitePiece);

        } else if (piecePosition == 1 || piecePosition == 6) {

          /*Create a Black and White Knight and add them to the set and board*/
          blackPiece = new Knight(BLACK_KNIGHT, &squareBlack);
          whitePiece = new Knight(WHITE_KNIGHT, &squareWhite);

          Game::_blackPieces.insert(blackPiece);
          Game::_whitePieces.insert(whitePiece);

          squareBlack.setOccupant(blackPiece);
          squareWhite.setOccupant(whitePiece);

        } else if (piecePosition == 2 || piecePosition == 5) {

          /*Create a Black and White Bishop and add them to the set and board*/
          blackPiece = new Bishop(BLACK_BISHOP, &squareBlack);
          whitePiece = new Bishop(WHITE_BISHOP, &squareWhite);

          Game::_blackPieces.insert(blackPiece);
          Game::_whitePieces.insert(whitePiece);

          squareBlack.setOccupant(blackPiece);
          squareWhite.setOccupant(whitePiece);

        } else if (piecePosition == 3) {
          // Place Queen
          blackPiece = new Queen(BLACK_QUEEN, &squareBlack);
          whitePiece = new Queen(WHITE_QUEEN, &squareWhite);

          Game::_blackPieces.insert(blackPiece);
          Game::_whitePieces.insert(whitePiece);

          squareBlack.setOccupant(blackPiece);
          squareWhite.setOccupant(whitePiece);

        } else if (piecePosition == 4) {
          // Place King
          blackKing = new King(BLACK_KING, &squareBlack);
          whiteKing = new King(WHITE_KING, &squareWhite);

          Game::_blackPieces.insert(blackKing);
          Game::_whitePieces.insert(whiteKing);

          squareBlack.setOccupant(blackKing);
          squareWhite.setOccupant(whiteKing);

        } else { /* It must be a Pawn */
          // Place Pawn
          blackPiece = new Pawn(BLACK_PAWN, &squareBlack);
          whitePiece = new Pawn(WHITE_PAWN, &squareWhite);

          Game::_blackPieces.insert(blackPiece);
          Game::_whitePieces.insert(whitePiece);

          squareBlack.setOccupant(blackPiece);
          squareWhite.setOccupant(whitePiece);
        }
      }
    }

    Game::_player = new Player("Black", *blackKing, _blackPieces);
    Game::_nextPlayer = new Player("White", *whiteKing, _whitePieces);
  }
  _board->display(cout);
}

/**
 * @return Player&
 */
Player *Game::getNextPlayer() {
  Player *nextPlayer = Game::_nextPlayer;
  Game::_nextPlayer = Game::_player;
  Game::_player = nextPlayer;
  return nextPlayer;
}

/**
 * @param player
 * @return Player&
 */
Player &Game::getOpponentOf(Player &player) {
  return *Game::_player;
}


