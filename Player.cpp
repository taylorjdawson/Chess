/**
 * Project Chess
 * @author Brian R. Snider
 */


#include "Player.h"

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
    return "";
}

/**
 * @return King&
 */
King& Player::getKing() {
    return _king;
}

/**
 * @return set<Piece*>&
 */
set<Piece*>& Player::getPieces() {
    return _pieces;
}

/**
 * @return boolean
 */
bool Player::makeMove() {
    return false;
}

/**
 * @param piece
 */
void Player::capture(Piece& piece) {
    _capturedPieces.insert(_capturedPieces.begin(), &piece);
}

/**
 * @return int
 */
int Player::calculateScore() {
    return 0;
}