#ifndef MERGESORT_H
#define MERGESORT_H
#include <stdlib.h>

static void merge(void* arr, void* L, void* R, size_t left_index, size_t right_index, size_t sizeof_element, int (*comparator)(const void*, const void*));/*Internal function for merging the suba-arrays*/
void merge_sort(void* arr, size_t number_of_elements, size_t sizeof_element, int (*comparator)(const void*, const void*));/*A sorting mergesort function, to use provide a pointer to an array, number of elements, sizeof a single element and a custom comparizon function*/


int compare_asc_example(const void* a, const void* b);/*An example function for sorting integers in ascending order*/
int compare_desc_example(const void* a, const void* b);/*An example function for sorting integers in descending order*/

#endif