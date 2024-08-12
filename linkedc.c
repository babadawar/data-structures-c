#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char address[50];
    int income;
    int id;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void add_node(char* name, char* address, int income, int id) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->name, name);
    strcpy(node->address, address);
    node->income = income;
    node->id = id;
    node->next = NULL;

    if (head == NULL) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void print_nodes(struct Node* head) {
    while (head!= NULL) {
        printf("ID: %d\n", head->id);
        printf("Name: %s\n", head->name);
        printf("Address: %s\n", head->address);
        printf("Income: %d\n", head->income);
        printf("------------\n");
        head = head->next;
    }
}

int main() {
    int choice;
    char name[50];
    char address[50];
    int income;
    int id;

    while(1) {
        printf("1. Add a node\n");
        printf("2. View nodes\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter address: ");
                scanf("%s", address);
                printf("Enter income: ");
                scanf("%d", &income);
                printf("Enter id: ");
                scanf("%d", &id);
                add_node(name, address, income, id);
                break;
            case 2:
                print_nodes(head);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}