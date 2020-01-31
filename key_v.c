#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

typedef struct // defining a structure containing a memory block of 255 bytes character of key and value
{
    char key[255];
    char val[255];
} kv_pair; // naming the type as key_pair

typedef struct // defining a structure containing a memory block to store an array of 255 key_pair and current usage in counts
{
    kv_pair pair[255];
    uint8_t count;
} kv_store;

void add(kv_store *store, char key[255], char val[255]) // the function signature for the function add.
{
    bool itWasCopied = false;

    for (uint8_t idx = 0; idx < store->count; idx++) // looping through the used pairs in the store structure
    {
        if (strncmp(key, store->pair[idx].key, 255) == 0)
        {
            strncpy(store->pair[idx].val, val, 255);
            itWasCopied = true;
        }
    }
    if (itWasCopied == false)
    {
        strncpy(store->pair[store->count].key, key, 255);
        strncpy(store->pair[store->count].val, val, 255);
        store->count++;
    }
}

char* get(kv_store *store, char key[255])
{
    for (uint8_t idx = 0; idx < store->count; idx++)
    {
        if (strncmp(key, store->pair[idx].key, 255) == 0)
        {
            return store->pair[idx].val;
        }
    } 
    return "";
}
void del(kv_store *store, char key[255])
{
    for (uint8_t idx = 0; idx < store->count; idx++)
    {
        if (strncmp(key, store->pair[idx].key, 255) == 0)
        {
            strncpy(store->pair[idx].val, store->pair[store->count-1].val, 255);
            strncpy(store->pair[idx].key, store->pair[store->count-1].key, 255);
            store->count--;
            break;
        }
    }
}

int main()
{
    // printf() displays the string inside quotation

    kv_store emmanuel = {0};

    add(&emmanuel, "TEST", "1TEST_VAL");
    add(&emmanuel, "TEST2", "2TEST_VAL");
    add(&emmanuel, "TEST", "3TEST_VAL");
    add(&emmanuel, "TEST", "4TEST_VAL");
    add(&emmanuel, "TEST4", "5TEST_VAL");
    add(&emmanuel, "TEST3", "6TEST_VAL");
    add(&emmanuel, "TEST", "7TEST_VAL");
    add(&emmanuel, "TEST", "8TEST_VAL");

    char* a = get(&emmanuel, "TEST4");
    printf("%s \n", a); // should print 8TEST_VAL

    return 0;
}