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
void apresentarInfocpf();
void apresentarInfocnpj();

// PESQUIIAR INFOS
// DISTRIBUIR ALIMENTOS
// ADICIONAR ALIMENTOS
// ADICIONAR RESTAURANTES
// ADICIONAR CLIENTES
// ADICIONAR PARCEIROS

// STRUCTS

typedef struct login{
    char login[20];
    char senha[10];
}login;

typedef struct codigoPessoa{
    int codP;
}cod_p;

typedef struct endereco{
    char logradouro[50];
    int numero;
    int cep;
    char cidade[50];
    char estado[2]; 
}end;

typedef struct codigoEstabelecimento{
    int codE;
}cod_e;

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
    cod_p codigo;
    char nome[50];
    char sobrenome[50];
    char genero;
    int cpf;
    int priori;
    data nascimento;
    end endereco;
    tel telefone;
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
    end endereco;
    tel telefone;
    doa doacao;
}pjuridica;

typedef struct dadosFamilias{
    cod_p;
    char nome[50];
    char sobrenome[50];
    int cpf;
    int priori;
    data data;
    end endereço;
    tel telefone;
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
    char login[20], senha[10];
    do{
        printf ("1 - Admin\n");
        printf ("2 - Visitante\n");
        printf ("0 - Sair\n");
        scanf ("%d", &opt);
        switch (opt)
        {
        case 1:
            printf ("Login: \n");
            scanf ("%s", login);
            printf ("Senha: ");
            scanf ("%s", senha);
            menuAdmin();
            break;
        
        case 2:
            printf ("Pesquisar restaurantes: ");
            printf ("1 - Endereco\n");
            printf ("2 - Refeicoes\n");
            break;
        }
    }while(opt != 0);
}

void menuAdmin()
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
        }
    }while(opt != 0);
void apresentarInfocpf(pjuridica *resul) {
  printf("\nResultados:\n");
  printf("\nNome: %s", resul->nome);
  printf("Sobrenome: %s", resul->sobrenome);
  printf("CPF: %d\n", resul->cpf);
  printf("Código: ");
  for (int i = 0; i < 10; i++) {
    printf("%d", resul->codigo.codigo[i]);
  };
  printf("\n");
}
void apresentarInfocpf(pfisica *resul) {
    printf("\nResultados:\n");
    printf("\nNome: %s", resul->nome);
    printf("Sobrenome: %s", resul->sobrenome);
    printf("CPF: %d\n", resul->cpf);
    printf("Código: ");
    for (int i = 0; i < 10; i++) {
        printf("%d", resul->codigo.codP[i]);
    };
    printf("Data de nascimento: %d/%d/%d", resul->nascimento.dia, resul->nascimento.mes, resul->nascimento.ano);
    printf("DDD do telefone: ", pfis->telefone.ddd);
    printf("Telefone fixo: %d", pfis->telefone.fixo);
    printf("Telefone celular: %d", pfis->telefone.celular);
    printf("Prioridade: %d", pfis->priori);
  printf("\n");
}
void apresentarInfocnpj(pjuridica *resul) {
    printf("\nResultados:\n");
    printf("\nNome: %s", resul->nome);
    printf("Sobrenome: %s", resul->sobrenome);
    printf("CNPJ: %d\n", resul->cnpj);
    printf("Código: ");
    printf("Codigo: %d", resul->codigop);
    printf("Data de nascimento: %d/%d/%d", resul->nascimento.dia, resul->nascimento.mes, resul->nascimento.ano);
    printf("DDD do telefone: ", pfis->telefone.ddd);
    printf("Telefone fixo: %d", pfis->telefone.fixo);
    printf("Telefone celular: %d", pfis->telefone.celular);
    printf("Prioridade: %d", pfis->priori);
  printf("\n");
}
void adicionarPessoas(pfisica *pfis, pjuridica *pjur, int doisum) {
  if (doisum == 1) {
    fflush(stdin);
    printf("Digite o nome da pessoa: ");
    getchar();
    fgets(pfis->nome, 50, stdin);
    printf("Digite o sobrenome da pessoa: ");
    fgets(pfis->sobrenome, 50, stdin);
    printf("Digite o cpf: ");
    scanf("%d", &pfis->cpf);
    printf("Digite o dia de nascimento: ");
    scanf("%d",&pfis->nascimento.dia);
    printf("Digite o mes de nascimento: ");
    scanf("%d",&pfis->nascimento.mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d",&pfis->nascimento.ano);
    printf("Digite o DDD do telefone: ");
    scanf("%d",&pfis->telefone.ddd);
    printf("Digite o telefone fixo: ");
    scanf("%d", &pfis->telefone.fixo);
    printf("Digite o telefone celular: ");
    scanf("%d", &pfis->telefone.celular);
    gerarCodigo(pfis, pjur, doisum);
  } else if (doisum == 2) {
        fflush(stdin);
    printf("Digite o nome da pessoa/estabelecimento: ");
    getchar();
    fgets(pjur->nome, 50, stdin);
    printf("Digite o sobrenome da pessoa(caso seja pessoa): ");
    fgets(pjur->sobrenome, 50, stdin);
    printf("Digite o cnpj: ");
    scanf("%d", &pjur->cnpj);
    printf("Digite o DDD do telefone: ");
    scanf("%d",&pjur->telefone.ddd);
    getchar();
    printf("Digite o telefone fixo: ");
    scanf("%d", &pjur->telefone.fixo);
    getchar();
    printf("Digite o telefone celular: ");
    scanf("%d", &pjur->telefone.celular);
    getchar();
    printf("Digite o logradouro do endereço: ");
    scanf("%d", &pjur->endereco.logradouro);
    fflush(stdin);
    getchar();
    printf("Digite o endereço: ");
    fflush(stdin);
    getchar();
    fgets(pjur->endereco.endereco, 50, stdin);
    printf("Digite o numero: ");
    scanf("%d", &pjur->endereco.numero);
    printf("Digite o CEP: ");
    scanf("%",&pjur->endereco.cep);
    printf("Digite o nome da cidade: ");
    fflush(stdin);
    getchar();
    fgets(pjur->endereco.cidade, 50, stdin);
    printf("Digite o estado(2 letras): ");
    scanf("%s", &pjur->endereco.estado);
    gerarCodigo(pfis, pjur, doisum);
  }
}

