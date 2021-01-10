/*
 * board.hpp
 * 
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <iostream>
#include <memory>
#include <ostream>
#include <cstring>

typedef unsigned char status; // represents the status of the cell


class Board {
   public:
      Board(unsigned x, unsigned y); // x is the width of the row and y is the width of the colum
      unsigned getRow() const noexcept; 
      unsigned getCol() const noexcept;
      status* getStatus() const noexcept;
      status at(unsigned x, unsigned y)  noexcept;
      void setBoard(unsigned x, unsigned y, status st)  noexcept;
      void swap( Board* w ); 
      std::ostream& operator<<(std::ostream& os);
      ~Board();
     

    private:
      unsigned row_; // number of rows
      unsigned col_; // number of columns
      status* status_; // charecter stored in each cell either '0' 'x'
       
};

std::ostream& operator<<(std::ostream& os, const Board& b);


#endif
