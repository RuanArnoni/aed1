#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta, int n){
    int aux, cont = 0;
    int *inicio;
    inicio = aposta;
    printf("Digite os numeros a serem apostados(apenas valores entre 0 e 100 serao considerados): ");
    while(n!=cont){
        scanf("%d", &aux);
        if(aux>0 && aux<100){
            *aposta = aux;
            aposta++;
            cont++;
        }
    }
    aposta = inicio;  
}

void sorteia_valores(int *sorteio, int n){
    for(int i=0; i<n; i++){
        srand(time(NULL));
        sorteio[i] = rand() % 100;
      }
}

int *compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
    int *resultante;
    int *inicio;
    for(int i=0; i<na; i++){
        for(int j=0; j<ns; j++){
            if(aposta[i]==sorteio[j]){
                *qtdacertos++;
            }
        }
    }
    resultante = malloc(sizeof(int)*(*qtdacertos));
    if(resultante==NULL){
        printf("Malloc do resultante deu errado.");
    }else{
        inicio = resultante;
        for(int i=0; i<na; i++){
            for(int j=0; j<ns; j++){
             if(aposta[i]==sorteio[j]){
                *resultante = aposta[i];
                resultante++;
            }
        }
    }
        resultante = inicio;
        return resultante;
    }
}

void main(){
    int numAposta;
    int *pAposta;
    int *pSorteio;
    int numSorteio = 20;
    int qntacertos = 0;
    int *resultado;
    
    printf("Digite o numero de valores que deseja apostar: ");
    scanf("%d", &numAposta);
    pAposta = malloc(sizeof(int)*numAposta);
    if(pAposta==NULL){
        printf("Malloc deu errado.");
    }
    ler_aposta(pAposta, numAposta);
    pSorteio = malloc(sizeof(int)*numSorteio);
    sorteia_valores(pSorteio, numSorteio);
    resultado = compara_aposta(pAposta, pSorteio, &qntacertos, numAposta, numSorteio);
    printf("Voce acertou um total de %d numeros: ", qntacertos);
    for(int i=0; i<qntacertos; i++){
        printf("%d ", resultado[i]);
    }
    
    free(pAposta); 
    free(pSorteio);
    free(resultado);
}