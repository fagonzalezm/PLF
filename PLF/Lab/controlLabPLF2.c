#include <stdio.h>
#include <stdlib.h>

char * leerArchivo(char * palabra){

	FILE * archivo;
	archivo = fopen("Entrada.in", "r");
	if(archivo == NULL){
		printf("Archivo no encontrado");
		return NULL;
	}
	fscanf(archivo, "%s", palabra);
	return palabra;
}

int esDigito(char simbolo){
	if(simbolo == '0' || simbolo == '1' || simbolo == '2' || simbolo == '3' || simbolo == '4' || simbolo == '5' || simbolo == '6' || simbolo == '7' || simbolo == '8' || simbolo == '9'){
		return 1;
	}
	return 0;
}

int algoritmo(char * palabra){
	//0 representa error, 10 aceptar
	int entrada;
	int i = 0;
	char simbolo;
	int tabla [7][6] = {{2,0,0,0,0,0},{2,3,5,0,0,0},{4,0,0,0,0,0},{4,0,5,0,0,10},{7,0,0,6,6,0},{7,0,0,0,0,0},{7,0,0,0,0,10}};
	int estado = 1;
	while(estado != 10){
		printf("estado = %d\n", estado);
		simbolo = palabra[i];
		printf("simbolo = %c\n", simbolo);
		if(esDigito(simbolo) == 1){
			entrada = 0;
		}
		else if(simbolo == '\0'){
			entrada = 5;
		}
		else if(simbolo == '.'){
			entrada = 1;
		}
		else if(simbolo == 'E'){
			entrada = 2;
		}
		else if(simbolo == '+'){
			entrada = 3;
		}
		else if(simbolo == '-'){
			entrada = 4;
		}
		else{
			return 0;
		}
		estado = tabla[estado - 1][entrada];
		printf("estado siguiente = %d\n", estado);
		if(estado == 0){
			return 0;
		}
		i = i + 1;
	}
	return 1;
}




int main(){
	char * palabra = NULL;
	palabra = (char*)malloc(sizeof(char) * 100);
	leerArchivo(palabra);
	int resultado = algoritmo(palabra);
	printf("resultado = %d\n", resultado);
	return 0;
}