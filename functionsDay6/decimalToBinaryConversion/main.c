#include <stdio.h>

// Recursive function to convert decimal to binary
void decimalToBinaryRecursive(int n) {
    if (n == 0) {
        return;
    }
    decimalToBinaryRecursive(n / 2);
    printf("%d", n % 2);
}

// Loop-based function to convert decimal to binary
void decimalToBinaryLoop(int n) {
    int binary[32];
    int i = 0;

    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }

    // Print binary in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    int number;

    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &number);

    printf("\nDecimal to Binary (Recursive): ");
    if (number == 0) {
        printf("0");
    } else {
        decimalToBinaryRecursive(number);
    }

    printf("\nDecimal to Binary (Loop): ");
    decimalToBinaryLoop(number);

    printf("\n");

    return 0;
}
