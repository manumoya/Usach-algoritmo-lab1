#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cola.h"
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

void recorre_rutas(int posNodoIni, Cola *cola){
  int  nuevas_rutas[5];
  resetear_rutas(nuevas_rutas);
  
  printf("pos nodo ini %d ", posNodoIni);
  printf("\n"); 

  int cont_ruta=0;
  for (int i=1; i<5; i++){
    int valor = matriz_grafo[posNodoIni][i];
    if (valor != 0){
      nuevas_rutas[cont_ruta]=i;
      cont_ruta++;
    }
  }
  printf("\n");
  //imprimir_rutas(nuevas_rutas);

  if (cont_ruta==0){
    printf("sin ruta calcula viaje %i", posNodoIni);
     printf("\n");

  }else{
    for (int i=0; i<5; i++){
      if (nuevas_rutas[i]!=0){
        recorre_rutas(nuevas_rutas[i], cola);
        printf("ruta %d ", nuevas_rutas[i]);
        printf("\n");
      }
    }
  }

}


int main() {

  Cola *cola;
  if ((cola = (Cola *) malloc (sizeof (Cola))) == NULL) 
    return -1;
  inicializa(cola);
  

  push(cola,"A",1);
  push(cola,"B",2);
  push(cola,"C",3);
  print_cola(cola);
  
  push(cola,"D",4);
  print_cola(cola);
  pop(cola);
  print_cola(cola);
  pop(cola);
  print_cola(cola);


  /*
  generar_grafo("abcd");
  //imprimir_grafo();
  agregar_adyacencia("a", "b", 1);
  agregar_adyacencia("a", "c", 2);
  agregar_adyacencia("a", "d", 3);
  agregar_adyacencia("d", "c", 4);
  imprimir_grafo();
  */

  //push(cola,"a", 1);
  //recorre_rutas( posicion_nodo("a"), cola);

  
}