#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverse( const char *str1 ) ;

int main() {

    char text[ 50 ] = "I Love you" ;
    char *out ;
    out = reverse( text ) ;

    printf( "%s\n" , out ) ;

    free( out ) ;

    return 0 ;

}

char *reverse( const char *str1 ) {

    size_t str_size = strlen( str1 ) ;

    char *str2 ;
    str2 = (char *)malloc( str_size + 1 ) ;

    if (str2 == NULL) {
        return NULL;
    }

    size_t i ;

    for( i = 0 ; i < str_size ; i++ ) {
        str2[ str_size - i - 1 ] = str1[ i ] ;
    }

    str2[ str_size ] = '\0' ;

    return str2 ;

}// end reverse function