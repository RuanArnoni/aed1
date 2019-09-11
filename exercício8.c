#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1, int n1, int *v2, int n2){
    int *pAux;
    pAux = malloc(sizeof(int)*(n1+n2));
    for(int i=0; i<n1+n2; i++){
        if(i<n1){
            pAux[i] = v1[i];
        }else{
            pAux[i] = *v2;
            v2++;
        }
    }
    return pAux;
}

int main(){
    int tam1, tam2 = 0;
    int *pVetorresultante;
    printf("Digite o tamanho do vetor 1 e do vetor 2(nesta ordem): ");
    scanf("%d %d", &tam1, &tam2);
    int vetor1[tam1], vetor2[tam2];
    printf("Digite os elementos do vetor 1: ");
    for(int i=0; i<tam1; i++){
        scanf("%d", &vetor1[i]);
    }
    printf("Digite os elementos do vetor 2: ");
    for(int i=0; i<tam2; i++){
        scanf("%d", &vetor2[i]);
    }
    pVetorresultante = uniao(vetor1, tam1, vetor2, tam2);
    for(int i=0; i<tam1+tam2; i++){
        printf("%d ", pVetorresultante[i]);
    }
    free(pVetorresultante);
}