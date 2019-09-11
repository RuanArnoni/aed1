#include <stdio.h>
#include <stdlib.h>

int *valores_entre(int *v, int n, int min, int max, int *qtd){
    for(int i=0; i<n; i++){
        if(v[i]>=min && v[i]<=max){
            (*qtd)++;
        }
    }
    if(*qtd>0){
        int *pAux;
        int *inicio;
        int aux;
        pAux = malloc(sizeof(int)*(*qtd));
        if(pAux==NULL){
            printf("Malloc deu errado.");
        }
        inicio = pAux;
        for(int i=0; i<n; i++){
        if(v[i]>=min && v[i]<=max){
            *pAux = v[i];
            pAux++;
        }
    }
        return inicio;
    }else{
        return NULL;
    }
}

int main(){
    int tam =0;
    int max = 0;
    int min = 0;
    printf("Digite o numero de elementos do vetor: ");
    scanf("%d", &tam);
    int vetor[tam];
    int *pVetor;
    int quantidade = 0;
    printf("Digite os elementos do vetor :");
    for(int i=0; i<tam; i++){
        scanf("%d", &vetor[i]);
    }
    for(int i=0; i<tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\nDigite o valor maximo e o valor minimo(nesta ordem): ");
    scanf("%d %d", &max, &min);
    pVetor = valores_entre(vetor, tam, min, max, &quantidade);
    if(pVetor==NULL){
        printf("Nao ha valores entre o minimo e o maximo.");
    }else{
        for(int i=0; i<quantidade; i++){
            printf("%d ", pVetor[i]);
        }
    }
    free(pVetor);
}