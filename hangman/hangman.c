#include <stdio.h>
#include <stdlib.h>

char* getword();

int main(void){
	char* word = getword(12);
	char guess;
	int i, count = 0, tries = 5;
	for( i = 0; i < 12; i++ ){
		if( (guess = getchar()) == word[i] )
			count++;
	}
	printf("You got %d matches\n");
}

char* getword(){
	char* word = malloc(12);
	int i;
	printf("Input a word (max. 11 characters): ");
	for( i = 0; i < 12; i++ ){
		if( (word[i] = getchar()) == '\n' ){
			word[i] = '\0';
			break;
		}else if(i == 12)
			word[i] == '\0';
	}
	return word;
}
