#include <stdio.h>
#include <stdlib.h>
#include "Libs/libget.h"

int** genMatrix();
char* transMatrix( int** matrix );
void printMatrix( char* matrix );
void getData( int** matrix );

int main( int argc, char** argv ){
	int** dataMatrix = genMatrix();
	char* writeMatrix = transMatrix( dataMatrix );
	printMatrix( writeMatrix );
	getData( dataMatrix );
	writeMatrix = transMatrix( dataMatrix );
	printMatrix( writeMatrix );
}

//generates data matrix

int** genMatrix(){
	int i, j;
	int** matrix = malloc( sizeof( int* ) * 3 );
	for( i = 0; i < 3; i++ ){
		matrix[i] = malloc( sizeof( int ) * 3 );
	}
	for( i = 0; i < 3; i++ ){
		for( j = 0; j < 3; j++ ){
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

//translates and readies the data to be printed

char* transMatrix( int** matrix ){
	int i, j, k = 0;
	char* charMatrix = malloc( 9 );
	for( i = 0; i < 3; i++ ){
		for( j = 0; j < 3; j++ ){
			switch( matrix[i][j] ){
				case 1:
					charMatrix[k] = 'X';
					k++;
					break;
				case 2:
					charMatrix[k] = 'O';
					k++;
					break;
				case 0:
					charMatrix[k] = ' ';
					k++;
					break;
			}
		}
	}
	return charMatrix;
}

//prints the data

void printMatrix( char* matrix ){
	int i, j = 0, c = 0;
	printf( " A  B  C  \n");
	for( i = 0; i < 9; i++ ){
		j++;
		printf( "|%c|", matrix[i] );
		if( j > 2 ){
			printf( "%d", ++c );
			printf( "\n" );
			j = 0;
		}
	}
}

void getData( int** matrix ){
	char collumn; int i;
	int row;
	printf( "Wich column ?: " );
	collumn = getchar();
	while( collumn != 'A' && collumn != 'B' && collumn != 'C' ){
		printf( "Not a valid collumn! please enter a new one: " );
		collumn = 'A';
	}
	switch(collumn){
		case 'A':
			i = 0;
			break;
		case 'B':
			i = 1;
			break;
		case 'C':
			i = 2;
	}
	printf( "Wich row ?: " );
	row = getint();
	while( row > 3 && row < 1 ){
		printf( "Not a valid row number, please enter a new one: " );
		row = getint();
	}
	printf( "input 1 for an X, 2 for an O: " );
	matrix[row - 1][i] = getint();
	while( matrix[i][row - 1] < 1 && matrix[i][row - 1] > 2 ){
		printf( "Please enter a valid option: " );
		matrix[row - 1][i] = getint();
	}

}
