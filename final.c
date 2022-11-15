  
// talvez oq coloquei ai não faça o menor sentioo

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


//FUNÇÕES (PROTOTIPOS)


int numeroRandom(int cod[10);
void cadastroRest();
void cadastroPonte();
void cadastroIndividuo();
void cadastroParceiros();
void pesquisar();
void deleteRegistro();


// PESQUIIAR INFOS
// DISTRIBUIR ALIMENTOS
// ADICIONAR ALIMENTOS
// ADICIONAR RESTAURANTES
// ADICIONAR CLIENTES
// ADICIONAR PARCEIROS
// 

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
    
    int numPes, numPont, numRest, numCic, numParc;
    int escolha;
    int login, senha;
    // Erro por completo aqui.

    pes *pessoa=malloc(10000*sizeof(pes));
    pont *ponte=malloc(10000*sizeof(pont));
    restt *rest=malloc(10000*sizeof(restt));
    cic *ciclos=malloc(10000*sizeof(cic));
    parc *parceiros=malloc(10000*sizeof(parc));
    numPes=1;
    do(
        printf("\n*******************************************************\n* Menu de seleção:                                    *\n* Digite 1 para entrar no Menu de Cadastramento;      *\n* Digite 2 para entrar no menu de edição de cadastros;* \n* Digite 3 para entrar no menu de exclusão;           *\n*******************************************************");
        scanf("%d", &escolha);
        switch(escolha)

            case 1:
                printf("\n*******************************************************\n* Menu de seleção:                                    *\n* Digite 1 para cadastrar um individuo/familia ;      *\n* Digite 2 para cadastrar um Restaurante;             * \n* Digite 3 para cadastrar um parceiro                 *\n*******************************************************");
                scanf("%d", &escolha);
                switch(escolha){
                    case 1:

                        break;
                    case 2:
                    
                        break;
                    case 3:
                    
                        break;
                }
            break;
            case 2:
                printf("\n*******************************************************\n* Menu de seleção:                                    *\n* Digite 1 para editar um individuo/familia ;         *\n* Digite 2 para editar um Restaurante;                * \n* Digite 3 para editar um parceiro;                   *\n*******************************************************");
                scanf("%d", &escolha);
                switch(escolha){
                    case 1:
                    
                        break;
                    case 2:
                    
                        break;
                    case 3:
                    
                        break;
                }
            break;
            case 3:
                printf("\n*******************************************************\n* Menu de seleção:                                    *\n* Digite 1 para excluir um individuo/familia ;        *\n* Digite 2 para excluir um Restaurante;               * \n* Digite 3 para excluir um parceiro;                  *\n*******************************************************");
                scanf("%d", &escolha);
                switch(escolha){
                    case 1:
                    
                        break;
                    case 2:
                    
                        break;
                    case 3:

                        break;

            }
    )while(escolha!=0);
        cadastroIndividuo(&pessoa[numPes]);
}



// FUNÇÕES (CONSTRUIDAS)

void numeroRandom(int cod[10){
    srand(time(NULL));
    int L[10][10], i, j, cont;                           
    for (i=0; i<10; i++){                                      
        for (j=0; j<10; j++){                              
            L[i][j] = rand() %10;                               
            if (L[i][j]<5){                                     
                L[i][j]=0;
            }else
                L[i][j]=1;
        }
    }
    for (i=0; i<10; i++){                                      
        for (j=0; j<10; j++){                              
            if(L[i][j]){
                cont++; 
            }
        }
        if(cont>5){
            cod[i]=1;
        }
        else{
            cod[i]=0;
        }
        printf("\n");
        cont=0;
    }
}
;

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

