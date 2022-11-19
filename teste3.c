#define _gnu_source
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

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
    int contador=1;
    vol *voluntario = malloc(contador*sizeof(vol));
    pjuridica *juridica = malloc(contador*sizeof(pjuridica));
    pfisica *fisica = malloc(contador*sizeof(pfisica));

    menuPrincipal(voluntario, juridica, fisica, contador);
    return 0;
}

void menuPrincipal(vol *voluntario, pfisica *fisica, pjuridica *juridica, int contador) // precisa receber login e senha
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
                menuAdmin(voluntario, juridica, fisica, contador);
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
    return 0;
};

void menuAdmin(vol *voluntario, pfisica *fisica, pjuridica *juridica, int contador)
{
    int opt;
    do{
        printf ("MENU ADMINISTRADOR\n");                              
        printf ("1 - Cadastramento\n");      
        printf ("2 - Pesquisa\n");
        printf ("0 - Sair\n");
        printf ("Opcao: ");           
        scanf ("%d", &opt);
        switch (opt)
        {
        case 1:
            opt=imprimeOpcoes(voluntario, juridica, fisica, contador);
            contador++
            adicionarPessoas(fisica);
            break;
    
        case 2:
            opt=imprimeOpcoes(voluntario, juridica, fisica, contador);
            pesquisarPessoas(fisica, contador);

        default:
            break;
        }    
    }while(opt != 0);
}

void adicionarPessoas(pfisica *fisica) {
    fflush(stdin);
    printf("Nome: ");
    getchar();
    //scanf("%s", fisica.nome);
    //fflush(stdin);
    fgets(fisica->nome, 50, stdin);
    printf("Sobrenome: ");
    fgets(fisica->sobrenome, 50, stdin);
    printf("Genero: ");
    scanf("%c", &fisica->genero);
    printf("CPF: "); //
    scanf("%d", &fisica->cpf);
    //adicionarPrioridade(fisica);
    printf("Dia do nascimento: ");
    scanf("%d", &fisica->data.dia);
    printf("Mes do nascimento: ");
    scanf("%d", &fisica->data.mes);
    printf("Ano de nascimento: ");
    scanf("%d", &fisica->data.ano);
    printf("DDD do telefone: ");
    scanf("%d", &fisica->telefone.ddd);
    printf("Telefone fixo (Digite 0 caso nao tenha): ");
    scanf("%d", &fisica->telefone.fixo);
    printf("Telefone celular (Digite 0 caso nao tenha): ");
    scanf("%d", &fisica->telefone.celular);
    printf("Logradouro do endereço: ");
    fflush(stdin);
    getchar();
    fgets(fisica->endereco.logradouro, 50, stdin);
    printf("Numero da casa: ");
    scanf("%d", &fisica->endereco.numero);
    printf("CEP: ");
    scanf("%d", &fisica->endereco.cep);
    printf("Nome da cidade: ");
    fflush(stdin);
    getchar();
    fgets(fisica->endereco.cidade, 50, stdin);
    printf("Estado(2 letras): ");
    scanf("%s", fisica->endereco.estado);
    //gerarCodigo(fisica);
}
void pesquisarPessoas(pfisica *fisica, int contador)
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
        printf ("Opcao: ");
        scanf ("%d", &opt);       
        switch (opt)
        {
        case 1:
            printf ("Digite o nome: ");
            fgets (nome,50, stdin);
            pesquisarPessoaNome(fisica, contador, nome);
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
            //menuPesquisar();
                
        default:
            break;
        }
    }while(opt != 0);
}

void pesquisarPessoaNome(pfisica *fisica, int contador, char pesquisa[50]) {
    pfisica *resul;
    for (int i = 0; i < contador; i++) {
        if (strcmp(fisica[i].nome,pesquisa) == 1) {
            resul = &fisica[i];
            apresentarInfocpf(resul, i);
        }
    }
}

void apresentarInfocpf(pfisica *fisica, int pos) {
    printf("\nResultados:\n");
    printf("\nNome: %s\n", fisica->nome);
    printf("Sobrenome: %s\n", fisica->sobrenome);
    printf("CPF: %d\n", fisica->cpf);
    printf("Código: %d\n", fisica->codigo.codP);
    printf("Data de nascimento: %d/%d/%d\n", fisica->data.dia, fisica->data.mes, fisica->data.ano);
    printf("telefones: Fixo (%d) %d, Celular (%d) %d\n", fisica->telefone.ddd,fisica->telefone.fixo,fisica->telefone.ddd, fisica->telefone.celular );
    printf("Endereco: %s %s %d %s  numero: %d\n", fisica->endereco.estado,fisica->endereco.cidade, fisica->endereco.cep, fisica->endereco.logradouro, fisica->endereco.numero);
    printf("Posição no vetor: %d\n", pos);
    printf("\n");
}