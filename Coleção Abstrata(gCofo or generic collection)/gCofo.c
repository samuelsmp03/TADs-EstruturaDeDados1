#include "gCofo.h"
gCofo* gCofCreate(int max_itens){
    gCofo *gc;
    if(max_itens > 0){
        gc = (gCofo*)malloc(sizeof(gCofo)*max_itens);
        if(gc !=NULL){
            gc->item = (void**)malloc(sizeof(void*)*max_itens);
            if (gc->item != NULL){
                gc->numItens = 0;
                gc->maxItens = max_itens;
                gc->cur = -1;
                return gc;
            }
            free(gc);
        }
    }
    return NULL;
}

int gCofDestroy(gCofo *gc){
    if(gc != NULL){
        if(gc->numItens == 0){
            free(gc->item);
            free(gc);
            return TRUE;
        }
    }
    return FALSE;
}

int gCofInsert(gCofo* gc, void* item){
    if(gc != NULL){
        if(gc->numItens < gc->maxItens){
            gc->item[gc->numItens] = item;
            gc->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void* gCofGetFirst(gCofo *gc){
    if(gc != NULL){
        gc->cur = 0;
        return gc->item[gc->cur];
    }
    return NULL;
}

void* gCofGetNext(gCofo* gc){
    if(gc != NULL){
        gc-> cur++;
        return gc->item[gc->cur];
    }
    return NULL;
}
int cmp(void* elm1, void* elm2){
    if(elm1 != NULL && elm2 != NULL){
        float *pElm1, *pElm2;
        pElm1 = (float*)elm1;
        pElm2 = (float*)elm2;
        if(*pElm1 == *pElm2){
            return TRUE;
        }
    }
    return FALSE;
}
void* gCofQuery(gCofo *gc,void* key, int (*cmp)(void*,void*)){
    void *data;
    int i=0,stat;
    if(gc != NULL && key !=NULL){
        if(gc->numItens > 0){
            stat = cmp(key,gc->item[i]);
            while(i<gc->numItens && stat != TRUE){
                i++;
                stat = cmp(key,gc->item[i]);
            }
            if(stat == TRUE){
                data = gc->item[i];
                return data;
            }
        }
    }
    return NULL;
}

void* gCofRemove(gCofo *gc,void* key, int (*cmp)(void*,void*)){
    void *data;
    int i=0,j=0,stat;
    if(gc != NULL && key !=NULL){
        if(gc->numItens > 0){
            stat = cmp(key,gc->item[i]);
            while(i<gc->numItens && stat != TRUE){
                i++;
                stat = cmp(key,gc->item[i]);
            }
            if(stat == TRUE){
                data = gc->item[i];
                for(j = i; j < gc->numItens;j++){
                    gc->item[j] = gc->item[j+1];
                }
                gc->numItens--;
                return data;
            }
        }
    }
    return NULL;
}
