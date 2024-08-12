#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Declare head and tail as global variables
Node* head = NULL;
Node* tail = NULL;

// Function to insert a node at the end of the list
void insertNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to delete the head or tail node
void deleteHeadOrTail(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 0) { // Delete head
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        free(temp);
    } else { // Delete tail
        if (head->next == NULL) {
            head = NULL;
            tail = NULL;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
    }
}

// Function to delete all instances of a given item
void deleteAllInstances(int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                head = temp->next;
                if (head != NULL) {
                    head->prev = NULL;
                } else {
                    tail = NULL;
                }
            } else {
                prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = prev;
                } else {
                    tail = prev;
                }
            }
            free(temp);
            temp = prev;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Function to print the linked list
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Insert nodes into the list
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(2);
    insertNode(4);
    insertNode(2);

    printf("Original list: ");
    printList();

    // Delete the head node
    deleteHeadOrTail(0);

    printf("List after deleting head: ");
    printList();

    // Delete all instances of 2
    deleteAllInstances(2);

    printf("List after deleting all instances of 2: ");
    printList();

    // Delete the tail node
    deleteHeadOrTail(1);

    printf("List after deleting tail: ");
    printList();

    return 0;
}