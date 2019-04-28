#include <stdio.h>
#include <malloc.h>

/*  generic node structre for a singly linked List*/
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;   //  head of the list: initially NULL

/*  traverse throught the list  */
void traverse(struct node *head){
    struct node *ptr = head;    //  a temporary node pointing to head

    if(ptr == NULL){    //  no nodes in the list
        printf("List Underflow! Unable to print!");
        return;
    }

    while(ptr->next != NULL){   //  iterating throughout the list(till NULL is reached)
        printf("%d -> ", ptr->data);  //  printing current node
        ptr = ptr->next;    //  shifting the temporary node to the next one
    }
    printf("%d -> ", ptr->data);  //  printing the last node
    //printf("\b\b  \b\b");   //  just beautifying stuffs! :*
    printf("NULL");
}

/*  insert node at the beginning of the list    */
struct node* insert_begin(struct node *head, int data){
    if (head == NULL) { //  if list is initially empty
        head = (struct node *)malloc(sizeof(struct node));  //  allocate the memory for head
        if (head == NULL) { //  if head couldnt be allocated: insufficient memory :(
            printf("Memory Underflow! Insertion failed!");
            return head;
        }
        head->data = data;  //  storing the data to the node
        head->next = NULL;  //  end of the list
        return head;
    }
    
    struct node *newNode = (struct node *)malloc(sizeof(struct node));  //  allocate memory for the new node
    
    if (newNode == NULL) {  //  if new node couldnt be allocated: insufficient memory :(
        printf("Memory Underflow! Insertion failed!");
        return head;
    }
    else {
        newNode->data = data;   //  store the data to the new node
        newNode->next = head;   //  link the new node to the head
        head = newNode; //  now the new node is the head
    }
    return head;
}

/*  insert at the end of the list   */
struct node* insert_end(struct node *head, int data){
    if (head == NULL) {
        head = (struct node *)malloc(sizeof(struct node));
        if (head == NULL) {
            printf("Memory Underflow! Insertion failed!");
            return head;
        }
        head->data = data;
        head->next = NULL;
        return head;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    if (newNode == NULL) {
        printf("Memory Underflow! Insertion failed!");
        return head;
    }
    else {
        struct node *ptr = head;
        while(ptr->next != NULL){   //  iterating till the last element
            ptr = ptr->next;    //  shifting the temporary node to the next one
        }
        newNode->data = data;
        newNode->next = NULL;   //  ending the list(as Insertion is being done at the end)
        ptr->next = newNode;    //  the previous last node is linked to the new node
    }
    return head;
}

/*  insert at the passed index  */
struct node* insert(struct node* head, int data, int idx){     //  idx is index of the insertion point, not postion! ;)
    if (head == NULL) {
        head = (struct node *)malloc(sizeof(struct node));
        if (head == NULL) {
            printf("Memory Underflow! Insertion failed!");
            return head;
        }
        head->data = data;
        head->next = NULL;
        return head;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if(idx == 0)    //  if idx is zero, insert at the beginning
    {
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    if (newNode == NULL) {
        printf("Memory Underflow! Insertion failed!");
        return head;
    }
    else {
        struct node *ptr = head;
        for(int i = 0; i < idx-1; i++)
        {   //  interating till the required position to insert
            ptr = ptr->next;
            if(ptr == NULL){    //  if end of the list is already reached
                printf("Index overflow! Unable to insert");
                return head;
            }
        }
        newNode->data = data;

        /*  inserting the node in between the current temporary node and the next one   */
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    return head;
}

/*  delete from the beginning   */
struct node* delete_begin(struct node* head){
    if (head == NULL) {
        printf("List underflow! Unable to delete!");
        return head;
    }

    else if(head->next == NULL){    //  when head is the only element and has to be deleted
        head == NULL;   //  set it to NULL
        return head;
    }

    struct node *ptr = head;
    head = head->next;  //  shifting the head too the next one
    free(ptr);  //  freeing the temporary node(which was the last head)

    return head;
}

/*  delete from the end */
struct node* delete_end(struct node* head){
    if (head == NULL) {
        printf("List underflow! Unable to delete!");
        return head;
    }

    else if(head->next == NULL){    
        head == NULL;
        return head;
    }

    struct node *ptr = head, *ptr_prev/*previous to the temporary node*/;
    while(ptr->next != NULL){
        ptr_prev = ptr; //  tracking the previous to the temporary pointer
        ptr = ptr->next;
    }
    //  iterating throughout, ptr is the last element now
    ptr_prev->next = NULL;  //  complete the list after the previous to last node
    free(ptr);  //  free the last node

    return head;
}

/*  delete from the passed index    */
struct node* del(struct node* head, int idx){
    if (head == NULL) {
        printf("List underflow! Unable to delete!");
        return head;
    }

    struct node *ptr = head, *toDel/*the node needed to delete*/;

    if(idx == 0)    //  if idx is zero, delete from beginning
    {
        head = head->next;
        free(ptr);
        return head;
    }

    for(int i = 0; i < idx-1; i++)
    {
        ptr = ptr->next;
        if(ptr->next == NULL){
            printf("Index overflow! Unable to delete");
            return head;
        }
    }
    toDel = ptr->next;  //  node that is needed to be deleted

    if(ptr->next != NULL)   //  if the temporary node is not the last element
        ptr->next = ptr->next->next;
    free(toDel);

    return head;
}

/*  SAMPLE MAIN FUNCTION TO TEST THE FUNCTIONS     
int main(int argc, char const *argv[])
{
    // insert(1, 0);
    // insert(2, 0);
    // insert(3, 1);
    // insert(4, 2);
    // insert(5, 3);
    
    // traverse();

    // delete_begin();
    // delete_begin();
    
    // printf("\n");
    // traverse();

    struct node *ll1 = NULL, *ll2 = NULL;
    ll1 = insert_begin(ll1, 1);
    ll1 = insert_begin(ll1, 2);
    ll1 = insert_begin(ll1, 3);

    ll2 = insert_end(ll2, 10);
    ll2 = insert_end(ll2, 20);
    ll2 = insert_end(ll2, 30);

    traverse(ll1);
    printf("\n");
    traverse(ll2);

    return 0;
}*/
