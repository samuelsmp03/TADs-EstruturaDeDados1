#include "gCofo.h"

typedef struct __gcofo__{
    int numItens;
    int maxItens;   
    int cur;
    void** item;
}gCofo;


gCofo *gCofCreate(int max_itens){ //Criando um cofo
    gCofo *gc;
    if(max_itens > 0){
        gc = (gCofo*)malloc(sizeof(gCofo)*max_itens);
        if(gc != NULL){
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
    return MEM_COF_ERR;//Ocorreu algum erro
}

int gCofDestroy(gCofo *gc){ //Destruindo um cofo

    if(gc != MEM_COF_ERR){//Verificando se esse cofo "existe"
        if(gc->numItens == 0){
            free(gc->item);
            free(gc);
            return TRUE;
        }
    }
    return FALSE;
}

int gCofInsert(gCofo* gc, void* item){ //Inserindo elementos ao cofo
    if(gc != MEM_COF_ERR && gc != NULL){
        if(gc->numItens < gc->maxItens && gc->maxItens>0){
            gc->item[gc->numItens] = item;
            gc->numItens++;
            return TRUE;
        }
    }
    return FALSE;//Ocorreu algum erro
}

void *gCofGetFirst(gCofo *gc){ //Retornando o primeiro elemento do cofo
    if(gc != MEM_COF_ERR){
        if(gc->numItens > 0) {
            gc->cur = 0;
            return gc->item[gc->cur];
        }
    }
    return MEM_ERR;//Ocorreu algum erro
}

void *gCofGetNext(gCofo *gc){ //Retornando o elemento seguinte do cofo
    if(gc != MEM_COF_ERR){
        if(gc->cur < gc->numItens-1 && gc->cur > -1) {
            gc->cur++;
            return gc->item[gc->cur];
        }
    }
    return MEM_ERR; //Ocorreu algum erro
}

void *gCofQuery(gCofo *gc,void *key, int (*cmp)(void*,void*)){ //Procurando elemento no cofo
    void *data;
    int i=0,stat;
    if( gc!=MEM_COF_ERR && key !=NULL){
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
    return MEM_ERR;//Ocorreu algum erro
}

void *gCofRemove(gCofo *gc,void *key, int (*cmp)(void*,void*)){ //Removendo elemento no cofo
    void *data;
    int i=0,j=0,stat;
    if(gc != MEM_COF_ERR && key !=NULL){ //Verificando se o cofo e a key existem
        if(gc->numItens > 0){
            stat = cmp(key,gc->item[i]);
            if (stat == FALSE) {
                i++;
                while (i < gc->numItens && stat != TRUE) {
                    stat = cmp(key, gc->item[i]);
                    i++;
                }
            }
            if(stat == TRUE){
                data = gc->item[i];
                for(j = i; j < gc->numItens;j++){
                    gc->item[j] = gc->item[j+1];
                }
                gc->numItens--;
                gc->cur--;
                return data;
            }
        }
    }
    return MEM_ERR;//Ocorreu algum erro
}
