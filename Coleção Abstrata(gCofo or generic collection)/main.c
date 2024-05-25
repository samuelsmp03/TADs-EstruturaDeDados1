#include "gCofo.h"
#include "gCofo.c"

void verification(int bool){
    if(bool == TRUE){
        printf("Operacao realizada com sucesso!\n");
    }else{
        printf("Operacao mal sucedida!\n");
    }
}

int main(){
    gCofo *gc;
    int max_itens=0;
    printf("DIgite o tamanho do cofo desejado: ");
    scanf("%d",&max_itens);
    gc = gCofCreate(max_itens);
    return 0;
}
