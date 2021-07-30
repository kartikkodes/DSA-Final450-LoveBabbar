#include <stdio.h>
#include <malloc.h>
//----------------------------------------------------------------------------------------------------
struct dot
{
    int data;
    struct dot *is_holding;
};
//----------------------------------------------------------------------------------------------------
void traversal(struct dot *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->is_holding;
    }
}


//-----------------------------------------------------------------------------------------------------
struct dot * reverseK(struct dot * headNode, int k)
{
    struct dot *prevptr = (struct dot *)malloc(sizeof(struct dot));
    struct dot *currptr = (struct dot *)malloc(sizeof(struct dot));
    struct dot *nextptr = (struct dot *)malloc(sizeof(struct dot));

    prevptr = NULL;
    currptr = headNode;
    int count = 0;
    int count2 = 0;

    while (currptr != NULL && count<k)
    {
        nextptr = currptr->is_holding;
        currptr->is_holding = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr!=NULL){
    headNode->is_holding = reverseK(nextptr,k);
    }
    return prevptr;
}
//------------------------------------------------------------------------------------
int main()
{
    struct dot *head;
    struct dot *second;
    struct dot *third;
    struct dot *fourth;
    struct dot *fifth;
    struct dot *sixth;
    struct dot *newHead;

    head = (struct dot *)malloc(sizeof(struct dot));
    second = (struct dot *)malloc(sizeof(struct dot));
    third = (struct dot *)malloc(sizeof(struct dot));
    fourth = (struct dot *)malloc(sizeof(struct dot));
    fifth = (struct dot *)malloc(sizeof(struct dot));
    sixth = (struct dot *)malloc(sizeof(struct dot));

    head->data = 10;
    head->is_holding = second;

    second->data = 20;
    second->is_holding = third;

    third->data = 30;
    third->is_holding = fourth;
    fourth->data = 40;
    fourth->is_holding = fifth;

    fifth->data=50;
    fifth->is_holding=sixth;

    sixth->data=60;
    sixth->is_holding=NULL;

    traversal(head);
    printf("\n\n----------------------\n\n");
    int k = 2;
    head=reverseK(head,k);
    traversal(head);
}
