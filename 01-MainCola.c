#include "01-Cola.h"
/**
 * 1. Write a program to implement a queue using an array. Programs should
contain functions for inserting elements into the queue, displaying queue
elements, and checking whether the queue is empty or not.
Expected Output:
Initialize a queue!
Check the queue is empty or not? Yes
Insert some elements into the queue:
Queue elements are: 1 2 3
Insert another element into the queue:
Queue elements are: 1 2 3 4
Check the queue is empty or not? No
*/

int datosEntrada(COLA);//solicita los datos int hasta que el usuario indique qeu ya no mas
void mostrarCola(COLA);
void colaVacia(COLA);
void liberarMem(COLA, COLA);
void manejaError(int);

int main(){
    COLA C, C1;
    int aux;
    C = crearCola();
    C1 = crearCola();
    
    datosEntrada(C);   
    liberarMem(C, C1);
}

int datosEntrada(COLA C){
    int opc=0,x;
    do{
        printf("\nSeleccione una opcion\n");
        printf("1 - Ingresar elemento\n");
        printf("2 - Mostrar cola\n");
        printf("3 - Salir\n");
        scanf("%i", &opc);
        printf("\n");

        switch (opc){
            case 1:
                printf("\nIngerse el elemento: \n");
                scanf("%i", &x);
                encolar(C, x);
                break;
            case 2:
                mostrarCola(C);
                colaVacia(C);
        }
    } while (opc != 3);

}

void mostrarCola(COLA C){
    int x;
    printf("\nElementos de la cola:\n\n");
    while (es_vaciaCola(C) == FALSE){
        x = desencolar(C);
        printf("%i, ", x);
    }
    
}

void colaVacia(COLA C){
    if (es_vaciaCola(C) == TRUE){
        printf("\nCola con elementos\n");
    }else
    {
        printf("\nCola vacia\n");
    }
    
    
}

void liberarMem(COLA C, COLA C1){
    free(C);
    free(C1);
    manejaError(1);
}

void manejaError(int msg){
    char * mensajes[] = {"\n\nNo hay memoria disponible", "\n\nSe ha liberado la memoria", 
                        "\n\nPila llena", "\n\nPila vacia", "\n\nCola llena", "\n\nCola vacia"};
    printf("%s", mensajes[msg] );
}