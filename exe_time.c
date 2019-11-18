#include <time.h>   //  for time_t
#include "arr.c"
#include "bubble_sort.c"
#include "insertion_sort.c"
#include "selection_sort.c"
#include "merge_sort.c"
#include "quick_sort.c"

double time_in_s(time_t start, time_t stop){
    return ((double)(stop - start)/CLOCKS_PER_SEC);
}

int main(int argc, char const *argv[])
{
    int *arr, size, low_bound, upp_bound;
    printf("Enter length of the array: ");
    scanf("%d", &size);
    printf("Enter lower bound of the random numbers: ");
    scanf("%d", &low_bound);
    printf("Enter upper bound of the random numbers: ");
    scanf("%d", &upp_bound);

    printf("\n\n");

    arr = random_list(size, low_bound, upp_bound);
    int *arr1 = arr, *arr2 = arr, *arr3 = arr, *arr4 = arr, *arr5 = arr;

    time_t start, stop;

    start = clock();     bubble_sort(arr1, size);   stop = clock();
    printf("Bubble Sort: %lfs\n", time_in_s(start, stop));

    start = clock();     insertion_sort(arr2, size);    stop = clock();
    printf("Insertion Sort: %lfs\n", time_in_s(start, stop));

    start = clock();     selection_sort(arr3, size);    stop = clock();
    printf("Selection Sort: %lfs\n", time_in_s(start, stop));

    start = clock();     merge_sort(arr4, 0, size);    stop = clock();
    printf("Merge Sort: %lfs\n", time_in_s(start, stop));

    start = clock();     quick_sort(arr5, 0, size);     stop = clock();
    printf("Quick Sort: %lfs\n", time_in_s(start, stop));


    return 0;
}
