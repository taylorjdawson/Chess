/**
 * Project Chess
 * @author Taylor J. Dawson
 */


#include <iostream>
#include <regex>
#include "Player.h"

using namespace std;

/**
 * Player implementation
 */
Player::Player(Color color,
               const string &_name,
               King &_king,
               set<Piece *> &_pieces) : _color(color), _name(
    _name), _king(_king), _pieces(_pieces) {}

string Player::getName() {
  return _name;
}

King &Player::getKing() {
  return _king;
}

Color Player::getColor() {
  return _color;
}

set<Piece *> &Player::getPieces() {
  return _pieces;
}

bool Player::makeMove() {
  /*CONSIDER bool for computer or human user
   * if computer then skip prompt and generate a move.
   * */

  /*CONSIDER: Out sourceing the getinput function for modifiability
   * that way we can get input from sayyyy a mouse instead? */
  string move;
  /* TODO: Explain this "cleverness" */
  regex algNotation("(?=[A-Ha-h][1-8]\\s[A-Ha-h][1-8]).{5}");
  bool validMove = false;

  /* Prompt user for move*/
  cout << _name << " enter move: ";

  /* Get move from player*/
  getline(cin, move);

  /* Validate the string that it is the correct format by
  checking the input against the regex */
  if (regex_match(move, algNotation)) {

    /* Extract the algebraic notation to matrix*/
    string from = move.substr(0, 2);
    string to = move.substr(3, 4);

    /* Check that they are not the same. We can't move a piece to the location
     * that it currently is in. */
    if (from == to) {
      cout << "Invalid move: " << move << endl;
    } else {

      Board *board = Board::getInstance();

      /* Convert the algebraic notation to matrix indices */
      /*                                   TODO: Explain this         */
      Square &fromSquare = board->getSquareAt(56 - from[1], from[0] - 97);
      Square &toSquare = board->getSquareAt(56 - to[1], to[0] - 97);

      /* First check to see if the piece is owned by this player */
      if (_pieces.find(fromSquare.getOccupant()) != _pieces.end()) {

        /* Then check that the piece can legally move to that desired location*/
        if (fromSquare.getOccupant()->canMoveTo(toSquare)) {


          //TODO: Check for check here

          /* If the square is occupied by an opposing piece then TAKE it!*/
          if (toSquare.isOccupied()
              && toSquare.getOccupant()->getColor() == this->getColor()) {
            cout << "Can't Move!" << endl;
          }
          else {
            fromSquare.getOccupant()->setLocation(&toSquare);
            toSquare.setOccupant(fromSquare.getOccupant());
            fromSquare.setOccupant(nullptr);
          }


          validMove = true;
        } else {  
          cout << "Can't Move!" << endl;
        }
      } else {
        cout << "Invalid move: " << move << endl;
        cout << "That's not your piece" << endl;
      }
    }

    /*cout << "From: " << from << " To: " << to << endl;*/

  } else {
    cout << "Invalid move: " << move << endl;
  }

//  cout << "Your move: " << move << endl;

  return validMove;
}

void Player::capture(Piece &piece) {
  _capturedPieces.insert(_capturedPieces.begin(), &piece);
}

int Player::calculateScore() {
  return 0;
}

void Player::display(ostream &os) {
  os << _name;
}

ostream &operator<<(ostream &os, Player &player) {
  player.display(os);
  return os;
}