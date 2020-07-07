#include <stdio.h>
#define SIZE 4

void showArrayAdresses(float array[]) {
    printf("\nArray Adresses\n");
    printf("0: %p\n", &array[0]);
    printf("1: %p\n", &array[1]);
    printf("2: %p\n", &array[2]);
    printf("3: %p\n", &array[3]);
    
    return;
}

void showArrayAdressesByPointer(float *array) {
    printf("output with pointers\n");
    printf("\ntestTesttest\n");
    printf("0: %p\n", &array[0]);
    printf("1: %p\n", &array[1]);
    printf("2: %p\n", &array[2]);
    printf("3: %p\n", &array[3]);
}

int  main (void) {
    float prices[SIZE] = {1000.0f, 2000.0f, 3000.0f, 4000.0f};

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

    size_t floatsize = sizeof(float);

    printf("Float size: %zu bytes\n", floatsize);
    printf("Length of an array: %zu", sizeof prices / sizeof(float));
    showArrayAdresses(prices);
    showArrayAdressesByPointer(prices);
    return 0;
}