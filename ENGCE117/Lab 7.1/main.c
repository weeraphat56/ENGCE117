#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

struct LinkedList {
    struct studentNode *start;
    struct studentNode **now;
};

/* ===== LinkedList Functions ===== */

void InitList(struct LinkedList *list) {
    list->start = NULL;
    list->now = &(list->start);
}

void InsNode(struct LinkedList *list, const char n[], int a, char s, float g) {
    struct studentNode *newNode =
        (struct studentNode *)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    newNode->next = *(list->now);
    *(list->now) = newNode;
}

void DelNode(struct LinkedList *list) {
    if (*(list->now) != NULL) {
        struct studentNode *temp = *(list->now);
        *(list->now) = (*(list->now))->next;
        free(temp);
    }
}

void GoNext(struct LinkedList *list) {
    if (*(list->now) != NULL) {
        list->now = &((*(list->now))->next);
    }
}

void GoFirst(struct LinkedList *list) {
    list->now = &(list->start);
}

void ShowCurrent(struct LinkedList *list) {
    if (*(list->now) != NULL) {
        printf("%s %d %c %.2f\n",
               (*(list->now))->name,
               (*(list->now))->age,
               (*(list->now))->sex,
               (*(list->now))->gpa);
    }
}

void ShowAll(struct LinkedList *list) {
    struct studentNode *temp = list->start;
    while (temp != NULL) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList listA;
    struct LinkedList listB;
    struct LinkedList *listC;

    InitList(&listA);
    InitList(&listB);

    InsNode(&listA, "one", 1, 'A', 1.1);
    InsNode(&listA, "two", 2, 'B', 2.2);
    InsNode(&listA, "three", 3, 'C', 3.3);

    GoNext(&listA);
    ShowCurrent(&listA);

    InsNode(&listB, "four", 4, 'D', 4.4);
    InsNode(&listB, "five", 5, 'E', 5.5);
    InsNode(&listB, "six", 6, 'F', 6.6);

    GoNext(&listB);
    DelNode(&listB);
    ShowAll(&listB);

    listC = &listA;
    GoNext(listC);
    ShowCurrent(listC);

    listC = &listB;
    ShowAll(listC);

    return 0;
}