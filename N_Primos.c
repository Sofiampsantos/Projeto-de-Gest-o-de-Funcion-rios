#include <stdio.h>

void primos(int num);

int main() {
    int n;

    printf("********** NÈMEROS PRIMOS **********\n\n");

    for (int  i = 0; i <= n; i++){ 
        printf("Os n£meros primos s∆o:\t"); //Imprime os n£meros primos
    }
    primos(n); //Chamada da funá∆o primos
    
    return 0;
}

void primos(int num) {
    int primo;
    num=50;

    for (int i = 2; i <= num; i++) { // Comeáa no 2, porque o 1 n∆o Ç primo
        primo = 1; // Se o primo for 1, significa que Ç primo
        for (int j = 2; j <= i / 2; j++) { // Verifica se o n£mero Ç divis°vel por algum n£mero menor que ele
            if (i % j == 0) { //Se o i for divis°vel por j, ent∆o n∆o Ç primo
                primo = 0; // Se o primo for 0, sigifica que n∆o Ç primo
            }
        }
        if (primo) { //Se o primo for 1, ent∆o Ç primo
            printf("%d ", i); // Imprime o n£mero 
        }
    }
    printf("\n");
}