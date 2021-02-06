/*		Demetrius Christou
	ddc@iastate.edu
	Cpre 185 Section E
	Programming Practice 5

	Reflection 1 - I was trying to find creative ways to play with strings and learn a little about structs

	Reflection 2 - yes, i was able to show users many things about what they inputted.

	Reflection 3 - i would have tried to find more premade string functions to make things a little easier

	Reflection 4 - this practice allowed me to play with basic pointers and also allowed me to use malloc while also helping me learn how to use structs
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORDS 100


struct frequency
{
	char letter;
	int value;
} frequency;
 //proto
int numAlpha(char* word);
int numNumbers(char* word);
void output(char* word);
void init(struct frequency array[]);
void freq(struct frequency array[], char* word);
int mostCommon(struct frequency array[]);



int main() {
	char* temp;
	char* word; //array of char
	struct frequency alpha[26]; 
	
	

	printf("enter a string:");
	gets(temp);//use gets instead of scanf in order to catch multiple words
	word = (char*)malloc( sizeof(char) * strlen(temp) + 1);//creates a space large enough to hold the string + 1 for NULL
	strcpy(word, temp);//places the string into word
	output(word);
	init(alpha);
	freq(alpha, word);
	printf("the most common letter is %c it occured %d times \n", alpha[mostCommon(alpha)].letter, alpha[mostCommon(alpha)].value);

	return 0;
}

int numAlpha(char* word) {
	int ret = 0, i;

	for(i = 0; i < strlen(word); i++) {
		if(isalpha(word[i])) {
			ret++;
		}
	}

	return ret;
}

int numNumbers(char* word) {
	int ret = 0, i;

	for(i = 0; i < strlen(word); i++) {
		if(isdigit(word[i])) {
			ret++;
		}
	}

	return ret;
}

void output(char* word) {
	printf("number of alphabetic characters: %d\n", numAlpha(word));
	printf("number of numbers: %d\n", numNumbers(word));
}

void freq(struct frequency array[], char* word) {
	int i, ascii;
	for(i = 0; i < strlen(word); i++) {
		if(isalpha(word[i]) && (word[i] <= 'z')) {
			ascii = word[i];
			array[ascii - 'a' ].value += 1;
		}
	}
}

void init(struct frequency array[]) {
	int i;
	for(i = 0; i < 26; i++) {
		array[i].letter = 'a' + i;
		array[i].value = 0;
	}
}

int mostCommon(struct frequency array[]) {
	int greatest = array[0].value;
	int ret;
	int i;
	for(i = 0; i<26; i++) {
		if(greatest <= array[i].value) {
			greatest = array[i].value;
			ret = i;
		}
	}
	return ret;
}


