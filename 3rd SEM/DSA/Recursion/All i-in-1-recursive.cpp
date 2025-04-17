#include <stdio.h>

// Factorial
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Fibonacci
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// GCD / HCF
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// LCM using GCD
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Sum of digits
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return n % 10 + sumOfDigits(n / 10);
}

// Reverse number
int reverse(int n, int rev) {
    if (n == 0) return rev;
    return reverse(n / 10, rev * 10 + n % 10);
}

// Count digits
int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

// Check Prime (Recursive divisor check)
int isPrime(int n, int i) {
    if (n <= 2) return (n == 2) ? 1 : 0;
    if (n % i == 0) return 0;
    if (i * i > n) return 1;
    return isPrime(n, i + 1);
}

// Power (a^b)
int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}

// Print numbers from 1 to n
void printAsc(int n) {
    if (n == 0) return;
    printAsc(n - 1);
    printf("%d ", n);
}

// Decimal to binary
void toBinary(int n) {
    if (n == 0) return;
    toBinary(n / 2);
    printf("%d", n % 2);
}

// Palindrome check (string)
int isPalindrome(char str[], int start, int end) {
    if (start >= end) return 1;
    if (str[start] != str[end]) return 0;
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    int choice, n, a, b, result;
    char str[100];

    do {
        printf("\n--- Recursive Programs Menu ---\n");
        printf("1. Factorial\n");
        printf("2. Fibonacci\n");
        printf("3. GCD (HCF)\n");
        printf("4. LCM\n");
        printf("5. Sum of Digits\n");
        printf("6. Reverse Number\n");
        printf("7. Count Digits\n");
        printf("8. Prime Check\n");
        printf("9. Power (a^b)\n");
        printf("10. Print 1 to N\n");
        printf("11. Decimal to Binary\n");
        printf("12. Palindrome (string)\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Factorial: %d\n", factorial(n));
                break;
            case 2:
                printf("Enter term: ");
                scanf("%d", &n);
                printf("Fibonacci(%d): %d\n", n, fibonacci(n));
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("GCD: %d\n", gcd(a, b));
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("LCM: %d\n", lcm(a, b));
                break;
            case 5:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Sum of digits: %d\n", sumOfDigits(n));
                break;
            case 6:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Reversed: %d\n", reverse(n, 0));
                break;
            case 7:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Digit Count: %d\n", countDigits(n));
                break;
            case 8:
                printf("Enter number: ");
                scanf("%d", &n);
                if (isPrime(n, 2)) printf("%d is Prime\n", n);
                else printf("%d is Not Prime\n", n);
                break;
            case 9:
                printf("Enter base and exponent: ");
                scanf("%d %d", &a, &b);
                printf("%d^%d = %d\n", a, b, power(a, b));
                break;
            case 10:
                printf("Enter number: ");
                scanf("%d", &n);

