#include <stdio.h>

void go( int **p , int *z ) ;

int main() {
    int *a ;
    int b = 10 ;
    int c = 20 ;

    go( &a , &b ) ;
    printf( "%d %p %p\n" , *a , a , &a ) ;
    go( &a , &c ) ;
    printf( "%d %p %p\n" , *a , a , &a ) ;

    return 0 ;
}

void go( int **p , int *z ) {
    *p = z ;
}