#include "sll.c"    //  singly linked list node and generic functions are here
#include <time.h>   //  for timekeeping
#include <stdbool.h>    //  for a stupid bool var

#define MAX_ELEMENTS 10 //  max elements for the list

/*  theses definations are for random list generation   */
#define LOWER_BOUND 0
#define UPPER_BOUND 100

/*  this function returns a random number each time within the range:
    (LOWER_BOUNd ... UPPER_BOUND), both inclusive   */
int rand_num()
{
    static bool first_time = true;
    if(first_time){
        srand(time(NULL));  //  seed srand only once in the program
        first_time = false; //  first time over!
    }

    return (rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND);  //    both inclusive  
}

struct node* merge(struct node* left, struct node* right)
{
    struct node* merged = NULL; //  a temp LL where the merged list will be stored

    while(left != NULL && right != NULL){   //  iterating through the sub-lists
        if(left->data <= right->data){  
            merged = insert_end(merged, left->data);    //  sort and insert to the list
            left = left->next;  //  shift the tested list
        }

        else if(left->data >= right->data){
            merged = insert_end(merged, right->data);   //  sort and insert to the list
            right = right->next;    //  shift the tested list
        }
    }

    while(left != NULL){    //  if there are extra element(s) in the left LL, insert them too
        merged = insert_end(merged, left->data);
        left = left->next;
    }
    
    while(right != NULL){   //  if there are extra element(s) in the right LL, insert them too
        merged = insert_end(merged, right->data);
        right = right->next;
    }

    // printf("Sorting & Merging: \n");    //  PRINT DEBUGGING
    // traverse(merged);   printf("\n\n"); //  PRINT DEBUGGING
    return merged;
}

struct node* merge_sort(struct node *list)
{
    if(list == NULL || list->next == NULL)  //  terminating condition, when the list is empty
        return list;

    struct node *left = list, *right = list;
    while(right != NULL && right->next != NULL && right->next->next != NULL){   //  finding the mid element
        right = right->next->next;  //  hopping right two at a time
        left = left->next;  //  while hopping left one at a time
    }
    /*  after the above iteration: left is the middle element   */
    right = left->next; //  setting the head of the right LL to the next of mid
    left->next = NULL;  //  terminating the left LL's end to NULL
    left = list;    //  setting the head of left LL to the head of the list

    // printf("Spliting: \n"); //  PRINT DEBUGGING
    // printf("Left: ");   traverse(left);     printf("\n");   //  PRINT DEBUGGING
    // printf("Right: ");   traverse(right);   printf("\n\n"); //  PRINT DEBUGGING

    left = merge_sort(left);    //  keep on dividing the left half
    right  = merge_sort(right);  //  keep on dividing the right half
    list = merge(left, right);      //  conquer the left and right halves
}

int main(int argc, char const *argv[])
{
    struct node *list = NULL;

    for(int i=0; i<MAX_ELEMENTS; i++)   //  random list generation
        list = insert_end(list, rand_num());

    traverse(list);
    printf("\n\n");

    time_t start = clock(); //  start your stopwatch
    list = merge_sort(list);
    time_t stop = clock();  //  stop! the sorting is over :)

    printf("\n\nSorted List: "); traverse(list); printf("\n");
    double time = ((double)(stop - start)/CLOCKS_PER_SEC)*1000.0;   //  calculate the time in ms
    printf("Time: %gms\n", time); //  print the time

    return 0;
}
