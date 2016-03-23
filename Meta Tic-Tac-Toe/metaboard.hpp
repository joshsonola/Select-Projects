// metaboard.hpp
#include "board.hpp"

/**
* @brief A two-dimensional vector class.
*/
class MetaBoard
{
    
private:
    Board * boards;
public:
    // Constructor
    MetaBoard();

    // Destructors
    ~MetaBoard();
    
    // Mutator methods
    void MetaPlace(int board_num, int num, char value);

    // Accesor methods
    char MetaQuery(int board_num, int num);
    char GetBoardWin(int board_num);
    char CheckBoardWin(int board_num);
    char MetaCheckWin();
    bool GetBoardDraw(int board_num);
    void PrintMetaBoard();

};
