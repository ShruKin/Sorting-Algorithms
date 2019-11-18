#include <stdio.h>  //  'cause thats standard
#include <stdlib.h> //  for rand and srand

#define sizeofarr(a) (sizeof(a)/sizeof(a[0]))   //  too lazy to count your no. of elements? use this!

/*  one stop solution to print the whole list   */
void print_arr(int arr[] ,int size){
    for(int i=0; i<size; i++)
        printf("%d, ", arr[i]);
    printf("\b\b  \b\b\n");
}

/*  random numbers call for random fum  */
int* random_list(int size, int low_bound, int upp_bound){
    int *arr;
    arr = (int *)malloc(size * sizeof(int));
    srand(time(0));
    for(int i=0; i<size; i++)
        arr[i] = (rand() % (upp_bound - low_bound + 1) + low_bound);  //  random no. at each element

    return arr;
}
