/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _GAME_H
#define _GAME_H

//#define ROOK ()
//#define KNIGHT ()
//#define BISHOP ()
//#define KING ()
//#define QUEEN ()
//#define PAWN ()

#include <bitset>
#include "Player.h"
#include "Board.h"
#include "Piece.h"
#include "Pawn.h" //TODO: Possibly remove
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"

//class Board;
using namespace std;
class Game {
 public:
  Game();

  static void initialize() {
    if(!gameInitialized)
    {

      /* Initialize the pieces */

      /* Initialize the board */

      /* Initialize the players */

      /* Hand off the pieces sets to the players */

      for(int rank = 0; rank < 2; rank++)
      {
        for(int file = 0; file < 8; file++)
        {
          Square& squareBlack = _board->getSquareAt(rank, file);
          Square& squareWhite = _board->getSquareAt((7 - rank), file);


          /*
           * The following operation will provide my
           * switch statement with 16 unique integers used
           * to determine which piece to place where.
           * Note:
           * */
          int piecePosition = ((rank << 3) | file);

          if(piecePosition == 0 || piecePosition == 7)
          {
            // Place Rook

            // Add black rook to list of blackpieces row-major
            //_blackPieces[/*rank * file + rank*/0] = new Rook(BLACK, &square);

            cout << "Place Black Rook at: ("<< rank << "," << file << ") ";
            squareBlack.setOccupant(new Rook(BLACK, &squareBlack));
            cout << "Place White Rook at: ("<< (7 - rank) << "," << file << ")" <<endl;
            squareBlack.setOccupant(new Rook(BLACK, &squareBlack));
          } else if (piecePosition == 1 || piecePosition == 6)
          {
            // Place Knight
            cout << "Place Black Knight at: ("<< rank << "," << file << ") ";
            squareBlack.setOccupant(new Knight(BLACK, &squareBlack));
            cout << "Place White Knight at: ("<< (7 - rank) << "," << file << ")" <<endl;
            squareWhite.setOccupant(new Knight(WHITE, &squareWhite));
          } else if (piecePosition == 2 || piecePosition == 5)
          {
            // Place Bishop
            cout << "Place Black Bishop at: ("<< rank << "," << file << ") ";
            squareBlack.setOccupant(new Bishop(BLACK, &squareBlack));

            cout << "Place White Bishop at: ("<< (7 - rank) << "," << file << ")" <<endl;
            squareWhite.setOccupant(new Bishop(WHITE, &squareWhite));

          } else if (piecePosition == 3)
          {
            // Place Queen
            cout << "Place Black Queen at: ("<< rank << "," << file << ") ";
            squareBlack.setOccupant(new Queen(BLACK, &squareBlack));
            cout << "Place White Queen at: ("<< (7 - rank) << "," << file << ")" <<endl;
            squareWhite.setOccupant(new Queen(WHITE, &squareWhite));
          } else if (piecePosition == 4)
          {
            // Place King
            cout << "Place Black King at: ("<< rank << "," << file << ") ";
//            squareBlack.setOccupant(new King(BLACK, &squareBlack));
            cout << "Place White King at: ("<< (7 - rank) << "," << file << ")" <<endl;
//            squareBlack.setOccupant(new King(BLACK, &squareBlack));
          }
          else { /* It is a Pawn */

            // Place Pawn
            cout << "Place Black Pawn at: ("<< rank << "," << file << ") ";
            squareBlack.setOccupant(new Pawn(BLACK, &squareBlack));

            cout << "Place White Pawn at: ("<< (7 - rank) << "," << file << ")" <<endl;
            squareWhite.setOccupant(new Pawn(WHITE, &squareWhite));

          }



        }
      }
    }
  }

    
  Player& getNextPlayer();

  /**
   * @param player
   */
  Player& getOpponentOf(Player& player);

 private:
  static bool gameInitialized;
  static const string BLACK;
  static const string WHITE;
  Player _player;
  Player _nextPlayer;
  static Board *_board;
  static Piece _whitePieces[];
  static Piece* _blackPieces[];

};

bool Game::gameInitialized = false;
const string Game::BLACK = "B";
const string Game::WHITE = "W";
Board* Game::_board = Board::getInstance();

#endif //_GAME_H