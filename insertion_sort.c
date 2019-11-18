#include <stdio.h>

/*  meet insertion sort here   */
void insertion_sort(int arr[], int size){
    for(int i=1; i<size; i++){
        int temp = arr[i];
        int j = i-1;
        while(temp <= arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}