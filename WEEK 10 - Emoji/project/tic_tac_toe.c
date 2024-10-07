#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define COMPUTER 1 
#define HUMAN 2 
#define SIDE 3 
#define COMPUTERMOVE 'O' 
#define HUMANMOVE 'X'  

struct Move { 
	int row, col; 
}; 

char player = 'x', opponent = 'o'; 

bool isMovesLeft(char board[3][3]) 
{ 
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) 
			if (board[i][j] == '_') 
				return true; 
	return false; 
} 
 
int evaluate(char b[3][3]) 
{ 
	for (int row = 0; row < 3; row++) { 
		if (b[row][0] == b[row][1] 
			&& b[row][1] == b[row][2]) { 
			if (b[row][0] == player) 
				return +10; 
			else if (b[row][0] == opponent) 
				return -10; 
		} 
	} 
 
	for (int col = 0; col < 3; col++) { 
		if (b[0][col] == b[1][col] 
			&& b[1][col] == b[2][col]) { 
			if (b[0][col] == player) 
				return +10; 

			else if (b[0][col] == opponent) 
				return -10; 
		} 
	} 

	if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) { 
		if (b[0][0] == player) 
			return +10; 
		else if (b[0][0] == opponent) 
			return -10; 
	} 

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) { 
		if (b[0][2] == player) 
			return +10; 
		else if (b[0][2] == opponent) 
			return -10; 
	} 
	return 0; 
} 
int minimax(char board[3][3], int depth, bool isMax) 
{ 
	int score = evaluate(board); 
	if (score == 10) 
		return score;  
	if (score == -10) 
		return score;  
	if (isMovesLeft(board) == false) 
		return 0; 

	if (isMax) { 
		int best = -1000; 
 
		for (int i = 0; i < 3; i++) { 
			for (int j = 0; j < 3; j++) { 
		 
				if (board[i][j] == '_') { 
		 
					board[i][j] = player; 
					int val 
						= minimax(board, depth + 1, !isMax); 
					if (val > best) { 
						best = val; 
					} 
 
					board[i][j] = '_'; 
				} 
			} 
		} 
		return best; 
	} 
	else { 
		int best = 1000; 
		for (int i = 0; i < 3; i++) { 
			for (int j = 0; j < 3; j++) { 
		 
				if (board[i][j] == '_') { 
					board[i][j] = opponent; 

					int val 
						= minimax(board, depth + 1, !isMax); 
					if (val < best) { 
						best = val; 
					} 
					board[i][j] = '_'; 
				} 
			} 
		} 
		return best; 
	} 
} 
struct Move findBestMove(char board[3][3]) 
{ 
	int bestVal = -1000; 
	struct Move bestMove; 
	bestMove.row = -1; 
	bestMove.col = -1;  
	for (int i = 0; i < 3; i++) { 
		for (int j = 0; j < 3; j++) { 
			if (board[i][j] == '_') {  
				board[i][j] = player;  
				int moveVal = minimax(board, 0, false); 
 
				board[i][j] = '_'; 
				if (moveVal > bestVal) { 
					bestMove.row = i; 
					bestMove.col = j; 
					bestVal = moveVal; 
				} 
			} 
		} 
	} 
	return bestMove; 
} 
void showBoard(char board[][SIDE]) 
{ 
	printf("\n\n"); 
	printf("\t\t\t %c | %c | %c \n", board[0][0], 
		board[0][1], board[0][2]); 
	printf("\t\t\t--------------\n"); 
	printf("\t\t\t %c | %c | %c \n", board[1][0], 
		board[1][1], board[1][2]); 
	printf("\t\t\t--------------\n"); 
	printf("\t\t\t %c | %c | %c \n\n", board[2][0], 
		board[2][1], board[2][2]); 
}  
void showInstructions() 
{ 
	printf("\t\t\t Tic-Tac-Toe\n\n"); 
	printf("Choose a cell numbered from 1 to 9 as below "
		"and play\n\n"); 

	printf("\t\t\t 1 | 2 | 3 \n"); 
	printf("\t\t\t--------------\n"); 
	printf("\t\t\t 4 | 5 | 6 \n"); 
	printf("\t\t\t--------------\n"); 
	printf("\t\t\t 7 | 8 | 9 \n\n"); 

	printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n"); 
} 
void initialise(char board[][SIDE], int moves[]) 
{ 
	srand(time(NULL)); 
	for (int i = 0; i < SIDE; i++) { 
		for (int j = 0; j < SIDE; j++) 
			board[i][j] = ' '; 
	}  
	for (int i = 0; i < SIDE * SIDE; i++) 
		moves[i] = i; 
	for (int i = 0; i < SIDE * SIDE; i++) { 
		int randIndex = rand() % (SIDE * SIDE); 
		int temp = moves[i]; 
		moves[i] = moves[randIndex]; 
		moves[randIndex] = temp; 
	} 
} 
void declareWinner(int whoseTurn) 
{ 
	if (whoseTurn == COMPUTER) 
		printf("COMPUTER has won\n"); 
	else
		printf("HUMAN has won\n"); 
}  
int rowCrossed(char board[][SIDE]) 
{ 
	for (int i = 0; i < SIDE; i++) { 
		if (board[i][0] == board[i][1] 
			&& board[i][1] == board[i][2] 
			&& board[i][0] != ' ') 
			return 1; 
	} 
	return 0; 
}  
int columnCrossed(char board[][SIDE]) 
{ 
	for (int i = 0; i < SIDE; i++) { 
		if (board[0][i] == board[1][i] 
			&& board[1][i] == board[2][i] 
			&& board[0][i] != ' ') 
			return 1; 
	} 
	return 0; 
} 
int diagonalCrossed(char board[][SIDE]) 
{ 
	if ((board[0][0] == board[1][1] 
		&& board[1][1] == board[2][2] 
		&& board[0][0] != ' ') 
		|| (board[0][2] == board[1][1] 
			&& board[1][1] == board[2][0] 
			&& board[0][2] != ' ')) 
		return 1; 

	return 0; 
} 
int gameOver(char board[][SIDE]) 
{ 
	return (rowCrossed(board) || columnCrossed(board) 
			|| diagonalCrossed(board)); 
} 

void playTicTacToe(int whoseTurn) 
{ 
	char board[SIDE][SIDE]; 
	int moves[SIDE * SIDE]; 


	initialise(board, moves); 

	showInstructions(); 

	int moveIndex = 0, x, y; 
	while (!gameOver(board) && moveIndex != SIDE * SIDE) { 
		if (whoseTurn == COMPUTER) { 

			char tempBoard[3][3]; 
			for (int i = 0; i < 3; i++) { 
				for (int j = 0; j < 3; j++) { 
					if (board[i][j] == 'X') { 
						tempBoard[i][j] = 'x'; 
					} 
					else if (board[i][j] == 'O') { 
						tempBoard[i][j] = 'o'; 
					} 
					else { 
						tempBoard[i][j] = '_'; 
					} 
				} 
			} 
			struct Move thisMove = findBestMove(tempBoard); 
			x = thisMove.row; 
			y = thisMove.col; 

			board[x][y] = COMPUTERMOVE; 
			printf("COMPUTER has put a %c in cell %d %d\n", 
				COMPUTERMOVE, x, y); 
			showBoard(board); 
			moveIndex++; 
			whoseTurn = HUMAN; 
		} 
		else if (whoseTurn == HUMAN) { 
			int move; 
			printf("Enter your move (1-9): "); 
			scanf("%d", &move); 
			if (move < 1 || move > 9) { 
				printf("Invalid input! Please enter a "
					"number between 1 and 9.\n"); 
				continue; 
			} 
			x = (move - 1) / SIDE; 
			y = (move - 1) % SIDE; 
			if (board[x][y] == ' ') { 
				board[x][y] = HUMANMOVE; 
				showBoard(board); 
				moveIndex++; 
				if (gameOver(board)) { 
					declareWinner(HUMAN); 
					return; 
				} 
				whoseTurn = COMPUTER; 
			} 
			else { 
				printf("Cell %d is already occupied. Try "
					"again.\n", 
					move); 
			} 
		} 
	} 

	
	if (!gameOver(board) && moveIndex == SIDE * SIDE) 
		printf("It's a draw\n"); 
	else { 
		if (whoseTurn == COMPUTER) 
			whoseTurn = HUMAN; 
		else if (whoseTurn == HUMAN) 
			whoseTurn = COMPUTER; 

		declareWinner(whoseTurn); 
	} 
} 
 
int main() 
{ 
	 
	playTicTacToe(COMPUTER); 

	return 0; 
}
