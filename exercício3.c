#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz(int linhas, int colunas){
    int **Maux;
    Maux=malloc(sizeof(int*)*linhas);
    for(int i=0; i<linhas; i++){
        Maux[i]=malloc(sizeof(int)*colunas);
    }
    return Maux;
}

void libera_memoria(int **Maux, int linhas){
    for(int i=0; i<linhas; i++){
        free(Maux[i]);
    }
    free(Maux);
}

int main(){
    int **M;
    int i, j, linhas, colunas;
    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);
    M = aloca_matriz(linhas, colunas);
    printf("Digite os elementos da matriz: ");
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            scanf("%d", &M[i][j]);
        }
    }
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    libera_memoria(M, linhas);
}