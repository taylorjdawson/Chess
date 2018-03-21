/**
 * Project Chess
 * @author Brian R. Snider
 */


#include "Game.h"

/**
 * Game implementation
 */

Board * _board = Board::getInstance();

Game::Game() = default;

/*void Game::initialize() {
    if(!gameInitialized)
    {
        _board = *Board::getInstance();
        initializeBoard();
    }
}*/

/**
 * @return Player&
 */
Player& Game::getNextPlayer() {
    return _nextPlayer;
}

/**
 * @param player
 * @return Player&
 */
Player& Game::getOpponentOf(Player& player) {
    return _player;
}

/*void Game::initializeBoard() {
    for(int rank = 0; rank < 1; rank++)
    {
        for(int file = 0; file < 8; file++)
        {
//            _board.getSquareAt(rank, file).setOccupant();
        }
    }
}*/

