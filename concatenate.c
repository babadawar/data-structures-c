#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    
    if (list1 == NULL) {
        return list2;
    }


    if (list2 == NULL) {
        return list1;
    }

  
    struct Node* current = list1;
    while (current->next!= NULL) {
        current = current->next;
    }

  
    current->next = list2;

    return list1;
}

st
void printList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    
    struct Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);

    struct Node* list2 = createNode(4);
    list2->next = createNode(5);
    list2->next->next = createNode(6);

    
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    
    struct Node* concatenatedList = concatenateLists(list1, list2);

    
    printf("Concatenated List: ");
    printList(concatenatedList);

    return 0;
}