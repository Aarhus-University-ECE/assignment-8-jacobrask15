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
    printf("\nTjekker om queue er empty efter init, skal være 1:    %d", aa);

    enqueue(test_queue, -5);
    enqueue(test_queue, 10);
    enqueue(test_queue, 0);
    enqueue(test_queue, 5);

    // printf("\nFront skal være -5:    %d", test_queue->front->data);
    // printf("\nRear skal være 0:    %d", test_queue->rear->data);

    int x = dequeue(test_queue);
    int y = dequeue(test_queue);
    int z = dequeue(test_queue);
    int k = dequeue(test_queue);

    printf("\nSkal være -5:    %d", x);
    printf("\nskal være 10:    %d", y);
    printf("\nSkal være 0:    %d", z);
    printf("\nSkal være 5:    %d", k);

    printf("\nTester queue size, så forventet er 0:    %d", test_queue->size);

    return 0;
}
