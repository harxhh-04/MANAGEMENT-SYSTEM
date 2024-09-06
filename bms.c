#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account {
    int acc_no;
    char name[60];
    float balance;
    struct Account* next;
} Account;
Account* createAccount(int acc_no, char* name, float balance) {
    Account* newAccount = (Account*)malloc(sizeof(Account));
    newAccount->acc_no = acc_no;
    strcpy(newAccount->name, name);
    newAccount->balance = balance;
    newAccount->next = NULL;
    return newAccount;
}
void insertAccount(Account** head, int acc_no, char* name, float balance) {
    Account* newAccount = createAccount(acc_no, name, balance);
    if (*head == NULL) {
        *head = newAccount;
    } else {
        Account* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newAccount;
    }
}
void displayAccounts(Account* head) {
    while (head!= NULL) {
        printf("Account No: %d\n", head->acc_no);
        printf("Name: %s\n", head->name);
        printf("Balance: $%.2f\n", head->balance);
        printf("\n");
        head = head->next;
    }
}
void depositMoney(Account* head, int acc_no, float amount) {
    while (head!= NULL) {
        if (head->acc_no == acc_no) {
            head->balance += amount;
            printf("Deposit successful. New balance: $%.2f\n", head->balance);
            return;
        }
        head = head->next;
    }
    printf("Account not found.\n");
}
void withdrawMoney(Account* head, int acc_no, float amount) {
    while (head!= NULL) {
        if (head->acc_no == acc_no) {
            if (head->balance >= amount) {
                head->balance -= amount;
                printf("Withdrawal successful. New balance: $%.2f\n", head->balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
        head = head->next;
    }
    printf("Account not found.\n");
}
void deleteAccount(Account** head, int acc_no) {
    if (*head == NULL) {
        printf("No accounts found.\n");
        return;
    }
    if ((*head)->acc_no == acc_no) {
        Account* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Account deleted successfully.\n");
        return;
    }
    Account* prev = *head;
    Account* curr = (*head)->next;
    while (curr!= NULL) {
        if (curr->acc_no == acc_no) {
            prev->next = curr->next;
            free(curr);
            printf("Account deleted successfully.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Account not found.\n");
}
int main() {
    Account* head = NULL;

    int choice;
    while (1) {
    	printf("=========Banking Management System=========\n\n");
        printf("1. Create a new account\n");
        printf("2. Display all accounts\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Delete an account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int acc_no;
                char name[60];
                float balance;
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter initial balance: ");
                scanf("%f", &balance);
                insertAccount(&head, acc_no, name, balance);
                break;
            }
            case 2:
                displayAccounts(head);
                break;
            case 3: {
                int acc_no;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                depositMoney(head, acc_no, amount);
                break;
}
            case 4: {
                int acc_no;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdrawMoney(head, acc_no, amount);
                break;
            }
            case 5: {
                int acc_no;
                printf("Enter account number to delete: ");
                scanf("%d", &acc_no);
                deleteAccount(&head, acc_no);
                break;
            }
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
