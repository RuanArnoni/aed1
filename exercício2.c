#include <stdio.h>
#include <stdlib.h>

int *cria_vetor(int tam){
    int *pAux;
    pAux=malloc(sizeof(int)*tam);
    return pAux;
}

void imprime_elementos(int *pAux, int tam){
    printf("Os elementos do vetor sao: ");
    for(int i=0; i<tam; i++){
        printf("%d ", *pAux);
        pAux++;
    }
}

void libera_memoria(int *pAux){
    free(pAux);
}

void main(){
    int tamanho;
    int *pVetor;
    int *inicio;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    pVetor = cria_vetor(tamanho);
    inicio = pVetor;
    printf("Digite os elementos do vetor: ");
    for(int i=0; i<tamanho; i++){
        scanf("%d", pVetor);
        pVetor++;
    }
    pVetor = inicio;
    imprime_elementos(pVetor, tamanho);
    libera_memoria(pVetor);
}