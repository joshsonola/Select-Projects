// board.cpp
#include "board.hpp" 
#include <cstdio>

// Default Constructor
Board::Board() {
	squares = new char[9];
	squares[0] = '1';
	squares[1] = '2';
	squares[2] = '3';
	squares[3] = '4';
	squares[4] = '5';
	squares[5] = '6';
	squares[6] = '7';
	squares[7] = '8';
	squares[8] = '9';
}

// Deconstructor
Board::~Board() {
	delete[] squares;
}


// Mutators 

void Board::Place(int num, char piece)
{
    squares[num - 1] = piece;
}

// Accessors 

char Board::Query(int num)
{
    return squares[num - 1];
}

char Board::CheckWin()
{
	if (Query(1) == Query(2) && Query(2) == Query(3) 
	&& Query(3) != 'D') 
		return Query(1);
	else if (Query(4) == Query(5) && Query(5) == Query(6) 
	&& Query(6) != 'D') 
		return Query(4);
	else if (Query(7) == Query(8) && Query(8) == Query(9)
	&& Query(9) != 'D') 
		return Query(7);
	else if (Query(1) == Query(4) && Query(4) == Query(7)
	&& Query(7) != 'D') 
		return Query(1);
	else if (Query(2) == Query(5) && Query(5) == Query(8)
	&& Query(8) != 'D') 
		return Query(2);
	else if (Query(3) == Query(6) && Query(6) == Query(9)
	&& Query(9) != 'D') 
		return Query(3);
	else if (Query(1) == Query(5) && Query(5) == Query(9)
	&& Query(9) != 'D') 
		return Query(1);
	else if (Query(7) == Query(5) && Query(5) == Query(3)
	&& Query(3) != 'D') 
		return Query(7);
    else 
    	return 'f';
}

int Board::TotalCount()
{
	int count, i;
	count = 0;
    for (i = 0; i < 9; i++) {
    	if (squares[i] == 'X' || squares[i] == 'O' || squares[i] == 'D') {
    		count += 1;
    	}
    }
    return count;
}

int Board::CountX()
{
	int count, i;
	count = 0;
    for (i = 0; i < 9; i++) {
    	if (squares[i] == 'X') {
    		count += 1;
    	}
    }
    return count;
}

int Board::CountO()
{
	int count, i;
	count = 0;
    for (i = 0; i < 9; i++) {
    	if (squares[i] == 'O') {
    		count += 1;
    	}
    }
    return count;
}

bool Board::CheckDraw()
{	
	// If there aren't 9 pieces on the board, there cannot be a draw
    if (TotalCount() != 9) {
    	return false;
    } 
    else {
    	if (CheckWin() == 'f')
    		return true;
    	else
    		return false;
    }
}

void Board::PrintBoard()
{	
	printf("%c | %c | %c\n", Query(1), Query(2), Query(3));
	printf("__|___|__\n");
	printf("%c | %c | %c\n", Query(4), Query(5), Query(6));
	printf("__|___|__\n");
	printf("%c | %c | %c\n", Query(7), Query(8), Query(9));
}
