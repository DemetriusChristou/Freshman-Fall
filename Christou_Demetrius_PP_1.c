/*		Demetrius Christou
	ddc@iastate.edu
	Cpre 185 Section E
	Programming Practice 1

	Reflection 1 - i was trying to learn how to use arrays of numbers. also i was trying to practice my use of functions.
	i also wanted to find a way to make a somewhat interactive interface on the program to make it more enjoyable to use.

	Reflection 2 - yes i think i was sucessful since i managed to making a functioning program that can do 5 different functions.

	Reflection 3 - i would try to find a way to have the function work with any amount of numbers so that i could fully use the array of numbers.

	Reflection 4 - the most valuable thing I learned was to use functions in general to minimize the amount of code inside the main function. 
	this helps to keep things uncluttered and easy to read even if it may take a little longer to implement.
*/

#include <stdio.h>
//prototypes
int greatestNum(int num1, int num2, int num3, int num4);
int smallestNum(int num1, int num2, int num3, int num4);
void listEven(int num1, int num2, int num3, int num4);

int main() {
	int nums[3];
	int command;
	printf("Enter four numbers: ");
	scanf(" %d, %d, %d, %d", &nums[0], &nums[1], &nums[2], &nums[3]);
	while(1) { 
		printf("enter command (1 re-enter numbers, 2 greatest number in list, 3 smallest number, 4 returns what numbers are even or odd, 5 exit)\n");
		scanf("%d", &command);
		if(command == 5) {
			return 0; //this ends the while loop to stop the program
		} else if(command == 1) { 
			printf("Enter four numbers: ");
			scanf(" %d, %d, %d, %d", &nums[0], &nums[1], &nums[2], &nums[3]);
		} else if(command == 2) {
			printf("The greatest number is %d. \n", greatestNum(nums[0], nums[1], nums[2], nums[3]) );
		} else if(command == 3) {
			printf("The smallest number is %d. \n", smallestNum(nums[0], nums[1], nums[2], nums[3]) );
		} else if(command == 4) {
			printf("the list is ");
			listEven(nums[0], nums[1], nums[2], nums[3]);
		}
	}
}
//functions
int greatestNum(int num1, int num2, int num3, int num4) {//compares every number to then return the largest value.
	int greatestNum;
	if(num1 >= num2) {
		greatestNum = num1; // instead of comparing every single number i can instead just test the largest from the first if statement with the rest.
	} else {
		greatestNum = num2;
	}
	if (num3 >= greatestNum) {
		greatestNum = num3;
	}
	if (num4 >= greatestNum) {
		greatestNum = num4;
	}
	return greatestNum;
}

int smallestNum(int num1, int num2, int num3, int num4) {//compares every number to return the smallest value
	int smallestNum;
	if(num1 <= num2) {
		smallestNum = num1;
	} else {
		smallestNum = num2;
	}
	if (num3 <= smallestNum) {
		smallestNum = num3;
	}
	if (num4 <= smallestNum) {
		smallestNum = num4;
	}
	return smallestNum;
}

void listEven(int num1, int num2, int num3, int num4) {//tells if numbers are even or odd
	if(num1 % 2 == 0) { // if a number is divisible by 2 then its even.
		printf("even, " );
	} else {
		printf("odd, ");
	}
	if(num2 % 2 == 0) {
		printf("even, " );
	} else {
		printf("odd, ");
	}
	if(num3 % 2 == 0) {
		printf("even, " );
	} else {
		printf("odd, ");
	}
	if(num4 % 2 == 0) {
		printf("even\n" );
	} else {
		printf("odd\n");
	}
}