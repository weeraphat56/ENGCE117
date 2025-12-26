#include <stdio.h>

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;

void upgrade( struct student *child ) ;

int main() {
    struct student aboy ;
    aboy.sex = 'M' ;
    aboy.gpa = 3.00 ;
    
    upgrade( &aboy ) ;

    printf( "%.2f" , aboy.gpa ) ;

    return 0 ;
}// end main function

void upgrade( struct student *child ) {
    if ( child->sex = 'M' ) {
        child->gpa *= 1.1 ;
    }
    else {
        child->gpa *= 1.2 ;
    }// end if else
}// end upgrade function