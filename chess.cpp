// 1713075
// 2018-3-17
// Assignment 7

#include <limits>
#include <regex>
#include "Game.h"

using namespace std;
int main() {
  Game::initialize();

  Player* player = Game::getNextPlayer();
  bool done = true;

//  while(done)
//  {
//    while(!player->makeMove()){}
//    player = Game::getNextPlayer();
//  }

  std::set<int> myset;
  cout << *(myset.insert(10).first) << endl;

//  cout << player;



  return 0;
}