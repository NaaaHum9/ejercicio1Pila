#include "01-Ejercicio.h"
/**
 * Funciona el codigo pero al momento de imprimir me da dos datos 
 * de basura al inicio y al final, y en medio se tienen los elementos de la pila
 * 
*/
/*1. Write a program to implement a stack using an array with push and pop
operations.
Expected Output:
Elements in the stack are: 3 5 4 3 2 1*/
void datosPila(PILA);
void mostrarPila(PILA);
void liberarMem(PILA, PILA, PILA);
void manejoMsg(int);

int main(){
    int selec = 0;
    PILA S, S2, S3;

    S = crearPila();
    S2 = crearPila();
    S3 = crearPila();

    do{
        printf("\nSeleccione una opcion\n");
        printf("1 - Igresar elemento \n");
        printf("2 - Mostrar elementos \n");
        printf("3 - Salir \n");
        scanf("%i", &selec);
        printf("\n");
        switch (selec){
        case 1:
            datosPila(S);
            break;
        case 2:
            copiaPila(S, S2, S3);
            mostrarPila(S2);
            break;
        }

    } while (selec != 3);
    liberarMem(S, S2, S3);
    
}

void datosPila(PILA S){//c
    int e;
    printf("Ingrese un elemento: \n");
    scanf("%i", &e);
    apilar(S, e);
    //apilar(S, S->pila);

}

//pila donde se aguarde los elementos de la pila S
void mostrarPila(PILA S){
    int aux;
    printf("Elementos ingresados: \n");
    while (es_vaciaPila(S) == FALSE){
        aux = desapilar(S);
        printf("%i \n", aux);
    }
    
}

void manejoMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . .","Pila llena", "Pila vacia", "Se ha liberado la memoria . . .  "};
    printf("%s", mensajes[msg] );
}

void liberarMem(PILA S, PILA S2, PILA S3){
    free(S);
    free(S2);
    free(S3);
    manejoMsg(3);
}
