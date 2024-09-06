#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Reservation {
    int seatNumber;
    char passengerName[50];
    char classType; // 'E' for Economy, 'B' for Business
};


void displayMenu();
void reserveTicket(struct Reservation[], int);
void cancelReservation(struct Reservation[], int);
void displayRecords(const struct Reservation[], int);
int adminLogin();

int main() {
    if (!adminLogin()) {
        printf("Admin login failed. Exiting program.\n");
        return 1; 
    }

    struct Reservation reservations[50];
    int numReservations = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reserveTicket(reservations, numReservations);
                numReservations++;
                break;
            case 2:
                cancelReservation(reservations, numReservations);
                break;
            case 3:
                displayRecords(reservations, numReservations);
                break;
            case 4:
                printf(":-)........Exiting program.......Have A Nice Day.......:-)\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

int adminLogin() {
    char username[20];
    char password[20];

    printf("===== Admin Login =====\n");
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    
    if (strcmp(username, "harsh") == 0 && strcmp(password, "123") == 0) {
        printf("Admin login successful.\n");
        return 1; 
    } else {
        printf("Incorrect username or password.\n");
        return 0; 
    }
}


void displayMenu() {
    printf("\n======== Airline Reservation System =======\n");
    printf("1. Reserve Ticket\n");
    printf("2. Cancel Reservation\n");
    printf("3. Display Records\n");
    printf("4. Exit\n");
}

void reserveTicket(struct Reservation reservations[], int numReservations) {
    if (numReservations < 50) {
        printf("Enter passenger name: ");
        scanf("%s", reservations[numReservations].passengerName);

        printf("Enter seat class ('E' for Economy, 'B' for Business): ");
        scanf(" %c", &reservations[numReservations].classType);

        printf("Reservation successful. Seat number: %d\n", numReservations + 1);
    } else {
        printf("Sorry, all seats are booked.\n");
    }
}

void cancelReservation(struct Reservation reservations[], int numReservations) {
    int seatNumber;
    printf("Enter seat number to cancel reservation: ");
    scanf("%d", &seatNumber);

    if (seatNumber >= 1 && seatNumber <= numReservations) {
        
        seatNumber--; 
        reservations[seatNumber].seatNumber = 0;
        reservations[seatNumber].passengerName[0] = '\0'; 
        reservations[seatNumber].classType = '\0'; 

        printf("Reservation for seat %d canceled.\n", seatNumber + 1);
    } else {
        printf("Invalid seat number.\n");
    }
}


void displayRecords(const struct Reservation reservations[], int numReservations) {
    printf("\n======= Reservation Records =======\n");
    printf("Seat\tClass\tPassenger Name\n");
	int i;
    for (i = 0; i < numReservations; i++) {
        printf("%d\t%c\t%s\n", i + 1, reservations[i].classType, reservations[i].passengerName);
    }
}



