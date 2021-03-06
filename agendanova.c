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
    int seletor, CP, i, j, cont, selectalgo, tmp, tam, min, min_id;
    char nomeaux[50];
    long int matriculaaux;
}VARIAVEIS;

//declaração de ponteiros
VARIAVEIS *pAux;
PESSOA *apontapessoa;
PESSOA *apontapessoaaux;
PESSOA *apontapessoaaux1;
void *pBuffer;

//declaração de funções
void realoca_buffer();
void lista_pessoas();
void remove_pessoa();
void preenche_dados();
void insertion_sort();
void selection_sort();
void bubble_sort();

int main(){
    pBuffer = malloc(sizeof(VARIAVEIS));
    if(pBuffer==NULL){
        printf("Malloc deu errado.");
    }
    pAux = pBuffer;
    pAux->CP=0;
    pAux->seletor=0;
    pAux->i=0;
    pAux->cont=0;
    printf("~~AGENDA 2019/2~~");
    while(1){
    printf("\nDigite o que voce deseja:\n1)Adicionar pessoa\n2)Remover pessoa\n3)Listar\n4)Ordenar\n5)Sair\n\n");
        scanf("%d", &pAux->seletor);
        getchar();
    switch (pAux->seletor)
    {
    case (1):
        (pAux->CP)++;
        realoca_buffer();
        preenche_dados();
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
        printf("Digite o algoritmo de ordenacao q deseja usar:\n1)Insertion Sort\n2)Selection Sort\n3)Bubble sort\n");
        scanf("%d", &pAux->selectalgo);
        if((pAux->selectalgo)==1){
            insertion_sort();
        }
        if((pAux->selectalgo)==2){
            selection_sort();
        }
        if((pAux->selectalgo)==3){
            bubble_sort();
        }
        break;
    case (5):
        return 0;
        break;
    }
    if(pAux->seletor<1 || pAux->seletor>4){
        printf("Valor digitado nao permitido.\n");
    }
    }
    free(pBuffer);
}

void realoca_buffer(){
    //realocando buffer para adicionar uma nova pessoa
    pBuffer = realloc(pBuffer, sizeof(VARIAVEIS)+sizeof(PESSOA)*(pAux->CP));
        if(pBuffer == NULL){
            printf("Nao foi possivel alocar o buffer.");
        }
    pAux = pBuffer;
    apontapessoa = pBuffer + sizeof(VARIAVEIS) + sizeof(PESSOA)*(pAux->CP) - sizeof(PESSOA);
}
void preenche_dados(){
    printf("Digite o nome da pessoa: ");
    fgets(apontapessoa->nome,50,stdin);
    for((pAux->i)=0; (pAux->i)<(strlen(apontapessoa->nome)); (pAux->i)++){
        if(apontapessoa->nome[pAux->i]=='\n'){
            apontapessoa->nome[(pAux->i)]='\0';
        }
    }
    printf("Digite a idade da pessoa: ");
    scanf("%d", &apontapessoa->idade);
    while((apontapessoa->idade)<=0 || (apontapessoa->idade)>100){
        printf("Idade digitada nao permitida.\n");
        printf("Digite a idade da pessoa: ");
        scanf("%d", &apontapessoa->idade);
    }
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
    printf("\nPessoas para serem removidas:\n");
    lista_pessoas();
    printf("Digite a pessoa que deseja remover: ");
    scanf("%d", &pAux->cont);
    while((pAux->cont)<=0 || (pAux->cont)>(pAux->CP)){
        printf("Valor digitado para pessoa ser removida nao permitido.\n");
        printf("Digite a pessoa que deseja remover: ");
        scanf("%d", &pAux->cont);
        }
    if(pAux->cont==pAux->CP){
        pAux->CP--;
        realoca_buffer();
        printf("Pessoa removida com sucesso!\n");
    }else{
        apontapessoa = pBuffer + sizeof(VARIAVEIS) + sizeof(PESSOA)*pAux->cont - sizeof(PESSOA);
        apontapessoaaux = pBuffer + sizeof(VARIAVEIS) + sizeof(PESSOA)*pAux->cont;
        for(pAux->i=0; (pAux->i)<((pAux->CP)-(pAux->cont)-1);(pAux->i)++){
            strcpy(apontapessoa->nome, apontapessoaaux->nome);
            apontapessoa->idade = apontapessoaaux->idade;
            apontapessoa->matricula = apontapessoaaux->matricula;
            apontapessoa++;
            apontapessoaaux++;
        }
        strcpy(apontapessoa->nome, apontapessoaaux->nome);
        apontapessoa->idade = apontapessoaaux->idade;
        apontapessoa->matricula = apontapessoaaux->matricula;
        pAux->CP--;
        realoca_buffer();
        printf("Pessoa removida com sucesso!\n");
        }
}

void insertion_sort(){
    pAux->tam = pAux->CP;
    for(pAux->j = 1; (pAux->j)<(pAux->tam); (pAux->j)++){
        pAux->i = (pAux->j)-1;
        apontapessoa = pBuffer + sizeof(VARIAVEIS) + sizeof(PESSOA)*(pAux->j);//ponteiro do j
        apontapessoaaux = apontapessoa-1;//ponteiro do i
        apontapessoaaux1 = apontapessoaaux;
        strcpy(pAux->nomeaux, apontapessoa->nome);
        pAux->tmp = apontapessoa->idade;
        pAux->matriculaaux = apontapessoa->matricula;
            while(((pAux->i)>=0) && (pAux->tmp)<(apontapessoaaux->idade)){
                apontapessoaaux1 = apontapessoaaux+1;
                strcpy(apontapessoaaux1->nome, apontapessoaaux->nome);
                apontapessoaaux1->idade = apontapessoaaux->idade;
                apontapessoaaux1->matricula = apontapessoaaux->matricula;
                apontapessoaaux--;
                (pAux->i)--;
            }
            apontapessoaaux1 = apontapessoaaux+1;
            strcpy(apontapessoaaux1->nome, pAux->nomeaux);
            apontapessoaaux1->idade = pAux->tmp;
            apontapessoaaux1->matricula = pAux->matriculaaux;
    }
}

void selection_sort(){
    pAux->tam = pAux->CP;
    for((pAux->i)=0; (pAux->i)<(pAux->tam)-1; (pAux->i)++){
        apontapessoa = pBuffer + sizeof(VARIAVEIS)+sizeof(PESSOA)*(pAux->i);
        strcpy(pAux->nomeaux, apontapessoa->nome);
        pAux->tmp = apontapessoa->idade;
        pAux->matriculaaux = apontapessoa->matricula;
        pAux->min = apontapessoa->idade;
        for((pAux->j)=(pAux->i)+1; (pAux->j)<(pAux->tam); (pAux->j)++){
            apontapessoaaux = pBuffer + sizeof(VARIAVEIS)+sizeof(PESSOA)*(pAux->j);
            if((apontapessoaaux->idade)<(pAux->min)){
                pAux->min = apontapessoaaux->idade;
                strcpy(apontapessoa->nome, apontapessoaaux->nome);
                apontapessoa->idade = apontapessoaaux->idade;
                apontapessoa->matricula = apontapessoaaux->matricula;
                strcpy(apontapessoaaux->nome, pAux->nomeaux);
                apontapessoaaux->idade = pAux->tmp;
                apontapessoaaux->matricula = pAux->matriculaaux;
            }
        }  
    }
}

void bubble_sort(){
    pAux->tam = pAux->CP;
    for((pAux->i)=0; (pAux->i)<(pAux->tam)-1; (pAux->i)++){
        for((pAux->j)=0; (pAux->j)<(pAux->tam)-(pAux->i)-1; (pAux->j)++){
            apontapessoa = pBuffer + sizeof(VARIAVEIS) + sizeof(PESSOA)*(pAux->j);
            apontapessoaaux = apontapessoa+1;
            if((apontapessoa->idade)>(apontapessoaaux->idade)){
                strcpy(pAux->nomeaux, apontapessoa->nome);
                pAux->tmp = apontapessoa->idade;
                pAux->matriculaaux = apontapessoa->matricula;
                strcpy(apontapessoa->nome, apontapessoaaux->nome);
                apontapessoa->idade = apontapessoaaux->idade;
                apontapessoa->matricula = apontapessoaaux->matricula;
                strcpy(apontapessoaaux->nome, pAux->nomeaux);
                apontapessoaaux->idade = pAux->tmp;
                apontapessoaaux->matricula = pAux->matriculaaux;
            }
        }
    }
}