#include "list_queue.h"
#include <assert.h>

void init_queue(queue *q)
{
  // Add your init_queue
  q->size = 0;
  q->front = NULL;
  q->rear = NULL;
}

int empty(queue *q)
{
  int x;

  if (q->size == 0)
  {
    x = 1;
  }
  else
  {
    x = 0;
  }

  return x;
}

void enqueue(queue *q, int x)
{
  // Add your enqueue function
  qnode *new_node = (qnode *)malloc(sizeof(qnode)); /*Creates node that is being enqueued*/
  new_node->data = x;                               /*inputs desired data in new node*/
  new_node->next = NULL;                            /*links the new node to linked list*/

  /*In the case of inserting first node in list*/
  if (q->rear == NULL)
  {
    q->rear = new_node;
    q->front = new_node;
  }
  else
  {
    q->rear->next = new_node; /*linsk new_node to list*/
    q->rear = new_node;       /*updates  new_node to be rear*/
  }

  q->size++;
}

int dequeue(queue *q)
{
  // Add your dequeue function
  int x;                     /*output*/
  assert(q->size > 0);       /*Cannot succesfully dequeue empty queue*/
  x = q->front->data;        /*collects data from front*/
  q->front = q->front->next; /*updates front to be node after the node we just dequeued*/

  q->size = q->size - 1; /*list is 1 node smaller*/

  return x;
}
