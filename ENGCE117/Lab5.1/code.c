#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void ShowAll(struct studentNode *walk);
struct studentNode *AddNode(struct studentNode **walk, const char name[20], int age, char sex, float gpa);
void InsNode(struct studentNode *walk, const char name[20], int age, char sex, float gpa);
void DelNode(struct studentNode *walk);

int main() {
    struct studentNode *start = NULL;
    struct studentNode *now = NULL;

    
    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);

    
    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(start);

   
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

struct studentNode *AddNode(struct studentNode **walk, const char name[20], int age, char sex, float gpa) {
    
    while (*walk != NULL) {
        walk = &(*walk)->next;
    }

    
    *walk = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy((*walk)->name, name);
    (*walk)->age = age;
    (*walk)->sex = sex;
    (*walk)->gpa = gpa;
    (*walk)->next = NULL;

    return *walk;
}

void InsNode(struct studentNode *walk, const char name[20], int age, char sex, float gpa) {
    if (walk == NULL) return;
    
    struct studentNode *temp = walk->next;
    walk->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(walk->next->name, name);
    walk->next->age = age;
    walk->next->sex = sex;
    walk->next->gpa = gpa;
    walk->next->next = temp;
}

void DelNode(struct studentNode *walk) {
    if (walk == NULL || walk->next == NULL) return;

    struct studentNode *temp = walk->next->next;
    free(walk->next); 
    walk->next = temp;
}//end function