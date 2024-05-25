//
// Created by samuelmp on 14/05/24.
//

#ifndef TAD_LISTA_SLLIST_H
#define TAD_LISTA_SLLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define SLL_MEM_ERR (SLList*)-1
#define MEM_ERR (void*)-1
#define SLNODE_MEM_ERR (SLnode*)-1

typedef struct _SLList_ SLList;
typedef struct _SLnode_ SLnode;
SLList *sllCreate(void); //OK
int sllDestroy(SLList *l); //OK
int SsllInsertFirst(SLList *l,void *data); //Não foi utilizado
int sllInsertLast(SLList *l,void *data); //OK
void *sllRemoveFirst(SLList *l); //OK
void *sllGetFirst(SLList *l); //0K
void *sllGetNext(SLList *l); //OK
void *sllQuery(SLList *l, void *key,int (*cmp)(void*,void*)); //OK
void *sllRemoveSpec(SLList *l,void *key,int (*cmp)(void*,void*)); //OK
int sllNumNodes(SLList *l);

#endif //TAD_LISTA_SLLIST_H
