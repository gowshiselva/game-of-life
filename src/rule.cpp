
#include<rule.hpp>

 Rule::Rule(Board* b):brd(b)
 {
    row_ = b->getRow();
    col_ = b->getCol();
    brdT = new Board(row_, col_);
 }

bool Rule::hasLivingCells() const noexcept
{
    for (unsigned y=0; y < col_; ++y)
    {
        for (unsigned x=0; x < row_; ++x)
        {
            if(brd->at(x,y))
            {
              return true;
            }
            
        }
    }
    return false;
    std::cout << " No alive cells" <<std::endl;
}

void Rule::swapCells()
{
    brd->swap(brdT);
}

void Rule::setRuleB(std::vector<unsigned>& birth)
{
    birth_ = birth;
}

void Rule::setRuleS(std::vector<unsigned>& live)
{
    live_ = live;
}
void Rule::setRules()
{
  unsigned n = 0;
   for (unsigned y=0; y < row_; ++y)
    {
        for (unsigned x=0; x < col_; ++x)
        {
            n = findNeighbours(x, y);
            if(brd->at(x, y))
              {
                  brdT->setBoard(x,y, isDead(n) ? 1:0);                  
              }
              else
               {
                  brdT->setBoard(x,y, isBirth(n) ? 1:0);
               }
            
        }
    }
}

int Rule::findNeighbours(int xx, int yy)
{
    int n = 0, nx, ny;
        for( int y = -1; y < 2; y++ ) {
            for( int x = -1; x < 2; x++ ) {
                if( !x && !y ) continue;
                nx = ( col_ + xx + x ) % col_;;
                ny = ( row_ + yy + y ) % row_;
                n += brd->at( nx, ny ) > 0 ? 1 : 0;
            }
        }
        return n;
}

bool Rule::isDead( unsigned n )
{
        return( live_.end() != find( live_.begin(), live_.end(), n ) );
}

bool Rule::isBirth( unsigned n )
{
        return( birth_.end() != find( birth_.begin(), birth_.end(), n ) );
}
Rule:: ~Rule()
 {
     if(brdT) delete brdT;
 }

