//
// Created by vitor on 15/05/22.
//

#include "circular_queue.h"
#include "stdlib.h"
#include "stdio.h"

#define TRUE 1
#define FALSE 0

typedef struct queue {
    int front;
    int rear;
    int max_elements;
    int size;
    void **elements;
} CircularQueue;

CircularQueue *circularQueueCreate(int max_elements) {
    CircularQueue *circular_queue = (CircularQueue *) malloc(sizeof(CircularQueue));

    if (max_elements < 0 || circular_queue == NULL) return NULL;

    circular_queue->elements = (void **) malloc(sizeof(void *) * max_elements);

    if (circular_queue->elements == NULL) {
        free(circular_queue);
        return NULL;
    }

    circular_queue->front = 0;
    circular_queue->rear = -1;
    circular_queue->max_elements = max_elements;
    circular_queue->size = 0;

    return circular_queue;
}

int circularQueueIncrement(int max_elements, int i) {
    if (i == max_elements - 1) return 0;
    else return i + 1;
}

int circularQueueDecrement(int max_elements, int i) {
    if (i < 0) return i - 1;
    else return max_elements - 1;
}

int circularQueueDestroy(CircularQueue *circularQueue) {
    if (circularQueue == NULL || circularQueue->size != 0) return FALSE;

    free(circularQueue->elements);
    free(circularQueue);

    return TRUE;
}

void *circularQueueFind(CircularQueue *circularQueue, void *key, int (*cmp)(void *, void *)) {
    if (circularQueue == NULL) return NULL;

    for (int i = 0; i < circularQueue->size; i++) {
        if (cmp(circularQueue->elements[i], key)) {
            void *data = circularQueue->elements[i];
            return data;
        }
    }

    return NULL;
}

void *circularQueueFindAll(CircularQueue *circularQueue) {
    if (circularQueue == NULL || circularQueue->elements == NULL) return NULL;

    return circularQueue->elements;
}

int circularQueuePush(CircularQueue *circularQueue, void *data) {
    if (circularQueue == NULL || circularQueue->size > circularQueue->max_elements) return FALSE;

    circularQueue->rear = circularQueueIncrement(circularQueue->max_elements, circularQueue->rear);
    circularQueue->elements[queue->rear] = data;
    circularQueue->size++;

    return TRUE;
}

void *circularQueuePop(CircularQueue *circularQueue) {
    if (circularQueue == NULL || circularQueue->rear < 0) return NULL;

    void *result = circularQueue->elements[circularQueue->front];

    for (int i = circularQueue->front; i < circularQueue->rear; i++) {
        circularQueue->elements[i] = circularQueue->elements[i + 1];
    }
    circularQueue->rear--;
    circularQueue->size--;

    return result;
}

void *circularQueueRemove(CircularQueue *circularQueue, void *key, int (*cmp)(void *, void *)) {
    if (circularQueue == NULL || key == NULL || cmp == NULL || circularQueue->rear < 0) return NULL;

    for (int i = 0; i < circularQueue->size; i++) {
        if (cmp(circularQueue->elements[i], key)) {
            void *result = circularQueue->elements[i];
            for (int j = i; j < circularQueue->rear; j++) {
                circularQueue->elements[i] = circularQueue->elements[i + 1];
            }
            return result;
        }
    }
    circularQueue->rear--;
    circularQueue->size--;

    return NULL;
}

void *circularQueuePromove(CircularQueue *circularQueue, int promove_positions) {
    if (circularQueue == NULL || promove_positions < 0) return FALSE;

    int new_position = circularQueue->rear - promove_positions;
    void *rear_element = circularQueue->elements[circularQueue->rear];

    for (int i = circularQueue->rear; i > new_position; i--) {
        circularQueue->elements[i] = circularQueue->elements[i - 1];
    }
    circularQueue->elements[new_position] = rear_element;

    return circularQueue->elements[circularQueue->rear];
}

void *circularQueueDemote(CircularQueue *circularQueue, int demote_positions) {
    if (circularQueue == NULL || demote_positions < 0) return FALSE;

    int new_position = circularQueue->front + demote_positions;
    void *front_element = circularQueue->elements[circularQueue->front];

    for (int i = circularQueue->front; i < new_position; i++) {
        circularQueue->elements[i] = circularQueue->elements[i + 1];
    }
    circularQueue->elements[new_position] = front_element;

    return circularQueue->elements[circularQueue->rear];
}

void *circularQueueFirst(CircularQueue *circularQueue) {
    if (circularQueue == NULL || circularQueue < 0) return NULL;

    void *result = circularQueue->elements[circularQueue->front];

    return result;
}