// 1713075
// 2018-4-8
// Assignment 7
/* W.I.P. -- The poop hit the fan */

#include <limits>
#include <regex>
#include "Game.h"

#define BLACK_FG ("\033[30m")
#define WHITE_FG ("\033[37m")
#define WHITE_BG ("\033[47m")
#define BLACK_BG ("\033[40m")
//#define
using namespace std;
int main() {


//  Board::getInstance()->displayColored(cout);

  Game::initialize();

  Player* player = Game::getNextPlayer();
  bool done = true;

  while(done)
  {
    while(!player->makeMove()){}
    Board::getInstance()->display(cout);
    player = Game::getNextPlayer();
  }

/*  std::set<int> myset;
  cout << *(myset.insert(10).first) << endl;

  cout << (int) "♜";

  char str[] = "\u2654\n";
  setlocale(LC_ALL, "");
  printf("%lc\n", 0x2654 + 6);
  for (i = 0; i < 0xffff; i++) {
    printf("%x - %lc\n", i, i);
  }*/
//  cout << WHITE_BG << BLACK_FG << "♟" << BLACK_BG << WHITE_FG << "♙"<< BLACK_BG << endl;

  return 0;
}