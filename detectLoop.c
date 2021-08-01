#include<stdio.h>
#include<malloc.h>

struct dot {
    int data;
    struct dot * is_holding;
};

void traversal(struct dot * node){
    while (node!=NULL)
    {
        printf("%d\n",node->data);
        node=node->is_holding;
    } 
}


//Floyd Agorithm OR Tortoise and hare algorithm
void checkLoop_and_removeLoop(struct dot * node){

    struct dot * hare = (struct dot *)malloc(sizeof(struct dot));
    struct dot * tort = (struct dot *)malloc(sizeof(struct dot));

    hare=node;
    tort=node;
        while (hare && tort && hare->is_holding)
    {
        printf("Phase 1\n");

        tort=tort->is_holding;
        hare=hare->is_holding->is_holding;
        printf("Phase 2\n");
        if (hare == tort)
        {
            printf("Loop has stopped at node where data is %d\n",tort->data);
            break;
        }
        else{
            printf("Unsuccesfull");
            printf("\n-----------------\nNEW ITERATION BEGINING\n");
        }
        // getchar();
    }
    hare=node;
    printf("\nEntering second while loop\n");
    while (hare->is_holding!=tort->is_holding)
            {
                hare=hare->is_holding;
                tort=tort->is_holding;
            }
            printf("Out of the 2 while loop\n");
            tort->is_holding=NULL;

}

int main(){ 
    struct dot * head = (struct dot *)malloc(sizeof(struct dot));
    struct dot * second = (struct dot *)malloc(sizeof(struct dot));
    struct dot * third = (struct dot *)malloc(sizeof(struct dot));
    struct dot * fourth = (struct dot *)malloc(sizeof(struct dot));
    struct dot * fifth = (struct dot *)malloc(sizeof(struct dot));
    struct dot * sixth = (struct dot *)malloc(sizeof(struct dot));

    head->data=10;
    head->is_holding=second;

    second->data=20;
    second->is_holding=third;

    third->data=30;
    third->is_holding=fourth;

    fourth->data=40;
    fourth->is_holding=fifth;

    fifth->data=50;
    fifth->is_holding=sixth;

    sixth->data=60;
    sixth->is_holding=third;

    checkLoop_and_removeLoop(head);
    printf("\nStarting traversal\n");
    traversal(head);
    return 0;
}