//
// Created by samuelmp on 14/05/24.
//
#include "SLList.h"

typedef struct _SLList_{
    SLnode *first;
    SLnode *cur;
}SLList;

typedef struct _SLnode_{
    void *data;
    struct _SLnode_  *next;
}SLnode;

SLList *sllCreate(void){
    SLList *l;
    l = (SLList*)malloc(sizeof(SLList));
    if(l != NULL){
        l->first = SLNODE_MEM_ERR;
        l->cur = SLNODE_MEM_ERR;
        return l;
    }
    return SLL_MEM_ERR;
}

int sllDestroy(SLList *l){
    if(l != SLL_MEM_ERR){
        if(l->first == SLNODE_MEM_ERR){
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertFirst(SLList *l, void *data){
    SLnode *newnode = (SLnode*)malloc(sizeof(SLnode));
    if(l != SLL_MEM_ERR){
        if(data != NULL){
            if(newnode!= NULL) {
                newnode->data = data;
                newnode->next = l->first;
                l->first = newnode;
                return TRUE;
            }
        }
    }
    return FALSE;
}

int sllInsertLast(SLList *l, void *data){
    SLnode *newnode, *last;
    if(l != SLL_MEM_ERR){
        if(data != NULL){
            newnode = (SLnode*)malloc(sizeof(SLnode));
            if(newnode != NULL) {
                newnode->data = data;
                newnode->next = SLNODE_MEM_ERR;
                if (l->first == SLNODE_MEM_ERR) {
                    l->first = newnode;
                    return TRUE;
                } else {
                    last = l->first;
                    while (last->next != SLNODE_MEM_ERR) {
                        last = last->next;
                    }
                    last->next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}
void *sllGetFirst(SLList *l){
    void *data;
    if (l != SLL_MEM_ERR){
        if(l->first != SLNODE_MEM_ERR) {
            l->cur = l->first;
            data = l->cur->data;
            return data;
        }
    }
    return MEM_ERR;
}

void *sllGetNext(SLList *l){
    void *data;
    if(l!= SLL_MEM_ERR){
        l->cur = l->cur->next;
        if(l->cur != SLNODE_MEM_ERR){
            data = l->cur->data;
            return data;
        }
    }
    return MEM_ERR;
}

void *sllRemoveFirst(SLList *l){
    SLnode *first;
    void* data;
    if(l != SLL_MEM_ERR){
        if(l->first != SLNODE_MEM_ERR){
            first = l->first;
            data = first->data;
            l->first = first->next;
            l->cur = first->next;
            free(first);
            return data;
        }
    }
    return MEM_ERR;
}



void *sllQuery(SLList *l, void *key,int (*cmp)(void*,void*)){ //OK
    SLnode *atual;
    void *data;
    int state;
    if(l != SLL_MEM_ERR){
        if(l->first != SLNODE_MEM_ERR) {
            if(key != NULL){
                atual = l->first;
                data = atual->data;
                state = cmp(key, data);
                while (atual->next != SLNODE_MEM_ERR && state == FALSE) {
                    atual = atual->next;
                    data = atual->data;
                    state = cmp(key, data);
                }
                if (state == TRUE) {
                    return data;
                }
            }
        }
    }
    return MEM_ERR;
}


void *sllRemoveSpec(SLList *l,void *key,int (*cmp)(void*,void*)){
    SLnode *atual,*prev;
    void *data;
    int state;
    if(l != SLL_MEM_ERR){
        if(l->first != SLNODE_MEM_ERR){
            if(key != NULL) {
                atual = l->first;
                prev = SLNODE_MEM_ERR;
                state = cmp(key, atual->data);
                while (atual->next != SLNODE_MEM_ERR && state == FALSE) {
                    prev = atual;
                    atual = atual->next;
                    state = cmp(key, atual->data);
                }
                if (state == TRUE) {
                    data = atual->data;
                    if (prev == SLNODE_MEM_ERR) {
                        l->first = atual->next;
                        l->cur = atual->next;
                    } else {
                        prev->next = atual->next;
                    }
                    free(atual);
                    return data;
                }
            }
        }
    }
    return MEM_ERR;
}
int sllNumNodes(SLList *l){
    SLnode *cur;
    int count = 0;
    if(l != SLL_MEM_ERR){
        if(l->first != SLNODE_MEM_ERR){
            cur = l->first;
            count++;
            if(cur->next != SLNODE_MEM_ERR){
                cur = cur->next;
                count++;
            }
        }
    }
    return count;
}
