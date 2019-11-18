#include <stdio.h>

int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot the highest element
    int i = low - 1;  // Index of smaller element 
  
    for(int j = low; j <= high- 1; j++) 
    { 
        if(arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quick_sort(int arr[], int low, int high) 
{ 
    if(low < high) 
    { 
        int pi = partition(arr, low, high); //  arr[pi] is sorted
  
        quick_sort(arr, low, pi - 1); 
        quick_sort(arr, pi + 1, high); 
    } 
} 