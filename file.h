FILE *itineraro;
char nombre_archivo[] = "itinerario.txt";
//int resultado = EXITO;

void abrir_archivo(){
	if ( (itineraro = fopen(nombre_archivo, "r") ) == NULL){
    	printf("No se ha podido abrir el archivo %s.\n", nombre_archivo);
  	}else{
  		printf("Archivo abierto %s.\n", nombre_archivo);
  	}
}

void cerrar_archivo(){
	if (fclose(itineraro)!=0) {
      printf("No se ha podido cerrar el fichero %s.\n", nombre_archivo);
   
    }else{
  		printf("Archivo cerrado %s.\n", nombre_archivo);
  	}
}