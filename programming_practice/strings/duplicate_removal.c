/* Remove all the duplicate characters in a string */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    char *str;
    char char_seen[128];
    int i, fill_pos;
    size_t len;

    if (argc != 2) {
        fprintf (stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    str = strdup(argv[1]);
    memset(char_seen, 0, sizeof(char_seen));

    len = strlen(str);
    fill_pos = 0;
    for (i = 0; i < len; i++) {
        if (!char_seen[(int)str[i]]) {
            str[fill_pos] = str[i];
            fill_pos++;
            char_seen[(int)str[i]] = 1;
        }
    }
    str[fill_pos] = '\0';

    fprintf (stdout, "Resultant string: %s\n", str);
    free(str);
    return 0;
}
