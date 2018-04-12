/**
 * Project Chess
 * @author Taylor J. Dawson
 */

#include "Game.h"

static const char *const BLACK_ROOK = "B";
static const char *const BLACK_KNIGHT = "B";
static const char *const BLACK_BISHOP = "B";
static const char *const BLACK_QUEEN = "B";
static const char *const BLACK_KING = "B";
static const char *const BLACK_PAWN = "B";
static const char *const WHITE_ROOK = "W";
static const char *const WHITE_KNIGHT = "W";
static const char *const WHITE_BISHOP = "W";
static const char *const WHITE_QUEEN = "W";
static const char *const WHITE_KING = "W";
static const char *const WHITE_PAWN = "W";



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

        if (piecePosition == 0 || piecePosition == 7) {

          /*Create a Black and White Rook and add them to the set and board*/
          blackPiece = new Rook(BLACK_ROOK/*Game::Color::Black*/, &squareBlack);
          whitePiece = new Rook(WHITE_ROOK/*Game::Color::White*/, &squareWhite);

        } else if (piecePosition == 1 || piecePosition == 6) {

          /*Create a Black and White Knight and add them to the set and board*/
          blackPiece = new Knight(BLACK_KNIGHT/*Game::Color::Black*/, &squareBlack);
          whitePiece = new Knight(WHITE_KNIGHT/*Game::Color::White*/, &squareWhite);

        } else if (piecePosition == 2 || piecePosition == 5) {

          /*Create a Black and White Bishop and add them to the set and board*/
          blackPiece = new Bishop(BLACK_BISHOP/*Game::Color::Black*/, &squareBlack);
          whitePiece = new Bishop(WHITE_BISHOP/*Game::Color::White*/, &squareWhite);

        } else if (piecePosition == 3) {
          // Place Queen
          blackPiece = new Queen(BLACK_QUEEN/*Game::Color::Black*/, &squareBlack);
          whitePiece = new Queen(WHITE_QUEEN/*Game::Color::White*/, &squareWhite);


        } else if (piecePosition == 4) {
          // Place King
          blackPiece = blackKing = new King(BLACK_KING/*Game::Color::Black*/, &squareBlack);
          whitePiece = whiteKing = new King(WHITE_KING/*Game::Color::White*/, &squareWhite);

        } else { /* It must be a Pawn */
          // Place Pawn
          blackPiece = new Pawn(BLACK_PAWN/*Game::Color::Black*/, &squareBlack);
          whitePiece = new Pawn(WHITE_PAWN/*Game::Color::White*/, &squareWhite);

        }
        squareBlack.setOccupant(*(Game::_blackPieces.insert(blackPiece).first));
        squareWhite.setOccupant(*(Game::_whitePieces.insert(whitePiece).first));
      }
    }

    Game::_player = new Player("Black", *blackKing, _blackPieces);
    Game::_nextPlayer = new Player("White", *whiteKing, _whitePieces);
  }

  _board->display(cout);

  /***************ROW

  for (auto it=_blackPieces.begin(); it!=_blackPieces.end(); ++it)
    std::cout << ' ' << **it;
  std::cout << '\n';

  ROW ***************/
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


