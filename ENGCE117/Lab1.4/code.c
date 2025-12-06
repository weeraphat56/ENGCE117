#include <stdio.h>
#include <stdlib.h> 

int GetSet( int ** ) ; 

int main() {
    int *data = NULL; 
    int num = 0;
    int i = 0;

    num = GetSet( &data );

    if ( num > 0 && data != NULL ) {
        // Print the array elements
        for( i = 0 ; i < num ; i++ ) {
            printf( "\n%d" , data[i] );
        }

        // Free the dynamically allocated memory
        free(data);
        data = NULL;
    } 

    return 0 ;
} 

int GetSet( int **data ) {
    int num;
    int i = 0;
    
    // Read the desired array size
    if ( scanf( "%d" , &num ) != 1 ) {
        // Error on size input format
        return 0 ;
    }

    if ( num <= 0 ) {
        // Error on size value
        return 0 ;
    }
    
    // Allocate memory using malloc based on the input size 'num'
    *data = (int*) malloc( num * sizeof(int) ); 

    if ( *data == NULL ) {
        // Error on memory allocation
        return 0;
    }

    // Read the array elements
    for( i = 0 ; i < num ; i++ ) {
        if ( scanf( "%d" , &(*data)[i] ) != 1 ) {
             // Error on element input format
             free(*data); 
             *data = NULL;
             return 0;
        }
    }

    return num ;
}
