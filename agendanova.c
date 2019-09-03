#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
    char nome[50];
    int idade;
    long int matricula;
}PESSOA;

//struct de variaveis que utilizarei
typedef struct variaveis{
    int seletor;
    int CP;
    int i;
}VARIAVEIS;

//declaração de ponteiros
VARIAVEIS *pAux;
PESSOA *apontapessoa;
void *pBuffer;

//declaração de funções
void adiciona_pessoa();
void lista_pessoas();
void remove_pessoa();

int main(){
    pBuffer = malloc(sizeof(VARIAVEIS));
    if(pBuffer==NULL){
        printf("Malloc deu errado.");
    }
    pAux = pBuffer;
    pAux->CP=0;
    pAux->seletor=0;
    pAux->i=0;
    while(1){
    printf("~~AGENDA~~\n\nDigite o que voce deseja:\n1)Adicionar pessoa\n2)Remover pessoa\n3)Listar\n4)Sair\n\n");
        scanf("%d", &pAux->seletor);
        getchar();
    switch (pAux->seletor)
    {
    case (1):
        (pAux->CP)++;
        adiciona_pessoa();
        break;
    case (2):
        remove_pessoa();
        break;
    case (3):
        if(pAux->CP==0){
            printf("Nao ha pessoas para listar.\n");
        }else{
            lista_pessoas();
        }
        break;
    case (4):
        return 0;
        break;
    }
    if(pAux->seletor<1 || pAux->seletor>4){
        printf("Valor digitado nao permitido.\n");
    }
    }
}

void adiciona_pessoa(){
    //realocando buffer para adicionar uma nova pessoa
    pBuffer = realloc(pBuffer, sizeof(VARIAVEIS)+sizeof(PESSOA)*(pAux->CP));
        if(pBuffer == NULL){
            printf("Nao foi possivel alocar o buffer.");
        }
    pAux = pBuffer;
    apontapessoa = pBuffer + sizeof(VARIAVEIS) + sizeof(PESSOA)*(pAux->CP) - sizeof(PESSOA);
    //preenchimento de dados da pessoa
    printf("Digite o nome da pessoa: ");
    fgets(apontapessoa->nome,50,stdin);
    for((pAux->i)=0; (pAux->i)<(strlen(apontapessoa->nome)); (pAux->i)++){
        if(apontapessoa->nome[pAux->i]=='\n'){
            apontapessoa->nome[(pAux->i)]='\0';
        }
    }
    printf("Digite a idade da pessoa: ");
    scanf("%d", &apontapessoa->idade);
    printf("Digite a matricula da pessoa: ");
    scanf("%li", &apontapessoa->matricula);
    printf("\nPessoa adicionada com sucesso!\n");
}

void lista_pessoas(){
    apontapessoa = pBuffer + sizeof(VARIAVEIS);
    for(pAux->i=1; (pAux->i)<(pAux->CP); (pAux->i)++){
        printf("Pessoa %d: %s, %d anos, matricula %li\n", pAux->i, apontapessoa->nome, apontapessoa->idade, apontapessoa->matricula);
        apontapessoa++;
    }
    printf("Pessoa %d: %s, %d anos, matricula %li\n\n", pAux->i, apontapessoa->nome, apontapessoa->idade, apontapessoa->matricula);
}

void remove_pessoa(){
    
}



