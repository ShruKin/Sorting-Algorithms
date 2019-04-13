#include <stdio.h>  //  'cause thats standard
#include <time.h>   //  for time_t
#include <stdlib.h> //  for rand and srand

#define sizeofarr(a) (sizeof(a)/sizeof(a[0]))   //  too lazy to count your element? use this!

/*  theses definations are for random list generation   */
#define MAX_ELEMENTS 10
#define LOWER_BOUND 0
#define UPPER_BOUND 100

void merge(int arr[], int l, int mid, int r)
{
    int i = l, j = mid+1, k = 0;
    int *temp = (int*)malloc((r-l+1) * sizeof(int));

    while((i <= mid) && (j <= r))   //  iterate over the subarrays
    {
        if(arr[i] <= arr[j])    //  sorting
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    //  copying rest of the elements(if any left)
	while(i <= mid)
    {
		temp[k++] = arr[i++];
	}
	while(j <= r)
    {
		temp[k++] = arr[j++];
	}

    //  copying the temp sorted part into the proper position in arr
    int m, t=0;
    for(m=l; m<=r; m++, t++)
        arr[m] = temp[t];
}

void merge_sort(int arr[], int l, int r)
{
    if(r <= l)  //  terminating condition
        return;

    int mid = (l + r) / 2;  //  mid element index

    merge_sort(arr, l, mid);    //  divide the left half
    merge_sort(arr, mid+1, r);  //  divide the right half
    merge(arr, l, mid, r);      //  conquer 
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
    merge_sort(arr, 0, sizeofarr(arr));   //  sort it out ;)
    time_t stop = clock();  //  stop! the sorting is over :)

    printf("\nSorted list:\n"); print_arr(arr, sizeofarr(arr)); //  printing the sorted list
    
    double time = ((double)(stop - start)/CLOCKS_PER_SEC)*1000.0;   //  calculate the time in ms
    printf("\nTime: %gms\n", time); //  print the time

    return 0;
}
