#include <stdio.h>
#include <stdlib.h>

int main(){
    void *pBuffer;
    int *BufferAux;
    int seletor;//seleciona os tipos de dados
    int numerointeiros=0;//nome ja diz
    int numerofloats=0;//nome ja diz
    int numerodoubles=0;//nome ja diz
    int numeroentradas=0;//nome ja diz
    int *pInteiro;//ponteiro pra inteiro
    float *pFloat;//e assim vai
    double *pDouble;
    int *pEntradas;//ponteiro que vai armazenar no fim do buffer a ordem que o usuário selecionou
    pBuffer = malloc(sizeof(int));
    BufferAux = malloc(sizeof(int));
    printf("Digite o tipo de dado:\n1)Int\n2)Float\n3)Double\n4)Parar as entradas\n\n");
    scanf("%d", &seletor);
    while(seletor!=4){
        switch (seletor)
        {
        case 1:
            numerointeiros++;
            numeroentradas++;
            pBuffer = realloc(pBuffer,sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles);
            pInteiro = pBuffer + sizeof(int)*numerointeiros - sizeof(int);
            pFloat = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats - sizeof(float);
            pDouble = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles - sizeof(double);
            printf("Digite o valor do inteiro: ");
            scanf("%d", pInteiro);
            BufferAux = realloc(BufferAux, sizeof(int)*numeroentradas);
            pEntradas = BufferAux + sizeof(int)*numeroentradas - sizeof(int);
            *pEntradas = seletor;
            break;

        case 2:
            numerofloats++;
            numeroentradas++;
            pBuffer = realloc(pBuffer,sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles);
            pInteiro = pBuffer + sizeof(int)*numerointeiros - sizeof(int);
            pFloat = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats - sizeof(float);
            pDouble = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles - sizeof(double);
            printf("Digite o valor do float: ");
            scanf("%f", pFloat);
            BufferAux = realloc(BufferAux, sizeof(int)*numeroentradas);
            pEntradas = BufferAux + sizeof(int)*numeroentradas - sizeof(int);
            *pEntradas = seletor;
            break;

        case 3:
            numerodoubles++;
            numeroentradas++;
            pBuffer = realloc(pBuffer,sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles);
            pInteiro = pBuffer + sizeof(int)*numerointeiros - sizeof(int);
            pFloat = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats - sizeof(float);
            pDouble = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles - sizeof(double);
            printf("Digite o valor do double: ");
            scanf("%lf", pDouble);
            BufferAux = realloc(BufferAux, sizeof(int)*numeroentradas);
            pEntradas = BufferAux + sizeof(int)*numeroentradas - sizeof(int);
            *pEntradas = seletor;
            break;
        }
        printf("Digite o tipo de dado:\n1)Int\n2)Float\n3)Double\n4)Parar as entradas\n\n");
    scanf("%d", &seletor);
    }
    printf("Valores em sequencia: ");
    pEntradas = BufferAux;//aqui eu reaponto todos os ponteiros pro início do seu tipo
    pInteiro = pBuffer;
    pFloat = pBuffer + sizeof(int)*numerointeiros;
    pDouble = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats;
        for(int i=0; i<numeroentradas-1; i++){//esse ciclo printa na ordem que foi digitado os números, com ''numeroentradas-1'' pq como o *pEntradas é a última coisa do buffer, se rodar 1 a mais ele pula pra fora e da segmentation fudeu
            if(*pEntradas==1){
                printf("%d ", *pInteiro);
                pInteiro++;
                pEntradas++;
            }else{
                 if(*pEntradas==2){
                printf("%f ", *pFloat);
                pFloat++;
                pEntradas++;
            }else{
                if(*pEntradas==3){
                printf("%lf ", *pDouble);
                pDouble++;
                pEntradas++;
            }
            }
            }
        }
        if(*pEntradas==1){
                printf("%d ", *pInteiro);
            }else{
                 if(*pEntradas==2){
                printf("%f ", *pFloat);
            }else{
                if(*pEntradas==3){
                printf("%lf ", *pDouble);
            }
            }
            }
        printf("\n");
    printf("Valores na sequencia (int-float-double):\n");
    pEntradas = BufferAux;//aqui eu reaponto todos os ponteiros pro início do seu tipo
    pInteiro = pBuffer;
    pFloat = pBuffer + sizeof(int)*numerointeiros;
    pDouble = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats;
    printf("Inteiros: ");//e aqui pra baixo printo todos inteiros, dps todos floats...s
    for(int i=0; i<numerointeiros; i++){
        printf("%d ", *pInteiro);
        pInteiro++;
    }
    printf("\n");
    printf("Floats: ");
    for(int i=0; i<numerofloats; i++){
        printf("%f ", *pFloat);
        pFloat++;
    }
    printf("\n");
    printf("Doubles: ");
    for(int i=0; i<numerodoubles-1; i++){
        printf("%lf ", *pDouble);
        pDouble++;
    }
    printf("%lf\n", *pDouble);
    free(pBuffer);
}
