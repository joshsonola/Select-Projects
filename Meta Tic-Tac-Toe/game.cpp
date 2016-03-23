#include <iostream>
#include <cstdio>
#include "game.hpp"


// Default Constructor
Game::Game() {
	MetaBoard curr_meta_board;
	turn = 'X';
}

// Deconstructor
Game::~Game() {
	
}

void Game::Run()
{	
	int num, board_num;
	Board overall_board;
	overall_board.PrintBoard();

	printf("Player X, pick your first board to play on: ");
	scanf("%d", &board_num);
	printf("Player X, please play on board number %d\n\n", board_num);

    while (overall_board.CheckWin() == 'f' && overall_board.TotalCount() != 9) {
		printf("\n\n");
		curr_meta_board.PrintMetaBoard();
		printf("Player %c, Enter your number for board %d: ", GetTurn(), board_num);
		scanf("%d", &num);
		
		// Do not allow a player to play on a square that has been played on
		while(curr_meta_board.MetaQuery(board_num, num) == 'X' || 
		curr_meta_board.MetaQuery(board_num, num) == 'O') {
			printf("Invalid square, please choose another square: ");
			scanf("%d", &num);
		}
		
		// Make the move on the respective board
		curr_meta_board.MetaPlace(board_num, num, GetTurn());	
		ChangeTurn();
		board_num = num;
		
		// Check if one of the smaller boards is solved or a draw occured
		// Mark the overall_board accordingly
		for (int i = 1; i < 10; i++) {
			if ((curr_meta_board.GetBoardWin(i) != 'f') 
			&& (overall_board.Query(i) != 'O' && overall_board.Query(i) != 'X'
			&& overall_board.Query(i) != 'D')) {
				printf("Board %d was solved by player %c\n", i, 
				curr_meta_board.GetBoardWin(i));
				overall_board.Place(i, curr_meta_board.GetBoardWin(i));
			}
			else if((curr_meta_board.GetBoardDraw(i)) 
			&& (overall_board.Query(i) != 'O' && overall_board.Query(i) != 'X' 
			&& overall_board.Query(i) != 'D')) {
				printf("Board %d was resulted in a draw", i);
				overall_board.Place(i, 'D');	
			}
		}
		printf("\n\n");
		overall_board.PrintBoard();	
	}
	// Determine why the game was stopped and display the proper result
	if (overall_board.CheckWin() != 'f') {
		ChangeTurn();
		printf("\n\nThree in a row, Player %c wins!!\n\n\n", GetTurn());
	}
	else // (overall_board.TotalCount() == 9) 
	{
		if (overall_board.CountX() > overall_board.CountO()) {
			printf("\n\nPlayer X has marked more %d boards than Player O"
			"\n\nPlayer X wins!!\n\n\n", overall_board.CountX() - 
			overall_board.CountO());
		}
		else if (overall_board.CountX() < overall_board.CountO()){
			printf("\n\nPlayer O has marked more %d boards than Player X"
			"\n\nPlayer O wins!!\n\n\n", overall_board.CountO() - 
			overall_board.CountX());
		}
		else {
			printf("Metatictactoe has resulted in a draw, both players"
			" marked %d boards \n\n\n", overall_board.CountO());
		}
	}	
	curr_meta_board.PrintMetaBoard();
		
}

char Game::GetTurn()
{
    return turn;
}

void Game::ChangeTurn()
{
    if (GetTurn() == 'X') 
    	turn = 'O';
    else
    	turn = 'X';
}

