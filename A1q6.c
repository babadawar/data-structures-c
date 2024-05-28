#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    double sum = 0, sum_sq = 0;
    double mean, variance, std_dev;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    double arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
        sum_sq += arr[i] * arr[i];
    }

    mean = sum / n;
    variance = (sum_sq / n) - (mean * mean);
    std_dev = sqrt(variance);

    printf("The mean is: %.2lf\n", mean);
    printf("The variance is: %.2lf\n", variance);
    printf("The standard deviation is: %.2lf\n", std_dev);

    return 0;
}
