#include <stdio.h>

/*  swap it with a 3rd variable: make a function to make it look sec(c) */
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*  meet bubble sort here   */
void bubble_sort(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i; j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

/*  one stop solution to print the whole list   */
void print_arr(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d, ", arr[i]);
    printf("\b\b  \b\b\n");
}