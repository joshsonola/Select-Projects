// board.hpp

/**
* @brief A two-dimensional vector class.
*/
class Board
{
    char * squares;
private:

public:
    // Constructor
    Board();

    // Destructors
    ~Board();
    
    // Mutator methods
    void Place(int num, char value);

    // Accesor methods
    char Query(int num);
    char CheckWin();
    bool CheckDraw();
    int TotalCount();
    int CountX();
    int CountO();
    void PrintBoard();

};

