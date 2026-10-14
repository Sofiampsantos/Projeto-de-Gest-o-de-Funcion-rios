#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define MAX 30
 
typedef struct {
  int dia, mes, ano;
}tdata;
 
struct Funcionario{
    int num_func;
    char nome[30];
    int genero;
    tdata data;
    int depart;
    int cargo;
    float salario;
};
 
    int menu(int i);
    int submenu(int i);
    void pedir(struct Funcionario *vetor_funci, int i);
    void ordenar(struct Funcionario *vetor_funci, int i);
    void mostrar(struct Funcionario *vetor_funci, int i);
    void funci_dep(struct Funcionario *vetor_funci, int i);
    void funci_car(struct Funcionario *vetor_funci, int i);
    void procu_nome(struct Funcionario *vetor_funci, int i);
    void estatistica(struct Funcionario *vetor_funci, int i);
    void remover(struct Funcionario *vetor_funci, int *i);
    void contagem(struct Funcionario *vetor_funci, int i);
    void escrever_dados(struct Funcionario *vetor_funci, int i);
    void leitura(struct Funcionario *vetor_funci, int *i);
    void backup(struct Funcionario *vetor_funci, int i);
 
 
int main(){
    system("color 3F");
    int op, i=0, op1;
 
    struct Funcionario *vetor_funci=(struct Funcionario *)malloc(MAX*sizeof(struct Funcionario));;
 
    leitura(vetor_funci, &i);

    printf("Ol , Bem vindo ao nosso programa!\n\n");
 
    do{
        op = menu(i);
        switch (op){
        case 1:
            pedir(vetor_funci, i);
            i++;
            break;
        case 2:
            ordenar(vetor_funci, i);
            mostrar(vetor_funci, i);
            break;
        case 3:
        op1 = submenu(i);
            switch (op1){
                case 1:
                funci_dep(vetor_funci,i);
                    break;
                case 2:
                funci_car(vetor_funci,i);
                    break;
                case 3:
                procu_nome(vetor_funci, i);
                    break;
            default:
                break;
            }
        case 4:
            break;
        case 5:
            mostrar(vetor_funci,i);
            break;
        case 6:
            estatistica(vetor_funci,i);
            break;
        case 7:
            remover(vetor_funci,&i);
            break;
        case 8:
            contagem(vetor_funci,i);
            break;
        case 9:
            escrever_dados(vetor_funci,i);
            printf("Sair...\n");
            break;
        case 10:
            leitura(vetor_funci,&i);
            break;
            case 11:
            backup(vetor_funci, i);
            return 0;
        default:
            printf("Op‡Æo inv lida! Tente novamente.\n");
            break;
        }
    } while (op !=0);

    free(vetor_funci);
}
 
int menu(int i){
    int opcao;

    
    system("pause");
    system("cls");
 
    printf("********** MENU **********\n");
    printf("\n1.Registar");
    printf("\n2.Listar");
    printf("\n3.Procurar por departamento, cargo e nome");
    printf("\n4.Dados Estat­sticos");
    printf("\n5.Eliminar");
    printf("\n6.Backup");
    printf("\n0.Sair do Programa");
    printf("\n\t\tTOTAL DE FUNCIONARIOS: %d/%d", i, MAX);
 
    do{
        printf("\n\nEscolha a sua op?’o: ");
        scanf("%d", &opcao);
 
        if (opcao<0 || opcao>6){
            printf("Op‡Æo incorreta! Escolha novamente:");
            scanf("%d", &opcao);
        }
       
    } while (opcao < 0 || opcao > 6);
 
    return opcao;
 
}
 
int submenu(int i){
    int option;
 
    printf("********** PROCURAR UM FUNCIONARIO **********\n");
    printf("\n1.Pelo departamento");
    printf("\n2.Pelo cargo");
    printf("\n3.Pelo nome");
 
     do{
        printf("\n\nEscolha a sua op?’o: ");
        scanf("%d", &option);
 
        if (option<1 || option>3){
            printf("Op?’o incorreta! Escolha novamente:");
            scanf("%d", &option);
        }
       
    } while (option < 1 || option > 3);
 
    return option;
}
 
void pedir(struct Funcionario *vetor_funci, int i){
 
   
        printf("\n********** DADOS DO %d FUNCIONæRIO **********\n\n", i+1);
        fflush(stdin);
        printf("\n\tNõ funcionÿrio: ");
        printf("\n\tNome: ");
        gets(vetor_funci[i].nome);
        fflush(stdin);
 
        do{
            printf("\n\tG?NERO\n\t1.Feminino\n\n\t2.Masculino\n\n\t3.Outro\n\tIndique: ");
            scanf("%d",&vetor_funci[i].genero);
            fflush(stdin);
        } while (vetor_funci[i].genero < 1 || vetor_funci[i].genero > 3);
        printf("\n\tDATA DE NASCIMENTO: ");
        do{
            printf("\n\tDia: ");
            scanf("%d", &vetor_funci[i].data.dia);
            fflush(stdin);
        } while (vetor_funci[i].data.dia < 1 || vetor_funci[i].data.dia > 31);
        do{
            printf("\n\tMes: ");
            scanf("%d", &vetor_funci[i].data.mes);
            fflush(stdin);
        } while (vetor_funci[i].data.mes < 1 || vetor_funci[i].data.mes > 12);
 
        do{
           printf("\n\tAno: ");
           scanf("%d", &vetor_funci[i].data.ano);
           fflush(stdin);
        } while (vetor_funci[i].data.ano < 1900 || vetor_funci[i].data.ano > 2025);
 
        do{
             printf("\n\tDEPARTAMENTO\n\t\t1.Desenvolvimento\n\t\t2.Suporte\n\t\t3.RH\n\t\t4.Finan?as\n\t\tIndique: ");
             scanf("%d", &vetor_funci[i].depart);
             fflush(stdin);
        } while (vetor_funci[i].depart < 1 || vetor_funci[i].depart > 4);
       
        do{
           printf("\n\tCARGO\n\t\t1.Jœnior\n\t\t2.Pleno\n\t\t3.Senior\n\t\t4.L­der\n\t\tIndique: ");
           scanf("%d",&vetor_funci[i].cargo);
           fflush(stdin);
        } while (vetor_funci[i].cargo < 1 || vetor_funci[i].cargo > 4);
 
        printf("\nSalÿrio: ");
        scanf("%f",&vetor_funci[i].salario);
        fflush(stdin);
}
 
void ordenar(struct Funcionario *vetor_funci, int i){
    //metodo bubblesort
 struct Funcionario vetor_temp;
 
    for (int cont = 0; cont < i; cont++){
        for (int  j = 0; j < i; j++){
            if (strcmp(vetor_funci[j].nome, vetor_funci[j + 1].nome) > 0){
                vetor_temp = vetor_funci[j];
                vetor_funci[j] = vetor_funci[j + 1];
                vetor_funci[j + 1] = vetor_temp;
            }
        }
    }
}
 
void mostrar(struct Funcionario *vetor_funci, int i){
 
    printf("\n**********DADOS DO FUNCIONARIO**********\n");
 
    for (int j = 0; j < i; j++){
        if (vetor_funci[j].num_func != 0 && strlen(vetor_funci[j].nome)>0){
        printf("\t| %2d |",vetor_funci[j].num_func);
        printf("\t%24s|",vetor_funci[j].nome);
        printf("\t%4c |",vetor_funci[j].genero);
        printf("\t    %2d.%2d.%4d |",vetor_funci[j].data.dia,vetor_funci[j].data.mes,vetor_funci[j].data.ano);
        printf("\t%15d |",vetor_funci[j].depart-1);
        printf("\t%6d |",vetor_funci[j].cargo-1);
        printf("\t%8.2f |", vetor_funci[j].salario);
        }
    }
}
 
void funci_dep(struct Funcionario *vetor_funci, int i){
    int dep;

    printf("******** DEPARTAMENTO **********\n");
    printf("\n1.Desenvolvimento");
    printf("\n2.Suporte");
    printf("\n3.RH");
    printf("\n4.Finan?as");
    printf("\nEscolha o departamento que deseja procurar: ");
    scanf("%d", &dep);
 
   
    for (int cont = 0; cont < i; i++){
        if (vetor_funci[cont].depart == dep){
          mostrar(vetor_funci, i);
        }
    }
}
 
void funci_car(struct Funcionario *vetor_funci, int i){
    int car;
   
    printf("********** CARGO **********\n");
    printf("\n1.Jœnior");
    printf("\n2.Pleno");
    printf("\n3.Senior");
    printf("\n4.L­der");
    printf("Escolha o cargo que deseja procurar: ");
    scanf("%d", &car);
 
 
    for (int cont = 0; cont < i; cont++){
        if (vetor_funci[cont].depart == car){ 
          mostrar(vetor_funci, cont);
        }
    }
}
 
void procu_nome(struct Funcionario *vetor_funci, int i){
    char nome[30];
 
    printf("Nome do funcionÿrio que deseja procurar: ");
    fflush(stdin);
    gets(nome);
 
    for (i = 0; i < MAX; i++){
        if (strcmp(vetor_funci[i].nome, nome) == 0){
            printf("Nome: %s", vetor_funci[i].nome);
            printf("Genero: %d", vetor_funci[i].genero);
            printf("Dia: %d|M?s: %d|Ano: %d", vetor_funci[i].data.dia, vetor_funci[i].data.mes, vetor_funci[i].data.ano );
            printf("Departamento: %d", vetor_funci[i].depart);
            printf("Cargo: %d", vetor_funci[i].cargo);
            printf("Salÿrio: %f", vetor_funci[i].salario);
        }
    }
}
 
void estatistica(struct Funcionario *vetor_funci, int i){
 
    int genero[4] = {0}, depart[5] = {0}, cargo[5] = {0}; // Temos 4 gˆneros, 5 departamentos  e 5 cargos (0 nÆo definido, 1 j£nior, 2 pleno, 3 sˆnior, 4 l¡der)
    float soma_salario = 0;
    int count = 0;

    for (int j = 0; j < i; j++) {
        if (vetor_funci[j].num_func != 0 && strlen(vetor_funci[j].nome) > 0) { // a FUN€ÇO strlen verifica se o nome do funcion rio nÆo est  vazio
            genero[vetor_funci[j].genero]++;
            depart[vetor_funci[j].depart]++;
            cargo[vetor_funci[j].cargo]++;
            soma_salario += vetor_funci[j].salario;
            count++;
        }
    }

    printf("-*-*-*-*-*-*-*-*-*-* DADOS DOS FUNCIONARIOS *-*-*-*-*-*-*-*-*-*-\n\n");
    printf("Funcion rios por gˆnero Feminino: %d\n", genero[1]);
    printf("Funcion rios por gˆnero Masculino: %d\n", genero[2]);
    printf("Funcion rios por gˆnero Outro: %d\n", genero[3]);
    printf("Funcion rios por Departamento Desenvolvimento: %d\n", depart[1]);
    printf("Funcion rios por Departamento Suporte: %d\n", depart[2]);
    printf("Funcion rios por Departamento RH: %d\n", depart[3]);
    printf("Funcion rios por Departamento Finan‡as: %d\n", depart[4]);
    printf("Funcion rios por Cargo J£nior: %d\n", cargo[1]);
    printf("Funcion rios por Cargo Pleno: %d\n", cargo[2]);
    printf("Funcion rios por Cargo Senior: %d\n", cargo[3]);
    printf("Funcion rios por Cargo L¡der: %d\n", cargo[4]);
    if (count > 0)
        printf("M‚dia de sal rio: %.2f\n", soma_salario / count);
    else
        printf("M‚dia de sal rio: 0.00\n");
}
 
void remover(struct Funcionario *vetor_funci, int *i){
 
    int num_func;
    printf("Nœmero do funcionrio que deseja eliminar: ");
    scanf("%d", &num_func);
 
    for (*i = 0; i < i; *i++){
        if (vetor_funci[*i].num_func == num_func){ 
            //Se o nœmero do funcionÿrio for igual, ? igual ao nœmero que foi inserido pelo utilizador.
            printf("Funcionrio %d removido com sucesso!\n", num_func);
            vetor_funci[*i].num_func = 0;
            strcpy(vetor_funci[*i].nome, ""); 
            //A fun?’o strcpy ? usada para copiar uma string para outra. 
            //A fun?’o esta a limpar o nome do funcionÿrio.
            vetor_funci[*i].genero = 0; 
            // O vetor_funci[i].genero ? definido como 0, para o g?nero do funcionÿrio for removido.
            vetor_funci[*i].data.dia = 0;
            vetor_funci[*i].data.mes = 0;
            vetor_funci[*i].data.ano = 0;
            vetor_funci[*i].depart = 0;
            vetor_funci[*i].cargo = 0;
            vetor_funci[*i].salario = 0.0;
        }
    }
 
}
 
void contagem(struct Funcionario *vetor_funci, int i){
 
    int total = 0;
    for (int cont = 0; cont < i; cont++){
        if (vetor_funci[cont].depart == 1){
            total++;
        }
    }

    printf("\nNœmero de funcionÿrios do departamento de desenvolvimento: %d", total);

}
 
void escrever_dados(struct Funcionario *vetor_funci, int i){

 FILE *fp = fopen("funcionarios.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro!\n");
        return;
    }

    fwrite(vetor_funci, sizeof(struct Funcionario), i, fp);
    fclose(fp);
    printf("Dados guardados com sucesso no ficheiro!\n");
}
 
void leitura(struct Funcionario *vetor_funci, int *i){
 
FILE *fp = fopen("funcionarios.bin", "rb");
    if (fp == NULL) {
        printf("Nenhum ficheiro de funcionarios encontrado.\n");
        *i = 0;
        return;
    }

    *i = fread(vetor_funci, sizeof(struct Funcionario), MAX, fp);
    fclose(fp);
    printf("Dados carregados do ficheiro binÿrio! Total de funcionÿrios: %d\n", *i);
}

void backup(struct Funcionario *vetor_funci, int i){
    FILE *fp = fopen("backup_funcionarios.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro de backup!\n");
        return;
    }
    fwrite(vetor_funci, sizeof(struct Funcionario), i, fp);
    fclose(fp);
    printf("Backup realizado com sucesso!\n");
}