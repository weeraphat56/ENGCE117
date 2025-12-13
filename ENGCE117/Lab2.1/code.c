#include <stdio.h>
#include <string.h>

void reverse( char str1[] , char str2[] ) ;

int main() {

    char text[ 50 ] = "hello word" ;
    char out[ 50 ] ;
    reverse( text , out ) ;

    printf( "%s" , out ) ;

    return 0 ;
}// end main function

void reverse( char str1[] , char str2[] ) {

    int str_size = strlen( str1 ) ;
    int i = 0 ;

    for( i = 0 ; i < str_size ; i++ ) {
        str2[ str_size - i - 1 ] = str1[ i ] ;
    }// end for loop

    str2[ str_size + 1 ] = '\0' ;

}// end reverse function