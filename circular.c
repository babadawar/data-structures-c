#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head; 
    } else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode; 
    }
}

void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp->next != head) {
        if (temp->data == data) {
            if (prev == NULL) {
                Node* next = temp->next;
                while (next->next != head) {
                    next = next->next;
                }
                head = temp->next;
                next->next = head; 
                tail = next; 
            } else {
                prev->next = temp->next;
                if (temp == tail) {
                    tail = prev; 
                }
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == data) {
        if (prev == NULL) {
            head = NULL;
            tail = NULL;
        } else {
            prev->next = temp->next;
            tail = prev; 
        }
        free(temp);
    }
}


void printList() {
    Node* temp = head;
    while (true) {
        printf("%d ", temp->data);
        temp = temp->next;
        if (temp == head) {
            break;
        }
    }
    printf("\n");
}

int main() {
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(5);

    printf("Original list: ");
    printList();

    deleteNode(3);

    printf("List after deleting 3: ");
    printList();

    return 0;
}