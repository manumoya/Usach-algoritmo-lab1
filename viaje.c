#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pila.h"
#include "matriz.h"

void resetear_rutas(int arrRutas[]){
  for (int i=0; i<5; i++)
      arrRutas[i]=0;
}
void imprimir_rutas(int arrRutas[]){
  for (int i=0; i<5; i++){
    printf("ady %d ", arrRutas[i]);
    printf("\n"); 
  }
}

void recorre_rutas(int posNodoIni, Pila *pila){
  int nuevas_rutas[5];
  resetear_rutas(nuevas_rutas);
  
  printf("nodo ini pos %d ", posNodoIni);
  printf("\n"); 

  /* guarda todas las adyacencias del nodo*/
  int cont_ruta=0;
  for (int i=1; i<5; i++){
    int valor = matriz_grafo[posNodoIni][i];
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

  if (cont_ruta==0){
    printf("sin ruta calcula viaje %i", posNodoIni);
    printf("\n");
    print_pila(pila);
    //pop(cola);

  }else{
    /* calculo las rutas de todas las adyacencias*/
    for (int i=0; i<5; i++){
      if (nuevas_rutas[i]!=0){
        char nombre_nodo = matriz_grafo[nuevas_rutas[i]][0];
        int costo_nodo =matriz_grafo[posNodoIni][nuevas_rutas[i]];
        //push(cola, &nombre_nodo, costo_nodo);
        printf("Push ruta \n");
        //print_cola(cola);
        //printf(" nodo nombre %c", nombre_nodo); 
        //printf(" - nodo costo %d", costo_nodo); 

        recorre_rutas(nuevas_rutas[i], pila);
        //pop(cola);
        printf("ruta %d ", nuevas_rutas[i]);
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
  

  push(pila,"A",1);
  
  push(pila,"B",2);
  push(pila,"C",3);
  print_pila(pila);
  push(pila,"D",4);
  print_pila(pila);
  pop(pila);
  print_pila(pila);
  /*
  pop(pila);
  print_pila(pila);*/
  

  /*
  generar_grafo("abcd");
  //imprimir_grafo();
  agregar_adyacencia("a", "b", 1);
  agregar_adyacencia("a", "c", 2);
  agregar_adyacencia("a", "d", 3);
  agregar_adyacencia("d", "c", 4);
  imprimir_grafo();
  
  push(cola,"a", 0);
  recorre_rutas( posicion_nodo("a"), cola);
  */

  
}