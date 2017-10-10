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