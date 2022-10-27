#include "insertion_sort.h"
#include "linked_list.h"



void sort(linked_list *llPtr)
{
    node_t *ptr_to_current = llPtr->head->next;
    node_t *ptr_to_pre = llPtr->head;
    node_t *tracker = llPtr->head;
    

    while(ptr_to_current != NULL) 
    {
        /*In the case that node must be inserted as new head*/
        if (ptr_to_current->data < ptr_to_pre->data && ptr_to_pre == llPtr->head) 
        {
            llPtr->head = swap(ptr_to_pre, ptr_to_current); /*New head must be the first in ll, which is returned by function*/
            ptr_to_current = llPtr->head->next; /*now points to 2nd node in list*/
            ptr_to_pre = llPtr->head; /*now points to 1st node in list*/
        }

        else if (ptr_to_current->data < ptr_to_pre->data) /*node needs to be sorted*/
        {
            /*tracker must be one node before pre*/
            while (tracker->next != ptr_to_pre) 
            {
                tracker = tracker->next;
            }

            tracker->next = swap(ptr_to_pre, ptr_to_current); /*because tracker is one node before pre, the next of the tracker must point to the y of the funtion*/
            ptr_to_pre = tracker; /*to compare to next data one down in list*/
            tracker = llPtr->head; /*resets tracker to start*/
        }

        else
        {
            /*when list is sorted move currrent and previous the the right in list*/
            ptr_to_current = ptr_to_current->next; 
            ptr_to_pre = ptr_to_pre->next;
        }
    }
}