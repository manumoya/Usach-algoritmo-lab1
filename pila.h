
typedef struct _nodo {
    char nombre[20];
    int costo;
    struct _nodo *siguiente;
}Nodo;

typedef struct _pila{
  Nodo *inicio;
  Nodo *final;  
}Pila;

/*  FUNCIONES DE COLA  */ 


void inicializa(Pila *pila){
  pila->inicio = NULL;
  pila->final = NULL; 
}
  
/* pila push */
void push(Pila *pila, char nombre[20], int costo) {
	/* Crear un nodo nuevo */
  Nodo *nuevo;
  nuevo = (Nodo*)malloc(sizeof(Nodo));

  strcpy(nuevo->nombre,nombre);
  nuevo->costo=costo;
  nuevo->siguiente = NULL;

  /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
  /*printf(" \n pushh nodo: %s", nuevo->nombre);
  printf("\n");
  */
  
  if(pila->inicio==NULL){
    //printf("\n Acá pushh 1ro: %s ",nuevo->nombre);
    pila->final= nuevo;
  }

  /* Si la cola no estaba vacía, añadimos el nuevo como 1ro */
  if(pila->inicio != NULL){
    nuevo->siguiente = pila->inicio;
  }  
 
  /* Ahora, el último elemento de la cola es el nuevo nodo */
  pila->inicio= nuevo;
}

/* cola pop */
void pop(Pila *pila) {
  Nodo *nodo_pop;
  //if (primero==NULL){
  if (pila->inicio==NULL){
    //printf( "\nLa lista está vacía!! (pop)\n" );
    return;
  }  
  nodo_pop = pila->inicio;
  pila->inicio = nodo_pop->siguiente;
  
  /*printf("pop primero: %s", nodo_pop->nombre);
  printf("\n");
  */
  free(nodo_pop);
}

/* Imprimir cola */
void print_pila(Pila *pila){
	Nodo *auxiliar;
	auxiliar = pila->inicio;
  
  if (auxiliar==NULL){
    printf( "\nLa lista está vacía!!\n" );
  }else{
    printf("\nMostrando pila completa:\n");
  }  
  while (auxiliar!=NULL) {
    printf("nombre: %s", auxiliar->nombre);
    printf(" costo: %d", auxiliar->costo);
    printf("\n");
    auxiliar = auxiliar->siguiente;
  }
  //printf("\n");
}


void print_pila_con_ciclo(Pila *pila){
  Nodo *auxiliar;
  auxiliar = pila->inicio;
  if (auxiliar==NULL){
    printf( "\nLa lista está vacía!!\n" );
  }else{
    printf("\nMostrando pila completa:\n");
  }
  int nro_nodos=1;
  while (auxiliar!=NULL) {
    if (nro_nodos>1){
      printf("nombre: %s", auxiliar->nombre);
      printf(" costo: %d", auxiliar->costo);
      printf("\n");
    }
    nro_nodos++;
    auxiliar = auxiliar->siguiente;
  }
  //printf("\n");
}

/* ver si existe nodo */
int existe_ciclo(Pila *pila, char nodo[]){
  Nodo *auxiliar;
  auxiliar = pila->inicio;
  printf("\nMostrando pila completa:\n");
  if (auxiliar==NULL) printf( "\nLa lista está vacía!!\n" );
  int validacion=0;
  int cont_pila=0;
  while (auxiliar!=NULL && validacion==0) {
    /*
    printf("nombre: %s", auxiliar->nombre);
    printf(" costo: %d", auxiliar->costo);
    printf("\n");
    printf(" nodo inex: %c", nodo[0]);
    */
    //if (auxiliar->nombre[0]==nodo[0] && cont_pila>1){
    if (auxiliar->nombre[0]==nodo[0] && cont_pila>1){
      validacion=1;
    }
    auxiliar = auxiliar->siguiente;
    cont_pila++;
  }
  printf("\n");
  return (validacion);
}