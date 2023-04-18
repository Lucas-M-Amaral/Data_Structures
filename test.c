#include <stdio.h>

int main()
{
    fork();
    printf("fork1");
    fork();
    printf("fork2");
    fork();
    printf("fork3");

    return 0;
}