#include "arr.c"
#include "bubble_sort.c"
#include "insertion_sort.c"
#include "selection_sort.c"
#include "merge_sort.c"

int main(int argc, char const *argv[])
{
    int *arr, ch, size, low_bound, upp_bound;

    while(1){
        printf("MENU");
        printf("\n1. Generate a random array");
        printf("\n2. Print array");
        printf("\n3. Bubble Sort");
        printf("\n4. Insertion Sort");
        printf("\n5. Selection Sort");
        printf("\n6. Merge Sort");
        printf("\n7. Quick Sort");
        printf("\n0. EXIT");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        printf("\n");

        switch(ch){
            case 0: exit(0);    break;

            case 1:
                printf("Enter length of the array: ");
                scanf("%d", &size);
                printf("Enter lower bound of the random numbers: ");
                scanf("%d", &low_bound);
                printf("Enter upper bound of the random numbers: ");
                scanf("%d", &upp_bound);
                
                arr = random_list(size, low_bound, upp_bound);
                printf("\nRandom List generated with %d numbers between %d-%d\n", size, low_bound, upp_bound);
                print_arr(arr, size);
                break;

            case 2: print_arr(arr, size);   break;

            case 3: bubble_sort(arr, size); break;

            case 4: insertion_sort(arr, size);  break;

            case 5: selection_sort(arr, size);  break;

            case 6: merge_sort(arr, 0, size);   break;

            default: printf("Wrong choice! Try again");

        }
        printf("\n\n");
    }
    return 0;
}
