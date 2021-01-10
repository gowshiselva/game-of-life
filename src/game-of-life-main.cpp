/*
*game-of-life-main.cpp
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>

#include "board.hpp"
#include "rule.hpp"
#include "game.hpp"

int main() {

    unsigned width; // widht and height of the board
    std::cout << "Enter the noard size \n" << std::endl;
    std::cin >> width;
    Game  c(width,width);
    std::cout << "Press 1 to run the Game \n";

    unsigned o; 
    
    do {
        std::cin >> o;
    } 
    while( o < 1 || o > 4 );
    {
       std::cin.ignore();       
       c.runGame(); 
       auto k = std::cin.get();  
       std::cout << k;
       return k;
    }
    
   
}