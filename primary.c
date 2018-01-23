#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_SIZE 256


__attribute__((constructor(101)))
void
first_call_ctor(void)
{
    char* display_string = malloc(MAX_STRING_SIZE);
    memset(display_string, '\0', MAX_STRING_SIZE);
    strncpy(display_string, "{*} nerfnet van hier du schwuchteln", MAX_STRING_SIZE);
    printf("%s\n", display_string);
    free(display_string);
    fprintf(stderr, "%s\n", "{*} primary c.tor finished execution");
}

__attribute__((constructor(102)))
void
second_call_ctor(void)
{
    char* safe_string = malloc(MAX_STRING_SIZE);
    strncpy(safe_string, "this is the second c.tor", MAX_STRING_SIZE);
    
    char* token = strtok(safe_string, " ");

    while (token)
    {
        printf("{*} %s\n", token);
        token = strtok(NULL, " ");
    }

    free(safe_string);
}

int
main(void)
{
    return EXIT_SUCCESS;
}

__attribute__((destructor(101), aligned(4)))
void
first_call_dtor(void)
{ return; }