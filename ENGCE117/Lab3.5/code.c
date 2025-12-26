#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

// ฟังก์ชันคืนค่าเป็น Pointer ไปยัง Array 10 elements ของ struct student
struct student (*GetStudent(int *room))[10];

int main() {
    struct student (*children)[10];
    int group;

    children = GetStudent(&group);

    if (children == NULL) {
        return 1;
    }

    int showi;
    int showj;

    printf("\nROOM\tNAME\tAGE\tSEX\tGPA\n");
    printf("--------------------------------------------\n");
    for (showi = 0; showi < group; showi++) {
        for (showj = 0; showj < 10; showj++) {
            printf("%d\t%s\t%d\t%c\t%.2f\n", 
                   showi + 1, 
                   children[showi][showj].name, 
                   children[showi][showj].age, 
                   children[showi][showj].sex, 
                   children[showi][showj].gpa);
        }
    }

    // ใช้ free() แทน delete [] ในภาษา C
    free(children);
    
    return 0;
}

struct student (*GetStudent(int *room))[10] {
    printf("Enter number of rooms: ");
    if (scanf("%d", room) != 1) {
        return NULL;
    }

    if (*room <= 0) {
        return NULL;
    }

    // ใช้ malloc เพื่อจองหน่วยความจำแบบ Dynamic ในภาษา C
    // จองพื้นที่ขนาด (จำนวนห้อง * 10 คน * ขนาด struct)
    struct student (*child)[10] = malloc((*room) * sizeof(struct student[10]));

    if (child == NULL) {
        return NULL; // กรณี Memory เต็ม
    }

    int i = 0;
    int j = 0;

    for (i = 0; i < *room; i++) {
        printf("--- Room %d ---\n", i + 1);
        for (j = 0; j < 10; j++) {
            printf("Student %d Name: ", j + 1);
            scanf("%s", child[i][j].name);

            printf("Age: ");
            scanf("%d", &child[i][j].age);

            printf("Sex (M/F): ");
            scanf(" %c", &child[i][j].sex);

            printf("GPA: ");
            scanf("%f", &child[i][j].gpa);
            printf("\n");
        }
    }

    return child;
}// end GetStudent function