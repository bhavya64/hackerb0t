#include "array.h"

void init_array(array_t *a, size_t initialSize)
{
    a->array = malloc(initialSize * sizeof(char*));
    a->used = 0;
    a->size = initialSize;
}

void insert_array(array_t *a, char* element)
{
    if (a->used == a->size)
    {
        a->size++;
        a->array = realloc(a->array, a->size * sizeof(char*));
    }
    int element_size = strlen(element);
    //free(a->array[a->used]);
    a->array[a->used] = malloc(element_size +1);
    memcpy(a->array[a->used], element, (element_size +1));
    a->used++;
}

void remove_from_array(array_t* a)
{
    free(a->array[a->used-1]);
    a->array[a->used-1] = NULL;
    a->used--;
    a->size--;
}

void free_array(array_t *a)
{
    if(a == NULL) return;
    for(int i = 0; i < a->used; i++)
        free(a->array[i]);
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}
