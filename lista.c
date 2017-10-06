#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
struct _nodo {
	char nombre[20];
	int costo;
    struct _nodo *anterior;
    struct _nodo *siguiente;

};

struct _nodo *primero, *ultimo;

/* Añadir nodo al final de la lista*/
struct _nodo add_last_nodo(struct _nodo *nodo_padre, char nombre_ciudad[20], int costo_viaje) {
		/* se define */
		struct _nodo *nuevo;
		/* se reserva memmoria para el nodo*/
		nuevo = (struct _nodo*)malloc(sizeof(struct _nodo));
		if (nuevo==NULL) printf( "No hay memoria disponible!\n");
		
		if (nodo_padre==NULL) { /* Es primer nodo */
			printf( "1ro nodo \n");
			strcpy(nuevo->nombre,nombre_ciudad);
			nuevo->costo = costo_viaje;
			nuevo->anterior=NULL;
     		nuevo->siguiente=NULL;
     		return *nuevo;
     	}else{ /* Ingresar  otros nodos*/
     		printf( "last nodo \n");
     		strcpy(nuevo->nombre,nombre_ciudad);
     		nuevo->costo = costo_viaje;
     		nuevo->anterior=nodo_padre;
     		nuevo->siguiente=NULL;
     		return *nuevo;
     	}

}

/* Imprime lista*/
void print_list(){
	int total_viaje=0;
	struct _nodo *auxiliar;
	auxiliar = primero;
    printf("\nMostrando la lista completa:\n");
    if (auxiliar==NULL) printf( "\nLa lista está vacía!!\n" );
    while (auxiliar!=NULL) {
    	total_viaje=total_viaje+auxiliar->costo;
    	printf("Ciudad: %s", auxiliar->nombre);
        printf(" Costo: %d", auxiliar->costo);
        printf("\n");
        auxiliar = auxiliar->siguiente;
    }
    printf("Total Viaje: %d", total_viaje);
    printf("\n");
}

/* Imprime lista*/
void print_list2(){
    int total_viaje=0;
    struct _nodo *auxiliar;
    auxiliar = primero;
    printf("\nMostrando la lista completa:\n");
    if (auxiliar==NULL) printf( "\nLa lista está vacía!!\n" );
    while (auxiliar!=NULL) {
        total_viaje=total_viaje+auxiliar->costo;
        printf("Ciudad: %s", auxiliar->nombre);
        printf(" Costo: %d", auxiliar->costo);
        printf("\n");
        auxiliar = auxiliar->siguiente;
    }
    printf("Total Viaje: %d", total_viaje);
    printf("\n");
}


int main() {

 	/*
   	ultimo = (struct _nodo *) NULL;
	*/ 

    struct _nodo *nodA, *nodB, *nodC, *nodD;
    
    *nodA = add_last_nodo(NULL,"A", 1000);

    printf("Ciudad: %s", nodA->nombre);
    printf("\n");

    *nodB = add_last_nodo(nodA, "B", 500);
    
    printf("Ciudad: %s", nodB->nombre);
    printf("\n");


    /*
    *nodC = add_last_nodo(nodB, "C", 100);
	*nodD = add_last_nodo(nodC, "D", 30);
	*/

	/*print_list();*/


    /*
	ultimo = "B";

    printf("%d ", primero);
    printf("%d ", ultimo);
	*/

    /* Definir puntero y arreglo dinamico*/
    int *ptr;
    ptr = (int*)malloc(sizeof(int*)*10);

    /* asigna valor a cada puntero */
	for (int i=0; i<10; i++){
		ptr[i]=i;
	}

	/* imprmir valor asignado */
	for (int i=0; i<10; i++){
		printf("%d ", ptr[i]);
		printf("%d ", &ptr[i]);
		printf("\n");
	}
	
}