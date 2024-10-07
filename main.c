#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 30
#define MAX_NAME_LENGTH 50

struct Booking {
    char name[MAX_NAME_LENGTH];
    int seatNo;
    char source[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];
    // Add more fields as needed
};

struct Booking bookings[MAX_SEATS];
int bookedSeats = 0;

void bookSeat() {
    if (bookedSeats >= MAX_SEATS) {
        printf("No more seats available.\n");
        return;
    }

    struct Booking newBooking;

    printf("Enter name: ");
    scanf("%s", newBooking.name);

    printf("Enter seat number: ");
    scanf("%d", &newBooking.seatNo);

    printf("Enter source: ");
    scanf("%s", newBooking.source);
    printf("Enter destination: ");
    scanf("%s", newBooking.destination);

    // Add more input fields as needed

    bookings[bookedSeats++] = newBooking;
    printf("Seat booked successfully.\n");
}

void viewReservations() {
    if (bookedSeats == 0) {
        printf("No reservations made yet.\n");
        return;
    }

    printf("All reservations:\n");
    printf("Seat No.\tName\tSource\tDestination\n");
    for (int i = 0; i < bookedSeats; ++i) {
        printf("%d\t\t%s\t%s\t%s\n", bookings[i].seatNo, bookings[i].name,bookings[i].source,bookings[i].destination);
    }
}

void editReservation() {
    int seatToEdit;
    printf("Enter seat number to edit: ");
    scanf("%d", &seatToEdit);

    int found = 0;
    for (int i = 0; i < bookedSeats; ++i) {
        if (bookings[i].seatNo == seatToEdit) {
            printf("Enter new name: ");
            scanf("%s", bookings[i].name);
            // Add more fields to edit as needed

            printf("Reservation edited successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Reservation not found.\n");
    }
}

void printTicket() {
    int seatToPrint;
    printf("Enter seat number to print ticket: ");
    scanf("%d", &seatToPrint);

    int found = 0;
    for (int i = 0; i < bookedSeats; ++i) {
        if (bookings[i].seatNo == seatToPrint) {
            printf("Ticket for Seat No. %d\n", bookings[i].seatNo);
            printf("Passenger Name: %s\n", bookings[i].name);
            printf("Passenger Source: %s\n", bookings[i].source);
            printf("Passenger Destination: %s\n", bookings[i].destination);
            // Add more fields to print as needed

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Reservation not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nMini Bus Booking System\n");
        printf("1. Book a seat\n");
        printf("2. View reservations\n");
        printf("3. Edit a reservation\n");
        printf("4. Print a ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookSeat();
                break;
            case 2:
                viewReservations();
                break;
            case 3:
                editReservation();
                break;
            case 4:
                printTicket();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
