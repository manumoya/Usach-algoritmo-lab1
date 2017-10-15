#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pila.h"
#include "matriz.h"
#include "file.h"

void resetear_rutas(int arrRutas[]){
  int largo_rutas = get_largo_matriz();
  for (int i=0; i<largo_rutas; i++)
      arrRutas[i]=0;
}
void imprimir_rutas(int arrRutas[]){
  int largo_rutas = get_largo_matriz();
  for (int i=0; i<largo_rutas; i++){
    printf("ady %d ", arrRutas[i]);
    printf("\n"); 
  }
}

void recorre_rutas(int posNodoIni, Pila *pila){
  //int nuevas_rutas[5];

  int largo_rutas = get_largo_matriz();
  int *nuevas_rutas;
  nuevas_rutas = (int*)malloc(sizeof(int*)*largo_matriz);

  resetear_rutas(nuevas_rutas);
  
  printf("nodo ini pos %d ", posNodoIni);
  printf("\n"); 

  /* guarda todas las adyacencias del nodo*/
  int cont_ruta=0;
  for (int i=1; i<largo_matriz; i++){
    int valor = matriz_grafo_din[posNodoIni][i];
    if (valor != 0){
      //printf("pos nodo %c", matriz_grafo[0][i]); 
      //printf(" pos nodo costo %d", matriz_grafo[posNodoIni][i]); 
      printf("\n");
      nuevas_rutas[cont_ruta]=i;
      cont_ruta++;
    }
  }
  printf("\n");
  //imprimir_rutas(nuevas_rutas);
  int hay_ciclo=existe_ciclo(pila, &matriz_grafo_din[posNodoIni][0]);
  //printf("nodo esta en pila, ciclo? %d \n", hay_ciclo);
  
  if (hay_ciclo==1){
    printf("hay ciclo,  calcula viaje %i", posNodoIni);
    printf("\n");
    //pop(pila);
    print_pila(pila);

  }else if (cont_ruta==0){
    printf("sin ruta calcula viaje %i", posNodoIni);
    printf("\n");
    print_pila(pila);
    //pop(cola);

  }else{
    /* calculo las rutas de todas las adyacencias*/
    for (int i=0; i<largo_matriz; i++){
      if (nuevas_rutas[i]!=0){
        char nombre_nodo = matriz_grafo_din[nuevas_rutas[i]][0];
        int costo_nodo =matriz_grafo_din[posNodoIni][nuevas_rutas[i]];
        push(pila, &nombre_nodo, costo_nodo);
        //printf("Push ruta \n");
        //print_cola(cola);
        //printf(" nodo nombre %c", nombre_nodo); 
        //printf(" - nodo costo %d", costo_nodo); 

        recorre_rutas(nuevas_rutas[i], pila);
        pop(pila);
        //printf("ruta %d ", nuevas_rutas[i]);
        printf("\n");
      }
    }
  }

}


int main() {

  Pila *pila;
  if ((pila = (Pila *) malloc (sizeof (Pila))) == NULL) 
    return -1;
  inicializa(pila);
  
/*
  push(pila,"A",1);
  
  push(pila,"B",2);
  push(pila,"C",3);
  print_pila(pila);
  push(pila,"D",4);
  print_pila(pila);
  pop(pila);
  print_pila(pila);
  
  pop(pila);
  print_pila(pila);*/
  

  //generar_grafo("ABCD");
  //imprimir_grafo();

  primer_nodo[0]='A';
  abrir_archivo();
  leer_archivo();
  cerrar_archivo();

  //imprimir_grafo();

  /*
  agregar_adyacencia("A", "B", 1);
  agregar_adyacencia("A", "C", 2);
  agregar_adyacencia("A", "D", 3);
  agregar_adyacencia("D", "C", 4);
  imprimir_grafo();
  */

  push(pila,"A", 0);
  recorre_rutas( posicion_nodo("A"), pila);


}