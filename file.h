FILE *itinerario;
char nombre_archivo[] = "itinerario.txt";
//int resultado = EXITO;

void abrir_archivo(){
	if ( (itinerario = fopen(nombre_archivo, "r") ) == NULL){
    	printf("No se ha podido abrir el archivo %s.\n", nombre_archivo);
  	}else{
  		printf("Archivo abierto %s.\n", nombre_archivo);
  	}
}

void cerrar_archivo(){
	if (fclose(itinerario)!=0) {
      printf("No se ha podido cerrar el fichero %s.\n", nombre_archivo);
   
    }else{
    	fclose(itinerario);
  		printf("Archivo cerrado %s.\n", nombre_archivo);
  	}
}


int len_linea(char cadena[]){
    int j=0;
    while (cadena[j] != '\0') 
    	j++;
    return j;
}

char get_val_prim_linea(char linea[], char ini_or_nronodo){
	if ( ini_or_nronodo=='N'){
    	//printf( "Nro : \n");
        return (linea[0]);
    }
    if (ini_or_nronodo=='D'){
        //printf( "NOD : \n");
    	return (linea[2]);
    }
}

char get_val_otras_linea(char linea[], char tipo_valor){
	
	if ( tipo_valor=='O'){
    	//printf( "Orig : \n");
        return (linea[0]);
    }
    if (tipo_valor=='D'){
        //printf( "Dest : \n");
    	return (linea[2]);
    }
    if (tipo_valor=='C'){
        //printf( "Cos : \n");
    	return (linea[4]);
    }
}

void carga_matriz(int nro_linea, char linea[]){
	if (nro_linea==1){
		//carga primera linea
		//linea2 = linea;
		printf( "NRO : %c \n", get_val_prim_linea(linea, 'N'));
		//linea2 = linea;
		printf( "NOD : %c \n", get_val_prim_linea(linea, 'D'));
	}else{
		// carga rutas
		printf( "Orig : %c \n", get_val_otras_linea(linea, 'O'));
		printf( "Dest : %c \n", get_val_otras_linea(linea, 'D'));
		printf( "Cos : %c \n", get_val_otras_linea(linea, 'C'));	
	}
	printf("\n");	
}

void leer_archivo(){
	char linea[100];
	int nro_linea=1;

	while (!feof(itinerario)){
		fgets(linea,sizeof(linea),itinerario);
		
		//printf("largo fila %d", len_linea(linea)); 
		printf(" fila %d", nro_linea); 
		printf("\n");

		carga_matriz(nro_linea, linea);

		nro_linea++;
		
		//fprintf(stdout , "%s\n\n\n",linea);
	}
}