#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int *pAux, int tam){
    printf("Digite os elementos do vetor: ");
    for(int i=0; i<tam; i++){
        scanf("%d", pAux);
        pAux++;
    }
}

int main(){
    int tamanho;
    int *pVetor;
    printf("Digite um valor para o tamanho do vetor: ");
    scanf("%d", &tamanho);
    pVetor = malloc(sizeof(int)*tamanho);
    preenche_vetor(pVetor, tamanho);
    printf("Os elementos do vetor são: ");
    for(int i=0; i<tamanho; i++){
        printf("%d ", *pVetor);
        pVetor++;
    }
    free(pVetor);
}