/*		Demetrius Christou
	ddc@iastate.edu
	Cpre 185 Section E
	Programming Practice 3

	Reflection 1 - I was trying to learn more about loops filled with characters. I was also interested in learning more about some basic types of encryptions.

	Reflection 2 - Yes, i was sucessful since this program can sucessfully encrypt messages.

	Reflection 3 - If starting again i probably would have tried to understand more about how encryption works because i had a hard time understanding the formulas i found on wikipedia.

	Reflection 4 - The most important thing i learned while making this was how to make an array of characters that can hold up to 100 characters. I felt this is a good way to input a large amount of data from a user.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <ctype.h>

#define MSGLENGTH 100
//prototypes
void ceasarCypher(const char message[], int size, int offset);
int offset(int num);
void vigernereCypher(const char message[], const char vigernereCypher[], int size, int keySize);
int keyLength(const char vigKey[], int size);

int main() {
	int offsetWord, i;
	char input;
	char message[MSGLENGTH] = {0};//sets the entire array to 0
	char vigKey[MSGLENGTH] = {0};
	printf("enter a message to be encoded:");
	gets(message);//this can take in a string with spaces
	for(i = 0; i < MSGLENGTH; i++) {
		message[i] = tolower(message[i]);
	}
	printf("%s\n", message );

	printf("do you want to encrypt with a ceasar cypher or a vigenere cypher(c/v)\n");
	scanf(" %c", &input);
	//encrypts message
	srand(time(NULL));
	offsetWord = rand() % 26;
	if(input == 'c') {
		ceasarCypher(message, MSGLENGTH, offsetWord);
	} else if (input == 'v') {
		printf("enter the key to use:");
		scanf("%s", vigKey);
		vigernereCypher(message, vigKey, MSGLENGTH, keyLength(vigKey, MSGLENGTH));
		}
   
    

	return 0;
}

void ceasarCypher(const char message[], int size, int offset) {//ceasar cypher offsets each char by a random number 
	int i;
	for(i = 0; i < MSGLENGTH; i++) {
    	if(((message[i] >= 'a') && (message[i] <= 'z') ) && (message[i] != ' ')) { 
    		if((message[i] + offset) > 'z') {
    			printf("%c",(message[i] - 'a' + offset) % 26  + 'a');//if it goes over z you have to set it back to 'a'
    		} else printf("%c",message[i] + offset);//if it doesnt go over z you can just add the offset
    	} else {
    		printf("%c", message[i] );
    	}
    }
}
int offset(int num) {//num is how much you want to offset by

	return rand() % num;
}
void vigernereCypher(const char message[], const char vigKey[], int size, int keySize) {
	//(messageletter + keyletter) % 26
	int i;
	for(i = 0; i < size; i++) {
		if (((message[i] >= 'a') && (message[i] <= 'z') ) && (message[i] != ' ')) { 
			printf("%c", ( (message[i] - 'a' + vigKey[i % keySize] - 'a') % 26) + 'a');
		} else { 
			printf("%c", message[i]);
		}
	}
}
int keyLength(const char vigKey[], int size) {//returns the size of the key
	int counter = 0;
	int i;
	for(i = 0; i < size; i++) {
		if (((vigKey[i] >= 'a') && (vigKey[i] <= 'z') ) && (vigKey[i] != ' ')) {
			counter++;
		}
	}
	return counter;
}