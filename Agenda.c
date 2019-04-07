#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int idade;
    long int matricula;
} PESSOA;


void realoca_buffer(int *seletoraux, int *CPaux, int aux, void *pBufferaux, PESSOA *apontapessoaaux)
{
    pBufferaux = realloc(pBufferaux, sizeof(int)*2 + sizeof(PESSOA)*aux);
    seletoraux = pBufferaux;
    CPaux = seletoraux + 1;
    apontapessoaaux = (PESSOA*)(CPaux + 1);
    apontapessoaaux=apontapessoaaux + aux;
}


void preenche_dados(PESSOA *apontapessoaaux)
{
    printf("Digite o nome da pessoa: ");
    scanf("%s", &apontapessoaaux->nome);
    printf("Digite sua idade:");
    scanf("%d", &apontapessoaaux->idade);
    printf("Digite sua matricula:");
    scanf("%li", &apontapessoaaux->matricula);
    printf("\n");
    printf("Pessoa adicionada com sucesso!\n\n");
}

void imprime_pessoas(int *CPaux, PESSOA *apontapessoaaux, int aux)
{
    apontapessoaaux = (PESSOA*)(CPaux + 1);
    aux--;
    while(aux>0)
    {
        printf("%s, %d anos, matricula %li\n", apontapessoaaux->nome, apontapessoaaux->idade, apontapessoaaux->matricula);
        apontapessoaaux++;
        aux--;
    }
    printf("%s, %d anos, matricula %li\n", apontapessoaaux->nome, apontapessoaaux->idade, apontapessoaaux->matricula);

}

int main()
{
    int *seletor;
    int *CP;
    PESSOA *apontapessoa;
    void *pBuffer = malloc(sizeof(int)*2 + sizeof(PESSOA));
    if(pBuffer==NULL)
    {
        printf("Malloc deu errado.");
    }
    seletor = pBuffer;
    CP = seletor + 1;
    apontapessoa = (PESSOA*)(CP + 1);
    *CP = 0;
    while(1)
    {
        printf("Digite o que voce deseja:\n1)Adicionar pessoa\n2)Remover pessoa\n3)Listar\n4)Sair\n\n");
        scanf("%d", &*seletor);
        switch(*seletor)
        {
        case(1):
            *CP++;
            realoca_buffer(seletor, CP, *CP, pBuffer, apontapessoa);
            preenche_dados(apontapessoa);
            break;
        case(2):
            if(*CP==0)
            {
                printf("Nao ha pessoas para remover.\n");
            }else
            {

            }
            break;
        case(3):
            if(*CP==0)
            {
                printf("Nao ha pessoas para listar.\n");
            }else
            {
            imprime_pessoas(CP, apontapessoa, *CP);
            }
            break;
        case(4):

            break;

        }
        if(*seletor!=(1 || 2 || 3 || 4))
        {
            printf("Valor nao permitido, digite novamente.\n\n");
        }
    }
}
