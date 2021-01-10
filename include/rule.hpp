#ifndef __RULE_H__
#define __RULE_H__

#include<vector>
#include<algorithm>

#include"board.hpp"
class Rule
{
  public:
    Rule(Board* b);
    ~Rule();
    bool hasLivingCells() const noexcept;
    void swapCells();
    void setRuleB(std::vector<unsigned>& birth);
    void setRuleS(std::vector<unsigned>& live);
    void setRules();

    private:
      int findNeighbours( int xx, int yy);
      bool isDead(unsigned n);
      bool isBirth(unsigned n);
      unsigned row_,col_;
      Board *brd, *brdT;
      std::vector<unsigned> live_, birth_;
};

#endif
