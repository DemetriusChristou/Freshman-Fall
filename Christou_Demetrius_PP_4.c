/*		Demetrius Christou
	ddc@iastate.edu
	Cpre 185 Section E
	Programming Practice 1

	Reflection 1 - i was tying to improve my use of 2d arrays and also making my program use alot of functions.

	Reflection 2 - yes i think i was somewhat successful since i created a functioning game but was unable to find a way to check if the board i create is solvable.

	Reflection 3 - i think i would have tried to make the game more compatable with any board size other than 4 by 4

	Reflection 4 - the most valuable thing I learned was to use a bunch of different functions for each part of my code so that it is very easy to follow.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//prototypes
void initBoard(int board[][4], int size);
void printBoard(int board[][4]);
int findZero(int board[][4], int* i, int* j);
void moveRight(int board[][4]);
void moveLeft(int board[][4]);
void moveDown(int board[][4]);
void moveUp(int board[][4]);
int gameOver(int gameboard[][4], int wincondish[][4]);
void shuffleBoard(int sample[][4]);

int main() {
	char input;
	printf("Goal of the game is to put every number back in order with the bottom right value being 0(use WASD to move the numbers around)\n");
	int gameboard[4][4] = {11, 10, 8, 13, 3, 15, 0, 6, 4, 2, 14, 5, 12, 1, 7, 9};//starting board
	int wincondishion[4][4] = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 0};//goal of game is to make it look like this
	shuffleBoard(gameboard);
	printBoard(gameboard);

	while(!(gameOver(gameboard,wincondishion))) {

		printf("enter move (W, A, S, D):");
		scanf(" %c", &input);
		switch (input) {
			case 'A':case 'a':
				moveLeft(gameboard);
				printBoard(gameboard);
				break;
			case 'D':case 'd':
				moveRight(gameboard);
				printBoard(gameboard);
				break;
			case 'w':case 'W':
				moveUp(gameboard);
				printBoard(gameboard);
				break;
			case 's':case 'S':
				moveDown(gameboard);
				printBoard(gameboard);
				break;
			default:
				printf("not valid input\n");
				break;
		}
		printf("\n");

	}
	printf("you win!");
	return 1;
}

//functions
void initBoard(int board[][4], int size) {//just prints values in the array
	int i, j;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			printf("%d\n", board[i][j]);
		}
	}
}

int findZero(int board[][4], int* x, int* y) {//locates the zero so i know what point the user is talking about
	*x = 0;
	*y = 0;
	int i, j;
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			if(board[i][j] == 0) {//stops at first found 0 but there should only be one zero so it should be fine
				*x = i;
				*y = j;
				return 1;
			}
		}
	}
	return 0;
}

void moveRight(int board[][4]) {
	int i, j, temp;
	findZero(board, &i, &j);
	if((i - 1) < 0) {//error check
		printf("you cant do that dummy\n");
		return;
	}
	temp = board[i-1][j];
	board[i-1][j] = 0;
	board[i][j] = temp;
}
void moveLeft(int board[][4]) {
	int i, j, temp;
	findZero(board, &i, &j);
	if((i + 1) > 3) {//error check
		printf("you cant do that dummy\n");
		return;
	}
	temp = board[i+1][j];
	board[i+1][j] = 0;
	board[i][j] = temp;
}
void moveDown(int board[][4]) {
	int i, j, temp;
	findZero(board, &i, &j);
	if((j - 1) < 0) {//error checking
		printf("you cant do that dummy\n");
		return;
	}
	temp = board[i][j-1];
	board[i][j-1] = 0;
	board[i][j] = temp;
}
void moveUp(int board[][4]) {
	int i, j, temp;
	findZero(board, &i, &j);
	if((j + 1) > 3) {//error check
		printf("you cant do that dummy\n");
		return;
	}
	temp = board[i][j+1];
	board[i][j+1] = 0;
	board[i][j] = temp;
}

int gameOver(int gameboard[][4], int wincondish[][4]){
	int i, j;
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			if(gameboard[i][j] != wincondish[i][j]) {
				return 0;//game not over
			}
		}
	}
	return 1; //game over
}


void printBoard(int board[][4]) {
	printf(			"%4d%4d%4d%4d\n"
					"%4d%4d%4d%4d\n"
					"%4d%4d%4d%4d\n"
					"%4d%4d%4d%4d\n", board[0][0] , board[1][0], board[2][0], board[3][0], board[0][1], board[1][1], board[2][1], board[3][1],board[0][2],board[1][2],board[2][2],board[3][2],board[0][3],board[1][3],board[2][3],board[3][3]);
}

void shuffleBoard(int sample[][4]) {//this will shuffle the sample board to create a new board for each start
	int i, j, k, l;
	int temp;
	srand(time(0));//creates random seed
		for(i = 0; i < 4; i++) {
			for(j = 0; j < 4; j++) {//same code as what was shown by Dr.Daniels just modified for a 2d array.
				k = rand() % (i + 1);
				l = rand() % (j + 1);
				temp = sample[i][j];
				sample[i][j] = sample[k][l];
				sample[k][l] = temp;
		}
	}

}
