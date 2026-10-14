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
    
    void pedir(struct Funcionario *vetor_funci, int *i);
    void ordenar(struct Funcionario *vetor_funci, int *i);
    void escrever(struct Funcionario *vetor_funci, int *i);
    void mostrar(struct Funcionario *vetor_funci, int *i);
    void funci_dep(struct Funcionario *vetor_funci, int *i);
    void funci_car(struct Funcionario *vetor_funci, int *i);
    void procu_nome(struct Funcionario *vetor_funci, int *i);
    void conclusao(struct Funcionario *vetor_funci, int *i);
    void remover(struct Funcionario *vetor_funci, int *i);
    void contagem(struct Funcionario *vetor_funci, int *i);
    void escrever_dados(struct Funcionario *vetor_funci, int *i);
    void leitura(struct Funcionario *vetor_funci, int *i);


int main(){
    int op, i;


    FILE *funcionarios;
    struct Funcionario * vetor_funci =(struct Funcionario *)malloc(MAX * sizeof(struct Funcionario));
    if (funcionarios == NULL){
        printf("Erro na aloca‡äa de mem¢ria.\n");
        exit(1);
    }


    do{
        op = menu(i);
        switch (op){
        case 1:
            submenu(i);
            break;
        case 2:
            pedir(vetor_funci, i);
            break;
        case 3:
            ordenar(vetor_funci,i);
            break;
        case 4: 
            escrever(vetor_funci,i);
            break;
        case 5:
            mostrar(vetor_funci,i);
            break;
        case 6:
            funci_dep(vetor_funci,i);
            break;
        case 7:
            funci_car(vetor_funci,i);
            break;
        case 8:
            procu_nome(vetor_funci,i);
            break;
        case 9:
            conclusao(vetor_funci,i);
            break;
        case 10:
            remover(vetor_funci,i);
            break;
        case 11:
            contagem(vetor_funci,i);
            break;
        case 12:
            escrever_dados(vetor_funci,i);
            break;
        case 13:
            leitura(vetor_funci,i);
            break;
        default:
            break;
        }
    } while (op !=0);
    
   


    

    free(funcionarios);
}

int menu(int i){
    int opcao;

    printf("Ol , Bem vindo ao nosso programa!");

    system("pause");
    system("cls");

    printf("********** MENU **********\n\n");
    printf("\n1.Registar");
    printf("\n2.Listar");
    printf("\n3.Procurar por departamento, cargo e nome");
    printf("\n4.Dados Estat¡sticos");
    printf("\n5.Eliminar");
    printf("\n6.Backup");
    printf("\n0.Sair do Programa");
    

    do{
        printf("\n\nEscolha a sua op‡Æo: ");
        scanf("%d", &opcao);

        if (opcao<0 || opcao>6){
            printf("Op‡Æo incorreta! Escolha novamente:");
            scanf("%d", &opcao);
        }
        
    } while (opcao < 0 || opcao > 6);
    
    
}

int submenu(int i){
   



}

void pedir(struct Funcionario *vetor_funci, int *i){

    for (int i = 0; i < MAX; i++){
        printf("\n********** DADOS DO %d FUNCIONµRIO **********\n\n", i+1);
        printf("\n\tN§ funcion rio: ");
        scanf("%d", vetor_funci[i].num_func);
        printf("\n\tNome: ");
        gets(vetor_funci[i].nome);
        printf("\nG‚nero: ");
        scanf("%d", vetor_funci[i].genero);
        printf("\nData de nascimento: ");
        scanf("%d", vetor_funci[i].data);
        printf("\nDepartamento:");
        scanf("%d", vetor_funci[i].depart);
        printf("\nCargo: ");
        scanf("%d",vetor_funci[i].cargo);
        printf("\nSal rio: ");
        scanf("%f",vetor_funci[i].salario);
    }
    

}

void ordenar(struct Funcionario *vetor_funci, int *i){

}

void escrever(struct Funcionario *vetor_funci, int *i){

}

void mostrar(struct Funcionario *vetor_funci, int *i){

}

void funci_dep(struct Funcionario *vetor_funci, int *i){

}

void funci_car(struct Funcionario *vetor_funci, int *i){

}

void procu_nome(struct Funcionario *vetor_funci, int *i){

}

void conclusao(struct Funcionario *vetor_funci, int *i){

}

void remover(struct Funcionario *vetor_funci, int *i){

}

void contagem(struct Funcionario *vetor_funci, int *i){

}

void escrever_dados(struct Funcionario *vetor_funci, int *i){

}

void leitura(struct Funcionario *vetor_funci, int *i){

}