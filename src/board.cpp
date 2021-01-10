#include "board.hpp"
#include <iostream>
#include <algorithm>

Board::Board(unsigned x, unsigned y): row_(x), col_(y), status_(nullptr)
{
  int s = row_ * col_ * sizeof(status);
  status_ = new status[s];
  memset( status_, 0, s );
  //std::fill(status_.begin(), status_.end(),0);
}

unsigned Board::getRow() const noexcept
{
  return row_;
}

unsigned Board::getCol() const noexcept
{
  return col_;
}

status* Board::getStatus() const noexcept
{
  return status_;
}

status Board::at(unsigned x, unsigned y)  noexcept
{
  return status_[(x + y) * row_];
}

void Board::setBoard(unsigned x, unsigned y, status st)  noexcept
{
  status_[x + y * row_] = st;
}

void Board::swap( Board* b) 
{
  memcpy( status_, b->getStatus(), row_ * col_ * sizeof( status ) );
}

Board::~Board()
{
 delete [] status_;
}

std::ostream& Board::operator<<(std::ostream& os)
{
 
  return os;
}

std::ostream& operator<<(std::ostream& os, const Board* b)
{
 
  return os;
}