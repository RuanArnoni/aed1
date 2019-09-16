#include <stdio.h>
#include <stdlib.h>

int main(){
    void *pBuffer;
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
    printf("Digite o tipo de dado:\n1)Int\n2)Float\n3)Double\n4)Parar as entradas\n\n");
    scanf("%d ", &seletor);
    getchar();
    while(seletor!=4){
        switch (seletor)
        {
        case 1:
            numerointeiros++;
            numeroentradas++;
            pBuffer = realloc(pBuffer, sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles + sizeof(int)*numeroentradas);
            pInteiro = pBuffer + sizeof(int)*numerointeiros - sizeof(int);
            pFloat = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats - sizeof(float);
            pDouble = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles - sizeof(double);
            pEntradas = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles + sizeof(int)*numeroentradas - sizeof(int);
            printf("Digite o valor do inteiro: ");
            scanf("%d", pInteiro);
            getchar();
            *pEntradas = seletor;
            break;
        
        case 2:
            numerofloats++;
            numeroentradas++;
            pBuffer = realloc(pBuffer, sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles + sizeof(int)*numeroentradas);
            pInteiro = pBuffer + sizeof(int)*numerointeiros - sizeof(int);
            pFloat = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats - sizeof(float);
            pDouble = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles - sizeof(double);
            pEntradas = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles + sizeof(int)*numeroentradas - sizeof(int);
            printf("Digite o valor do float: ");
            scanf("%f", pFloat);
            getchar();
            *pEntradas = seletor;
            break;

        case 3:
            numerodoubles++;
            numeroentradas++;
            pBuffer = realloc(pBuffer, sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles + sizeof(int)*numeroentradas);
            pInteiro = pBuffer + sizeof(int)*numerointeiros - sizeof(int);
            pFloat = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats - sizeof(float);
            pDouble = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles - sizeof(double);
            pEntradas = pBuffer + sizeof(int)*numerointeiros + sizeof(float)*numerofloats + sizeof(double)*numerodoubles + sizeof(int)*numeroentradas - sizeof(int);
            printf("Digite o valor do double: ");
            scanf("%lf", pDouble);
            getchar();
            *pEntradas = seletor;
        }
        printf("Digite o tipo de dado:\n1)Int\n2)Float\n3)Double\n4)Parar as entradas\n\n");
    scanf("%d ", &seletor);
    getchar();
    }
    printf("Valores em sequencia: ");
    pInteiro = pBuffer;//aqui eu reaponto todos os ponteiros pro início do seu tipo
    pFloat = pInteiro + sizeof(int)*numerointeiros;
    pDouble = pFloat + sizeof(float)*numerofloats;
    pEntradas = pDouble + sizeof(double)*numerodoubles;
        for(int i=0; i<numeroentradas-1; i++){//esse ciclo printa na ordem que foi digitado os números, com ''numeroentradas-1'' pq como o *pEntradas é a última coisa do buffer, se rodar 1 a mais ele pula pra fora e da segmentation fudeu
            if(*pEntradas==1){
                printf("%d ", *pInteiro);
                pInteiro++;
                pEntradas++;
            }
            if(*pEntradas==2){
                printf("%f ", *pFloat);
                pFloat++;
                pEntradas++;
            }
            if(*pEntradas==3){
                printf("%lf ", *pDouble);
                pDouble++;
                pEntradas++;
            }
        }
        if(*pEntradas==1){//aí aqui eu printo o último
                printf("%d ", *pInteiro);
                pInteiro++; 
            }
            if(*pEntradas==2){
                printf("%f ", *pFloat);
                pFloat++;    
            }
            if(*pEntradas==3){
                printf("%lf ", *pDouble);
                pDouble++;  
            }
    printf("Valores na sequencia (int-float-double): ");
    pInteiro = pBuffer;//reaponto de novo
    pFloat = pInteiro + sizeof(int)*numerointeiros;
    pDouble = pFloat + sizeof(float)*numerofloats;
    pEntradas = pDouble + sizeof(double)*numerodoubles;
    printf("Inteiros: ");//e aqui pra baixo printo todos inteiros, dps todos floats...s
    for(int i=0; i<numerointeiros; i++){
        printf("%d ", *pInteiro);
        pInteiro++;
    }
    printf("Floats: ");
    for(int i=0; i<numerofloats; i++){
        printf("%f ", *pFloat);
        pFloat++;
    }
    printf("Doubles: ");
    for(int i=0; i<numerodoubles; i++){
        printf("%lf ", *pDouble);
        pDouble++;
    }        
    free(pBuffer);
}