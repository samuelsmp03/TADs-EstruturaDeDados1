//
// Created by samuelmp on 24/04/24.
//

#ifndef UNTITLED4_QUEUE_H
#define UNTITLED4_QUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef struct _QUEUE_ Queue;
Queue *qCreate(int num);
int qEnqueue (Queue *q,void* elm);
int qIsEmpty (Queue *q);
void* qFirst (Queue *q);
void *qDequeue (Queue *q);
int qDestroy(Queue *q);

#endif //UNTITLED4_QUEUE_H
