#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[50];
    int isAvailable; 
};

void addBook(struct Book books[], int *count);
void displayBooks(struct Book books[], int count);
void searchBook(struct Book books[], int count);

int main() {
    struct Book books[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
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

void addBook(struct Book books[], int *count) {
    printf("\n--- Add Book ---\n");
    printf("Enter Book ID: ");
    scanf("%d", &books[*count].id);
    printf("Enter Book Title: ");
    getchar(); 
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = 0; 
    printf("Enter Author Name: ");
    fgets(books[*count].author, sizeof(books[*count].author), stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = 0; 
    books[*count].isAvailable = 1; 
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(struct Book books[], int count) {
    if (count == 0) {
        printf("\nNo books to display!\n");
        return;
    }

    printf("\n--- Library Books ---\n");
    for (int i = 0; i < count; i++) {
        printf("Book ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Availability: %s\n", books[i].isAvailable ? "Available" : "Issued");
        printf("---------------------------\n");
    }
}

void searchBook(struct Book books[], int count) {
    if (count == 0) {
        printf("\nNo books to search!\n");
        return;
    }

    int id;
    printf("\n--- Search Book ---\n");
    printf("Enter Book ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("Book found!\n");
            printf("Book ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Availability: %s\n", books[i].isAvailable ? "Available" : "Issued");
            return;
        }
    }
    printf("Book with ID %d not found!\n", id);
}
