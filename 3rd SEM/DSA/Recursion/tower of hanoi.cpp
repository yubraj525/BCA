#include <stdio.h>

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char from, char to, char aux) {
    // Base case: If there is only one disk, just move it from 'from' peg to 'to' peg
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    // Step 1: Move n-1 disks from 'from' peg to 'aux' peg using 'to' peg
    towerOfHanoi(n - 1, from, aux, to);

    // Step 2: Move the nth disk from 'from' peg to 'to' peg
    printf("Move disk %d from %c to %c\n", n, from, to);

    // Step 3: Move n-1 disks from 'aux' peg to 'to' peg using 'from' peg
    towerOfHanoi(n - 1, aux, to, from);
}


int main() {
    int n;

    // Ask the user for the number of disks
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Print the steps to solve the Tower of Hanoi problem
    printf("\nSteps to solve Tower of Hanoi:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // A = Source, C = Target, B = Auxiliary
    return 0;
}

