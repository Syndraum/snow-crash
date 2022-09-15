#include <unistd.h>

#define TEXT "lol"

char *getenv(const char *name) {
    write(1, TEXT, 4);
    return NULL;
}