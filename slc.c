#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam, tmp, min, min_id;
    scanf("%d", &tam);
    int vet[tam];
    for(int i=0; i<tam; i++){
        scanf("%d", &vet[i]);
    }
    for(int i=0; i<tam-1; i++){
        min = vet[i];
        for(int j=i+1; j<tam; j++){
            if(vet[j]<min){
                min = vet[j];
                min_id = j;
                tmp = vet[i];
                vet[i] = vet[min_id];
                vet[min_id] = tmp; 
            }
        }    
    }
    for(int i=0; i<tam; i++){
        printf("%d", vet[i]);
    }
}