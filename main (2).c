/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    int id;
    char name[50];
    int age;
};

struct Patient queue[MAX];
int front = -1, rear = -1;

void addPatient() {
    if (rear == MAX - 1) {
        printf("\nQueue is full!\n");
        return;
    }

    struct Patient p;

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Patient Name: ");
    scanf(" %49[^\n]", p.name);

    printf("Enter Patient Age: ");
    scanf("%d", &p.age);

    if (front == -1)
        front = 0;

    queue[++rear] = p;

    printf("\nPatient added successfully!\n");
}

void treatPatient() {
    if (front == -1 || front > rear) {
        printf("\nNo patients waiting!\n");
        return;
    }

    printf("\nTreating Patient:\n");
    printf("ID: %d\n", queue[front].id);
    printf("Name: %s\n", queue[front].name);
    printf("Age: %d\n", queue[front].age);

    front++;

    if (front > rear)
        front = rear = -1;
}

void displayPatients() {
    int i;

    if (front == -1) {
        printf("\nNo patients in the queue!\n");
        return;
    }

    printf("\n--- Waiting Patients ---\n");

    for (i = front; i <= rear; i++) {
        printf("\nPatient ID: %d\n", queue[i].id);
        printf("Name: %s\n", queue[i].name);
        printf("Age: %d\n", queue[i].age);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n\n=== HUMAN PATIENT MANAGEMENT SYSTEM ===\n");
        printf("1. Add Patient\n");
        printf("2. Treat Patient\n");
        printf("3. Display Patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                treatPatient();
                break;

            case 3:
                displayPatients();
                break;

            case 4:
                printf("\nExiting the system...\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
