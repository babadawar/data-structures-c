#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertNode(int data) {
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

void deleteHeadOrTail(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 0) { 
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        free(temp);
    } else { 
        if (head->next == NULL) {
            head = NULL;
            tail = NULL;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
            free(tail->next);
        }
    }
}

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
                if (head == NULL) {
                    tail = NULL;
                }
            } else {
                prev->next = temp->next;
                if (temp->next == NULL) {
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

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(2);
    insertNode(4);
    insertNode(2);

    printf("Original list: ");
    printList();

    deleteHeadOrTail(0);

    printf("List after deleting head: ");
    printList();
2
    deleteAllInstances(2);

    printf("List after deleting all instances of 2: ");
    printList();

    deleteHeadOrTail(1);

    printf("List after deleting tail: ");
    printList();

    return 0;
}