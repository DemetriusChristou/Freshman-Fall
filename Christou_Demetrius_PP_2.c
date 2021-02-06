/*		Demetrius Christou
	ddc@iastate.edu
	Cpre 185 Section E
	Programming Practice 2

	Reflection 1 - I was trying to learn how to better use loops and learn more about multidimentinal loops.

	Reflection 2 - yes, while this game of tic tac toe isnt perfect it shouldnt run into too many issues unless you are trying to break it.

	Reflection 3 - i would maybe not use a multidimentinal array and use a single array instead as it might be easier to use.

	Reflection 4 - i learned how to set up a multidimentinal array and also how to have a printf span multiple lines.
*/

#include <stdio.h>
//prototypes
void updateBoard(char board[][3]);
int gameOver(char board[0][3], int player);

int main() {
	int i, j, x, y;
	int currentPlayer = 1, game = 1;
	char board[3][3];
	
	for(i = 0; i < 3; i++) {//initalizes the board
		for(j = 0; j < 3; j++) {
			board[i][j] = ' '; //this sets the entire board to 0
		}
	}
	updateBoard(board);//prints empty board

	//game start
	while(game != 0) { //game 1 means on game 0 means off
		if(currentPlayer == 1) { //player 1 turn
			printf("player one enter your move(ex 0,0 will put your move in the top left 2 is the max number for either input)");
			scanf(" %d, %d", &x, &y);
			if(board[x][y] != ' ') { 
				board[x][y] = 'x';
			} else {
				printf("that space is already chosen choose another\n");
				scanf(" %d, %d", &x, &y);
				board[x][y] = 'x';
			}
			updateBoard(board);
			currentPlayer = 2; //switches player
		} else if(currentPlayer == 2) {//player 2 turn
			printf("player two enter your move(ex 0,0 will put your move in the top left 2 is the max number for either input)");
			scanf(" %d, %d", &x, &y);
			if(board[x][y] != ' ') { 
				board[x][y] = 'o';
			} else {
				printf("that space is already chosen choose another\n");
				scanf(" %d, %d", &x, &y);
				board[x][y]= 'o';
			}
			updateBoard(board);
			currentPlayer = 1; //switches player
		}
		//checks for game over
		if(gameOver(board, currentPlayer) == 1) {
			break;
		}

	}
	return 0;
}
//functions
void updateBoard(char board[][3]) {
	
	printf("  %c | %c | %c  \n"\
			"------------\n"\
			"  %c | %c | %c  \n"\
			"------------\n"\
			"  %c | %c | %c  \n", 
			  board[0][0], board[1][0], board[2][0],
			  board[0][1], board[1][1], board[2][1],
			  board[0][2], board[1][2], board[2][2]);
	
}
int gameOver(char board[0][3], int player) {
	//win by across
	if( ((board[0][0] == board[1][0]) && (board[2][0] == board[1][0]) && (board[0][0] != ' ') )|| // top row has same symbol and it isnt space
	   ((board[0][1] == board[1][1]) && (board[2][1] == board[1][1]) && (board[0][1] != ' ')) ||  // middle row has same symbol
	   ((board[0][2] == board[1][2]) && (board[2][2] == board[1][2]) && (board[0][2] != ' '))     // bottom row has same symbol
	   ) {
	   	printf("player %d loses", player);
		return 1; // game is over
	} else if( ((board[0][0] == board[0][1]) && (board[0][2] == board[0][1]) && (board[0][0] != ' ') )|| // first col has same symbol and it isnt space
	   ((board[1][0] == board[1][1]) && (board[1][2] == board[1][1]) && (board[1][0] != ' ')) ||  // middle col has same symbol
	   ((board[2][0] == board[2][1]) && (board[2][2] == board[2][1]) && (board[2][0] != ' '))     // right col has same symbol
	   ) {
	   	printf("player %d loses", player);
		return 1; // game is over
	} else if( ((board[0][0] == board[1][1]) && (board[2][2] == board[1][1]) && (board[0][0] != ' ') )|| // left diagonal has same symbol and it isnt space
	   ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] != ' '))    // right diagonal has same symbol
	   ) {
	   	printf("player %d loses", player);
		return 1; // game is over
	}
	return 0;//game not over
}