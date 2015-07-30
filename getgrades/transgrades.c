#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Research disadvantages
 * of using this lib */
char* validStr = "detalleEvaluacion";

char* validateStr( int length, char* string );
FILE* cleanFile( FILE* fr );

int main( int argc, char* argv[] ){
	char* string = malloc( 50 );
	int error = 0;
	if( string == NULL )
		error++;
	FILE* fr = fopen( "./npm.htm", "r" );
	if( fr == NULL  )
		error++;
	FILE* fw = cleanFile( fr );
	if( error > 0 )
		exit(1);
	while( !feof( fr ) ){
		fgets( string, 50, fr );
	}
}

char* validateStr( int length, char* string ){
	
}

FILE* cleanFile( FILE* fr ){
	FILE* fw = fopen( "read.ht", "w" );
	if( fw == NULL )
		exit(1);
	char x;
	while( !feof( fr ) ){
		x = fgetc( fr );
		if( x != '\t' && x != 32 )
			fputc( x, fw );
	}
	rewind( fr );
	return fw;
}
