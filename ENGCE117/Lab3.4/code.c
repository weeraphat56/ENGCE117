#include <stdio.h>
#include <string.h>

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;

void GetStudent ( struct student child[ 20 ][ 10 ] , int *room ) ;

int main() {
    struct student children[ 20 ][ 10 ] ;
    int group ;
    int showi = 0 ;
    int showj = 0 ;

    GetStudent( children , &group ) ;

    printf( "ROOM\tNAME\tAGE\tSEX\tGPA\n" ) ;
    for( showi = 0 ; showi < group ; showi++ ) {
        for( showj= 0 ; showj < 10 ; showj++ ) {
            printf( "%d\t%s\t%d\t%c\t%.2f\n" , showi + 1 , children[ showi ][ showj ].name , children[ showi ][ showj ].age , children[ showi ][ showj ].sex , children[ showi ][ showj ].gpa ) ;
        }
    }

    return 0 ;
}

void GetStudent ( struct student child[ 20 ][ 10 ] , int *room ) {

    if ( scanf( "%d" , room ) != 1 ) {
        return ;
    }

    if ( *room < 0 || *room > 20 ) {
        return ;
    }

    int i = 0 ;
    int j = 0 ;

    for( i = 0 ; i < *room ; i++ ) {

        printf( "--- Room %d ---\n" , i + 1 ) ;

        for( j = 0 ; j < 10 ; j++ ) {
            char name[ 20 ] ;

            printf( "Name: " ) ;
            scanf( "%s" , name ) ;
            strcpy( child[ i ][ j ].name , name ) ;

            printf( "Age: " ) ;
            scanf( "%d" , &child[ i ][ j ].age ) ;

            printf( "Sex: " ) ;
            scanf(" %c", &child[i][j].sex ) ;

            printf("GPA: ");
            scanf("%f", &child[i][j].gpa ) ;

            printf( "\n" ) ;
        }// end for loop
    }// end for loop
}// end GetStudent function