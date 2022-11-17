#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

void gerarCodigo();
void menuPrincipal();
int imprimeOpcoes();
void menuCadastro();
void menuCadastrar();
void menuEditar();
void menuPesquisar();
void adicionarPessoas();
void dicionarEstabelecimento();
void pesquisarPessoas();
void pesquisarVoluntarios();
void pesquisarRestaurantes();
void apresentarInfocpf();
void apresentarInfocnpj();
void pesquisarPessoaNome();
void pesquisarPessoaSobrenome();
void pesquisarPessoaCPF();
void pesquisarPessoaGenero();
void setarPrioridade();

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
    data data;
    end endereco;
    tel telefone;
}pfisica;

typedef struct dadosVoluntario{
    cod_p codigo;
    char nome[50];
    char sobrenome[50];
    char genero;
    int cpf;
    int priori;
    data data;
    end endereco;
    tel telefone;
}vol;

// Cadastro de restaurantes, mercados, pessoas juridicas.

typedef struct doacao{
    int quantidade;
    char info[100];
    data data;
}doa;

typedef struct dadosPessoaisJuridica{
    cod_e codigo;
    char nome[50];
    char sobrenome[50];
    int cnpj;
    end endereco;
    tel telefone;
    doa doacao;
}pjuridica;

typedef struct dadosFamilias{
    cod_p codigo;
    char nome[50];
    char sobrenome[50];
    int cpf;
    int priori;
    data data;
    end endereco;
    tel telefone;
    int membros;
}fam;

int main()
{
    menuPrincipal();
    return 0;
}

void menuPrincipal() // precisa receber login e senha
{
    int opt, compl, comps;
    char login1[20], senha1[10], login2[20], senha2[10];
    do{
        printf ("\n1 - Admin\n");
        printf ("2 - Visitante\n");
        printf ("0 - Sair\n");
        printf ("Opcao: ");
        scanf ("%d", &opt);
        switch (opt)
        {
        case 1:
            printf ("Login: ");
            scanf ("%s", login1);
            printf ("Senha: ");
            scanf ("%s", senha1);
            strcpy(login1, login2);
            strcpy(senha1, senha2);
            compl = strcmp(login1, login2);
            comps = strcmp(senha1, senha2);
            if(compl == 0 && comps == 0){
                menuAdmin();
            }else{
                printf ("Senha incorreta, tente novamente");
            }
            break;
        
        case 2:
            printf ("Pesquisar restaurantes: \n");
            printf ("1 - Endereco\n");
            printf ("2 - Refeicoes\n");
            break;
        }
    }while(opt != 0);
}

int imprimeOpcoes()
{
    int opt;
    printf ("1 - Pessoas\n");
    printf ("2 - Voluntarios\n");
    printf ("3 - Restaurantes\n");
    printf ("4 - Mercados\n");
    printf ("0 - Sair\n");
    printf ("Opcao: ");
    scanf ("%d", &opt);  
}

void menuAdmin()
{
    int opt;
    do{
        printf ("MENU ADMINISTRADOR\n");                              
        printf ("1 - Cadastramento\n");      
        printf ("2 - Pesquisa\n");
        printf ("0 - Sair\n");
        scanf ("Opcao: ");           
        scanf ("%d", &opt);
        switch (opt)
        {
        case 1:
            opt=imprimeOpcoes();
            adicionarPessoas();
            break;
        case 2:
            opt=imprimeOpcoes();
            break;
        
        default:
            break;
        }    
    }while(opt != 0);
}

void adicionarPessoas() {
    pfisica *pfis;
    fflush(stdin);
    printf("Digite o nome da pessoa: ");
    getchar();
    fgets(pfis->nome, 50, stdin);
    printf("Digite o sobrenome da pessoa: ");
    fgets(pfis->sobrenome, 50, stdin);
    printf("Digite o genero: ");
    scanf("%c", &pfis->genero);
    printf("Digite o cpf: ");
    scanf("%d", &pfis->cpf);
    //adicionarPrioridade(pfis);
    printf("Digite o dia de nascimento: ");
    scanf("%d",&pfis->data.dia);
    printf("Digite o mes de nascimento: ");
    scanf("%d",&pfis->data.mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d",&pfis->data.ano);
    printf("Digite o DDD do telefone: ");
    scanf("%d",&pfis->telefone.ddd);
    printf("Digite o telefone fixo: ");
    scanf("%d", &pfis->telefone.fixo);
    printf("Digite o telefone celular: ");
    scanf("%d", &pfis->telefone.celular);
    printf("Digite o logradouro do endereço: ");
    fflush(stdin);
    getchar();
    fgets(pfis->endereco.logradouro, 50, stdin);
    printf("Digite o numero: ");
    scanf("%d", &pfis->endereco.numero);
    printf("Digite o CEP: ");
    scanf("%d", &pfis->endereco.cep);
    printf("Digite o nome da cidade: ");
    fflush(stdin);
    getchar();
    fgets(pfis->endereco.cidade, 50, stdin);
    printf("Digite o estado(2 letras): ");
    scanf("%s", &pfis->endereco.estado);
    //gerarCodigo(pfis);
}