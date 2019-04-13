#include <stdio.h>  //  'cause thats standard
#include <time.h>   //  for time_t
#include <stdlib.h> //  for rand and srand

#define sizeofarr(a) (sizeof(a)/sizeof(a[0]))   //  too lazy to count your element? use this!

/*  theses definations are for random list generation   */
#define MAX_ELEMENTS 10
#define LOWER_BOUND 0
#define UPPER_BOUND 100

/*  swap it with a 3rd variable: make a function to make it look sec(c) */
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

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

/*  one stop solution to print the whole list   */
void print_arr(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d, ", arr[i]);
    printf("\b\b  \b\b\n");
}

/*  random list generator   */
int* random_list(int arr[], int size){
    srand(time(0));
    for(int i=0; i<size; i++)
        arr[i] = (rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND);  //  random no. at each element

    return arr;
}

int main(int argc, char const *argv[])
{
    // int arr[] = {45, 85, 69, 12, 3, 78, 65, 47}; //  Huh! this braces enclosed initialization is booring!
    int arr[MAX_ELEMENTS];
    random_list(arr, sizeofarr(arr));   //  lets play with a random list!

    printf("Input list:\n"); print_arr(arr, sizeofarr(arr));    //  printing the input list(ideally unsorted!)

    time_t start = clock(); //  start checking your time
    selection_sort(arr, sizeofarr(arr));   //  sort it out ;)
    time_t stop = clock();  //  stop! the sorting is over :)

    printf("\nSorted list:\n"); print_arr(arr, sizeofarr(arr)); //  printing the sorted list
    
    double time = ((double)(stop - start)/CLOCKS_PER_SEC)*1000.0;   //  calculate the time in ms
    printf("\nTime: %gms\n", time); //  print the time

    return 0;
}
