#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct pessoa{
    char nome[30];
    DATA data;
    long int CPF;
}PESSOA;

void preenche_dados(PESSOA *pAux){
    printf("Digite o nome da pessoa: ");
    fgets(pAux->nome, 30, stdin);
    printf("Digite a data de nascimento da pessoa:\n");
    printf("Dia: ");
    scanf("%d", &pAux->data.dia);
    printf("Mes(numero): ");
    scanf("%d", &pAux->data.mes);
    printf("Ano: ");
    scanf("%d", &pAux->data.ano);
    printf("Digite o CPF: ");
    scanf("%ld", &pAux->CPF);
}

void imprime_dados(PESSOA *pAux){
    printf("Nome: %s", pAux->nome);
    printf("Data: %d-%d-%d\n", pAux->data.dia, pAux->data.mes, pAux->data.ano);
    printf("CPF: %ld\n", pAux->CPF);
}

void main(){
    PESSOA *apontapessoa;
    apontapessoa = malloc(sizeof(PESSOA));
    if(apontapessoa==NULL){
        printf("Malloc deu errado.");
    }
    preenche_dados(apontapessoa);
    imprime_dados(apontapessoa);
}

