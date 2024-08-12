#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* name;
    char* address;
    int income;
    int id;
    struct Node* next;
};

struct List {
    struct Node* head;
    struct Node* tail;
};

void init_list(struct List* list) {
    list->head = NULL;
    list->tail = NULL;
}

void add_node(struct List* list, char* name, char* address, int income, int id) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->name = strdup(name);
    node->address = strdup(address);
    node->income = income;
    node->id = id;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void print_nodes(struct List* list) {
    struct Node* current = list->head;
    while (current!= NULL) {
        printf("ID: %d\n", current->id);
        printf("Name: %s\n", current->name);
        printf("Address: %s\n", current->address);
        printf("Income: %d\n", current->income);
        printf("------------\n");
        current = current->next;
    }
}

int main() {
    struct List list;
    init_list(&list);

    add_node(&list, "dawar", "rambagh", 900000, 1);
    add_node(&list, "salman", "batamaloo", 60000, 2);
    add_node(&list, "wahid", "teng pora", 70000, 3);

    print_nodes(&list);

    return 0;
}