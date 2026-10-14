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
    void remover(struct Funcionario *vetor_funci, int i);
    void contagem(struct Funcionario *vetor_funci, int i);
    void escrever_dados(struct Funcionario *vetor_funci, int i);
    void leitura(struct Funcionario *vetor_funci, int *i);
 
 
int main(){
    system("color 3F");
    int op, i=0, op1;
 
    struct Funcionario *vetor_funci=(struct Funcionario *)malloc(MAX*sizeof(struct Funcionario));;
 
    leitura(vetor_funci, i);

    printf("Ol†, Bem vindo ao nosso programa!\n\n");
 
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
            remover(vetor_funci,i);
            break;
        case 8:
            contagem(vetor_funci,i);
            break;
        case 9:
            escrever_dados(vetor_funci,i);
            printf("Sair...\n");
            break;
        case 10:
            leitura(vetor_funci,i);
            break;
            return 0;
        default:
            printf("Opá∆o inv†lida! Tente novamente.\n");
            break;
        }
    } while (op !=0);

    free(vetor_funci);
}
 
int menu(int i){
    int opcao;
    int total_funcionarios = 0;
 
 
    system("pause");
    system("cls");
 
    printf("********** MENU **********\n");
    printf("\n1.Registar");
    printf("\n2.Listar");
    printf("\n3.Procurar por departamento, cargo e nome");
    printf("\n4.Dados Estat°sticos");
    printf("\n5.Eliminar");
    printf("\n6.Backup");
    printf("\n0.Sair do Programa");
    printf("\n\t\tTOTAL DE FUNCIONARIOS: %d/%d", total_funcionarios, MAX);
 
    do{
        printf("\n\nEscolha a sua opá∆o: ");
        scanf("%d", &opcao);
 
        if (opcao<0 || opcao>6){
            printf("Opá∆o incorreta! Escolha novamente:");
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
        printf("\n\nEscolha a sua opá∆o: ");
        scanf("%d", &option);
 
        if (option<1 || option>4){
            printf("Opá∆o incorreta! Escolha novamente:");
            scanf("%d", &option);
        }
       
    } while (option < 1 || option > 4);
 
    return option;
}
 
void pedir(struct Funcionario *vetor_funci, int i){
 
   
        printf("\n********** DADOS DO %d FUNCIONµRIO **********\n\n", i+1);
        fflush(stdin);
        printf("\n\tNß funcion†rio: ");
        printf("\n\tNome: ");
        gets(vetor_funci[i].nome);
        fflush(stdin);
 
        do{
            printf("\n\tGêNERO\n\t1.Feminino\n\n\t2.Masculino\n\n\t3.Outro\n\tIndique: ");
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
             printf("\n\tDEPARTAMENTO\n\t\t1.Desenvolvimento\n\t\t2.Suporte\n\t\t3.RH\n\t\t4.Finanáas\n\t\tIndique: ");
             scanf("%d", &vetor_funci[i].depart);
             fflush(stdin);
        } while (vetor_funci[i].depart < 1 || vetor_funci[i].depart > 4);
       
        do{
           printf("\n\tCARGO\n\t\t1.J£nior\n\t\t2.Pleno\n\t\t3.Senior\n\t\t4.L°der\n\t\tIndique: ");
           scanf("%d",&vetor_funci[i].cargo);
           fflush(stdin);
        } while (vetor_funci[i].cargo < 1 || vetor_funci[i].cargo > 4);
 
        printf("\nSal†rio: ");
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
 
    for (i = 0; i < MAX; i++){
        printf("\t| %2d |",vetor_funci[i].num_func);
        printf("\t%24s|",vetor_funci[i].nome);
        printf("\t%4c |",vetor_funci[i].genero);
        printf("\t    %2d.%2d.%4d |",vetor_funci[i].data.dia,vetor_funci[i].data.mes,vetor_funci[i].data.ano);
        printf("\t%15d |",vetor_funci[i].depart-1);
        printf("\t%6d |",vetor_funci[i].cargo-1);
        printf("\t%8.2f |", vetor_funci[i].salario);
       
    }
}
 
void funci_dep(struct Funcionario *vetor_funci, int i){
    int dep;
    char depart[][20] = {{"Desenvolvimenmto"}, {"Suporte"},{"RH"},{"Finanáas"}};
 
    switch (vetor_funci[i].genero){
    case 1: dep = 'F';break;
    case 2: dep = 'M';break;
    case 3: dep = 'O';break;
    }
 
    printf("******** DEPARTAMENTO **********\n");
    printf("\n1.Desenvolvimento");
    printf("\n2.Suporte");
    printf("\n3.RH");
    printf("\n4.Finanáas");
    printf("\nEscolha o departamento que deseja procurar: ");
    scanf("%d", &dep);
 
   
    for (int i = 0; i < MAX; i++){
        if (vetor_funci[i].depart == dep){
          mostrar(vetor_funci, i);
        }
    }
}
 
void funci_car(struct Funcionario *vetor_funci, int i){
    int car;
    char cargo[][20] = {{"J£nior"}, {"Pleno"},{"Senior"},{"L°der"}};
 
    switch (vetor_funci[i].cargo){
    case 1: car = 'J£nior';break;
    case 2: car = 'Pleno';break;
    case 3: car = 'Senior';break;
    case 4: car = 'L°der';break;
    }
   
    printf("********** CARGO **********\n");
    printf("\n1.J£nior");
    printf("\n2.Pleno");
    printf("\n3.Senior");
    printf("\n4.L°der");
    printf("Escolha o cargo que deseja procurar: ");
    scanf("%d", &car);
 
 
    for (int i = 0; i < MAX; i++){
        if (vetor_funci[i].depart == car){ 
          mostrar(vetor_funci, i);
        }
    }
}
 
void procu_nome(struct Funcionario *vetor_funci, int i){
    char nome[30];
 
    printf("Nome do funcion†rio que deseja procurar: ");
    fflush(stdin);
    gets(nome);
 
    for (i = 0; i < MAX; i++){
        if (strcmp(vetor_funci[i].nome, nome) == 0){
            printf("Nome: %s", vetor_funci[i].nome);
            printf("Genero: %d", vetor_funci[i].genero);
            printf("Dia: %d|Màs: %d|Ano: %d", vetor_funci[i].data.dia, vetor_funci[i].data.mes, vetor_funci[i].data.ano );
            printf("Departamento: %d", vetor_funci[i].depart);
            printf("Cargo: %d", vetor_funci[i].cargo);
            printf("Sal†rio: %f", vetor_funci[i].salario);
        }
    }
}
 
void estatistica(struct Funcionario *vetor_funci, int i){
 
    printf("-*-*-*-*-*-*-*-*-*-* DADOS DOS FUNCIONARIOS *-*-*-*-*-*-*-*-*-*-\n\n");
    printf("Funcion†rios por gÇneros: %d", vetor_funci[i].genero);
    printf("Funcion†rios por Departamento: %d", vetor_funci[i].depart);
    printf("Funcion†rios por Cargo: %d", vetor_funci[i].cargo);
    printf("MÇdia de salario: %d", vetor_funci[i].salario);
}
 
void remover(struct Funcionario *vetor_funci, int *i){
 
    int num_func;
    printf("N£mero do funcion†rio que deseja eliminar: ");
    scanf("%d", &num_func);
 
    for (i = 0; i < MAX; i++){
        if (vetor_funci[i].num_func == num_func){ 
            //Se o n£mero do funcion†rio for igual, Ç igual ao n£mero que foi inserido pelo utilizador.
            printf("Funcion†rio %d removido com sucesso!\n", num_func);
            vetor_funci[i].num_func = 0;
            strcpy(vetor_funci[i].nome, ""); 
            //A funá∆o strcpy Ç usada para copiar uma string para outra. 
            //A funá∆o esta a limpar o nome do funcion†rio.
            vetor_funci[i].genero = 0; 
            // O vetor_funci[i].genero Ç definido como 0, para o gànero do funcion†rio for removido.
            vetor_funci[i].data.dia = 0;
            vetor_funci[i].data.mes = 0;
            vetor_funci[i].data.ano = 0;
            vetor_funci[i].depart = 0;
            vetor_funci[i].cargo = 0;
            vetor_funci[i].salario = 0.0;
        }
    }
 
}
 
void contagem(struct Funcionario *vetor_funci, int i){
 
    int cont = 0;
    for (i = 0; i < MAX; i++){
        if (vetor_funci[i].depart == 1){
            cont++;
        }
        if (vetor_funci[i].cargo == 1){
            cont++;
        }
        if (vetor_funci[i].genero == 1){
            cont++;
        }
    }

    printf("\nN£mero de funcion†rios do departamento de desenvolvimento: %d", cont);
    printf("N£mero de funcion†rios do departamento de suporte: %d\n", cont);
    printf("N£mero de funcion†rios do departamento de RH: %d\n", cont);
    printf("N£mero de funcion†rios do departamento de finanáas: %d\n", cont);
    printf("N£mero de funcion†rios com cargo j£nior: %d\n", cont);
    printf("N£mero de funcion†rios com cargo pleno: %d\n", cont);
    printf("N£mero de funcion†rios com cargo senior: %d\n", cont);
    printf("N£mero de funcion†rios com cargo l°der: %d\n", cont);
    printf("N£mero de funcion†rios do gànero feminino: %d\n", cont);
    printf("N£mero de funcion†rios do gànero masculino: %d\n", cont);
    printf("N£mero de funcion†rios do gànero outro: %d\n", cont);
}
 
void escrever_dados(struct Funcionario *vetor_funci, int i){

 FILE *fp = fopen("funcionarios.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro!\n");
        return;
    }
    fclose(fp);
    printf("Dados guardados com sucesso no ficheiro!\n");
}
 
void leitura(struct Funcionario *vetor_funci, int *i){
 
FILE *fp = fopen("funcionarios.bin", "rb");
    if (fp == NULL) {
        printf("Nenhum ficheiro de funcion†rios encontrado.\n");
        *i = 0;
        return;
    }

    *i = fread(vetor_funci, sizeof(struct Funcionario), MAX, fp);
    fclose(fp);
    printf("Dados carregados do ficheiro bin†rio! Total de funcion†rios: %d\n", *i);
}