#include <stdio.h>
#include <stdlib.h> 

int *GetSet( int* ) ;

int main() {
    int *data = NULL , num ; 

    data = GetSet( &num ) ;

    if ( data != NULL ) {
        free(data) ; 
    }

    return 0 ;
}

int *GetSet( int *num ) {
    if ( scanf( "%d" , num ) != 1 ) {
        printf( "Array size input error\n" ) ;
        return NULL ;
    }

    if ( *num <= 0 ) {
        printf( "Array size must be positive number\n" ) ;
        return NULL ;
    }

    int *arr = (int*) malloc( (*num) * sizeof(int) ) ; 
    
    if (arr == NULL) {
        printf( "Memory allocation failed\n" ) ;
        return NULL;
    }
    
    int i = 0 ;

    for( i = 0 ; i < *num ; i++ ) {
        scanf( "%d" , &arr[ i ] ) ;
    }

    return arr ; 
}
