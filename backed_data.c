#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>

#define BACKING_FILE "/tmp/backing_file"
#define MAX_ENTRIES 20

typedef struct data_store_s {
    int num_entries;
    char key[20][32];
    char value[20][32];

} data_store_t;

data_store_t *ds;

void init()
{
    int fd = open(BACKING_FILE, O_RDWR | O_CREAT, 0640);
    if (fd) {
        struct stat st;
        size_t size;

        if (fstat(fd, &st) == 0) {
            /* Empty file */
            if (st.st_size == 0) {
                ftruncate(fd, sizeof(data_store_t));
            }
            ds = mmap(0, sizeof(ds), PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t) 0);
            assert(ds != NULL);
            if (st.st_size == 0) {
                memset(ds, 0, sizeof(data_store_t));
            }
        }
        close(fd);
    }
}

void set_value(char *key, char *value)
{
    int entry_index;
    if (!ds) {
        return;
    }
    if (ds->num_entries > MAX_ENTRIES) {
        return;
    }
    entry_index = ds->num_entries;
    
    strncpy(ds->key[entry_index], key, sizeof(ds->key[entry_index]));
    strncpy(ds->value[entry_index], value, sizeof(ds->value[entry_index]));

    ds->num_entries++;
}

char *get_value(char *key)
{
    int i;
    if (!ds) {
        return NULL;
    }

    for (i = 0; i < ds->num_entries; i++) {
        if (strncmp(ds->key[i], key, strlen(ds->key[i])) == 0) {
            return (char *)&ds->value[i];
        }
    }

    return NULL;
}

int main ()
{
    init();

    set_value("One", "1");
    set_value("Two", "2");
    set_value("Three", "3");
    set_value("Four", "4");
    printf("Value of One is %s\n", get_value("One"));
    printf("Value of Five is %s\n", get_value("Five"));
    printf("Value of Four is %s\n", get_value("Four"));
    return 0;
}
