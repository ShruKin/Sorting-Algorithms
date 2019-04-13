#include <stdio.h>  //  'cause thats standard
#include <time.h>   //  for time_t
#include <stdlib.h> //  for rand and srand

#define sizeofarr(a) (sizeof(a)/sizeof(a[0]))   //  too lazy to count your element? use this!

/*  theses definations are for random list generation   */
#define MAX_ELEMENTS 10
#define LOWER_BOUND 0
#define UPPER_BOUND 100

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
    insertion_sort(arr, sizeofarr(arr));   //  sort it out ;)
    time_t stop = clock();  //  stop! the sorting is over :)

    printf("\nSorted list:\n"); print_arr(arr, sizeofarr(arr)); //  printing the sorted list
    
    double time = ((double)(stop - start)/CLOCKS_PER_SEC)*1000.0;   //  calculate the time in ms
    printf("\nTime: %gms\n", time); //  print the time

    return 0;
}
