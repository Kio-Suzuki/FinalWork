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

typedef struct cadastro{
    int cpf;
    int cnpj;
}cada;

typedef struct data{
    int dia;
    int mes;
    int ano;
}data;

typedef struct codigoPessoa{
    int codP[10];
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
    char genero;
    cada cpf;
    data data;
    end endereco;
    tel telefone;
}vol;

typedef struct cdadosPessoaisFisica{
    char nome[50];
    char genero;
    cada cpf;
    int priori;
    int idade;
    data nascimento;
    end endereco;
    tel telefone;
    cod_p cod;
}pfisica;

typedef struct doacao{
    int quantidade;
    char info[100];
    data data;
}doa;

typedef struct dadosRestaurantes{
    cod_e codigo;
    char nome[50];
    cada cnpj;
    end endereco;
    tel telefone;
    doa doacao;
}rest;

void apresentarMenu();
pfisica cadastrarPessoa(void);
rest cadastrarRestaurante(void);
vol cadastrarVoluntario(void);
void gerarCodigo (int codU[10]);
void addComida();
void retComida();


int main()
{
    pfisica p1;
    rest r1;
    vol v1;
    apresentarMenu(p1, r1, v1);
    return 0;
}

void apresentarMenu(pfisica p1, rest r1, vol v1) {
  int opt, refei;
  printf("\nMENU\n");
  printf("1 - Administrador\n");
  printf("2 - Visitante\n");
  printf("3 - Sair\n");
  printf("Opcao: ");
  scanf("%d", &opt);
  switch (opt) {
  case 1:
    do {
      printf("\n1 - Cadastrar pessoa\n");
      printf("2 - Cadastrar voluntario\n");
      printf("3 - Cadastrar Restaurante\n");
      printf("4 - Consultar refeições\n");
      printf("0 - Sair\n");
      printf("Opcao: ");
      scanf("%d", &opt);
      switch (opt) {
      case 1:
        p1 = cadastrarPessoa();
        break;

      case 2:
        v1 = cadastrarVoluntario();
        break;

      case 3:
        r1 = cadastrarRestaurante();
        break;
      case 4:
         printf("\nNumero de refeições disponiveis: %d", n);
         printf("Digite 1 para adiconar refeições");
         printf("Digite 2 para retirar refeiçoes");
         scanf("%d", &refei);
         if(){
            
         }else if{}{

         }
      case 0:
        printf("Ate mais!");
        break;
      default:
        printf("Escolha outra opcao");
        break;
      }
    } while (opt == 1 || opt == 2);
    break;

  case 2:
    printf("\nPESQUISAR RESTAURANTE\n");
    printf("1 - Nome");
    printf("2 - Local");
    printf("Opcao: ");
    scanf("%d", &opt);

  default:
    printf("Escolha outra opcao");
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
    scanf("%s", &nome);
    sprintf(filename, "Pessoa %s.txt", nome);
    fp = fopen(filename,"w");
    mostrarPriori();
    gerarCodigo(p.cod.codP);
    printf ("\nNome completo: ");
    fflush(stdin);
    fgets (p.nome, 50, stdin);
    printf ("Genero: ");
    scanf ("%c", &p.genero);
    printf ("CPF: ");
    p.cpf.cpf=0;
    scanf ("%ld", &p.cpf.cpf);
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
    printf ("Telefone: ");
    scanf ("%d", &p.telefone.fixo);
    printf ("Celular: ");
    scanf ("%d", &p.telefone.celular);
    printf("Prioridade: ");
    scanf("%d", &p.priori);
    printf ("Cadastro realizado com sucesso!\n");
    fprintf(fp, "Nome: %sGênero: %c\nCPF: %ld\nData de nascimento %d/%d/%d\nLogradouro: %sNúmero:%d\nCEP: %d\nCidade: %sEstado: %sTelefone (%d) %d\nCelular (%d) %d \n Código: %d \n Prioridade: %d", p.nome, p.genero, p.cpf,  p.nascimento.dia, p.nascimento.mes, p.nascimento.ano, p.endereco.logradouro, p.endereco.numero, p.endereco.cep, p.endereco.cidade, p.endereco.estado, p.telefone.ddd, p.telefone.fixo, p.telefone.ddd, p.telefone.celular, p.cod.codP, p.priori );
    fclose(fp);
    return p;
}

rest cadastrarRestaurante(void)
{
    rest r;
    FILE *fp;
    char nome[50];
    char filename[50];
    printf("\0 Digite o nome do arquivo: ");
    scanf("%s", &nome);
    sprintf(filename, "Restaurante %s.txt", nome);
    printf("%s", filename);
    fp = fopen(filename, "w");
    printf ("\nNome: ");
    fflush(stdin);
    fgets (r.nome, 50, stdin);
    printf ("CNPJ: ");
    r.cnpj.cnpj = 0;
    scanf ("%ld", &r.cnpj);
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
    printf ("Telefone: ");
    scanf ("%d", &r.telefone.fixo);
    printf ("Celular: ");
    scanf ("%d", &r.telefone.celular);
    printf ("Cadastro realizado com sucesso!\n");
    fprintf(fp, "Nome: %sCNPJ: %ld\nLogradouro: %sNumero:%d\nCEP: %d\nCidade: %sEstado: %sTelefone (%d) %d\nCelular (%d) %d", r.nome, r.cnpj, r.endereco.logradouro, r.endereco.numero, r.endereco.cep, r.endereco.cidade, r.endereco.estado, r.telefone.ddd, r.telefone.fixo, r.telefone.ddd, r.telefone.celular);
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
    scanf("%s", &nome);
    sprintf(filename, "Voluntario%s.txt", nome);
    fp = fopen(filename,"w");
    printf ("\nNome completo: ");
    fflush(stdin);
    fgets (v.nome, 50, stdin);
    printf ("Genero: ");
    scanf ("%c", &v.genero);
    printf ("CPF: ");
    v.cpf.cpf=0;
    scanf ("%ld", &v.cpf.cpf);
    printf ("Nascimento\n");
    printf ("Dia: ");
    scanf ("%d", &v.data.dia);
    printf ("Mes: ");
    scanf ("%d", &v.data.mes);
    printf ("Ano: ");
    scanf ("%d", &v.data.ano);
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
    printf ("Telefone: ");
    scanf ("%d", &v.telefone.fixo);
    printf ("Celular: ");
    scanf ("%d", &v.telefone.celular);
    printf ("Cadastro realizado com sucesso!\n");
    fprintf(fp, "Nome: %sGênero: %c\nCPF: %ld\nData de nascimento %d/%d/%d\nLogradouro: %sNúmero:%d\nCEP: %d\nCidade: %sEstado: %sTelefone (%d) %d\nCelular (%d) %d", v.nome, v.genero, v.cpf,  v.data.dia, v.data.mes, v.data.ano, v.endereco.logradouro, v.endereco.numero, v.endereco.cep, v.endereco.cidade, v.endereco.estado, v.telefone.ddd, v.telefone.fixo, v.telefone.ddd, v.telefone.celular);
    fclose(fp);
    return v;
}
void gerarCodigo(int codU[10])
{
    int cod[10][10], i, j, cont = 0; 
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
}
int mostrarPriori(){
    printf("\nPrioridade 1 (menos vulnerável): Famílias de baixa renda com moradia e sem filhos.\n");
    printf("Prioridade 2: Famílias de baixa renda com moradia e com filhos de qualquer idade.\n");
    printf("Prioridade 3: Famílias/Indivíduos adultos sem filhos em situação de rua.\n");
    printf("Prioridade 4: Famílias com filhos com idade entre 10 e 16 anos em situação de rua.\n");
    printf("Prioridade 5 (mais vulnerável): Famílias com filhos com idade menor de 10 anos de idade e em situação de rua.\n");
}
void addComida(){
   
}
void retComida(){

}