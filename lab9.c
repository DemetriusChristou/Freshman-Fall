// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	wordCount = readWords(wordlist, argv[1]);
	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		// add code to print the words to the screen here for part 1 
		for (i = 0; i < wordCount-1; i++) {
			
			if((i % 5) == 0) {//makes a new line if its the 5th item
				printf("\n");
			}
			
			printf("%15s", wordlist[i]);
		}
	}

// most of your code for part 2 goes here. Don't forget to include the ncurses library 

    return 0;
	}

void trimws(char* s) {
	int i;
	for (i = 0; i < WORDLEN; i++) {
		if (s[i] == ' ' || s[i] == '\0') {//if a space or NULL 
			s[i] = '\0';//replace the space with null
			return;
		}
	}
}

int readWords(char* wl[MAXWORDS], char* filename) {
	int i = 0;
	FILE* file;
	file = fopen(filename, "r");//opens a file for read only
	char temp[WORDLEN];//dont point this to NULL to initilize

	while (fscanf(file, " %s", temp) == 1) {
		//trimws(wl[i]);
		int length = strlen(temp);
		wl[i] = malloc(sizeof(char) *(length + 1));//allocates memory for a string of the temp size
		strcpy(wl[i], temp);//use strcpy to place one string into another
		i++;
		
	}
	fclose(file);
	return i + 1;//returns the num of items read
}