//
// Created by samuelmp on 24/04/24.
//
#include "queue.h"

typedef struct _QUEUE_{
    void** item;
    int front,rear;
    int maxItens;
}Queue;

Queue *qCreate(int n){
    Queue *q;
    if(n > 0){
       q = (Queue*)malloc(sizeof(Queue));
       if(q != NULL){
           q->item = (void**)malloc(sizeof(void*)*n);
           if(q->item != NULL){
               q->maxItens = n;
               q->front = 0;
               q->rear = -1;
               return q;
           }
       }
        free(q);
    }
    return NULL;
}

int qDestroy(Queue *q){
    if(q != NULL){
        if(q->rear<0){
            free(q->item);
            free(q);
            return TRUE;
        }
    }
    return FALSE;
}

int qEnqueue(Queue *q,void* elm){
    if(q!=NULL){
        if(q->rear < q->maxItens-1){
            q->rear++;
            q->item[q->rear] = elm;
            return TRUE;
        }
    }
    return FALSE;
}

void *qDequeue(Queue *q){
    void *data;
    int i;
    if(q!=NULL){
        if(q->rear >= 0){
            data = q->item[q->front];
            for(i=0;i<q->rear;i++){
                q->item[i] = q->item[i+1];
            }
            q->rear--;
            return data;
        }
    }
    return NULL;
}

void *qFirst(Queue *q){
    if(q!=NULL){
        if(q->rear >= 0){
            return q->item[q->front];
        }
    }
    return NULL;
}

int qIsEmpty(Queue *q){
    if(q!=NULL){
        if(q->rear < 0){
            return TRUE;
        }
    }
    return FALSE;
}
