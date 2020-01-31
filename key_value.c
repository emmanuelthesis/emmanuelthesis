#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

typedef struct
{
   char key[255];
   char val[255];
} kv_pair;

typedef struct
{
   kv_pair *pairs;
} kv_store;

// The function add stores key and value into the store. Check if the key matches, we assign a given value
//If the key is not known, make it known and assign the given value.
void add(kv_store *store, char key, char val)
{
   // check if a pair with the key is in store
   
   kv_pair* pair;
   uint8_t store_length = sizeof(store->pairs) / sizeof(struct kv_pair);

   printf("\nkey = %c,value = %c,pair = %c, store_length = %c\n", key, val, pair, store_length);

   for (uint8_t idx = 0; idx < store_length; idx++)
   {
      kv_pair current_pair = store->pairs[idx];
      if (strcmp(key, current_pair.key) == 0)
      {
         // since we found the right pair with the key, set the new value and  break out of the loop
          pair = &current_pair;
         // strcpy (char* destination, const char* source). It copies from source to destination
         strcpy(current_pair.val, val); // The source will be the assigned given (val) and and the destination
                                             // will be the store->pair[idx].val
         break;
      }
   }

   if (!pair)
   {
      // create a new pair with the key and value
      kv_pair new_pair = {.key = key, .val = val};
      // add the new pair to the store
      store->pairs[store_length] = new_pair;
   }
}

int main()
{
   // printf() displays the string inside quotation
   kv_store emmanuel = {0};
   // struct body bodies[n];

   add(&emmanuel, "TEST", "TEST_VAL");

   return 0;
}