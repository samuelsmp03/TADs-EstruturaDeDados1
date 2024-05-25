/*
gCofo.h
Arquivo com a especificação para o TAD gCofo.c
Tipo de dado gCofo
*/
#ifndef __GCOFO_H
#define __GCOFO_H
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include<stdlib.h>


typedef struct __gcofo__{
    int numItens;
    int maxItens;
    int cur;
    void** item;
}gCofo;

gCofo* gCofCreate(int max_itens);
int gCofDestroy(gCofo *gc);
int gCofInsert(gCofo *gc, void* item);
void* gCofRemove(gCofo *gc, void* key,int(*cmp)(void*,void*));
void* gCofQuery(gCofo *gc,void* key,int (*cmp)(void*,void*));
void* gCofGetFirst(gCofo *gc);
void* gCofGetNext(gCofo *gc);


#else
    typedef struct __gcofo__{
        int numItens;
        int maxItens;
        int cur;
        void** item;
    }gCofo;

    extern gCofo* gcofCreate(int max_itens);
    extern int gCofDestroy(gCofo* c);
    extern int gCofInsert(gCofo* c, void* item);
    extern void* gCofRemove(gCofo* c, void* key);
    extern void* gCofQuery(gCofo* c,void* key);
    extern void* gCofGetFirst(gCofo* c);
    extern void* gCofGetNext(gCofo* c);
    
#endif
