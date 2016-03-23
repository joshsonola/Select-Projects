// game.hpp
#include "metaboard.hpp"

class Game
{
    MetaBoard curr_meta_board;
    char turn;
private:

public:
    // Constructor
    Game();

    // Destructors
    ~Game();
    
    // Accessor methods
    char GetTurn();

    // Mutator methods
    void Run();
    void ChangeTurn();

};
