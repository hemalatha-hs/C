#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount(struct Account accounts[], int *accountCount);
void depositMoney(struct Account accounts[], int accountCount);
void withdrawMoney(struct Account accounts[], int accountCount);
void checkBalance(struct Account accounts[], int accountCount);

int main() {
    struct Account accounts[100];
    int accountCount = 0;
    int choice;

    while (1) {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                depositMoney(accounts, accountCount);
                break;
            case 3:
                withdrawMoney(accounts, accountCount);
                break;
            case 4:
                checkBalance(accounts, accountCount);
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

void createAccount(struct Account accounts[], int *accountCount) {
    printf("\n--- Create Account ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &accounts[*accountCount].accountNumber);
    printf("Enter Name: ");
    getchar(); 
    fgets(accounts[*accountCount].name, sizeof(accounts[*accountCount].name), stdin);
    accounts[*accountCount].name[strcspn(accounts[*accountCount].name, "\n")] = 0; 
    accounts[*accountCount].balance = 0; 
    (*accountCount)++;
    printf("Account created successfully!\n");
}

void depositMoney(struct Account accounts[], int accountCount) {
    if (accountCount == 0) {
        printf("\nNo accounts available to deposit money!\n");
        return;
    }
    int accountNumber;
    float amount;
    printf("\n--- Deposit Money ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposit successful! New Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdrawMoney(struct Account accounts[], int accountCount) {
    if (accountCount == 0) {
        printf("\nNo accounts available to withdraw money!\n");
        return;
    }

    int accountNumber;
    float amount;
    printf("\n--- Withdraw Money ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New Balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }

    printf("Account not found!\n");
}

void checkBalance(struct Account accounts[], int accountCount) {
    if (accountCount == 0) {
        printf("\nNo accounts available to check balance!\n");
        return;
    }

    int accountNumber;
    printf("\n--- Check Balance ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}
