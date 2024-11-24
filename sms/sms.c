#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);

int main() {
    struct Student students[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addStudent(struct Student students[], int *count) {
    printf("\n--- Add Student ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Enter Name: ");
    getchar(); 
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0; 
    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);
    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo students to display!\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("---------------------------\n");
    }
}

void searchStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo students to search!\n");
        return;
    }

    int rollNumber;
    printf("\n--- Search Student ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student found!\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }
    printf("Student with Roll Number %d not found!\n", rollNumber);
}
