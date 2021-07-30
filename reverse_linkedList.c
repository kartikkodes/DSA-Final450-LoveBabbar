#include<stdio.h>
#include<malloc.h>

//-------------------------------------------------------------
struct dot {
int data;
struct dot * is_holding;
};

//--------------------------------------------------------------
//Function for traversal of LL
void traversal(struct dot * headNode)
{
  while(headNode!=NULL){
  printf("%d\n",headNode->data);
  headNode = headNode->is_holding;
  }
}

//--------------------------------------------------------------
//Reverse Function
struct dot * reverseList(struct dot * node)
{
  struct dot * prev = (struct dot *)malloc(sizeof(struct dot));
  struct dot * current = (struct dot *)malloc(sizeof(struct dot));
  struct dot * next = (struct dot *)malloc(sizeof(struct dot));
  
  prev = NULL;
  current = node;
  
  while(current!=NULL)
  {
  next=current->is_holding;
  current->is_holding=prev;
  
  prev=current;
  current=next;
  }
  return prev;
}

//----------------------------------------------------------
//Main Function
int main()
{
struct dot * head = (struct dot *)malloc(sizeof(struct dot));
struct dot * second = (struct dot *)malloc(sizeof(struct dot));
struct dot * third = (struct dot *)malloc(sizeof(struct dot));
struct dot * fourth = (struct dot *)malloc(sizeof(struct dot));
struct dot * last = (struct dot *)malloc(sizeof(struct dot));

head->data = 10;
head->is_holding = second;

second->data = 20;
second->is_holding = third;

third->data = 30;
third->is_holding = fourth;

fourth->data = 40;
fourth->is_holding = last;

last->data = 50;
last->is_holding = NULL;

traversal(head);
printf("Reversing starting...");
head=reverseList(head);
traversal(head);
}
