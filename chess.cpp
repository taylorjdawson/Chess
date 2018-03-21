// 1713075
// 2018-3-17
// Assignment 6


#include <iostream>
#include "Game.h"
#include "Piece.h"
#include "Board.h"
#include "King.h"

using namespace std;
int main() {

//  Game::initialize();

  Board* _board = Board::getInstance();

  _board->display(cout);

//  _board->getSquareAt(0,0);
//  King* piece = new King("W",&_board->getSquareAt(0,0));
//  std::cout << "Hello, World!" << std::endl;
  return 0;

}