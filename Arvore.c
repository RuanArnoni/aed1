#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *pDireita, *pEsquerda;
}NODO;

NODO * insere(NODO *raiz, int aux){
    if(raiz == NULL){
        NODO *pAux = malloc(sizeof(NODO));
        pAux->pDireita = NULL;
        pAux->pEsquerda = NULL;
        pAux->num = aux;
        return pAux;
    }else{
        if(aux < raiz->num){
            raiz->pEsquerda = insere(raiz->pEsquerda, aux);
        }else{
            if(aux > raiz->num){
            raiz->pDireita = insere(raiz->pDireita, aux);
        }else{
                printf("\nNumero ja presente na lista.\n");
                return raiz;
        }
        }
    }
}

void imprime(NODO *raiz){
    if(raiz->pEsquerda!=NULL){
        imprime(raiz->pEsquerda);
    }
    printf("%d ", raiz->num);
    if(raiz->pDireita!=NULL){
        imprime(raiz->pDireita);
    }
    
}

NODO *busca(NODO *raiz, int aux){
    if(raiz!=NULL){
        NODO *pAux;
        pAux = raiz;
        while(pAux!=NULL && pAux->num!=aux){
            if(aux < pAux->num){
                pAux = pAux->pEsquerda;
            }else{
                pAux = pAux->pDireita;
            }
        }
        return pAux;
    }
}

NODO *buscaMin(NODO *raiz){
    NODO *pAux = raiz;
    while(pAux->pDireita!=NULL){
        pAux = pAux->pDireita;
    }
    return pAux;
}

NODO *removenum(NODO *raiz, int aux){
        if(aux == raiz->num){
            if(raiz->pEsquerda == NULL && raiz->pDireita==NULL){
                free(raiz->pEsquerda);
                raiz = NULL;
            }else if(raiz->pEsquerda==NULL && raiz->pDireita!=NULL){
                NODO *pAux = raiz->pDireita;
                free(raiz);
                raiz = pAux;
            }else if(raiz->pEsquerda!=NULL && raiz->pDireita==NULL){
                NODO *pAux = raiz->pEsquerda;
                free(raiz);
                raiz = pAux;
            }else{
                NODO *aux1 = buscaMin(raiz->pEsquerda);
                int aux2 = aux1->num;
                raiz = removenum(aux1, aux1->num);
                raiz->num = aux2;
                return raiz;
            }
        }else{
            if(aux < raiz->num){
                raiz->pEsquerda = removenum(raiz->pEsquerda, aux);
            }else
            {
                raiz->pDireita = removenum(raiz->pDireita, aux);
            }
            
        }
}

int main(){
    int seletor, aux;
    NODO *raiz = NULL;
    printf("\nDigite o que deseja:\n1)Adicionar numero\n2)Remover numero\n3)Listar numeros\n4)Buscar numero\n5)Sair\n\n");
    scanf("%d", &seletor);
    while(seletor!=5){
    switch (seletor)
    {
    case 1:
        printf("Digite o numero que deseja adicionar: ");
        scanf("%d", &aux);
        raiz = insere(raiz, aux);
        break;
    case 2:
        printf("\nDigite o numero que deseja remover: ");
        scanf("%d", &aux);
        NODO *buscar = busca(raiz, aux);
        if(buscar == NULL){
        printf("Numero nao esta na lista.\n");
        }else{ 
        NODO * remover = removenum(raiz, aux);
        }
        break;
    case 3:
        if(raiz == NULL){
            printf("Nao ha numeros na lista.\n");
        }else{
        imprime(raiz);
        }
        break;
    case 4:
        printf("Digite o numero que deseja buscar: ");
        scanf("%d", &aux);
        NODO *buscar2 = busca(raiz, aux);
        if (buscar2 != NULL)
        {
            printf("\nNumero presente na lista, %d \n", buscar2->num);
        }else{
            printf("\nNumero ausente na lista.\n");
        }
        break;
    }
    printf("\nDigite o que deseja:\n1)Adicionar numero\n2)Remover numero\n3)Listar numeros\n4)Buscar numero\n5)Sair\n\n");
    scanf("%d", &seletor);
    }
}