#include <stdio.h>

int main() {
    int n, i;
    long long product = 1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        product *= num;
    }

    printf("The product of the entered numbers is: %lld\n", product);

    return 0;
}
