//C program to find Largest and Smallest Elements of an array using for loop

#include <stdio.h>
#include<conio.h>
int main() {
    int min, max, a[10], i;
    clrscr();
    // Input
    printf("Enter 10 array elements:\n");
    for (i = 0; i < 10; i++) {
        printf("Enter element a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    // Initialize min and max with first element
    min = max = a[0];

    // Loop to find min and max
    for (i = 1; i < 10; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }

    // Output
    printf("Maximum element is %d\n", max);
    printf("Minimum element is %d\n", min);

    return 0;
}
