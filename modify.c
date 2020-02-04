#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char key[255];
    char dept[255];
    char position[255];
    char marital_status[255];
    int age;
} User_data;

typedef struct
{
    uint8_t count;
    User_data info[255];

} store_data;

void append(store_data *store, User_data add)
{
    bool testing_conditions = false;
    for (uint8_t idx = 0; idx < store->count; idx++)
    {
        if (strncmp(store->info[idx].key, add.key, 255) == 0)
        {
            strncpy(store->info[idx].dept, add.dept, 255);
            strncpy(store->info[idx].position, add.position, 255);
            strncpy(store->info[idx].marital_status, add.marital_status, 255);
            store->info[idx].age = add.age;
            testing_conditions = true;
        }
    }
    if (testing_conditions == false)
    {
        store->info[store->count] = add;
        store->count++;
    }
}
User_data get(store_data *store, uint8_t boundary)
{
    if (boundary >= store->count)
    {
        fprintf(stderr, "Error Message: out of bounds\n");
        exit(1);
    }
    return store->info[boundary];
}
char get_info(store_data *store, char key[255])
{
    char *ret = NULL;
    for (uint8_t idx = 0; idx < store->count; idx++)
    {
        User_data e = store->info[idx];
        if (strncmp(e.key, key, 255) == 0)
        {
            ret = malloc(255);
            strncpy(ret, e.dept, 255);
            strncpy(ret, e.position, 255);
            strncpy(ret, e.marital_status, 255);
            store->info[idx].age = e.age;
            break;
        }
    }

    if (ret == NULL)
    {
        fprintf(stderr, "Error Message: Out of bounds\n");
        exit(1);
    }
    return *ret;
}
void info_remove(store_data *store, uint8_t element_index)
{
    if (element_index >= store->count)
    {
        fprintf(stderr, "element_index out of bounds\n");
        exit(1);
    }
    store->info[element_index] = store->info[store->count - 1];
    store->count--;
}
int main()
{
    store_data emmanuel = {0};
    append(&emmanuel, (User_data){.key = "Test1", .dept = "math", .position = "Manager", .marital_status = "married", .age = 42});
    append(&emmanuel, (User_data){.key = "Test2", .dept = "computer", .position = "Accountant", .marital_status = "married", .age = 50});
    append(&emmanuel, (User_data){.key = "Test3", .dept = "English", .position = "CEO", .marital_status = "married", .age = 41});
    append(&emmanuel, (User_data){.key = "Test4", .dept = "Networking", .position = "intern", .marital_status = "married", .age = 30});

    printf("idx  key is   : %s\n", get(&emmanuel, 0).key);
    printf("idx  age is   : %d\n", get(&emmanuel, 0).age);
    printf("idx  dept is   : %s\n", get(&emmanuel, 0).dept);
    printf("idx  position is : %s\n", get(&emmanuel, 0).position);
    printf("idx  marital status is   : %s\n", get(&emmanuel, 0).marital_status);


    return 0;
}
