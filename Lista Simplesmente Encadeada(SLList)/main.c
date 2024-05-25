#include "SLList.h"
#define TAM_NOME 30

typedef struct _anime_{
    char nome[TAM_NOME];
    int ep;
    float nota;
}Anime;

int cmpS(void* elm1, void* elm2){
    //Função utilizada para comparar strings
    if(elm1 != NULL && elm2 != NULL){
        char *pElm1 = (char*)elm1;
        Anime *pElm2 = (Anime*)elm2;
        if (!strcmp(pElm1, pElm2->nome)) {
            return TRUE;
        }
    }
    return FALSE;
}

int cmpI(void* elm1, void* elm2){
    //Função utilizada para comparar inteiros
    if(elm1 != NULL && elm2 != NULL) {
        int *pElm1 = (int *) elm1;
        Anime *pElm2 = (Anime *) elm2;
        if (*pElm1 == pElm2->ep) {
            return TRUE;
        }
    }
    return FALSE;
}

int cmpF(void* elm1, void* elm2){
    //Função utilizada para comparar floats
    if(elm1 != NULL && elm2 != NULL){
        float *pElm1 = (float*)elm1;
        Anime *pElm2 = (Anime*)elm2;
        if (*pElm1 == pElm2->nota) {
            return TRUE;
        }
    }
    return FALSE;
}

int verificaVoid(void *teste){
    if(teste != MEM_ERR){
        printf("\nOperacao realizada com sucesso!");
        return TRUE;
    }
    printf("\nOperacao mal sucedida!!!");
    return FALSE;

}
int verificaInt(int res){
    if(res == TRUE){
        printf("\nOperacao realizada com sucesso!");
        return TRUE;
    }
    else {
        printf("\nOperacao mal sucedida!!!");
        return FALSE;
    }
}


int main(void) {
    int work = TRUE,opc1=0,opc2=0;
    int tam;
    Anime *pAnime,*aux;
    void *anime = MEM_ERR;
    void *removido;
    char auxS[TAM_NOME];
    int auxI;
    float auxF;
    SLList *l = SLL_MEM_ERR;
    while(work == TRUE){
        printf("\n\nDigite uma opção:");
        printf("\n1:Criar Lista\n2:Adicionar Anime\n3:Remover Anime\n4:Procura Anime\n5:Imprime animes");
        printf("\n6:Destruir Lista\n7:Esvaziar Lista\n8:Fechar o programa");
        printf("\n\tdigite:");
        scanf("%d",&opc1);
        switch (opc1) {

            case 1: //CRIAR LISTA
                if(l != SLL_MEM_ERR) {
                    printf("\nVoce ja possui uma lista!!!");
                }else{
                    l = sllCreate();
                    if(l == SLL_MEM_ERR){
                        printf("\nErro ao criar a lista!!!");

                    }else{
                        printf("\nLista criada com sucesso!");
                    }
                }
                break;

            case 2: //ADICIONAR ANIME
                if(l != SLL_MEM_ERR){
                    aux = (Anime*)malloc(sizeof(Anime));
                    if(aux == NULL){
                        printf("Erro ao alocar memoria para anime!!");
                        break;
                    }
                    printf("\nQual o nome do anime?");
                    getchar();
                    fgets(aux->nome, TAM_NOME, stdin);
                    if (strlen(aux->nome) > 0 && aux->nome[strlen(aux->nome) - 1] == '\n') {
                        aux->nome[strlen(aux->nome) - 1] = '\0';
                    }
                    printf("\nQuantos episódios tem esse anime?");
                    scanf("%d",&aux->ep);
                    printf("\nQual a nota que voce daria para esse anime?");
                    scanf("%f",&aux->nota);
                    verificaInt(sllInsertLast(l, (void*)aux));
                }else{
                    printf("\nCrie uma lista antes de adicionar animes!!!");
                }
                break;

            case 3: //REMOVER ANIME(INT,FLOAT,STRING)
                //SLLREMOVEKEY OK
                if(l != SLL_MEM_ERR){
                    printf("Digite por qual item voce deseja remover o anime:\n");
                    printf("1:Nome(String)\n2:Episodios(Int)\n3:Nota(Float)");
                    printf("\n\t\tdigite:");
                    scanf("%d",&opc2);
                    switch (opc2) {
                        case 1:
                            printf("\nQual o nome do anime?");
                            getchar();
                            fgets(auxS, TAM_NOME, stdin);
                            if (strlen(auxS) > 0 && auxS[strlen(auxS) - 1] == '\n') {
                                auxS[strlen(auxS) - 1] = '\0';
                            }
                            removido = sllRemoveSpec(l,&auxS,&cmpS);
                            if(verificaVoid(removido) == TRUE){
                                pAnime = (Anime*)removido;
                                printf("\nO anime %s foi removido com sucesso!",pAnime->nome);
                            }else{
                                printf("\nO anime nao foi encontrado!!!");
                            }
                            break;

                        case 2:
                            printf("\nDigite quantos episodios tem esse anime:");
                            scanf("%d",&auxI);
                            removido = sllRemoveSpec(l,&auxI,&cmpI);
                            if(verificaVoid(removido) == TRUE){
                                pAnime = (Anime*)removido;
                                printf("\nO anime %s foi removido com sucesso!",pAnime->nome);
                            }else{
                                printf("\nO anime nao foi encontrado!!!");
                            }
                            break;

                        case 3:
                            printf("\nDigite a nota desse anime:");
                            scanf("%f",&auxF);
                            removido = sllRemoveSpec(l, &auxF, &cmpF);
                            if(verificaVoid(removido) == TRUE){
                                pAnime = (Anime*)removido;
                                printf("\nO anime %s foi removido com sucesso!",pAnime->nome);
                            }else{
                                printf("\nO anime nao foi encontrado!!!");
                            }
                            break;

                        default:
                            printf("\nOpcao invalida!!!");
                            break;
                    }
                }else{
                    printf("\nCrie uma lista antes!!!");
                }
                break;

            case 4://PROCURA ANIME
                if(l != SLL_MEM_ERR){
                    printf("Digite por qual item voce deseja procurar o anime:\n");
                    printf("1:Nome(String)\n2:Episodios(Int)\n3:Nota(Float)");
                    printf("\n\t\tdigite:");
                    scanf("%d",&opc2);
                    switch (opc2) {
                        case 1:
                            printf("\nQual o nome do anime?");
                            getchar();
                            fgets(auxS, TAM_NOME, stdin);
                            if (strlen(auxS) > 0 && auxS[strlen(auxS) - 1] == '\n') {
                                auxS[strlen(auxS) - 1] = '\0';
                            }
                            removido = sllQuery(l,&auxS,&cmpS);
                            if(verificaVoid(removido) == TRUE){
                                pAnime = (Anime*)removido;
                                printf("\nO anime %s foi encontrado com sucesso!",pAnime->nome);
                            }else{
                                printf("\nO anime nao foi encontrado!!!");
                            }
                            break;

                        case 2:
                            printf("\nDigite quantos episodios tem esse anime:");
                            scanf("%d",&auxI);
                            removido = sllQuery(l,&auxI,&cmpI);
                            if(verificaVoid(removido) == TRUE){
                                pAnime = (Anime*)removido;
                                printf("\nO anime %s foi encontrado com sucesso!",pAnime->nome);
                            }else{
                                printf("\nO anime nao foi encontrado!!!");
                            }
                            break;

                        case 3:
                            printf("\nDigite a nota desse anime:");
                            scanf("%f",&auxF);
                            removido = sllQuery(l,&auxF,&cmpF);
                            if(verificaVoid(removido) == TRUE){
                                pAnime = (Anime*)removido;
                                printf("\nO anime %s foi encontrado com sucesso!",pAnime->nome);
                            }else{
                                printf("\nO anime nao foi encontrado!!!");
                            }
                            break;

                        default:
                            printf("\nOpcao invalida!!!");
                            break;
                    }
                }else{
                    printf("\nCrie uma lista antes!!!");
                }
                break;

            case 5://IMPRIMIR ELEMENTOS
                if(l != SLL_MEM_ERR){
                    anime = sllGetFirst(l);
                    printf("\nNOME\t\tEPISODIOS\t\tNOTA");
                    while(anime != MEM_ERR){
                        printf("\n%s\t\t\t\t%d\t\t\t\t%.1f", ((Anime*)anime)->nome, ((Anime *)anime)->ep, ((Anime*)anime)->nota);
                        anime = sllGetNext(l);
                    }
                    printf("\nNumero de elementos na lista: %d", sllNumNodes(l));
                }else{
                    printf("\nCrie uma lista antes!!!");
                }
                break;

            case 6://DESTRUIR LISTA
                if(l != SLL_MEM_ERR){
                    if(sllDestroy(l) == TRUE) {
                        l = SLL_MEM_ERR;
                        printf("\nLista destruida com sucesso!");
                    }else{
                        printf("\nErro ao destruir a lista!!!");
                    }
                }
                break;

            case 7://ESVAZIAR LISTA
                //SLLREMOVEFIRST ATÉ ACABAR OK
                if(l != SLL_MEM_ERR) {
                    removido = sllRemoveFirst(l);
                    while (removido != MEM_ERR) {
                        pAnime = (Anime*)removido;
                        printf("\nO anime %s foi removido com sucesso!", pAnime->nome);
                        removido = sllRemoveFirst(l);
                    }
                    printf("\nLista limpa com sucesso!");
                }else{
                    printf("\nCrie uma lista antes!!!");
                }
                break;

            case 8:
                printf("\nAte mais!!!");
                work = FALSE;
                break;

            default:
                printf("\nOpcao invalida!!!");
                break;
        }
    }
    return 0;
}
