  
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
    nasc;
    end; 
    tel;
}pfisica;

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
    nasc;
    end;
    tel;
    int membros;
}fam;

typedef struct doação{
    int quantidade;
    char info[100];
    data;
}doa;


typedef struct pessoas{
    int cpf, ddd, telefone, codigo;
    char nome[50], sobrenome[50];
}pes;



typedef struct pontes{
    int cpf, ddd, telefone, codigo;
    char nome[50], sobrenome[50];
}pont;

typedef struct restaurante{
    int cep;
    char nome[50], sobras;
}restt;



typedef struct ciclos{
    int kg, dia, mes, ano;
    struct restaurante;
    
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

    /* tentei usar alocação dinamica aq, mas ficou bem confuso, a tentativa era adicionar 10k posiçoes de cada um dos registros
    , mas botando pra funfar fica bem zoado, ce acha q daria pra usar alocacao dinamica em outro lugar ? */
    
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

