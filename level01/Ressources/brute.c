#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define LEN_HASH 13
#define LEN_KEY 8
#define DICT_NAME "rockyou.txt"

int handleline(FILE *dict, char *buff) {
    char    *line       = NULL;
    size_t  buff_size   = 0;
    size_t  size        = 0;

    size = getline(&line, &buff_size, dict);
    if (size < 1)
        return (0);
    strncpy(buff, line, LEN_KEY);
    if (size <= LEN_KEY)
        buff[ size - 1 ] = 0;
    free(line);
    return (1);
}

int main(int argc, char *argv[]) {
    FILE    *dict               = NULL;
    int     run                 = 1;
    char    salt[3]             = {0};
    char    buff[LEN_KEY + 1]   = {0};

    if (argc < 2) {
        dprintf(2, "usage: %s <target_hash>\n", argv[0]);
        return (1);
    }
    dict = fopen(DICT_NAME, "r");
    if (!dict) {
        dprintf(2, "%s: %s: %s\n", argv[0], DICT_NAME, strerror(errno));
        return (2);
    }
    strncpy(salt, argv[1], 2);
    printf("target: %s - salt: %s\n", argv[1], salt);
    while (run)
    {
        run = handleline(dict, buff);
        if (!strncmp(argv[1], crypt(buff, salt), LEN_HASH)) {
            printf("find - pass: %s\n", buff);
            run = 0;
        }
    }
    fclose(dict);
}