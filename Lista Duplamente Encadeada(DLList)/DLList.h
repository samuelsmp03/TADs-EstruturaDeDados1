//
// Created by samuelmp on 02/06/24.
//

#ifndef TAD_DLIST_DLLIST_H
#define TAD_DLIST_DLLIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct _dllist_ DLList;
typedef struct _dlnode_ DLnode;
DLList *dllCreate(); //OK
int dllDestroy(DLList *dl); //OK
int dllInsertAsFirst(DLList *dl, void *data); //OK
int dllInsertAsLast(DLList *dl, void *data); //OK
void *dllQuery(DLList *dl, void *key,int (*cmp)(void*,void*)); //OK
void *dllRemoveSpec(DLList *dl,void *key,int(*cmp)(void*,void*)); //OK
void *dllGetFirst(DLList *dl); //OK
void *dllGetNext(DLList *dl); //OK
int dllNumNodes(DLList *dl); //OK
#endif //TAD_DLIST_DLLIST_H
