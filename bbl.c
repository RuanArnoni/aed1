#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam, tmp;
    scanf("%d", &tam);
    int vet[tam];
    for(int i=0; i<tam; i++){
        scanf("%d", &vet[i]);
    }
    for(int i=0; i<tam-1; i++){
        for(int j=0; j<tam-i-1; j++){
            if(vet[j]>vet[j+1]){
                tmp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = tmp;
            }
        }
    }
    for(int i=0; i<tam; i++){
        printf("%d", vet[i]);
    }
}
