#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {4, 5, 6, 7, 8, 9};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array 1: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Array 2: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("Union of the two arrays: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }

    for (int i = 0; i < size2; i++) {
        int flag = 0;
        for (int j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            printf("%d ", arr2[i]);
        }
    }
    printf("\n");

    return 0;
}