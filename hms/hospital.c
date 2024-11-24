#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char doctor[50];
    char status[50]; 
    float bill;
};

void addPatient(struct Patient patients[], int *patientCount);
void displayPatients(struct Patient patients[], int patientCount);
void updateStatus(struct Patient patients[], int patientCount);
void generateBill(struct Patient patients[], int patientCount);

int main() {
    struct Patient patients[100];
    int patientCount = 0;
    int choice;

    while (1) {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient Record\n");
        printf("2. Display Patient Details\n");
        printf("3. Update Patient Status\n");
        printf("4. Hospital Billing\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(patients, &patientCount);
                break;
            case 2:
                displayPatients(patients, patientCount);
                break;
            case 3:
                updateStatus(patients, patientCount);
                break;
            case 4:
                generateBill(patients, patientCount);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addPatient(struct Patient patients[], int *patientCount) {
    printf("\n--- Add Patient Record ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &patients[*patientCount].id);
    printf("Enter Patient Name: ");
    getchar(); 
    fgets(patients[*patientCount].name, sizeof(patients[*patientCount].name), stdin);
    patients[*patientCount].name[strcspn(patients[*patientCount].name, "\n")] = 0; 
    printf("Enter Age: ");
    scanf("%d", &patients[*patientCount].age);
    printf("Enter Assigned Doctor's Name: ");
    getchar(); 
    fgets(patients[*patientCount].doctor, sizeof(patients[*patientCount].doctor), stdin);
    patients[*patientCount].doctor[strcspn(patients[*patientCount].doctor, "\n")] = 0; 
    strcpy(patients[*patientCount].status, "Admitted"); 
    patients[*patientCount].bill = 0; 
    (*patientCount)++;
    printf("Patient record added successfully!\n");
}

void displayPatients(struct Patient patients[], int patientCount) {
    if (patientCount == 0) {
        printf("\nNo patient records available!\n");
        return;
    }

    printf("\n--- Patient Details ---\n");
    for (int i = 0; i < patientCount; i++) {
        printf("Patient ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Assigned Doctor: %s\n", patients[i].doctor);
        printf("Status: %s\n", patients[i].status);
        printf("Bill: %.2f\n", patients[i].bill);
        printf("---------------------------\n");
    }
}

void updateStatus(struct Patient patients[], int patientCount) {
    if (patientCount == 0) {
        printf("\nNo patient records available to update!\n");
        return;
    }

    int id;
    printf("\n--- Update Patient Status ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("Enter New Status (Admitted/Discharged): ");
            getchar(); 
            fgets(patients[i].status, sizeof(patients[i].status), stdin);
            patients[i].status[strcspn(patients[i].status, "\n")] = 0; 
            printf("Patient status updated successfully!\n");
            return;
        }
    }

    printf("Patient ID not found!\n");
}

void generateBill(struct Patient patients[], int patientCount) {
    if (patientCount == 0) {
        printf("\nNo patient records available for billing!\n");
        return;
    }

    int id;
    float amount;
    printf("\n--- Hospital Billing ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("Enter Amount to Add to Bill: ");
            scanf("%f", &amount);
            patients[i].bill += amount;
            printf("Bill updated successfully! Current Bill: %.2f\n", patients[i].bill);
            return;
        }
    }
    printf("Patient ID not found!\n");
}
