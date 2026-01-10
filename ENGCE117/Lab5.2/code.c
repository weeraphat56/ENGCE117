#include <stdio.h>
#include <string.h>
#include <stdlib.h> /

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void ShowAll(struct studentNode *walk);
void GoNext(struct studentNode ***walk);
void InsNode(struct studentNode **walk, const char name[20], int age, char sex, float gpa);
void DelNode(struct studentNode **walk);

int main() {
    struct studentNode *start = NULL;
    struct studentNode **now = &start; 

    
    InsNode(now, "one", 6, 'M', 3.11);
    InsNode(now, "two", 8, 'F', 3.22); 
    
    GoNext(&now); 
    ShowAll(start);

    InsNode(now, "three", 10, 'M', 3.33);
    InsNode(now, "four", 12, 'F', 3.44);
    
    GoNext(&now);
    DelNode(now); 
    ShowAll(start);

    return 0;
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}


void GoNext(struct studentNode ***walk) {
    if ((**walk) != NULL) {
        *walk = &((**walk)->next);
    }
}

void InsNode(struct studentNode **walk, const char name[20], int age, char sex, float gpa) {
    
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = *walk; 
    *walk = newNode;       
}

void DelNode(struct studentNode **walk) {
    if (*walk == NULL) return;
    
    struct studentNode *temp = *walk;
    *walk = (*walk)->next; 
    free(temp);            
}// end function