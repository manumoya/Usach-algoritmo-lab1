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
void add_last_nodo(struct _nodo nodo_padre, char nombre_ciudad[20], int costo_viaje) {
		/* se define */
		struct _nodo *nuevo;
		/* se reserva memmoria para el nodo*/
		nuevo = (struct _nodo*)malloc(sizeof(struct _nodo));
		if (nuevo==NULL) printf( "No hay memoria disponible!\n");
		
		if (primero==NULL) { /* Es primer nodo */
			printf( "1ro nodo \n");
			primero=nuevo;
			strcpy(primero->nombre,nombre_ciudad);
			primero->costo = costo_viaje;
			primero->anterior=NULL;
     		primero->siguiente=NULL;
     		ultimo=primero;
     		return primero;
     	}else{ /* Ingresar  otros nodos*/
     		printf( "last nodo \n");
     		strcpy(nuevo->nombre,nombre_ciudad);
     		nuevo->costo = costo_viaje;
     		nuevo->anterior
     		nuevo->siguiente=NULL;
     		ultimo->siguiente=nuevo;
     		ultimo=nuevo;
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


int main() {

 	/*
   	ultimo = (struct _nodo *) NULL;
	*/ 
    
    add_last_nodo("A", 1000);
    add_last_nodo("B", 500);
    add_last_nodo("C", 100);
	add_last_nodo("D", 30);
	

	print_list();


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