/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include <iostream>
#include <regex>
#include "Player.h"
#include "Board.h"

using namespace std;

/**
 * Player implementation
 */
Player::Player(const string &_name, King &_king, set<Piece *> &_pieces) : _name(
    _name), _king(_king), _pieces(_pieces) {}

/**
 * @return string
 */
string Player::getName() {
  return _name;
}

/**
 * @return King&
 */
King &Player::getKing() {
  return _king;
}

/**
 * @return set<Piece*>&
 */
set<Piece *> &Player::getPieces() {
  return _pieces;
}

/**
 * @return boolean
 */
bool Player::makeMove() {
  /*CONSIDER bool for computer or human user
   * if computer then skip prompt and generate a move.
   * */
  string move;
  /* TODO: Explaing this "cleverness" */
  regex algNotation("(?=[A-Ha-h][1-8]\\s[A-Ha-h][1-8]).{5}");
  bool validMove = false;

  /* Prompt user for move*/
  cout << _name << " enter move: ";

  /* Get move from player*/
  getline(cin, move);

  /* Validate the string that it is the correct format by
  checking the input against the regex */
  validMove = regex_match(move, algNotation);

  if (validMove) {

    /* Extract the algebraic notation to matrix*/
    string fromSquare = move.substr(0, 2);
    string toSquare = move.substr(3, 4);

    /* Check that they are not the same. We can't move a piece to the location
     * that it currently is in. */
    if (fromSquare == toSquare) {
      cout << "Invalid move: " << move << endl;
      validMove = false;
    } else {

      //TODO: Clean up variables may be redundant
      /* Convert the algebraic notation to matrix indices*/
      int fromFile = fromSquare[0] - 97;//TODO: Explain this
      int fromRank = 56 - fromSquare[1];//TODO: Explain this
      int toFile = toSquare[0] - 97;
      int toRank = 56 - toSquare[1];

      Board* board = Board::getInstance();
      Square square = board->getSquareAt(fromRank, fromFile);

      /* First check to see if the pawn is owned by this player */

      /* Then check that the piece can legally move to that desired location */

      /* Check that the square where the piece wishes to move is not occupied */

      cout << square.getOccupant()->getColor()/*->canMoveTo(board->getSquareAt(fromRank, fromFile))*/ << endl;
    }

    /*cout << "From: " << fromSquare << " To: " << toSquare << endl;*/

  } else {
    cout << "Invalid move: " << move << endl;
  }

//  cout << "Your move: " << move << endl;

  return validMove;
}

/**
 * @param piece
 */
void Player::capture(Piece &piece) {
  _capturedPieces.insert(_capturedPieces.begin(), &piece);
}

/**
 * @return int
 */
int Player::calculateScore() {
  return 0;
}
void Player::display(ostream &os) {
  os << _name; /*+ getPieceSymbol()*/;
}
ostream &operator<<(ostream &os, Player &player) {
  player.display(os);
  return os;
}