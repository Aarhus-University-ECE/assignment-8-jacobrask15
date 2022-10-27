extern "C"
{
#include "insertion_sort.h"
#include "linked_list.h"
#include "list_queue.h"
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{

    int testlist[] = {4, 3, 10, 1, 6};
    linked_list *test = createLinkedList();
    for (int i = 0; i < 5; ++i)
    {
        insertFront(createNode(testlist[5 - i - 1]), test);
    }

    printLL(test);
    sort(test);
    printLL(test);

    queue *test_queue = (queue *)malloc(sizeof(queue));
    init_queue(test_queue);
    int aa = empty(test_queue);
    printf("\nSkal være 1:    %d", aa);

    enqueue(test_queue, -5);
    enqueue(test_queue, 10);
    enqueue(test_queue, 0);
    printf("\nFront skal være -5:    %d", test_queue->front->data);
    printf("\nRear skal være 0:    %d", test_queue->rear->data);
    int x = dequeue(test_queue);
    printf("\nFront skal være 10:    %d", test_queue->front->data);
    int y = dequeue(test_queue);
    int z = dequeue(test_queue);
    printf("\nSkal være -5:    %d", x);
    printf("\nkal være 10:    %d", y);
    printf("\nkal være 0:    %d", z);
    printf("\nkal være 0:    %d", test_queue->size);

    int a = empty(test_queue);
    printf("\nSkal være 1:    %d", a);

    return 0;
}
