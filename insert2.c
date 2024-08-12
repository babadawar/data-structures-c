#include <stdio.h>

int main() {
    int i, n, item, element, index = -1;
    int arr[7] = {20, 25, 30, 35, 40, 45}; // Make sure the array has space for the new element
    
    printf("Enter the element you want to add after: ");
    scanf("%d", &element);
    
    // Find the index of the element after which the new item should be added
    for (i = 0; i < 6; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Element %d not found in the array.\n", element);
        return 1;
    }
    
    printf("Enter the element you want to add: ");
    scanf("%d", &item);
    
    // Shift elements to the right to make space for the new element
    for (i = 6; i > index + 1; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert the new element
    arr[index + 1] = item;
    
    // Print the updated array
    for (i = 0; i < 7; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
