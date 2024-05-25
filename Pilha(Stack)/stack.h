//
// Created by samuelmp on 24/04/24.
//

#ifndef UNTITLED4_STACK_H
#define UNTITLED4_STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef struct _STACK_ Stack;
Stack *stkCreate(int max);
int stkDestroy(Stack *s);
int stkPush(Stack *s,void *elm);
void *stkPop(Stack *s);
void *stkTop(Stack *s);
int stkIsEmpty(Stack *s);

#endif //UNTITLED4_STACK_H
