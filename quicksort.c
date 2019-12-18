#include <stdio.h>
#include <stdlib.h>

void quicksort(int data[], int left, int right){
    int mid, tmp, i ,j;
    i = left;
    j = right;
    mid = data[(left+right)/2];
    do{
        while(data[i]<mid){
            i++;
        }
        while(data[j]>mid){
            j--;
        }
        if(i<=j){
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j++;
        }
    }while(i<=j);
    if(left<j){
        quicksort(data, left, j);
    }
    if(i<right){
        quicksort(data, i, right);
    }

}

int main(){
    int tam;
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tam);
    int vet[tam];
    printf("Digite os valores do vetor: ");
    for(int i=0; i<tam; i++){
        scanf("%d", vet[i]);
    }
    int left = 0;
    int right = tam;
    quicksort(vet, left, right);
}