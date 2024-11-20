#include <stdio.h>

// Recursive function to convert decimal to hexadecimal
void decimalToHexadecimalRecursive(int n) {
    if (n == 0) {
        return;
    }
    decimalToHexadecimalRecursive(n / 16);
    int remainder = n % 16;
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", remainder - 10 + 'A');
    }
}

// Loop-based function to convert decimal to hexadecimal
void decimalToHexadecimalLoop(int n) {
    char hexadecimal[32];
    int i = 0;

    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        int remainder = n % 16;
        if (remainder < 10) {
            hexadecimal[i++] = remainder + '0';
        } else {
            hexadecimal[i++] = remainder - 10 + 'A';
        }
        n /= 16;
    }

    // Print hexadecimal in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
}

int main() {
    int number;

    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &number);

    printf("\nDecimal to Hexadecimal (Recursive): ");
    if (number == 0) {
        printf("0");
    } else {
        decimalToHexadecimalRecursive(number);
    }

    printf("\nDecimal to Hexadecimal (Loop): ");
    decimalToHexadecimalLoop(number);

    printf("\n");

    return 0;
}
