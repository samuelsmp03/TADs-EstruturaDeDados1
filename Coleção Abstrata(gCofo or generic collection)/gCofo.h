/*
        gCofo.h
        Arquivo com a especificação para o TAD gCofo.c
        Tipo de dado gCofo
        */
//

#ifndef GCOFO_GCOFO_H
#define GCOFO_GCOFO_H


#include <stdio.h> //Padrão
#include <stdlib.h> //Malloc,free(),etc.
#include <string.h>//Trabalhar com strings

#define TRUE 1
#define FALSE 0
#define TAM_NOME 30 //Tamanho do campo char[]

#define MEM_ERR (void*) -1
#define MEM_COF_ERR (gCofo*) -2

/*
*Como no caso de retornamos NULL o programa irá ser fechado por segmentation fault criamos duas constantes fixas
*Que servirãm como o nosso NULL iremos verificar nas funções se ocorreu erro em alguma etapa. tal como adicionar
*algum elemento num cofo sem espaço ou tentar retirar um elemento não presente em um cofo,etc. Tal como também na
*MEM_COF_ERR utilizaremos cara caso do cofo ser vazio para servir como paramêtro em alguns if's do código.
*/

typedef struct __gcofo__ gCofo;


//Definindo as funções que serão implementadas em gCofo.c

gCofo* gCofCreate(int max_itens);
int gCofDestroy(gCofo *gc);
int gCofInsert(gCofo *gc, void* item);
void *gCofRemove(gCofo *gc, void* key,int(*cmp)(void*,void*));
void *gCofQuery(gCofo *gc,void* key,int (*cmp)(void*,void*));
void *gCofGetFirst(gCofo *gc);
void *gCofGetNext(gCofo *gc);


#endif //GCOFO_GCOFO_H
