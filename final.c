#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

//FUNÇÕES (PROTOTIPOS)

void gerarCodigo();
void menuPrincipal();
void imprimeOpcoes();
void menuCadastrar();
void menuPesquisar();
void pesquisarPessoas();
void pesquisarVoluntarios();
void pesquisarRestaurantes();

// PESQUIIAR INFOS
// DISTRIBUIR ALIMENTOS
// ADICIONAR ALIMENTOS
// ADICIONAR RESTAURANTES
// ADICIONAR CLIENTES
// ADICIONAR PARCEIROS

// STRUCTS

typedef struct codigoPessoa{
    int codP;
}cod_p;

typedef struct codigoEstabelecimento{
    int codE;
}cod_e;

typedef struct endereco{
    char logradouro[50];
    int numero;
    int cep;
    char cidade[50];
    char estado[2]; 
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
    char genero;
    int cpf;
    int priori;
    data;
    end; 
    tel;
}pfisica;


// Cadastro de restaurantes, mercados, pessoas juridicas.

typedef struct doacao{
    int quantidade;
    char info[100];
    data;
}doa;

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
    int priori;
    data;
    end;
    tel;
    int membros;
}fam;

// MAIN

int main()
{
    setlocale(LC_ALL,"");
    menuPrincipal();
}
    
// FUNÇÕES (CONSTRUIDAS)

void gerarCodigo()
{
    int cod[10][10], i, j, cont = 0, codU[10]; 
    srand(time(NULL));
    for (i = 0; i < 10; i++){                                      
        for (j = 0; j < 10; j++){                              
            cod[i][j] = rand() %2;                               
        } 
    }  
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if (cod[j][i] == 1){
                cont++;
            }      
        }
        if (cont >= 5){
            codU[i] = 1;
        }else{
            codU[i] = 0;
        }
        cont = 0;  
    }
    printf ("\nCODIGO UNICO: ");
    for (i = 0; i < 10; i++){
        printf ("%d ", codU[i]);
    }
}
    
void menuPrincipal()
{
    int opt;
    do{
        printf ("Para acessar o Menu, digite:\n");                              
        printf ("1 - Cadastramento\n");      
        printf ("2 - Pesquisa\n");
        printf ("0 - Sair\n");           
        scanf ("%d", &opt);
        switch (opt)
        {
        case 1:
            menuCadastrar();
            break;

        case 2:
            menuPesquisar();
            break;
        
        default:
            break;
        }    
    }while(opt != 0);
}

void imprimeOpcoes()
{
    
    printf ("1 - Pessoas\n");
    printf ("2 - Voluntarios\n");
    printf ("3 - Restaurantes\n");
    printf ("4 - Mercados\n");
    printf ("0 - Sair\n");    
}

void menuCadastrar()
{
    int opt;
    do{
        printf ("1 - Cadastrar\n");
        printf ("2 - Editar cadastro\n");
        printf ("3 - Excluir cadastro\n");
        printf ("0 - Sair\n");
        scanf ("%d", &opt);
        switch (opt)
        {
        case 1:
            imprimeOpcoes();
            scanf ("%d", &opt);
            break;
        
        case 2:
            imprimeOpcoes();
            scanf ("%d", &opt);
            break;

        case 3:
            imprimeOpcoes();
            scanf ("%d", &opt);
            break;

        default:
            break;
        }
    }while(opt != 0);
}

void menuPesquisar()
{
    int opt;
    do{
        imprimeOpcoes();
        scanf ("%d", &opt);
        switch (opt)
        {
        case 1:
            pesquisarPessoas();
            break;
            
        case 2:
            pesquisarVoluntarios();
            break;

        case 3:
            pesquisarRestaurantes();
            break;

        case 4:
            pesquisarRestaurantes();
            break;

        default:
            break;
        }
    }while(opt != 0);
}

void pesquisarPessoas()
{
    setlocale(LC_ALL,"Portuguese");
    int opt, cpf, data, priori, codU;
    char nome[50], gen;
    do{
        printf ("1 - Nome\n");
        printf ("2 - Sobrenome\n");
        printf ("3 - CPF\n");
        printf ("4 - Genero\n");
        printf ("5 - Data de nascimento\n");
        printf ("6 - Prioridade\n");
        printf ("7 - Codigo Unico\n");
        printf ("8 - Retornar\n");
        printf ("0 - Sair\n");
        scanf ("%d", &opt);       
        switch (opt)
        {
        case 1:
            printf ("Digite o nome: ");
            scanf ("%s", nome);
            break;

        case 2:
            printf ("Digite o sobrenome: ");
            scanf ("%s", nome);
            break;

        case 3:
            printf ("CPF: ");
            scanf ("%d", &cpf);
            break;

        case 4:
            printf ("Genero: ");
            scanf ("%c", &gen);
            break;
            
        case 5:
            printf ("Data de nascimento: ");
            scanf ("%d", &data);
            break;

        case 6:
            printf ("Prioridade: ");
            scanf ("%d", &priori);
            break;

        case 7:
            printf ("Codigo Unico: ");
            scanf ("%d", &codU);
            break;

        case 8:
            menuPesquisar();
                
        default:
            break;
        }
    }while(opt != 0);
}
        
void pesquisarVoluntarios()
{
    int opt, cpf, data, codU;
    char nome[50], gen;
    do{
        printf ("1 - Nome\n");
        printf ("2 - Sobrenome\n");
        printf ("3 - CPF\n");
        printf ("4 - Genero\n");
        printf ("5 - Data de nascimento\n");
        printf ("6 - Codigo Único\n");
        printf ("7 - Retornar\n");
        printf ("0 - Sair\n");
        scanf ("%d", &opt);       
        switch (opt)
        {
        case 1:
            printf ("Digite o nome: ");
            scanf ("%s", nome);
            break;

        case 2:
            printf ("Digite o sobrenome: ");
            scanf ("%s", nome);
            break;

        case 3:
            printf ("CPF: ");
            scanf ("%d", &cpf);
            break;

        case 4:
            printf ("Genero: ");
            scanf ("%c", &gen);
            break;

        case 5:
            printf ("Data de nascimento: ");
            scanf ("%d", &data);
            break;

        case 6:
            printf ("6 - Codigo Unico\n");
            scanf ("%d", &codU);
            break;

        case 7:
            menuPesquisar();
                
        default:
            break;
        }
    }while(opt != 0);
}
     
void pesquisarRestaurantes()
{
    int opt, cnpj, codU;
    char nome[50];
    do{
        printf ("1 - Nome\n");
        printf ("2 - CNPJ\n");
        printf ("3 - Codigo Unico\n");
        printf ("4 - Retornar\n");
        printf ("0 - Sair\n");
        scanf ("%d", &opt);       
        switch (opt)
        {
        case 1:
            printf ("Digite o nome: ");
            scanf ("%s", nome);
            break;

        case 2:
            printf ("CNPJ: ");
            scanf ("%d", &cnpj);
            break;

        case 3:
            printf ("6 - Codigo Unico\n");
            scanf ("%d", &codU);
            break;

        case 4:
            menuPesquisar();
                
        default:
            break;
        }
    }while(opt != 0);
}

