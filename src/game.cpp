
#include"game.hpp"

Game::Game( unsigned x, unsigned y ) : rule_(nullptr) {
        board_ = new Board( x, y );
    }

void Game::runGame()
{
    rule_ = new Rule(board_);
    gen = 1;
    std::vector<unsigned> t;
        t.emplace_back( 2 ); t.emplace_back( 3 ); rule_->setRuleS( t );
        t.clear(); t.emplace_back( 3 ); rule_->setRuleB( t );
               
    generation();
}
void Game::display()  const noexcept{
        system( "cls" );
        unsigned wid = board_->getRow();
        unsigned hei = board_->getCol();
        std::cout << "+" << std::string( wid, '-' ) << "+\n";
        for( unsigned y = 0; y < hei; ++y ) {
            std::cout << "|";
            for( unsigned x = 0; x < wid; ++x ) {
                if( board_->at( x, y ) ) std::cout << "#";
                else std::cout << ".";
            }
            std::cout << "|\n";
        }
        std::cout << "+" << std::string( wid, '-' ) << "+\n";
        std::cout << "Generation: " << gen << "\n\nPress [RETURN] for the next generation..\n";
        std::cin.get();
    }
void Game::generation() noexcept
{
    do 
    {
        display();
        rule_->setRules();
        rule_->swapCells();
        ++gen;
    }
    while ( rule_->hasLivingCells() );
}

Game::~Game() {
        if( rule_ ) delete rule_;
        delete board_;
    }

std::ostream& Game::operator<<(std::ostream& os)
{
  system( "cls" );
  unsigned no_rows = board_->getRow();
  unsigned no_cols = board_->getCol();
  (void)no_cols;
  os << "+" << std::string( no_rows, '-' ) << "+\n";
  
  return os;
}