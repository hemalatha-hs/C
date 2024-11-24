#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    int id;
    char name[50];
    int votes;
};

void addCandidate(struct Candidate candidates[], int *candidateCount);
void castVote(struct Candidate candidates[], int candidateCount);
void viewResults(struct Candidate candidates[], int candidateCount);

int main() {
    struct Candidate candidates[100];
    int candidateCount = 0;
    int choice;

    while (1) {
        printf("\n--- Election Management System ---\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. View Election Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate(candidates, &candidateCount);
                break;
            case 2:
                castVote(candidates, candidateCount);
                break;
            case 3:
                viewResults(candidates, candidateCount);
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

void addCandidate(struct Candidate candidates[], int *candidateCount) {
    printf("\n--- Add Candidate ---\n");
    printf("Enter Candidate ID: ");
    scanf("%d", &candidates[*candidateCount].id);
    printf("Enter Candidate Name: ");
    getchar();
    fgets(candidates[*candidateCount].name, sizeof(candidates[*candidateCount].name), stdin);
    candidates[*candidateCount].name[strcspn(candidates[*candidateCount].name, "\n")] = 0; 
    candidates[*candidateCount].votes = 0; 
    (*candidateCount)++;
    printf("Candidate added successfully!\n");
}

void castVote(struct Candidate candidates[], int candidateCount) {
    if (candidateCount == 0) {
        printf("\nNo candidates available to vote for!\n");
        return;
    }

    int id;
    printf("\n--- Cast Vote ---\n");
    printf("Enter Candidate ID to vote: ");
    scanf("%d", &id);

    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].id == id) {
            candidates[i].votes++;
            printf("Vote cast successfully for %s!\n", candidates[i].name);
            return;
        }
    }
    printf("Invalid Candidate ID! Vote not counted.\n");
}

void viewResults(struct Candidate candidates[], int candidateCount) {
    if (candidateCount == 0) {
        printf("\nNo candidates to display results for!\n");
        return;
    }

    printf("\n--- Election Results ---\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("Candidate ID: %d\n", candidates[i].id);
        printf("Name: %s\n", candidates[i].name);
        printf("Votes: %d\n", candidates[i].votes);
        printf("---------------------------\n");
    }
}
