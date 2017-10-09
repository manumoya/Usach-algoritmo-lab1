#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cola.h"
#include "matriz.h"

int main() {

  /*
  Cola *cola;
  if ((cola = (Cola *) malloc (sizeof (Cola))) == NULL) 
    return -1;
  inicializa(cola);
  push(cola,"A");
  push(cola,"B");
  push(cola,"C");
  print_cola(cola);
  
  push(cola,"D");
  print_cola(cola);
  pop(cola);
  print_cola(cola);
  pop(cola);
  print_cola(cola);
  */

  
  generar_grafo("abcd");
  imprimir_grafo();
  agregar_adyacencia("a", "b", 1);
  imprimir_grafo();
  
}