#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char    *string = NULL;
    char    letter  = 0;

    if (argc == 1) {
        dprintf(2, "usage: %s hash\n", argv[0]);
        return 1;
    }
    string = argv[1];
    for (size_t i = 0; i < strlen(string); i++)
    {
        letter = string[i];
        printf("%c", (char)(string[i] - i));
    }
    printf("\n");
}