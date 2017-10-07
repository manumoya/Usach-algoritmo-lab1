#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

struct _nodo {
	char valor[20];
	struct _nodo *siguiente;
};

/*  FUNCIONES DE COLA  */
struct _nodo *primero, *ultimo;

/* cola push */
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

/* cola pop */
void pop() {
  struct _nodo *nodo_pop;
  if (primero==NULL){
    printf( "\nLa lista está vacía!! (pop)\n" );
    return;
  }  
  nodo_pop = primero;
  primero = nodo_pop->siguiente;
  
  printf("pop primero: %s", nodo_pop->valor);
  printf("\n");
  free(nodo_pop);
}

/* Imprimir cola */
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



/*  FUNCIONES DE MATRIZ  */
char matriz_grafo[5][5];

/* generar grafo */
void generar_grafo(char vertices[]) {
  for(int i=0; i<5 && vertices[i] != '\0'; ++i){
    printf("char: %c", vertices[i] );
    printf("\n");
    matriz_grafo[0][i+1]=vertices[i];
    matriz_grafo[i+1][0]=vertices[i];
  }
}

/* imprimir grafo */
void imprimir_grafo(){
  for (int i=0; i<5; i++){
    for (int j=0; j<5; j++){
      printf("%c ", matriz_grafo[i][j]);
    }
    printf("\n");   
  }
}

int posicion_nodo(char letra[]){
  int posicion=0;

  printf("letra %s ", letra);
  printf("\n"); 

  for (int i=0; i<5; i++){
    if ( matriz_grafo[0][i] == letra[0]){
      i=6;
      posicion--;
    }
    posicion++;
  }  
  return posicion;
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
  
  generar_grafo("abcd");
  imprimir_grafo();
  printf("pos c %d ", posicion_nodo("c") ); 
  printf("pos a %d ", posicion_nodo("a") ); 

}