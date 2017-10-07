#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
struct _nodo {
	char valor[20];
	struct _nodo *siguiente;
};

struct _nodo *primero, *ultimo;

/* Añadir nodo al final de la lista*/
void push(char valor[20]) {
	/* Crear un nodo nuevo */
  struct _nodo *nuevo;
  nuevo = (struct _nodo*)malloc(sizeof(struct _nodo));

  strcpy(nuevo->valor,valor);
  /* Este será el último nodo, no debe tener siguiente */
  nuevo->siguiente = NULL;

  /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
  if(primero==NULL)
    primero = nuevo;
  /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
  if(ultimo!=NULL)
    ultimo->siguiente = nuevo;
   	
  /* Ahora, el último elemento de la cola es el nuevo nodo */
  ultimo = nuevo;
}

void pop() {
  struct _nodo *nodo_pop;
  if (primero==NULL) printf( "\nLa lista está vacía!! (pop)\n" );

  nodo_pop = primero;
  primero = nodo_pop->siguiente;
  
  printf("pop primero: %s", nodo_pop->valor);
  printf("\n");
  free(nodo_pop);
}



void print_list(){
	struct _nodo *auxiliar;
	auxiliar = primero;
    printf("\nMostrando la lista completa:\n");
    if (auxiliar==NULL) printf( "\nLa lista está vacía!!\n" );
    while (auxiliar!=NULL) {
    	printf("valor: %s", auxiliar->valor);
        printf("\n");
        auxiliar = auxiliar->siguiente;
    }
    printf("\n");
}

int main() {
	push("A");
	push("B");
  push("C");
  print_list();
  pop();
  print_list();
  push("D");
  print_list();
  pop();
  print_list();
  pop();
  pop();
  pop();
  pop();
}