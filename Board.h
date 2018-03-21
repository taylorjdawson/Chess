/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _BOARD_H
#define _BOARD_H
#define DIMENSION (8)


class Square;

class Board {
public:

  static Board* getInstance()
  {
    /* Check to see if instance has already been created.*/
    if(!_instance)
    {
      /*Instance has yet to be created, therefore create new instance.*/
      _instance = new Board();
    }

    return _instance;
  }
    
    /**
     * @param rank
     * @param file
     */
    Square& getSquareAt(int rank, int file) {
      return *_squares[rank][file];
    }
    
    /**
     * @param from
     * @param to
     */
    bool isClearRank(Square& from, Square& to);
    
    /**
     * @param from
     * @param to
     */
    bool isClearFile(Square& from, Square& to);
    
    /**
     * @param from
     * @param to
     */
    bool isClearDiagonal(Square& from, Square& to);
    
    /**
     * @param os
     */
    void display(ostream& os);

private: 
//    const int DIMENSION = 8;
    static Board* _instance;
    Square* _squares[DIMENSION][DIMENSION];
    Board() = default;
};

Board* Board::_instance = nullptr;
//Board::Board() = default;

#endif //_BOARD_H