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
void apresentarPrioridade();
void pesquisarRestauranteNome();
void pesquisarRestauranteCNPJ();
void pesquisarRestauranteCodigo();
void registrarTelefone();
void registrarEndereco();
void excluirPessoas();
void excluirVoluntarios();
void excluirRestaurantes();
void excluirParceiros();
void setarlogin();
void editarFisica();
void excluirFisica();
void editarVoluntarios();
void excluirVoluntarios();
void editarJuridica();
void excluirJuridica();
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

// MAIN

int main()
{
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
            //menuCadastrar();
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
    int opt;
    printf ("1 - Pessoas\n");
    printf ("2 - Voluntarios\n");
    printf ("3 - Restaurantes\n");
    printf ("4 - Mercados\n");
    printf ("0 - Sair\n");
    printf ("Opcao: ");
    scanf ("%d", &opt);  
}

void menuCadastro()
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
            menuCadastrar(opt);
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
            printf ("Escolhe outra opcao");
            break;
        }
    }while(opt != 0);
}

void menuCadastrar(int opt, pfisica *pfis, vol *volunt, pjuridica *pjur)
{
    switch (opt)
        {
        case 1:
            adicionarPessoas(pfis);
            break;
            
        case 2:
            adicionarVoluntario(volunt);
            break;

        case 3:
            adicionarEstabelecimento(pjur);
            break;

        case 4:
            adicionarEstabelecimento(pjur);
            break;   

        default:
            break;
        }          
}

void menuEditar(int opt){
    switch (opt)
    {
    case 1:
        
        break;
    case 2:

        break;

    case 3:

        break;

    default:
        break;
    }
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
    }while(opt != 0);
}

// FUNÇÃO APRESENTAR INFO

void apresentarInfocpf(pfisica *resul) {
    printf("\nResultados:\n");
    printf("\nNome: %s", resul->nome);
    printf("Sobrenome: %s", resul->sobrenome);
    printf("CPF: %d\n", resul->cpf);
    printf("Código: %d", resul->codigo.codP);
    printf("Data de nascimento: %d/%d/%d", resul->data.dia, resul->data.mes, resul->data.ano);
    printf("telefones: Fixo (%d) %d, Celular (%d) %d ", resul->telefone.ddd,resul->telefone.fixo,resul->telefone.ddd, resul->telefone.celular );
    printf("Endereco: %s %s %s %s %s numero: %s", resul->endereco.estado,resul->endereco.cidade, resul->endereco.cep, resul->endereco.logradouro, resul->endereco.numero);
    printf("\n");
}

void apresentarInfocnpj(pjuridica *resul) {
    printf("\nResultados:\n");
    printf("\nNome: %s", resul->nome);
    printf("Sobrenome (caso seja pessoa): %s", resul->sobrenome);
    printf("CNPJ: %d\n", resul->cnpj);
    printf("Codigo: %d", resul->codigo.codE);
    printf("telefones: Fixo (%d) %d, Celular (%d) %d ", resul->telefone.ddd,resul->telefone.fixo,resul->telefone.ddd, resul->telefone.celular );
    printf("Endereco: %s %s %s %s %s numero: %s", resul->endereco.estado,resul->endereco.cidade, resul->endereco.cep, resul->endereco.logradouro, resul->endereco.numero);
    printf("\n");
}

// FUNÇÃO ADICIONAR INFOS

void adicionar(pfisica *pfis, vol *voluntario) {
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
    adicionarPrioridade(pfis);
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
    gerarCodigo(pfis);
}

void adicionarPessoas(pfisica *pfis) {
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
    adicionarPrioridade(pfis);
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
    gerarCodigo(pfis);
}

  // PESQUISAR CPF
void pesquisarPessoaNome(pfisica *pessoas, char pesquisa[50], int contador) {
    pfisica resul;
    for (int i = 0; i < contador; i++) {
        if (strcmp(pessoas[i].nome,pesquisa) == 1) {
            resul = pessoas[i];
            apresentarInfocpf(&resul);
        }
    }
    };

void pesquisarPessoaSobrenome(pfisica *pessoas, char pesquisa[50], int contador) {
    pfisica resul;
    for (int i = 0; i < contador; i++) {
        if (strcmp(pessoas[i].sobrenome,pesquisa) == 1) {
            resul = pessoas[i];
            apresentarInfocpf(&resul);
        }
    }
    };
void pesquisarPessoaCPF(pfisica *pessoas, int pesquisa, int contador) {
    pfisica resul;
    for (int i = 0; i < contador; i++) {
        if (pessoas[i].cpf == pesquisa) {
            resul = pessoas[i];
            apresentarInfocpf(&resul);
        }
    }
    };
void pesquisarPessoaData(pfisica *pessoas, int dia, int mes, int ano, int contador) {
    pfisica resul;
    for (int i = 0; i < contador; i++) {    
        if (pessoas[i].data.dia == dia && pessoas[i].data.mes == mes && pessoas[i].data.ano == ano) {
            resul = pessoas[i];
            apresentarInfocpf(&resul);
        }
    }
    };
void pesquisarPessoaPrioridade(pfisica *pessoas, int pesquisa, int contador) {
    pfisica resul;
    for (int i = 0; i < contador; i++) {
        if (pessoas[i].priori == pesquisa) {
            resul = pessoas[i];
            apresentarInfocpf(&resul);
        }          
    }
}    
void pesquisarPessoaCodigo(pfisica *pessoas, char pesquisa[50], int contador) {
    pfisica resul;
    for (int i = 0; i < contador; i++) {
        if (pessoas[i].codigo.codP == pesquisa) {
            resul = pessoas[i];
            apresentarInfocpf(&resul);
        }
    }
}
void pesquisarPessoaGenero(pfisica *pessoas, char pesquisa[50], int contador){
    pfisica resul;
    for (int i = 0; i < contador; i++) {
        if (strcmp(pessoas[i].genero,pesquisa) == 1) {
            resul = pessoas[i];
            apresentarInfocpf(&resul);
        }
    }
    };
void setarPrioridade(pfisica *prioridade){
    printf("Tabela de prioridade:");
    printf("Digite a prioridade: ");
    scanf("%d", prioridade->priori);
}
void imprimirPrioridade(pfisica *prioridade){
    printf("\n%d", prioridade->priori);
}

//  PESQUISAR CNPJ
void pesquisarRestauranteNome(pjuridica *restaurantes, char pesquisa[50], int contador) {
    pjuridica resul;
    for (int i = 0; i < contador; i++) {
        if (strcmp(restaurantes[i].nome,pesquisa)==1) {
            resul = restaurantes[i];
            apresentarInfocnpj(&resul);
        }
    }
}
void pesquisarRestauranteCNPJ(pjuridica *restaurantes, int pesquisa, int contador) {
    pjuridica resul;
    for (int i = 0; i < contador; i++) {
        if (restaurantes[i].cnpj == pesquisa) {
            resul = restaurantes[i];
            apresentarInfocnpj(&resul);
        }
    }
}
void pesquisarRestauranteCodigo(pjuridica *restaurantes, int pesquisa, int contador) {
    pjuridica resul;
    for (int i = 0; i < contador; i++) {
        if (restaurantes[i].codigo.codE == pesquisa) {
            resul = restaurantes[i];
            apresentarInfocnpj(&resul);
        }
    }
}

// PESQUISAR VOLUNTARIOS
void pesquisarVoluntariosNome(vol *voluntarios, char pesquisa[50], int contador) {
    vol resul;
    for (int i = 0; i < contador; i++) {
        if (strcmp(voluntarios[i].nome,pesquisa) == 1) {
            resul = voluntarios[i];
            apresentarInfocpf(&resul);
        }
    }
    };

void pesquisarVoluntariosSobrenome(vol *voluntarios, char pesquisa[50], int contador) {
    vol resul;
    for (int i = 0; i < contador; i++) {
        if (strcmp(voluntarios[i].sobrenome,pesquisa) == 1) {
            resul = voluntarios[i];
            apresentarInfocpf(&resul);
        }
    }
    };
void pesquisarVoluntariosCPF(vol *voluntarios, int pesquisa, int contador) {
    vol resul;
    for (int i = 0; i < contador; i++) {
        if (voluntarios[i].cpf == pesquisa) {
            resul = voluntarios[i];
            apresentarInfocpf(&resul);
        }
    }
    };
void pesquisarVoluntariosData(vol *voluntarios, int dia, int mes, int ano, int contador) {
    vol resul;
    for (int i = 0; i < contador; i++) {    
        if (&voluntarios[i].data.dia == dia && voluntarios[i].data.mes == mes && voluntarios[i].data.ano == ano) {
            resul = voluntarios[i];
            apresentarInfocpf(&resul);
        }
    }
    };
void pesquisarVoluntariosPrioridade(vol *voluntarios, int pesquisa, int contador) {
    vol resul;
    for (int i = 0; i < contador; i++) {
        if (voluntarios[i].priori == pesquisa) {
            resul = voluntarios[i];
            apresentarInfocpf(&resul);
        }          
    }
}    
void pesquisarVoluntariosCodigo(vol *voluntarios, char pesquisa[50], int contador) {
    vol resul;
    for (int i = 0; i < contador; i++) {
        if (voluntarios[i].codigo.codP == pesquisa) {
            resul = voluntarios[i];
            apresentarInfocpf(&resul);
        }
    }
}
void pesquisarVoluntariosGenero(vol *voluntarios, char pesquisa[50], int contador){
    vol resul;
    for (int i = 0; i < contador; i++) {
        if (strcmp(voluntarios[i].genero,pesquisa) == 1) {
            resul = voluntarios[i];
            apresentarInfocpf(&resul);
        }
    }
};
void setarlogin(login *login){
    printf("Defina o login: "); 
    scanf("%s", login->login);
    printf("Defina a senha: "); 
    scanf("%s", login->senha);
}
void editarVoluntarios(vol *voluntarios, int contador){

}
void excluirVoluntarios(vol *voluntarios, int contador){


}
void editarPessoas(pfisica *fisica, int contador){

}
void excluirPessoas(pfisica *fisica, int contador){

}
void editarRestaurantes(pjuridica *juridica, int contador){

}
void excluirRestaurantes(pjuridica *juridica, int contador){

}