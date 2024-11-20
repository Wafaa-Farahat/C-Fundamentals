#include <stdio.h>

// Recursive function to calculate power
int power(int a, int b) {
    if (b == 0) {  // Base case
        return 1;
    } else {
        return a * power(a, b - 1);  // Recursive case
    }
}

int main() {
    int base, exponent;

    // Input from user
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    // Output result
    int result = power(base, exponent);
    printf("%d^%d = %d\n", base, exponent, result);

    return 0;
}
