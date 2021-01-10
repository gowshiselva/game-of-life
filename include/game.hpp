#ifndef __GAME_H__
#define __GAME_H__

#include<vector>
#include <iostream>
#include <string>

#include "board.hpp"
#include "rule.hpp"
class Game
{
    public:
       Game(unsigned x, unsigned y);
       ~Game();
       void runGame();
       std::ostream& operator<<(std::ostream& os);

    private:
       void display() const noexcept; 
       void generation() noexcept;
       Rule* rule_;
       Board* board_;
       unsigned gen;

};

#endif
