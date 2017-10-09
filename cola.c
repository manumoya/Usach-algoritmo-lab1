#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
struct _nodo {
	char valor[20];
	struct _nodo *siguiente;
};
*/


typedef struct _nodo {
    char valor[20];
    struct _nodo *siguiente;
}Nodo;

typedef struct _cola{
  Nodo *inicio;
  Nodo *final;  
}Cola;

/*  FUNCIONES DE COLA  */ 


void inicializa(Cola *cola){
  cola->inicio = NULL;
  cola->final = NULL; 
}
  
/* cola push */
void push(Cola *cola, char valor[20]) {
	/* Crear un nodo nuevo */
  Nodo *nuevo;
  nuevo = (Nodo*)malloc(sizeof(Nodo));

  strcpy(nuevo->valor,valor);
  /* Este será el último nodo, no debe tener siguiente */
  nuevo->siguiente = NULL;

  /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
  printf("\n Acá pushh ini: %s", nuevo->valor);
  if(cola->inicio==NULL){
    printf("\nAcá 1ro:\n");
    cola->inicio = nuevo;
    printf("\n Acá pushh 1ro: %s", cola->inicio->valor);
  
  }

  /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
  if(cola->final!=NULL)
    cola->final->siguiente = nuevo;
  
  /* Ahora, el último elemento de la cola es el nuevo nodo */
  cola->final= nuevo;
}

/* cola pop */
void pop(Cola *cola) {
  Nodo *nodo_pop;
  //if (primero==NULL){
  if (cola->inicio==NULL){
    printf( "\nLa lista está vacía!! (pop)\n" );
    return;
  }  
  nodo_pop = cola->inicio;
  cola->inicio = nodo_pop->siguiente;
  
  printf("pop primero: %s", nodo_pop->valor);
  printf("\n");
  free(nodo_pop);
}

/* Imprimir cola */
void print_cola(Cola *cola){
	Nodo *auxiliar;
	auxiliar = cola->inicio;
    printf("\nMostrando la lista completa:\n");
    if (auxiliar==NULL) printf( "\nLa lista está vacía!!\n" );
    while (auxiliar!=NULL) {
    	printf("valor: %s", auxiliar->valor);
        printf("\n");
        auxiliar = auxiliar->siguiente;
    }
    printf("\n");
}



/*  ======= FUNCIONES DE MATRIZ  ========== */
int largo =5;
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
      if (j==0 || i==0){
        printf("%c ", matriz_grafo[i][j]);
      }else{
        printf("%d ", matriz_grafo[i][j]);
      }
      
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

void agregar_adyacencia(char origen[], char destino[], int costo){
  int pos_origen=posicion_nodo(origen);
  int pos_destino=posicion_nodo(destino); 

  printf("pos orig %d ", pos_origen ); 
  printf("pos dsti %d ", pos_destino ); 
  printf("\n");   


  matriz_grafo[pos_origen][pos_destino]=costo;

}

int main() {
  //struct _nodo *primero, *ultimo;
  //primero=NULL;
  //ultimo=NULL;

  Cola *cola;
  if ((cola = (Cola *) malloc (sizeof (Cola))) == NULL) 
    return -1;
  inicializa(cola);
  push(cola,"A");
  //printf("\n Acá main: %s", cola->inicio->valor);

	push(cola,"B");
  push(cola,"C");
  
  //printf("\n Acá main: %s", cola);
  

  print_cola(cola);
  
  pop(cola);
  pop(cola);
  print_cola(cola);
  
  /*
  push(cola,"D");
  print_list(cola);
  pop(cola);
  print_list(cola);
  pop(cola);
  
  generar_grafo("abcd");
  imprimir_grafo();
  agregar_adyacencia("a", "b", 1);
  imprimir_grafo();
*/
}