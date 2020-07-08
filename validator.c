#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


const char * const allowedFlags[] = {"--size", "--sort", "--print"};
const int const allowedFlagsLength = sizeof allowedFlags / sizeof allowedFlags[0];

void validateFlags(const char * const flags[], const int length) {
    bool flagExists = false;
    //int incorrectFlagIndex = -1;
    for (int i = 1; i < length; i++)
    {
        flagExists = false;
        for (int j = 0; j < allowedFlagsLength; j++)
        {
            if (strcmp(flags[i], allowedFlags[j]) == 0) {
                flagExists = true;
            }
        }
        if (!flagExists) {
            printf("[-] Error: %s incorrect flag was given", flags[i]);
            exit(EXIT_FAILURE);
        }
    }
    return;
}

int main (const int argc, const char * const argv[]) {
    if (argc > 1) {
        validateFlags(argv, argc);
    }
    return EXIT_SUCCESS;
}