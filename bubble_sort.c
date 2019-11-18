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

/*  meet bubble sort here   */
void bubble_sort(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i; j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}
