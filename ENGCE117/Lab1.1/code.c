#include <stdio.h>

int main() {
    int n , i ;

    if ( scanf( "%d" , &n ) != 1 ) {
        printf( "Error" ) ;
        return 0 ;
    }// end if

    if ( n <= 0 ) {
        printf( "Error" ) ;
        return 0 ;
    }// end if

    for ( i = 0 ; i < n ; i++ ) {
        printf( "[%d] Hello world\n" , i + 1 ) ;
    }// end for

    return 0 ;
}// end main function 