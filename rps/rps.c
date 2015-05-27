#include <stdio.h>
#include <stdlib.h>

typedef enum {rock,paper,scissors} choice;

int main(void){
	choice player;
	time_t t; //data that saves time format
	//time(&t); fills this data
	srand( (unsigned) time(&t) );//Random Seed
	choice enemy = rand() % 3; //uses t to get a random number
	printf("Choose\n\t1. Rock\n\t2. Paper\n\t3. Scissors\n>");
	scanf("%d",&player); player-=1;
	if(player < 0 || player > 2){
		printf("Wrong number!\n");
		exit(1);
	}
	if(player == enemy)
		printf("It's a DRAW!");
	else if(player == 0 && enemy == 1)
		printf("You LOST! Enemy chose paper!\n");
	else if(player == 0 && enemy == 2)
		printf("You WON! enemy chose scissors");
	else if(player == 1 && enemy == 0)
		printf("You WON! Enemy chose paper!\n");
	else if(player == 1 && enemy == 2)
		printf("You LOST! enemy chose scissors\n");
	else if(player == 2 && enemy == 0)
		printf("You LOST! Enemy chose rock!\n");
	else if(player == 2 && enemy == 1)
		printf("You WON! enemy chose paper\n");
}

