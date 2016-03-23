// board.cpp
#include "metaboard.hpp"
#include <cstdio>

// Default Constructor
MetaBoard::MetaBoard() {
	boards = new Board[9];
}

// Deconstructor
MetaBoard::~MetaBoard() {
	delete[] boards;
}


// Mutators 

void MetaBoard::MetaPlace(int board_num, int num, char piece)
{
    boards[board_num - 1].Place(num, piece);
}

// Accessors 

char MetaBoard::GetBoardWin(int board_num)
{
    return boards[board_num - 1].CheckWin();
}

char MetaBoard::MetaQuery(int board_num, int num)
{
    return boards[board_num - 1].Query(num);
}

char MetaBoard::CheckBoardWin(int board_num)
{
	if (MetaQuery(board_num, 1) == MetaQuery(board_num, 2) 
		&& MetaQuery(board_num, 2) == MetaQuery(board_num, 3)) 
		return MetaQuery(board_num, 1);
	else if (MetaQuery(board_num, 4) == MetaQuery(board_num, 5) 
		&& MetaQuery(board_num, 5) == MetaQuery(board_num, 6)) 
		return MetaQuery(board_num, 4);
	else if (MetaQuery(board_num, 7) == MetaQuery(board_num, 8) 
		&& MetaQuery(board_num, 8) == MetaQuery(board_num, 9)) 
		return MetaQuery(board_num, 7);
	else if (MetaQuery(board_num, 1) == MetaQuery(board_num, 4) 
		&& MetaQuery(board_num, 4) == MetaQuery(board_num, 7)) 
		return MetaQuery(board_num, 1);
	else if (MetaQuery(board_num, 2) == MetaQuery(board_num, 5) 
		&& MetaQuery(board_num, 5) == MetaQuery(board_num, 8)) 
		return MetaQuery(board_num, 2);
	else if (MetaQuery(board_num, 3) == MetaQuery(board_num, 6) 
		&& MetaQuery(board_num, 6) == MetaQuery(board_num, 9)) 
		return MetaQuery(board_num, 3);
	else if (MetaQuery(board_num, 1) == MetaQuery(board_num, 5) 
		&& MetaQuery(board_num, 5) == MetaQuery(board_num, 9)) 
		return MetaQuery(board_num, 1);
	else if (MetaQuery(board_num, 7) == MetaQuery(board_num, 5) 
		&& MetaQuery(board_num, 5) == MetaQuery(board_num, 3)) 
		return MetaQuery(board_num, 7);
    else 
    	return 'f';
}

char MetaBoard::MetaCheckWin()
{
    if (CheckBoardWin(1) == CheckBoardWin(2) 
    	&& CheckBoardWin(2) == CheckBoardWin(3)) 
		return CheckBoardWin(1);
	else if (CheckBoardWin(1) == CheckBoardWin(2) 
    	&& CheckBoardWin(2) == CheckBoardWin(3)) 
		return CheckBoardWin(1);
	else if (CheckBoardWin(1) == CheckBoardWin(2) 
    	&& CheckBoardWin(2) == CheckBoardWin(3)) 
		return CheckBoardWin(1);
	else if (CheckBoardWin(1) == CheckBoardWin(2) 
    	&& CheckBoardWin(2) == CheckBoardWin(3)) 
		return CheckBoardWin(1);
	else if (CheckBoardWin(1) == CheckBoardWin(2) 
    	&& CheckBoardWin(2) == CheckBoardWin(3)) 
		return CheckBoardWin(1);
	else if (CheckBoardWin(1) == CheckBoardWin(2) 
    	&& CheckBoardWin(2) == CheckBoardWin(3)) 
		return CheckBoardWin(1);
	else if (CheckBoardWin(1) == CheckBoardWin(2) 
    	&& CheckBoardWin(2) == CheckBoardWin(3)) 
		return CheckBoardWin(1);
	else if (CheckBoardWin(1) == CheckBoardWin(2) 
    	&& CheckBoardWin(2) == CheckBoardWin(3)) 
		return CheckBoardWin(1);
    else 
    	return 'f';
}

bool MetaBoard::GetBoardDraw(int board_num)
{	
    return boards[board_num - 1].CheckDraw();
}

void MetaBoard::PrintMetaBoard()
{	
	printf("%c | %c | %c\t%c | %c | %c\t%c | %c | %c\n", 
		MetaQuery(1, 1), MetaQuery(1, 2), MetaQuery(1, 3), 
		MetaQuery(2, 1), MetaQuery(2, 2), MetaQuery(2, 3), 
		MetaQuery(3, 1), MetaQuery(3, 2), MetaQuery(3, 3));
	printf("__|___|__\t__|___|__\t__|___|__\n");
	printf("%c | %c | %c\t%c | %c | %c\t%c | %c | %c\n", 
		MetaQuery(1, 4), MetaQuery(1, 5), MetaQuery(1, 6), 
		MetaQuery(2, 4), MetaQuery(2, 5), MetaQuery(2, 6), 
		MetaQuery(3, 4), MetaQuery(3, 5), MetaQuery(3, 6));
	printf("__|___|__\t__|___|__\t__|___|__\n");
	printf("%c | %c | %c\t%c | %c | %c\t%c | %c | %c\n\n\n", 
		MetaQuery(1, 7), MetaQuery(1, 8), MetaQuery(1, 9), 
		MetaQuery(2, 7), MetaQuery(2, 8), MetaQuery(2, 9), 
		MetaQuery(3, 7), MetaQuery(3, 8), MetaQuery(3, 9));


	printf("%c | %c | %c\t%c | %c | %c\t%c | %c | %c\n", 
		MetaQuery(4, 1), MetaQuery(4, 2), MetaQuery(4, 3), 
		MetaQuery(5, 1), MetaQuery(5, 2), MetaQuery(5, 3), 
		MetaQuery(6, 1), MetaQuery(6, 2), MetaQuery(6, 3));
	printf("__|___|__\t__|___|__\t__|___|__\n");
	printf("%c | %c | %c\t%c | %c | %c\t%c | %c | %c\n", 
		MetaQuery(4, 4), MetaQuery(4, 5), MetaQuery(4, 6), 
		MetaQuery(5, 4), MetaQuery(5, 5), MetaQuery(5, 6), 
		MetaQuery(6, 4), MetaQuery(6, 5), MetaQuery(6, 6));
	printf("__|___|__\t__|___|__\t__|___|__\n");
	printf("%c | %c | %c\t%c | %c | %c\t%c | %c | %c\n\n\n", 
		MetaQuery(4, 7), MetaQuery(4, 8), MetaQuery(4, 9), 
		MetaQuery(5, 7), MetaQuery(5, 8), MetaQuery(5, 9), 
		MetaQuery(6, 7), MetaQuery(6, 8), MetaQuery(6, 9));


	printf("%c | %c | %c\t%c | %c | %c\t%c | %c | %c\n", 
		MetaQuery(7, 1), MetaQuery(7, 2), MetaQuery(7, 3), 
		MetaQuery(8, 1), MetaQuery(8, 2), MetaQuery(8, 3), 
		MetaQuery(9, 1), MetaQuery(9, 2), MetaQuery(9, 3));
	printf("__|___|__\t__|___|__\t__|___|__\n");
	printf("%c | %c | %c\t%c | %c | %c\t%c | %c | %c\n", 
		MetaQuery(7, 4), MetaQuery(7, 5), MetaQuery(7, 6), 
		MetaQuery(8, 4), MetaQuery(8, 5), MetaQuery(8, 6), 
		MetaQuery(9, 4), MetaQuery(9, 5), MetaQuery(9, 6));
	printf("__|___|__\t__|___|__\t__|___|__\n");
	printf("%c | %c | %c\t%c | %c | %c\t%c | %c | %c\n\n\n", 
		MetaQuery(7, 7), MetaQuery(7, 8), MetaQuery(7, 9), 
		MetaQuery(8, 7), MetaQuery(8, 8), MetaQuery(8, 9), 
		MetaQuery(9, 7), MetaQuery(9, 8), MetaQuery(9, 9));
}
