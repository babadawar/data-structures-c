#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char address[100];
    int income;
    int id;
    struct Node* next;
};

void add_node(struct Node** head, char* name, char* address, int income, int id) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->name, name);
    strcpy(node->address, address);
    node->income = income;
    node->id = id;
    node->next = *head;
    *head = node;
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
    struct Node* head = NULL;

    add_node(&head, "John Doe", "123 Main St", 50000, 1);
    add_node(&head, "Jane Smith", "456 Elm St", 60000, 2);
    add_node(&head, "Bob Johnson", "789 Oak St", 70000, 3);

    print_nodes(head);

    return 0;
}