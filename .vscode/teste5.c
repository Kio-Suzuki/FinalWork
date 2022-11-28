#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <io.h>
#include <conio.h>
#include <process.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
}data;

typedef struct codigoPessoa{
    int cod;
}cod_p;

typedef struct codigoEstabelecimento{
    int codE;
}cod_e;

typedef struct telefone{
    int ddd;
    int fixo;
    int celular;
}tel;

typedef struct endereco{
    char logradouro[50];
    int numero;
    int cep;
    char cidade[50];
    char estado[10]; 
}end;

typedef struct dadosVoluntario{
    cod_p codigo;
    char nome[50];
    char sobrenome[50];
    char cpf[20];
    char genero;
    data nascimento;
    end endereco;
    tel telefone;
}vol;

typedef struct cdadosPessoaisFisica{
    cod_p id;
    char nome[50];
    char genero;
    char cpf[20];
    int priori;
    int idade;
    data nascimento;
    end endereco;
    tel telefone;
}pfisica;

typedef struct doacao{
    int quantidade;
    char info[100];
    data data;
}doa;

typedef struct dadosRestaurantes{
    cod_e codigo;
    char nome[50];
    char cnpj[30];
    end endereco;
    tel telefone;
    doa doacao;
}rest;

void apresentarMenu();
pfisica cadastrarPessoa(void);
vol cadastrarVoluntario(void);
rest cadastrarRestaurante(void);
pfisica apresentarPessoa(void);
vol apresentarVoluntario(void);
rest apresentarRestaurante(void);
void apresentarPrioridade();

int main()
{
    apresentarMenu();
    return 0;
}

void apresentarMenu()
{
    int opt;
    printf ("\nMENU\n");
    printf ("1 - Administrador\n");
    printf ("2 - Visitante\n");
    printf ("3 - Sair\n");
    printf ("Opcao: ");
    scanf ("%d", &opt);
    switch (opt)
    {
    case 1:
        do{
            printf ("\n1 - Cadastrar Pessoa\n");
            printf ("2 - Cadastrar Voluntario\n");
            printf ("3 - Cadastrar Restaurante\n");
            printf ("4 - Pesquisar Pessoa\n");
            printf ("5 - Pesquisar Voluntario\n");
            printf ("6 - Pesquisar Restaurante\n");
            printf ("0 - Sair\n");
            printf ("Opcao: ");
            scanf ("%d", &opt);
            switch (opt)
            {
            case 1:
                cadastrarPessoa();
                break;

            case 2:
                cadastrarVoluntario();
                break;

            case 3:
                cadastrarRestaurante();
                break;

            case 4:
                apresentarPessoa();
                break;

            case 5:
                apresentarVoluntario();
                break;

            case 6:
                apresentarRestaurante();
                break;
            
            case 0:
                printf ("Ate mais!");
                break;

            default:
                printf ("Escolha outra opcao");
                break;
            }
        }while(opt >= 1 && opt <= 6);
            break;
    
    case 2:
        printf ("\nPESQUISAR RESTAURANTE\n");
        printf ("1 - Nome");
        printf ("2 - Local");
        printf ("Opcao: ");
        scanf ("%d", &opt);
    
    default:
        printf ("Escolha outra opcao");
        break;
    }
}

pfisica cadastrarPessoa(void) 
{
    pfisica p;
    FILE *fp;
    char nome[50];
    char filename[50];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);
    sprintf(filename, "Pessoa %s.txt", nome);
    fp = fopen(filename,"w");
    printf ("\nNome completo: ");
    fflush(stdin);
    fgets (p.nome, 50, stdin);
    printf ("CPF: ");
    fflush(stdin);
    fgets (p.cpf, 20, stdin);
    printf ("Genero: ");
    scanf (" %c", &p.genero);
    printf ("Nascimento\n");
    printf ("Dia: ");
    scanf ("%d", &p.nascimento.dia);
    printf ("Mes: ");
    scanf ("%d", &p.nascimento.mes);
    printf ("Ano: ");
    scanf ("%d", &p.nascimento.ano);
    printf ("Endereco (caso não tenha digite 0 nas perguntas seguintes)\n");
    printf ("Rua: ");
    fflush(stdin);
    fgets (p.endereco.logradouro, 50, stdin);
    printf ("Numero: ");
    scanf ("%d", &p.endereco.numero);
    printf ("CEP: ");
    scanf ("%d", &p.endereco.cep);
    printf ("Cidade: ");
    fflush(stdin);
    fgets (p.endereco.cidade, 50, stdin);
    printf ("Estado (2 letras): ");
    fflush(stdin);
    fgets (p.endereco.estado, 10, stdin);
    printf ("Telefone (caso não tenha digite 0 nas opções seguintes)\n");
    printf ("DDD: ");
    scanf ("%d", &p.telefone.ddd);
    printf ("Telefone fixo: ");
    scanf ("%d", &p.telefone.fixo);
    printf ("Celular: ");
    scanf ("%d", &p.telefone.celular);
    apresentarPrioridade();
    printf ("Prioridade: ");
    scanf ("%d", &p.priori);
    printf ("Cadastro realizado com sucesso!\n");
    fprintf(fp, "Nome: %sGênero: %c\nCPF: %sData de nascimento %d/%d/%d\nLogradouro: %sNúmero:%d\nCEP: %d\nCidade: %sEstado: %sTelefone (%d) %d\nCelular (%d) %d\nPrioridade: %d", p.nome, p.genero, p.cpf,  p.nascimento.dia, p.nascimento.mes, p.nascimento.ano, p.endereco.logradouro, p.endereco.numero, p.endereco.cep, p.endereco.cidade, p.endereco.estado, p.telefone.ddd, p.telefone.fixo, p.telefone.ddd, p.telefone.celular, p.priori);
    fclose(fp);
    return p;
}

rest cadastrarRestaurante(void)
{
    rest r;
    FILE *fp;
    char nome[50];
    char filename[50];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);
    sprintf(filename, "Restaurante %s.txt", nome);
    printf("%s", filename);
    fp = fopen(filename, "w");
    printf ("\nNome: ");
    fflush(stdin);
    fgets (r.nome, 50, stdin);
    printf ("CNPJ: ");
    fflush(stdin);
    fgets (r.cnpj, 30, stdin);
    printf ("Endereco\n");
    printf ("Rua: ");
    fflush(stdin);
    fgets (r.endereco.logradouro, 50, stdin);
    printf ("Numero: ");
    scanf ("%d", &r.endereco.numero);
    printf ("CEP: ");
    scanf ("%d", &r.endereco.cep);
    printf ("Cidade: ");
    fflush(stdin);
    fgets (r.endereco.cidade, 50, stdin);
    printf ("Estado (2 letras): ");
    fflush(stdin);
    fgets (r.endereco.estado, 10, stdin);
    printf ("Telefone\n");
    printf ("DDD: ");
    scanf ("%d", &r.telefone.ddd);
    printf ("Telefone fixo: ");
    scanf ("%d", &r.telefone.fixo);
    printf ("Celular: ");
    scanf ("%d", &r.telefone.celular);
    printf ("Cadastro realizado com sucesso!\n");
    fprintf(fp, "Nome: %sCNPJ: %sLogradouro: %sNumero:%d\nCEP: %d\nCidade: %sEstado: %sTelefone (%d) %d\nCelular (%d) %d", r.nome, r.cnpj, r.endereco.logradouro, r.endereco.numero, r.endereco.cep, r.endereco.cidade, r.endereco.estado, r.telefone.ddd, r.telefone.fixo, r.telefone.ddd, r.telefone.celular);
    fclose(fp);
    return r;
}

vol cadastrarVoluntario(void) 
{
    vol v;
    FILE *fp;
    char nome[50];
    char filename[50];
    printf("Digite o nome: ");
    scanf("%s", nome);
    sprintf(filename, "Voluntario %s.txt", nome);
    fp = fopen(filename,"w");
    printf ("\nNome completo: ");
    fflush(stdin);
    fgets (v.nome, 50, stdin);
    printf ("CPF: ");
    fflush(stdin);
    fgets (v.cpf, 20, stdin);
    printf ("Genero: ");
    scanf ("%c", &v.genero);
    printf ("Nascimento\n");
    printf ("Dia: ");
    scanf ("%d", &v.nascimento.dia);
    printf ("Mes: ");
    scanf ("%d", &v.nascimento.mes);
    printf ("Ano: ");
    scanf ("%d", &v.nascimento.ano);
    printf ("Endereco\n");
    printf ("Rua: ");
    fflush(stdin);
    fgets (v.endereco.logradouro, 50, stdin);
    printf ("Numero: ");
    scanf ("%d", &v.endereco.numero);
    printf ("CEP: ");
    scanf ("%d", &v.endereco.cep);
    printf ("Cidade: ");
    fflush(stdin);
    fgets (v.endereco.cidade, 50, stdin);
    printf ("Estado (2 letras): ");
    fflush(stdin);
    fgets (v.endereco.estado, 10, stdin);
    printf ("Telefone\n");
    printf ("DDD: ");
    scanf ("%d", &v.telefone.ddd);
    printf ("Telefone fixo: ");
    scanf ("%d", &v.telefone.fixo);
    printf ("Celular: ");
    scanf ("%d", &v.telefone.celular);
    printf ("Cadastro realizado com sucesso!\n");
    fprintf(fp, "Nome: %sCPF: %sGênero: %c\nData de nascimento %d/%d/%d\nLogradouro: %sNúmero:%d\nCEP: %d\nCidade: %sEstado: %sTelefone (%d) %d\nCelular (%d) %d", v.nome, v.cpf, v.genero,  v.nascimento.dia, v.nascimento.mes, v.nascimento.ano, v.endereco.logradouro, v.endereco.numero, v.endereco.cep, v.endereco.cidade, v.endereco.estado, v.telefone.ddd, v.telefone.fixo, v.telefone.ddd, v.telefone.celular);
    fclose(fp);
    return v;
}

pfisica apresentarPessoa(void)
{
    pfisica p;
    FILE *fp;
    char nome[50];
    char filename[50];
    char linha[200];
    printf("Digite o nome: ");
    scanf("%s", nome);
    printf("\n");
    sprintf(filename, "Pessoa %s.txt", nome);
    fp = fopen(filename,"r");
    if (fp){
        while(!feof(fp)){
            fgets(linha, 200, fp);
            puts(linha);
        }
    }else{
        printf ("Falha ao abrir o arquivo");
    }
    fclose(fp);
    return p;
}

vol apresentarVoluntario(void)
{
    vol v;
    FILE *fp;
    char nome[50];
    char filename[50];
    char linha[200];
    printf("Digite o nome: ");
    scanf("%s", nome);
    sprintf(filename, "Voluntario %s.txt", nome);
    fp = fopen(filename,"r");
    if (fp){
        while(!feof(fp)){
            fgets(linha, 200, fp);
            puts(linha);
        }
    }else{
        printf ("Falha ao abrir o arquivo");
    }
    fclose(fp);
    return v;
}

rest apresentarRestaurante(void)
{
    rest r;
    FILE *fp;
    char nome[50];
    char filename[50];
    char linha[200];
    printf("Digite o nome: ");
    scanf("%s", nome);
    sprintf(filename, "Pessoa %s.txt", nome);
    fp = fopen(filename,"r");
    if (fp){
        while(!feof(fp)){
            fgets(linha, 200, fp);
            puts(linha);
        }
    }else{
        printf ("Falha ao abrir o arquivo");
    }
    fclose(fp);
    return r;
}

void apresentarPrioridade()
{
    printf("\nPrioridade 1 (menos vulnerável): Famílias de baixa renda com moradia e sem filhos.\n");
    printf("Prioridade 2: Famílias de baixa renda com moradia e com filhos de qualquer idade.\n");
    printf("Prioridade 3: Famílias/Indivíduos adultos sem filhos em situação de rua.\n");
    printf("Prioridade 4: Famílias com filhos com idade entre 10 e 16 anos em situação de rua.\n");
    printf("Prioridade 5 (mais vulnerável): Famílias com filhos com idade menor de 10 anos de idade e em situação de rua.\n");
}