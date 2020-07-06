#include <stdio.h>
#define SIZE 4


int  main (void) {
    float prices[SIZE] = {1000.0f, 2000.0f, 3000.0f, 4000.0f};
    prices[4] = 12.0f;
    printf("output with indeces\n");
    printf("0: %.2f\n", prices[0]);
    printf("1: %.2f\n", prices[1]);
    printf("2: %.2f\n", prices[2]);
    printf("3: %.2f\n", prices[3]);
    
    printf("output with pointers\n");
    printf("0: %.2f\n", *(prices + 0));
    printf("1: %.2f\n", *(prices + 1));
    printf("2: %.2f\n", *(prices + 2));
    printf("3: %.2f\n", *(prices + 3));
    return 0;
}