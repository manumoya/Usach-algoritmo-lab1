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
    	printf( "Nro : \n");
        return (linea[0]);
    }
    if (ini_or_nronodo=='D'){
        printf( "NOD : \n");
    	return (linea[2]);
    }
        
	/*
	char separador[] = " ";
	char *trozo = NULL;
	char linea2[100]; 
	linea2= linea;
	trozo = strtok( linea2, separador);
	int cont_trozo=1;
    
    while( trozo != NULL ) {
        printf( "Cont Trozo : %d ", cont_trozo);
        printf( "Cont Trozo : %c \n", ini_or_nronodo);
        printf( "Trozo : %s \n", trozo);
        trozo = strtok( NULL, separador);
        
        if (cont_trozo==1 && ini_or_nronodo=='N'){
        	printf( "Nro : \n");
        	return (*trozo);
        	
       	}
       	if (cont_trozo==2 && ini_or_nronodo=='D'){
        	printf( "NOD : \n");
        	return (*trozo);
        	
        }
        
        cont_trozo++;
    }
    */

    //return 'HO';

}

void carga_matriz(int nro_linea, char linea[]){
	//for (int i=0; i<len_linea(linea); i++){
	//	printf("letra %c", linea[i]);
		//char linea2=linea;
		
		if (nro_linea==1){
			//carga primera linea
			//linea2 = linea;
			printf( "NRO : %c \n", get_val_prim_linea(linea, 'N'));
			//linea2 = linea;
			printf( "NOD : %c \n", get_val_prim_linea(linea, 'D'));
		}else{
			// carga rutas

		}

		
		printf("\n");	
	//}
}

void leer_archivo(){
	char linea[100];
	int nro_linea=1;

	while (!feof(itinerario)){
		fgets(linea,sizeof(linea),itinerario);
		
		printf("largo fila %d", len_linea(linea)); 
		printf("\n");

		carga_matriz(nro_linea, linea);

		nro_linea++;
		
		//fprintf(stdout , "%s\n\n\n",linea);
	}
}