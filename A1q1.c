#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        float num;
        scanf("%f", &num);
        sum += num;
    }

    average = sum / n;
    printf("The average of the entered numbers is: %.2f\n", average);

    return 0;
}
