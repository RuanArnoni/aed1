#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade
}PESSOA;

typedef struct{
    PESSOA info;
    struct NODO *pNext;
}NODO;

typedef struct{
    NODO *pFirst;
    NODO *pAux;
    int tamanho, pos;
}LISTA;

void preenche_dados(NODO *pNodo){
    printf("\nDigite o nome da pessoa: ");
    scanf("%s", pNodo->info.nome);
    printf("Digite a idade da pessoa: ");
    scanf("%d", &pNodo->info.idade);
}

void PUSH(LISTA *pLista, NODO *pNodo){
    if(pLista->tamanho==0){
        pLista->tamanho++;
        pLista->pFirst = pNodo;
        pNodo->pNext = NULL;
        preenche_dados(pLista->pFirst);
    }else{
        pLista->tamanho++;
        printf("Posicoes disponiveis: 1 a %d\n", pLista->tamanho);
        printf("\nDigite a posicao q deseja colocar a pessoa: ");  
        scanf("%d", &pLista->pos);
        if(pLista->pos==1){
            pNodo->pNext = pLista->pFirst;
            pLista->pFirst = pNodo;
            preenche_dados(pLista->pFirst);
        }else{
                pLista->pAux = pLista->pFirst;
                for(int i=1; i!=pLista->pos-1; i++){
                    pLista->pAux = pLista->pAux->pNext;
                } 
                pNodo->pNext = pLista->pAux->pNext;
                pLista->pAux->pNext = pNodo;
                preenche_dados(pNodo);
                }
            }
}

void PRINT(LISTA *pLista){
    pLista->pAux = pLista->pFirst;
    for(int i=0; i<pLista->tamanho; i++){
        printf("\nPessoa %d: %s, %d anos", i+1, pLista->pAux->info.nome, pLista->pAux->info.idade);
        pLista->pAux = pLista->pAux->pNext;
    }
}

int main(){
    int seletor;
    LISTA *pLista = (LISTA *)malloc(sizeof(LISTA));
    if(pLista==NULL){
        printf("Erro de alocacao.\n");
        return 0;
    }
    pLista->tamanho = 0;
    NODO *pNodo;
    printf("\n~~AGENDA LISTA~~\nDigite o que voce deseja:\n1)Adicionar pessoa\n2)Remover pessoa\n3)Limpar lista\n4)Listar\n5)Sair\n");
    scanf("%d", &seletor);
    while(seletor!=5){
        switch (seletor)
    {
    case 1:
        pNodo = (NODO *)malloc(sizeof(NODO));
        PUSH(pLista, pNodo);
        break;
    case 2:

        break;
    case 3:
        
        break;
    case 4:
        PRINT(pLista);
        break;
    }
        printf("\n~~AGENDA LISTA~~\nDigite o que voce deseja:\n1)Adicionar pessoa\n2)Remover pessoa\n3)Limpar lista\n4)Listar\n5)Sair\n");
        scanf("%d", &seletor);
    }
    free(pLista);
}