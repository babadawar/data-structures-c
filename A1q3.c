#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int biggest, smallest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    biggest = smallest = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > biggest) {
            biggest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    printf("The biggest number is: %d\n", biggest);
    printf("The smallest number is: %d\n", smallest);

    return 0;
}
