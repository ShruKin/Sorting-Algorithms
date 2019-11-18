#include <stdio.h>

/*  gaurding the swap function for possible redeclaration   */
#ifndef SWAP    //  ignore this line
#define SWAP    //  ignore this line
/*  swap it with a 3rd variable: make a function to make it look sec(c) */
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
#endif  //  ignore this line

/*  meet selection sort here   */
void selection_sort(int arr[], int size){
    int min_idx;
    for (int i=0; i<size-1; i++) 
    { 
        min_idx = i; 
        for (int j = i+1; j < size; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 

        swap(&arr[min_idx], &arr[i]); 
    } 
}