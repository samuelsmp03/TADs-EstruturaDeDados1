//
// Created by samuelmp on 02/06/24.
//
#include "DLList.h"
typedef struct _dlnode_{
    void *data;
    struct _dlnode_ *next;
    struct _dlnode_ *prev;
}DLnode;

typedef struct _dllist_{
    DLnode *first;
    DLnode *cur;
}DLList;

DLList *dllCreate(){
    DLList *dl;
    dl = (DLList*)malloc(sizeof(DLList));
    if(dl != NULL){
        dl->first = NULL;
        dl->cur = NULL;
        return dl;
    }
    return NULL;
}
int dllDestroy(DLList *dl){
    if(dl != NULL){
        if(dl->first == NULL){
            free(dl);
            return TRUE;
        }
    }
    return FALSE;
}

int dllInsertAsFirst(DLList *dl, void *data){
    DLnode *newnode;
    if(dl != NULL){
        if(data != NULL){
            newnode = (DLnode*)malloc(sizeof(DLnode));
            if(newnode != NULL){
                newnode->data = data;
                newnode->next = dl->first;
                newnode->prev = NULL;
                if(dl->first != NULL){
                    dl->first->prev = newnode;
                }
                dl->first = newnode;
                return TRUE;
            }
        }
    }
    return FALSE;
}

int dllInsertAsLast(DLList *dl, void *data){
    DLnode *newnode,*last;
    if(dl != NULL){
        if(data != NULL){
            newnode = (DLnode*)malloc(sizeof(DLnode));
            if(newnode != NULL){
                if(dl->first == NULL){
                    last = NULL;
                }else{
                    while(last->next != NULL){
                        last = last->next;
                    }
                }
                newnode->data = data;
                newnode->prev = last;
                newnode->next = NULL;
                if(last == NULL){
                    dl->first = newnode;
                }else{
                    last->next = newnode;
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}
void *dllQuery(DLList *dl, void *key,int (*cmp)(void*,void*)){
    DLnode *spec;
    int stat;
    if(dl != NULL && key != NULL){
        if(dl->first != NULL){
            spec = dl->first;
            stat = cmp(key, spec->data);
            while(stat == FALSE && spec->next != NULL){
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if(stat == TRUE){
                return spec->data;
            }
        }
    }
    return NULL;
}
void *dllRemoveSpec(DLList *dl, void *key,int (*cmp)(void*,void*)){
    DLnode *spec;
    void *data;
    int stat;
    if(dl != NULL && key != NULL){
        if(dl->first != NULL){
            spec = dl->first;
            stat = cmp(key, spec->data);
            while(stat == FALSE && spec->next != NULL){
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if(stat == TRUE){
                data = spec->data;
                if(spec == dl->first){
                    dl->first = spec->next;
                }else{
                    spec->prev->next = spec->next;
                    spec->next->prev = spec->prev;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}
void *dllGetFirst(DLList *dl){
    if(dl != NULL){
        if(dl->first != NULL){
            dl->cur = dl->first;
            return dl->cur->data;
        }
    }
    return NULL;
}

void *dllGetNext(DLList *dl){
    if(dl != NULL){
        if(dl->cur->next != NULL){
            dl->cur = dl->cur->next;
            return dl->cur->data;
        }
    }
    return NULL;
}

int dllNumNodes(DLList *dl){
    DLnode *cur;
    int size = 0;
    if(dl != NULL){
        if(dl->first != NULL){
            cur = dl->first;
            size++;
            while(cur->next != NULL){
                cur = cur->next;
                size++;
            }
        }
    }
    return size;
}