//
// Created by vitor on 15/05/22.
//

#ifndef CIRCULAR_QUEUE_CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_CIRCULAR_QUEUE_H

typedef struct queue CircularQueue;

CircularQueue *circularQueueCreate(int max_elements);

int circularQueueIncrement(int max_elements, int i);

int circularQueueDecrement(int max_elements, int i);

int circularQueuePush(CircularQueue *queue, void *data);

void *circularQueuePop(CircularQueue *circularQueue);

int circularQueueDestroy(CircularQueue *queue);

void **circularQueueElements(CircularQueue *queue);

void *circularQueueFind(CircularQueue *circularQueue, void *key, int (*cmp)(void *, void *));

void *circularQueueFindAll(CircularQueue *circularQueue);

void *circularQueueRemove(CircularQueue *circularQueue, void *key, int (*cmp)(void *, void *));

void *circularQueuePromove( CircularQueue *circularQueue, int promove_positions);

void *circularQueueDemote( CircularQueue *circularQueue, int demote_positions);

void *circularQueueFirst(CircularQueue *circularQueue);

#endif //CIRCULAR_QUEUE_CIRCULAR_QUEUE_H
