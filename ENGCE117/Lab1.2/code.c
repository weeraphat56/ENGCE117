#include <stdio.h>

void GetSet( int ** , int * ) ;

int main() {
    int *data, num;
    GetSet( &data, &num ) ;
    printf("%d", data[1] ) ;

    for( int i = 0 ; i < num ; i++ ) {
        printf("%d", data[ i ] ) ;
    }

    return 0 ;
}

void GetSet( int **data , int *num ) {
    int i = 0 ;

    if (scanf( "%d" , num ) != 1) {
        return ;
    }

    for( i = 0 ; i < *num ; i++ ) {
        scanf( "%d" , &data[ i ] ) ;
    }
}
