#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Research disadvantages
 * of using this lib */
char* validStr = "detalleEvaluacion";

char* validateStr( char* string );
FILE* cleanFile( FILE* fr );

int main( int argc, char* argv[] ){
	char* string = malloc( 200 );
	char* valid = malloc( 200 );
	int error = 0;
	if( string == NULL )
		error++;
	FILE* fr = fopen( "./npm.htm", "r" );
	if( fr == NULL  )
		error++;
	FILE* fw = cleanFile( fr );
	if( error > 0 )
		exit(1);
	while( !feof( fw ) ){
		fgets( string, 200, fw );
		valid = validateStr( string );
		printf( "%s", valid );
	}
}

char* validateStr( char* string ){
	char* details = "<tdclass='detalle";
	int i, count = 0;
	for( i = 0; i < 18; i++ ){
		if( details[i] == string[i] )
			count++;
	}
	if( count > 16 ){
		return string;
	}else{
		return "";
	}
}

FILE* cleanFile( FILE* fr ){
	FILE* fw = fopen( "read.ht", "rw" );
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
