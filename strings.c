#include <stdio.h>

const char ** allowedFlags = {"--print", "--god-mode"};

void printString(const char * string) {
    printf("%s ", string);
    return;
}


void printArrayString(const char ** array) {
    printf("\n%s\n", array[0]);
    printf("%s\n", array[1]);
    printf("%s\n", array[2]);
}

unsigned int checkAllowedFlags(const char ** const flags) {
    //for | while check
    return 1;
}
int  main (int argc,const char **  const argv) {
    printf("%d\n", argc);
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);

    if (argc > 1) checkAllowedFlags(argv);

    char hello1[] = {'H', 'e', 'l', 'l', 'o', '1', '\0'};
    char hello2[] = "Hello2";

    const char* hello3 = "Hello3";
    const char* const hello4 = "Hello4";

    const char * states[] = {"Moscow", "New-York", "Kyiv"};
    //const char states[3][20] = {}

    printf("Hello3: %p\n", hello3);
    printf("Hello4: %p\n", hello4);

    //hello3 = hello4;
    printf("after\n");

    printf("Hello3: %p\n", hello3);
    printf("Hello4: %p\n", hello4);

    printString(hello3);
    printString(hello4);

    printArrayString(states);
    return 0;
}