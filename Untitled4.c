#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[100];
    float salary;
    struct employee* next;
};

struct employee* head = NULL;
struct employee* tail = NULL;

void create() {
    int n;
    printf("Enter size of linked list: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        struct employee* temp = (struct employee*)malloc(sizeof(struct employee));

        printf("Enter the salary of employee %d: ", i);
        scanf("%f", &temp->salary);

        printf("Enter the ID of employee %d: ", i);
        scanf("%d", &temp->id);

        printf("Enter the name of employee %d: ", i);
        scanf("%s", temp->name);

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
}

void view() {
    struct employee* temp = head;
    while (temp != NULL) {
        printf("Employee ID: %d, Name: %s, Salary: %.2f\n", temp->id, temp->name, temp->salary);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("Enter 1 to create, 2 to view, or any other key to exit: ");
        scanf("%d", &choice);
        if (choice == 1)
            create();
        else if (choice == 2)
            view();
        else
            break;
    }
    return 0;
}