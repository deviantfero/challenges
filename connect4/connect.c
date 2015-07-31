#include <stdio.h>
#include <stdlib.h>
#include "Libs/libget.h"

int** genMatrix();
char* transMatrix( int** matrix );
void printMatrix( char* matrix );
void getData( int** matrix );
int compareData( int** matrix );

int main( int argc, char** argv ){
	int** dataMatrix = genMatrix();
	char* writeMatrix = transMatrix( dataMatrix );
	printMatrix( writeMatrix );
	do{
		getData( dataMatrix );
		writeMatrix = transMatrix( dataMatrix );
		printMatrix( writeMatrix );
	}while( !compareData( dataMatrix ) );
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
	int i, j = 0, f = 0; // f se refiere al numero de fila
	printf( " A  B  C  \n");
	for( i = 0; i < 9; i++ ){
		j++;
		printf( "|%c|", matrix[i] );
		if( j > 2 ){
			printf( "%d", ++f );
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
		collumn = getchar();
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

//validacion funcional para todas las filas.

int compareData( int** matrix ){
	int i = 0, j = 0, status = 0;
	int mv;
	for( i = 0; i < 3; i++ ){
		mv = matrix[i][j];
		if( mv == matrix[i][j + 1]  && mv == matrix[i][j + 2] && mv != 0 ){
			return 1;
		}
	}
	i = 0;
	for( j = 0; j < 3; j++ ){
		mv = matrix[i][j];
		if( mv == matrix[i + 1][j] && mv == matrix[i + 2][j] && mv != 0 ){
			return 1;
		}
	}
	j = 0; i = 0;
	mv = matrix[i][j];
	if( mv == matrix[i + 1][j + 1] && mv == matrix[i + 2][j + 2] && mv != 0 ){
		return 1;
	}
	i = 0; j = 2;
	mv = matrix[i][j];
	if( mv == matrix[i + 1][j - 1] && mv == matrix[i + 2][j - 2] && mv != 0 ){
		return 1;
	}
	return status;
}
