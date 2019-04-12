#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct de pessoas
typedef struct
{
    char nome[50];
    int idade;
    long int matricula;
} PESSOA;

//struct das variáveis que utilizarei
typedef struct{
    int seletor, CP, contador, i, tam;
}VARIAVEIS;

//declaração dos ponteiros
VARIAVEIS *pVar;
PESSOA *apontapessoa;
PESSOA *pAux;
void *pBuffer;

//declaração das funções
void realoca_buffer();
void preenche_dados();
void imprime_pessoas();
void remove_pessoa();

int main()
{
    pBuffer = malloc(sizeof(VARIAVEIS) + sizeof(PESSOA));
    if(pBuffer==NULL)
    {
        printf("Malloc deu errado.");
    }
    pVar = pBuffer;
    apontapessoa = pBuffer + sizeof(VARIAVEIS) + sizeof(PESSOA) - sizeof(PESSOA);
    pVar->seletor = 0;
    pVar->CP = 0;
    pVar->i = 0;
    pVar->contador = 0;
    pVar->tam = 0;
    while(1)
    {
        printf("\nDigite o que voce deseja:\n1)Adicionar pessoa\n2)Remover pessoa\n3)Listar\n4)Sair\n\n");
        scanf("%d", &pVar->seletor);
        getchar();
        switch((pVar->seletor))
        {
        case(1):
            (pVar->CP)++;
            realoca_buffer();
            preenche_dados();
            break;
        case(2):
            if((pVar->CP)==0)
            {
                printf("Nao ha pessoas para remover.\n");
            }else
            {
            remove_pessoa();
            }
            break;
        case(3):
            if((pVar->CP)==0)
            {
                printf("Nao ha pessoas para listar.\n");
            }else
            {
            imprime_pessoas();
            }
            break;
        case(4):
            return 0;
            break;
        }
        if((pVar->seletor)!= 1 && (pVar->seletor)!= 2 && (pVar->seletor)!= 3 && (pVar->seletor)!= 4){
            printf("Valor digitado nao permitido.\n\n");
        }
    }
}

void realoca_buffer()
{
    pBuffer= realloc(pBuffer, sizeof(VARIAVEIS) + (pVar->CP)*sizeof(PESSOA));
    pVar = pBuffer;
    apontapessoa = pBuffer + sizeof(VARIAVEIS) + (pVar->CP)*sizeof(PESSOA) - sizeof(PESSOA) ;
}

void preenche_dados()
{
    printf("Digite o nome da pessoa: ");
    fgets(apontapessoa->nome, 50, stdin);
    printf("Digite sua idade:");
    scanf("%d", &apontapessoa->idade);
    printf("Digite sua matricula:");
    scanf("%li", &apontapessoa->matricula);
    printf("\n");
    printf("Pessoa adicionada com sucesso!\n");
}

void imprime_pessoas()
{
    printf("\n");
    apontapessoa = pBuffer + sizeof(VARIAVEIS);
    if((pVar->CP)==1){
        printf("Contato 1: %s, %d anos, matricula %li\n", apontapessoa->nome, apontapessoa->idade, apontapessoa->matricula);
    }else{
        for((pVar->i)=1; (pVar->i)<((pVar->CP)); (pVar->i)++){
            printf("Contato %d: %s, %d anos, matricula %li\n", (pVar->i), apontapessoa->nome, apontapessoa->idade, apontapessoa->matricula);
            apontapessoa++;
        }
        printf("Contato %d: %s, %d anos, matricula %li\n", (pVar->i), apontapessoa->nome, apontapessoa->idade, apontapessoa->matricula);
    }
    printf("\n");
}

void remove_pessoa(){
    imprime_pessoas();
    printf("\nDigite a pessoa que você deseja remover: ");
    scanf("%d", &pVar->contador);
    getchar();
    if((pVar->contador)==(pVar->CP)){
        (pVar->CP)--;
        realoca_buffer();
    }else
    {
    pAux = pBuffer + sizeof(VARIAVEIS) +(sizeof(PESSOA)*((pVar->contador)-1));
    apontapessoa = pBuffer + sizeof(VARIAVEIS) +(sizeof(PESSOA)*((pVar->contador)));
    for((pVar->i)=0; (pVar->i)<=(((pVar->CP)-(pVar->contador))-1); (pVar->i)++){
        strcpy(pAux->nome,apontapessoa->nome);
        if((pVar->i)<(((pVar->CP)-(pVar->contador))-1)){
        apontapessoa++;
        pAux++;
    }
    }
    (pVar->CP)--;
    realoca_buffer();
    }
    printf("Pessoa removida com sucesso!\n");
}
