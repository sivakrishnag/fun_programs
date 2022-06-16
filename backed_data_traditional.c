#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BACKING_FILE "/tmp/backing_file"
#define MAX_ENTRIES 20

typedef struct data_store_entry_s {
   char key[32];
   char value[32];
} data_store_entry_t;

typedef struct data_store_s {
    int num_entries;
    data_store_entry_t entries[MAX_ENTRIES];
} data_store_t;

data_store_t ds;

void init()
{
    if (access(BACKING_FILE, F_OK) == F_OK) {
        FILE *fp = fopen(BACKING_FILE, "rb");
        if (fp) {
            fread(&ds, sizeof(data_store_t), 1, fp);
            fclose(fp);
        }
    } else {
        FILE *fp = fopen(BACKING_FILE, "wb");
        if (fp) {
            fwrite(&ds, sizeof(data_store_t), 1, fp);
            fclose(fp);
        }
    }
}

void set_value(char *key, char *value)
{
    int entry_index;
    FILE *fp;
    int idx;

    if (ds.num_entries > MAX_ENTRIES) {
        return;
    }

    for (idx = 0; idx < ds.num_entries; idx++) {
        if (strcmp(ds.entries[idx].key, key) == 0) {
            strncpy(ds.entries[idx].value, value, sizeof(ds.entries[idx].value));
            break;
        }
    }

    if (idx == ds.num_entries) {
        entry_index = ds.num_entries;

        strncpy(ds.entries[entry_index].key, key, sizeof(ds.entries[entry_index].key));
        strncpy(ds.entries[entry_index].value, value, sizeof(ds.entries[entry_index].value));

        ds.num_entries++;
    }

    /* Update the file with latest data */
    fp = fopen(BACKING_FILE, "wb");
    if (fp) {
        fwrite(&ds, sizeof(data_store_t), 1, fp);
        fclose(fp);
    }
}

char *get_value(char *key)
{
    int i;

    for (i = 0; i < ds.num_entries; i++) {
        if (strncmp(ds.entries[i].key, key, strlen(ds.entries[i].key)) == 0) {
            return (char *)&ds.entries[i].value;
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
