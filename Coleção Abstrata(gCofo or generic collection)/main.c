//Incluindo gCofo.h
#include "gCofo.h"

typedef struct _ANIME_{
    //Struct criada para ser armazenada no gCofo.Obedecendo os requisitos campos: char[30],int,float.
    char nome[TAM_NOME];
    int episodios;
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
            if (*pElm1 == pElm2->episodios) {
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



void menu(){
    //Interface do menu principal
    printf("\n-=-=-=-=----=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Selecione uma opção!!!\n");
    printf("1:Cria cofo\n2:Insere um anime\n3:Remove um anime\n4:Consulta um anime\n");
    printf("5:Lista os animes\n6:Destroi o cofo\n7:Esvazia o cofo\n8:Fecha o programa\n");
    printf("\nDigite:");
}

void menuBusca(){
    //Interface do menu de procurar Anime
    printf("\n-=-=-=-=----=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Por qual campo você gostaria de procurar o elemento?\n");
    printf("1:Nome do anime(String)\n2:Quantidade de episodios(Inteiro)\n");
    printf("3:Nota do anime(Float)\nDigite:");
}

void lerInt(int *opt){
    //Função auxiliar que verifica se o dado fornecido pelo usuario para a opc do switch é um numero inteiro.
    while (scanf("%d", opt) != 1) {
        getchar();
        getchar();
        printf("Entrada invalida. Por favor, insira um número inteiro.\n");
    }
}

void lerIntAnim(Anime *anime){ //Função auxiliar que verifica se o dado informado é um inteiro
    while (scanf("%d", &anime->episodios) != 1) {
        getchar();
        getchar();
        printf("Entrada invalida. Por favor, insira um número inteiro.\n");
    }
}
void lerFloatAnim(Anime *anime){ //Função auxiliar que verifica se o dado informado é um float
    while (scanf("%f", &anime->nota) != 1) {
        getchar();
        getchar();
        printf("Entrada invalida. Por favor, insira um número float.\n");
    }
}


int main() {
    int working = TRUE; //Condição do Loop do programa
    int opt, opt2, opt3, size = 0; //opts seram usadas em alguns switchs do codigo e size é uma auxiliar
    int auxI = 0;
    char auxS[TAM_NOME];
    float auxF = 0;
    void *removido;
    gCofo *gc = MEM_COF_ERR; /*Inicializando o gCofo com uma constante para que o código não dê segmentation
                            fault ao ser comparado como null.*/

    printf("\n\n \t\t\t*** Bem-vindo ao cofo de animes! ***\n");
    while (working == TRUE) { //Rodando o programa principal
        menu();
        lerInt(&opt); //Usando a função auxiliar para pegar a opção desejada no menu pelo usuario
        switch (opt) {
            case 1: //Criar Cofo
                if(gc == MEM_COF_ERR) { //Verifica se já existe um cofo
                    printf("Quantos animes você quer armazenar?");
                    lerInt(&size);
                    gc = gCofCreate(size);
                    if (gc != MEM_COF_ERR) {//Como substituimos NULL por esta constante para que não dê segmentation
                                            //fault, comparamos com ela para verificar se o cofo foi criado.
                        printf("\nCofo criado com sucesso!");
                    } else {
                        printf("\nErro ao criar o cofo");
                    }
                }else{

                }
                break;

            case 2: //Inserir animes ao Cofo

                if(gc!=MEM_COF_ERR) { //Verificando se o cofo já existe!

                    Anime *anime = (Anime *) malloc(sizeof(Anime));
                    if (anime == NULL) {
                        printf("Erro ao alocar memoria para anime!!");
                        break;
                    }
                    printf("\nQual o nome do anime?");
                    getchar();
                    fgets(anime->nome, TAM_NOME, stdin);

                    //Na linha abaixo substituo o ultimo caracter de uma str não vazia se for '\n' por '\0' para
                    //na hora de imprimir o '\n' deixar o código confuso
                    if (strlen(anime->nome) > 0 && anime->nome[strlen(anime->nome) - 1] == '\n') {
                        anime->nome[strlen(anime->nome) - 1] = '\0';
                    }
                    //Utilizando funções auxiliares para ler e verificar dados que o usuario forncer.
                    printf("\nQuantos episódios tem esse anime?");
                    lerIntAnim(anime);
                    printf("\nQual a nota que você daria pra esse anime?");
                    lerFloatAnim(anime);
                    getchar();//Limpando buffer
                    if (gCofInsert(gc, (void *) anime) == TRUE) {
                        printf("\nAnime adicionado com sucesso!");
                    } else {
                        printf("\nO anime não foi adicionado!!!");
                    }
                }else{ //Caso de não existir cofo!
                    printf("\nCrie um cofo antes!!!");
                }
                break;


            case 3:// Remover um anime do Cofo

                if (gc != MEM_COF_ERR) { //Verifica se já existe um cofo
                    menuBusca();
                    lerInt(&opt2);
                    switch (opt2) {

                        case 1: //Remove usando String
                            printf("\nQual o nome do anime? ");
                            getchar();
                            fgets(auxS, TAM_NOME, stdin);
                            if (strlen(auxS) > 0 && auxS[strlen(auxS) - 1] == '\n') {
                                auxS[strlen(auxS) - 1] = '\0';
                            }
                            removido = gCofRemove(gc, &auxS, &cmpS);

                            if (removido != MEM_ERR) { //Verifando se foi realizada a remoção com sucesso
                                Anime *pRemovido = (Anime *) removido;
                                printf("\nAnime %s encontrado e removido com sucesso!", pRemovido->nome);
                            } else {
                                printf("\nAnime nao encontrado!");
                            }
                            break;

                        case 2: //Remove usando int
                            printf("\nQuantos episodios tem? ");
                            scanf("%d", &auxI);
                            removido = gCofRemove(gc, &auxI, &cmpI);
                            if (removido != MEM_ERR) { //Verifando se foi realizada a remoção com sucesso
                                Anime *pRemovido = (Anime *) removido;
                                printf("\nAnime %s encontrado e removido com sucesso!", pRemovido->nome);
                            } else {
                                printf("\nAnime nao encontrado!");
                            }
                            break;

                        case 3: //Remove usando float
                            printf("\nQual a nota dada para esse anime? ");
                            scanf("%f", &auxF);
                            removido = gCofRemove(gc, &auxF, &cmpF);
                            if (removido != MEM_ERR) {
                                Anime *pRemovido = (Anime *) removido;
                                printf("\nAnime %s encontrado e removido com sucesso!", pRemovido->nome);
                            } else {
                                printf("\nAnime nao encontrado!");
                            }
                            break;
                        default:
                            printf("\nOpcao invalida!!!");
                            break;
                    }
                } else { //Não existe cofo
                    printf("\nCrie um cofo antes!!!");
                }
                break;

            case 4: //Query
                if (gc != MEM_COF_ERR) {
                    menuBusca();
                    lerInt(&opt3);
                    switch (opt3) {
                        case 1: //Remove usando String
                            printf("\nQual o nome do anime? ");
                            getchar();
                            fgets(auxS, TAM_NOME, stdin);
                            if (strlen(auxS) > 0 && auxS[strlen(auxS) - 1] == '\n') {
                                auxS[strlen(auxS) - 1] = '\0';
                            }
                            removido = gCofQuery(gc, &auxS, &cmpS);

                            if (removido != MEM_ERR) {
                                Anime *pRemovido = (Anime *) removido;
                                printf("\nAnime %s encontrado!", pRemovido->nome);
                            } else {
                                printf("\nAnime nao encontrado!");
                            }
                            break;

                        case 2: //Remove usando int
                            printf("\nQuantos episódios tem? ");
                            scanf("%d", &auxI);
                            removido = gCofQuery(gc, &auxI, &cmpI);
                            if (removido != MEM_ERR) {
                                Anime *pRemovido = (Anime *) removido;
                                printf("\nAnime %s encontrado!", pRemovido->nome);
                            } else {
                                printf("\nAnime nao encontrado!");
                            }
                            break;

                        case 3: //Remove usando float
                            printf("\nQual a nota dada para esse anime? ");
                            scanf("%f", &auxF);
                            removido = gCofQuery(gc, &auxF, &cmpF);
                            if (removido != MEM_ERR) {
                                Anime *pRemovido = (Anime *) removido;
                                printf("\nAnime %s encontrado!", pRemovido->nome);
                            } else {
                                printf("\nAnime nao encontrado!");
                            }
                            break;

                        default:
                            printf("\nOpcao invalida!!!");
                            break;

                    }
                } else {
                    printf("\nCrie um cofo antes!!!");
                }
                break;

            case 5: // Imprimindo elementos
                if (gc != MEM_COF_ERR) { //Verifica se já existe um cofo

                    Anime *pAnime = (Anime *) gCofGetFirst(gc);
                    printf("\nLISTA DE ANIMES NO COFO:\n");
                    printf("\nNOME\t\tEPISODIOS\t\tNOTA");
                    //Utilizando as funções gCofGetFirst e gCofGetNext para imprimir todos os elementos do cofo

                    int cont = 0;
                    while (pAnime != MEM_ERR && pAnime != NULL) {
                        printf("\n%s\t\t%d\t\t\t%.1f", pAnime->nome, pAnime->episodios, pAnime->nota);
                        pAnime = (Anime *) gCofGetNext(gc);
                        cont++;
                    }
                    printf("\n\nElementos no cofo:%d", cont);
                } else {
                    printf("\nCrie um cofo antes!!");
                }
                break;

            case 6: //Destruir o cofo
                if (gCofDestroy(gc) == TRUE) { // Verifica se a operação deu certo
                    printf("Cofo destruído com sucesso!");
                    gc = MEM_COF_ERR; //Determinando que gc agora está vazio e que não possui cofo.
                } else {
                    printf("Erro ao destruir o cofo!!!");
                }
                break;

            case 7: //Esvaziar o cofo
                if(gc != MEM_COF_ERR){ //Verifico se o cofo existe
                    void *aux= gCofGetFirst(gc);
                    Anime *pAux = (Anime *) aux;
                    while(aux != NULL && aux != MEM_ERR){
                        removido = gCofRemove(gc,&(pAux->episodios),&cmpI);
                        if (removido != MEM_ERR){
                            printf("\nAnime %s removido com sucesso do cofo!!",pAux->nome);
                        }else{
                            printf("\nErro ao remover o anime!!!");
                        }
                        aux = gCofGetFirst(gc);
                        pAux = (Anime*)aux;
                    }
                    printf("\nCofo esvaziado com sucesso!");
                }else{
                    printf("\nCrie um cofo antes!");
                }
                break;

            case 8: // Fechando o programa
                printf("\nAte mais!!");
                working = FALSE;
                break;

            default: //Opção incorreta
                printf("\nOpcao invalida!!!");
                break;
        }
    }
    return 0;
}
