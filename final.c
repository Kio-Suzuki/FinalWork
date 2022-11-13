  

// talvez oq coloquei ai não faça o menor sentioo

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


//FUNÇÕES (PROTOTIPOS)


int numeroRandom();
void cadastroRest();
void cadastroPonte();
pes cadastroIndividuo();
void cadastroParceiros();
void pesquisar();
void deleteRegistro();

// STRUCTS


typedef struct pessoas{
    int cpf, ddd, numero, codigo;
    char nome[50], sobrenome[50];
}pes;

typedef struct pontes{
    int cpf, ddd, numero, codigo;
    char nome[50], sobrenome[50];
}pont;

typedef struct restaurant{
    int cep;
    char nome[50], sobras;
}restt;

typedef struct ciclos{
    int kg, dia, mes, ano;
    struct restaurant;
    
}cic;

typedef struct parceiros{
    int nome;
    
}parc;




// MAIN

int main(void){
    pes *pessoa=malloc(10000*sizeof(pes));
    pont *ponte=malloc(10000*sizeof(pont));
    restt *rest=malloc(10000*sizeof(restt));
    cic *ciclos=malloc(10000*sizeof(cic));
    parc *parceiros=malloc(10000*sizeof(parc));
    int numPes, numPont, numRest, numCic, numParc;
    numPes=1
    cadastroIndividuo(&pessoa[numPes]);
}



// FUNÇÕES (CONSTRUIDAS)

void numeroRandom(){
    srand(time(NULL));
    int valor = rand()%10000;
    return valor;
};

void cadastroRest(){
    struct restaurant;
    codigoRandomUnico();
    sobras(kg)
};

void cadastroPonte(){
    codigoRandomUnico();
        struct pontes;

};

void cadastroIndividuo(pes *pessoa, int pos){
    pessoa[pos].codigo=numeroRandom();
    fgets(pessoa[pos].nome,50,stdin);
    fgets(pessoa[pos].sobrenome,50,stdin);
    scanf("%d", pessoa[pos].cpf);
};
void cadastroParceiros(){
    codigoRandomUnico();
    struct parceiros;
};

void pesquisar(){

};

