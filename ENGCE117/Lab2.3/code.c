#include <stdio.h>
#include <string.h>

void explode( char str1[] , char splitter , char str2[ 20 ][ 10 ] , int *count ) ;

int main() {

    char str[ 50 ] = "i/Love/you"  ;
    char out[ 20 ][ 10 ] ;
    int num ;
    explode( str , '/' , out , &num ) ;
    
    int i = 0 ;

    for( i = 0 ; i < num ; i++ ) {
        printf( "str2[%d] = %s\n" , i , out[i] ) ;
    }// end for loop

    return 0 ;

}// end main function

void explode( char str1[] , char splitter , char str2[ 20 ][ 10 ] , int *count ) {
   
    *count = 0 ;

    char word[10] ;
    int word_pos  = 0 ;

    int i = 0 ;

    while ( str1[ i ] != '\0' ) {
        if ( str1[ i ] == splitter ) {
            word[ word_pos + 1 ] = '\0' ;
            strcpy( str2[ *count ] , word ) ;
            *count += 1 ;
            word_pos = 0 ;
        }
        else{
            word[ word_pos ] = str1[ i ] ;
            word_pos++ ;
        }// end if else
        i++ ;
    }// end while loop

    word[ word_pos ] = '\0' ;
    strcpy( str2[ *count ] , word ) ;
    *count += 1 ;
}// end explode function