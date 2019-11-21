 // Nao se preocupem com isso
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define uteis
#define OFFSET 97
#define ALFABETO 26
#define true 1
#define false 0
#define bool int
#define DEFAULT "Traducao desconhecida\0"

// Estruturas de dados
struct Celula {
    char * pais;
    char * frase;
};

struct Dicionario {
    struct Celula letras[ALFABETO];
};

typedef struct Celula Celula;
typedef struct Dicionario Dicionario;

// Pesquisar : retorna true se o pais esta no dicionario, false caso contrario
bool pesquisar(Dicionario * dicionario, char * pais) {
    if (dicionario->letras[pais[0] - OFFSET].pais) {
        if (strcmp(pais, dicionario->letras[pais[0] - OFFSET].pais) == 0) {
            return true;
        }
    }
    return false;
}

// Inserir : insere par pais - frase no dicionario caso a primeira letra do pais esteja livre e retorna true, false caso nao insira
bool inserir(Dicionario * dicionario, char * pais, char * frase) {
    // SEU CODIGO AQUI
    if((dicionario->letras[pais[0]-OFFSET].pais)==NULL){
        if((dicionario->letras[pais[0]-OFFSET].pais = malloc(sizeof(char)*strlen(pais)))==NULL){
            printf("Malloc deu errado.");
            return false;
        }else{
            strcpy(dicionario->letras[pais[0]-OFFSET].pais, pais);
        }
        if ((dicionario->letras[pais[0]-OFFSET].frase = malloc(sizeof(char)*strlen(frase)))==NULL)
        {
            printf("Malloc deu errado.");
            return false;
        }else{
            strcpy(dicionario->letras[pais[0]-OFFSET].frase, frase);
        }
        return true;
    }else{
        return false;
    }
}

// Saudar : retorna a a traducao de "Feliz Natal!" no pais passado como parametro caso esteja no dicionario, retorna frase DEFAULT caso contrario
char * saudar(Dicionario * dicionario, char * pais) {
    // SEU CODIGO AQUI
    if((strcmp(dicionario->letras[pais[0]-OFFSET].pais, pais))==0){
        return dicionario->letras[pais[0]-OFFSET].frase;
    }else{
        return DEFAULT;
    }
}

// Inicializa dicionario
Dicionario * initDicionario() {
    Dicionario * d = (Dicionario *) malloc(sizeof(Dicionario));

    for (int i = 0; i < ALFABETO; i++) {
        d->letras[i].pais = NULL;
    }

    printf("Inserindo brasil\n");
    inserir(d, "brasil\0", "Feliz Natal!\0");

    printf("Inserindo alemanha\n");
    inserir(d, "alemanha", "Frohliche Weihnachten!\0");

    printf("Inserindo coreia\n");
    inserir(d, "coreia", "Chuk Sung Tan!\0");

    printf("Inserindo grecia\n");
    inserir(d, "grecia", "Kala Christougena!\0");

    printf("Inserindo estados-unidos\n");
    inserir(d, "estados-unidos", "Merry Christmas!\0");

    printf("Inserindo portugal\n");
    inserir(d, "portugal", "Feliz Natal!\0");

    printf("Inserindo suecia\n");
    inserir(d, "suecia", "God Jul!");

    printf("Inserindo turquia\n");
    inserir(d, "turquia", "Mutlu Noeller\0");

    printf("Inserindo mexico\n");
    inserir(d, "mexico", "Feliz Navidad!\0");

    printf("Inserindo italia\n");
    inserir(d, "italia", "Buon Natale!\0");

    printf("Inserindo libia\n");
    inserir(d, "libia", "Buon Natale!\0");

    printf("Inserindo japao\n");
    inserir(d, "japao", "Merii Kurisumasu!\0");

    return d;
}

int main() {
    printf("---Inicializacao---\n");
    Dicionario * d = initDicionario();
    //char * resultado; NÃO É OCUPADO

    printf("\n---Testes de Validacao---\n");
    printf("1. Pesquisa por traducao existente");
    if (pesquisar(d, "brasil")) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL.\n" RESET);
    }

    printf("2. Pesquisa por traducao nao existente");
    if (pesquisar(d, "bolivia") == false) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL.\n" RESET);
    }

    printf("3. Saudacao valida");
    if (strcmp(saudar(d, "japao"), "Merii Kurisumasu!") == 0) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL.\n" RESET);
    }

    printf("4. Saudacao invalida");
    if (strcmp(saudar(d, "marrocos"), DEFAULT) == 0) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL.\n" RESET);
    }

    for(int i=0; i<26; i++){ // LIBERA MEMÓRIA ALOCADA PARA CADA PAIS E FRASE
        if(d->letras[i].pais!= NULL){
            free(d->letras[i].pais);
            free(d->letras[i].frase);
        }
    }

    free(d); // LIBERA MEMÓRIA ALOCADA PARA O ALFABETO
    return 0;
}