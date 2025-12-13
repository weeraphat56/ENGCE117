#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_SIZE 20
#define MAX_OUT_LEN 10
#define MAX_INPUT_LEN 50

void explode( char str1[] , char splitter , char str2[ MAX_ARRAY_SIZE ][ MAX_OUT_LEN ] , int *count ) ;

int main() {

    char str[ MAX_INPUT_LEN ] = "I/Love/You"  ;
    char out[ MAX_ARRAY_SIZE ][ MAX_OUT_LEN ] ;
    int num ;
    explode( str , '/' , out , &num ) ;
    
    int i = 0 ;

    for( i = 0 ; i < num ; i++ ) {
        printf( "str2[%d] = %s\n" , i , out[i] ) ;
    }// end for loop

    return 0 ;

}// end main function

void explode( char str1[] , char splitter , char str2[ MAX_ARRAY_SIZE ][ MAX_OUT_LEN ] , int *count ) {
   
    *count = 0 ;

    char word[ MAX_OUT_LEN ] ;
    int word_pos  = 0 ;

    int i = 0 ;

    while ( str1[ i ] != '\0' ) {
        if ( str1[ i ] == splitter ) {
            word[ word_pos ] = '\0' ;
            strcpy( str2[ *count ] , word ) ;
            *count += 1 ;
            word_pos = 0 ;
        }
        else{
            word[ word_pos++ ] = str1[ i ] ;
        }// end if else
        i++ ;
    }// end while loop

    word[ word_pos ] = '\0' ;
    strcpy( str2[ *count ] , word ) ;
    *count += 1 ;
}// end explode function