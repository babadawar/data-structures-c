#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertAtHead(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    if (tail == NULL) {
        tail = newNode;
    }
}

void insertAtTail(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertBeforeNode(int data, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == key) {
        newNode->next = head;
        head = newNode;
        if (tail == head) {
            tail = newNode;
        }
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == key) {
            newNode->next = temp->next;
            temp->next = newNode;
            if (tail == temp->next) {
                tail = temp;
            }
            return;
        }
        temp = temp->next;
    }

    printf("Node with key %d not found\n", key);
}

void insertAfterNode(int data, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            newNode->next = temp->next;
            temp->next = newNode;
            if (tail == temp) {
                tail = newNode;
            }
            return;
        }
        temp = temp->next;
    }

    printf("Node with key %d not found\n", key);
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtHead(5);
    insertAtHead(10);
    insertAtHead(15);

    printf("Linked list after inserting at head: ");
    printList();
    
    insertAtTail(20);

    printf("Linked list after inserting at tail: ");
    printList();

    insertBeforeNode(12, 10);

    printf("Linked list after inserting before a node: ");
    printList();

    insertAfterNode(18, 15);

    printf("Linked list after inserting after a node: ");
    printList();

    return 0;
}