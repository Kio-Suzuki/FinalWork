  
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
void cadastroIndividuo();
void cadastroParceiros();
void pesquisar();
void deleteRegistro();

// STRUCTS

typedef struct codigoPessoa{
    int numero;
}cod_p;

typedef struct codigoEstabelecimento{
    int numero;
}cod_e;

typedef struct endereco{
    char logradouro[50];
    int numero;
    int cep;
    char cidade[50];
    char estado[2] 
}end;

// data para doação e tambem para nascimento.
typedef struct data{
    int dia;
    int mes;
    int ano;
}data;

typedef struct telefone{
    int ddd;
    int fixo;
    int celular;
}tel;

typedef struct dadosPessoaisFisica{
    cod_p;
    char nome[50];
    char sobrenome[50];
    int cpf;
    data;
    end; 
    tel;
}pfisica;


// Cadastro de restaurantes, mercados, pessoas juridicas.

typedef struct dadosPessoaisJuridica{
    cod_e;
    char nome[50];
    char sobrenome[50];
    int cnpj;
    end; 
    tel;
    doa;
}pjuridica;

typedef struct dadosFamilias{
    cod_p;
    char nome[50];
    char sobrenome[50];
    int cpf;
    data;
    end;
    tel;
    int membros;
}fam;

typedef struct doação{
    int quantidade;
    char info[100];
    data;
}doa;


// MAIN

int main(void){
    
    
    // Erro por completo aqui.

    pes *pessoa=malloc(10000*sizeof(pes));
    pont *ponte=malloc(10000*sizeof(pont));
    restt *rest=malloc(10000*sizeof(restt));
    cic *ciclos=malloc(10000*sizeof(cic));
    parc *parceiros=malloc(10000*sizeof(parc));
    int numPes, numPont, numRest, numCic, numParc;
    numPes=1;
    cadastroIndividuo(&pessoa[numPes]);
}



// FUNÇÕES (CONSTRUIDAS)

void numeroRandom(){
    srand(time(NULL));
    int valor = rand()%10000;
    return valor;
};

void cadastroRest(){
    struct restaurante;
    codigoRandomUnico();
    sobras(kg);
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

