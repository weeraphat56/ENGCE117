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

/* ---------- Function Prototype ---------- */
void initList(struct LinkedList *ll);
void goFirst(struct LinkedList *ll);
void goNext(struct LinkedList *ll);
void goLast(struct LinkedList *ll);
void insNode(struct LinkedList *ll, char name[], int age, char sex, float gpa);
void delNode(struct LinkedList *ll);
int findNode(struct LinkedList *ll, char name[]);
void editNode(struct LinkedList *ll, char name[], int age, char sex, float gpa);
void showAll(struct LinkedList *ll);
void readfile(struct LinkedList *ll);
void writefile(struct LinkedList *ll);

/* ---------- Implementation ---------- */

void initList(struct LinkedList *ll) {
    ll->start = NULL;
    ll->now = &(ll->start);
}

void goFirst(struct LinkedList *ll) {
    ll->now = &(ll->start);
}

void goNext(struct LinkedList *ll) {
    if (*(ll->now) != NULL)
        ll->now = &((*(ll->now))->next);
}

void goLast(struct LinkedList *ll) {
    goFirst(ll);
    while (*(ll->now) != NULL)
        goNext(ll);
}

void insNode(struct LinkedList *ll, char name[], int age, char sex, float gpa) {
    struct studentNode *newNode = 
        (struct studentNode*) malloc(sizeof(struct studentNode));

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = *(ll->now);
    *(ll->now) = newNode;
}

void delNode(struct LinkedList *ll) {
    if (*(ll->now) != NULL) {
        struct studentNode *temp = *(ll->now);
        *(ll->now) = temp->next;
        free(temp);
    }
}

int findNode(struct LinkedList *ll, char name[]) {
    goFirst(ll);
    while (*(ll->now) != NULL) {
        if (strcmp((*(ll->now))->name, name) == 0)
            return 1;
        goNext(ll);
    }
    return 0;
}

void editNode(struct LinkedList *ll, char name[], int age, char sex, float gpa) {
    if (*(ll->now) != NULL) {
        strcpy((*(ll->now))->name, name);
        (*(ll->now))->age = age;
        (*(ll->now))->sex = sex;
        (*(ll->now))->gpa = gpa;
    }
}

void showAll(struct LinkedList *ll) {
    struct studentNode *temp = ll->start;
    printf("\n--- Student List ---\n");
    while (temp != NULL) {
        printf("%s %d %c %.2f\n",
               temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
    printf("--------------------\n");
}

void readfile(struct LinkedList *ll) {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) return;

    char name[20];
    char sex;
    int age;
    float gpa;

    while (fscanf(fp, "%s %d %c %f",
           name, &age, &sex, &gpa) != EOF) {
        goLast(ll);
        insNode(ll, name, age, sex, gpa);
    }
    fclose(fp);
}

void writefile(struct LinkedList *ll) {
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) return;

    goFirst(ll);
    while (*(ll->now) != NULL) {
        struct studentNode *curr = *(ll->now);
        fprintf(fp, "%s %d %c %.2f\n",
                curr->name, curr->age,
                curr->sex, curr->gpa);
        goNext(ll);
    }
    fclose(fp);
}

/* ---------- Main ---------- */

int main() {
    struct LinkedList listA;
    initList(&listA);
    readfile(&listA);

    int menu;
    char name[20], newName[20];
    char sex;
    int age;
    float gpa;

    do {
        printf("\nMenu (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Name: "); scanf("%s", name);
                printf("Age: "); scanf("%d", &age);
                printf("Sex: "); scanf(" %c", &sex);
                printf("GPA: "); scanf("%f", &gpa);
                goLast(&listA);
                insNode(&listA, name, age, sex, gpa);
                break;

            case 2:
                printf("Name to find: ");
                scanf("%s", name);
                if (findNode(&listA, name)) {
                    printf("New Name Age Sex GPA: ");
                    scanf("%s %d %c %f",
                          newName, &age, &sex, &gpa);
                    editNode(&listA, newName, age, sex, gpa);
                } else
                    printf("Not found\n");
                break;

            case 3:
                printf("Name to delete: ");
                scanf("%s", name);
                if (findNode(&listA, name))
                    delNode(&listA);
                else
                    printf("Not found\n");
                break;

            case 4:
                printf("Name to find: ");
                scanf("%s", name);
                if (findNode(&listA, name)) {
                    struct studentNode *curr = *(listA.now);
                    printf("Found: %s %d %c %.2f\n",
                           curr->name, curr->age,
                           curr->sex, curr->gpa);
                } else
                    printf("Not found\n");
                break;

            case 5:
                showAll(&listA);
                break;
        }

    } while (menu != 0);

    writefile(&listA);
    return 0;
}