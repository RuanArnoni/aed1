#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct {
    int idade;
    char nome[50];
}PESSOA;

typedef struct {
    PESSOA pessoas[MAX];
    int topo;
}PILHA;

int pilha_cheia(PILHA *p){
    if(p->topo==MAX-1){
        return 1;
    }else{
        return 0;
    }
}
int pilha_vazia(PILHA *p){
    if(p->topo==-1){
        return 1;
    }else{
        return 0;
    }
}

void insere_pilha(PILHA *p){
    if(pilha_cheia(p) == 1){
        printf("\nERRO: pilha cheia.\n");
    }else{
        p->topo++;
        /*printf("Digite o nome da pessoa: ");
        fgets(p->pessoas[p->topo].nome, 50, stdin);*/
        printf("Digite a idade da pessoa: ");
        scanf("%d", &p->pessoas[p->topo].idade);
    }
}

void remove_pilha(PILHA *p){
    if(pilha_vazia(p)==1){
        printf("ERRO: pilha vazia.\n");
    }else{
        p->topo--;
    }
}

void limpa_pilha(PILHA *p){
    if(pilha_vazia(p)==1){
        printf("ERRO: pilha vazia.\n");
    }else{
        while(p->topo!=-1){
       /*p->pessoas[p->topo].nome = 0;*/
        p->pessoas[p->topo].idade = 0;
        p->topo--;
        }
    }
}

void lista_pilha(PILHA *p){
    int aux = p->topo;
    if(pilha_vazia(p)==1){
        printf("ERRO: pilha vazia.\n");
    }else{
        while(aux!=-1){
            printf("%d\n", p->pessoas[aux].idade);
            aux--;
        }
    }
}

void main(){
    int seletor = 0;
    PILHA *p = (PILHA *)malloc(sizeof(PILHA));
    p->topo = -1;
    printf("~~AGENDA COM PILHA~~\nDigite o que voce deseja:\n1)Adicionar pessoa\n2)Remover pessoa\n3)Limpar a pilha\n4)Listar\n5)Sair\n");
    scanf("%d", &seletor);
    while(seletor!=5){
    switch (seletor)
    {
    case 1:
        insere_pilha(p);
        break;
    case 2:
        remove_pilha(p);
        break;
    case 3:
        limpa_pilha(p);
        break;
    case 4:
        lista_pilha(p);
        break;
    }
    printf("~~AGENDA COM PILHA~~\nDigite o que voce deseja:\n1)Adicionar pessoa\n2)Remover pessoa\n3)Limpar a pilha\n4)Listar\n5)Sair\n");
    scanf("%d", &seletor);
    }
}