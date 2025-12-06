#include <stdio.h>
#include <stdlib.h> 

int *GetMatrix( int *row , int *col ) ;

int main() {
    int *data = NULL;
    int m = 0;
    int n = 0;
    data = GetMatrix( &m , &n ) ;

    if (data != NULL && m > 0 && n > 0) {
        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                printf("%d %d : %d \n" , i , j , data[ i * m + j ] ) ;
            }
        }
        
        free(data); 
    }
    
    return 0 ;
}

int *GetMatrix( int *row , int *col ) {
    printf( "Row: " );
    if ( scanf( "%d" , row ) != 1 ) {
        printf( "Error\n" );
        return NULL;
    }

    printf( "Column: " );
    if ( scanf( "%d" , col ) != 1 ) {
        printf( "Error\n" );
        return NULL;
    }

    if ( *row <= 0 || *col <= 0 ) {
        printf( "Error\n" );
        return NULL;
    }

    int size = *row * *col ;
    int *value = NULL;
    
    value = (int*) malloc( size * sizeof(int) ); 

    if (value == NULL) { 
        printf("Error: Memory Allocation Failed\n");
        return NULL;
    }
    
    int i = 0 ;
    int j = 0 ;
    
    printf("Enter %d elements (Row by Row):\n", size);

    for( i = 0 ; i < *row ; i++ ) {
        for( j = 0 ; j < *col ; j++ ) {
            printf("Input value for [%d][%d]: ", i, j);
            if (scanf( "%d" , &value[ i * *row + j ] ) != 1) {
                printf("Input Error\n");
                free(value);
                return NULL;
            }
        }
    }

    return value;
}
