#include <stdio.h>

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