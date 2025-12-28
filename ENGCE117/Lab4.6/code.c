#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void SaveNode( struct studentNode *child , char n[] , int a , char s , float g ) ;
void GoNext2( struct studentNode ***walk ) ;

int main() {
    struct studentNode *start , *now1 , **now2 ;
    char text[ 50 ] ;

    start = (struct studentNode *)malloc(sizeof(struct studentNode)) ;
    strcpy( text , "one" ) ;
    SaveNode( start , text , 6 , 'M' , 3.11 ) ;

    start->next = (struct studentNode *)malloc(sizeof(struct studentNode)) ;
    strcpy( text , "two" ) ;
    SaveNode( start->next , text , 8 , 'F' , 3.22 ) ;

    start->next->next = (struct studentNode *)malloc(sizeof(struct studentNode)) ;
    strcpy( text , "three" ) ;
    SaveNode( start->next->next , text , 10 , 'M' , 3.33 ) ;

    start->next->next->next = (struct studentNode *)malloc(sizeof(struct studentNode)) ;
    strcpy( text , "four" ) ;
    SaveNode( start->next->next->next , text , 12 , 'F' , 3.44 ) ;
    start->next->next->next->next = NULL ;

    now1 = start ;
    now2 = &now1 ; // แก้ไขให้ now2 ชี้ไปที่ now1 เพื่อให้ GoNext2 เลื่อนตำแหน่ง now1 ได้

    GoNext2( &now2 ) ;
    printf( "%s" , now1->name ) ;

    return 0 ;
}// end main function

void SaveNode( struct studentNode *child , char n[] , int a , char s , float g ) {
    strcpy( child->name , n ) ;
    child->age = a ;
    child->sex = s ;
    child->gpa = g ;
}// end SaveNode function

void GoNext2( struct studentNode ***walk ) {
    if ( walk == NULL || *walk == NULL || (**walk) == NULL ) {
        return ;
    }// end if
    **walk = (**walk)->next ;
}// end GoNext2 function