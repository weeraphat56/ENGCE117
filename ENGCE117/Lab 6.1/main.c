#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 20

struct studentNode {
    char name[NAME_SIZE];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);
void GoBack(struct studentNode *walk);
struct studentNode *AddNode(struct studentNode **start,
                             const char name[NAME_SIZE],
                             int age, char sex, float gpa);
void InsNode(struct studentNode *walk,
             struct studentNode **begin,
             const char name[NAME_SIZE],
             int age, char sex, float gpa);
void DelNode(struct studentNode **walk,
             struct studentNode **begin);

int main() {
    struct studentNode *start = NULL, *now;

    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);

    InsNode(now, &start, "three", 10, 'M', 3.33);
    ShowAll(start);

    InsNode(now, &start, "four", 12, 'F', 3.44);
    ShowAll(start);

    GoBack(now);

    DelNode(&now, &start);
    ShowAll(start);

    DelNode(&now, &start);
    ShowAll(start);

    DelNode(&now, &start);
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

void GoBack(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->back;
    }
    printf("\n");
}

struct studentNode *AddNode(struct studentNode **start,
                            const char name[NAME_SIZE],
                            int age, char sex, float gpa) {

    struct studentNode *newNode =
        (struct studentNode *)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;
    newNode->back = NULL;

    if (*start == NULL) {
        *start = newNode;
    } else {
        struct studentNode *temp = *start;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->back = temp;
    }

    return newNode;
}

void InsNode(struct studentNode *walk,
             struct studentNode **begin,
             const char name[NAME_SIZE],
             int age, char sex, float gpa) {

    struct studentNode *newNode =
        (struct studentNode *)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = walk;
    newNode->back = walk->back;

    if (walk->back != NULL)
        walk->back->next = newNode;
    else
        *begin = newNode;

    walk->back = newNode;
}

void DelNode(struct studentNode **walk,
             struct studentNode **begin) {

    struct studentNode *temp = *walk;

    if (temp->back != NULL)
        temp->back->next = temp->next;
    else
        *begin = temp->next;

    if (temp->next != NULL) {
        temp->next->back = temp->back;
        *walk = temp->next;
    } else {
        *walk = temp->back;
    }

    free(temp);
}