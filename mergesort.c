#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void merge(void* arr, void* L, void* R, size_t left_index, size_t right_index, size_t sizeof_element, int (*comparator)(const void*, const void*))
{
    size_t i = 0, j = 0, k = 0;
    //k is the index of the main array
    //i is the index of the L sub-array
    //j is the index of the R sub-array
    while (i < left_index && j < right_index)
    {
        if (comparator((char*)L + i * sizeof_element, (char*)R + j * sizeof_element) <= 0)
        {
            memcpy((char*)arr + k * sizeof_element, (char*)L + i * sizeof_element, sizeof_element);
            ++k;
            ++i;
        }
        else
        {
            memcpy((char*)arr + k * sizeof_element, (char*)R + j * sizeof_element, sizeof_element);
            ++k;
            ++j;
        }
    }

    //copy the remaining sub-arrays
    while (i < left_index) 
    {
        memcpy((char*)arr + k * sizeof_element, (char*)L + i * sizeof_element, sizeof_element);
        ++i;
        ++k;
    }
    while (j < right_index) 
    {
        memcpy((char*)arr + k * sizeof_element, (char*)R + j * sizeof_element, sizeof_element);
        ++j;
        ++k;
    }
}

void merge_sort(void* arr, size_t number_of_elements, size_t sizeof_element, int (*comparator)(const void*, const void*))
{
    size_t mid = number_of_elements/2;

    void* L, *R;
    if (number_of_elements < 2) return;

    L = malloc(mid * sizeof_element); //Left sub-array is from 0 to mid-1
    R = malloc((number_of_elements - mid) * sizeof_element); //Right sub-array is from mid to number_of_elements-1
    if (L == NULL || R == NULL)
    {
        fprintf(stderr, "Get more ram lol, or don't try to sort so much data idiot\n");
        abort();
    }

    memcpy(L, arr, mid * sizeof_element);
    memcpy(R, (char*)arr + mid * sizeof_element, (number_of_elements - mid) * sizeof_element);

    merge_sort(L, mid, sizeof_element, comparator);
    merge_sort(R, (number_of_elements - mid), sizeof_element, comparator);
    merge(arr, L, R, mid, number_of_elements - mid, sizeof_element, comparator);

    free(L);
    free(R);
}


int compare_asc_example(const void* a, const void* b)
{
    int* f = (int*)a;
    int*s = (int*)b;
    if (*f > *s) return 1;
    else if (*f < *s) return -1;
    return 0;
}

int compare_desc_example(const void* a, const void* b)
{
    int* f = (int*)a;
    int*s = (int*)b;
    if (*f > *s) return -1;
    else if (*f < *s) return 1;
    return 0;
}