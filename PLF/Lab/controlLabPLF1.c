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

int esDigito(char simoblo){
	if(simoblo == '0' || simoblo == '1' || simoblo == '2' || simoblo == '3' || simoblo == '4' || simoblo == '5' || simoblo == '6' || simoblo == '7' || simoblo == '8' || simoblo == '9'){
		return 1;
	}
	return 0;
}

int algoritmo(char * palabra){
	int estado = 1;
	int i = 0;
	char signo = palabra[i];
	while(signo != '\0'){
		printf("estado: %d\n", estado);
		printf("signo: %c\n", signo);
		if (estado == 1){
			if(esDigito(signo) == 1){
				estado = 2;
			}
			else{
				estado = 'E';
			}
		}
		else if (estado == 2){
			if(esDigito(signo) == 1){
				estado = 2;
			}
			else if(signo == '.'){
				estado = 3;
			}
			else if(signo == 'E'){
				estado  = 5;
			}
			else{
				estado = 'E';
			}
		}
		else if (estado == 3){
			if(esDigito(signo) == 1){
				estado = 4;
			}
			else{
				estado = 'E';
			}
		}
		else if (estado == 4){
			if(esDigito(signo) == 1){
				estado = 4;
			}
			else if(signo == 'E'){
				estado = 5;
			}
			else{
				estado = 'E';
			}
		}
		else if (estado == 5){
			if(esDigito(signo) == 1){
				estado = 7;
			}
			else if(signo == '+' || signo == '-'){
				estado = 6;
			}
			else{
				estado = 'E';
			}
		}
		else if (estado == 6){
			if(esDigito(signo) == 1){
				estado = 7;
			}
			else{
				estado = 'E';
			}
		}
		else if (estado == 7){
			if(esDigito(signo) == 1){
				estado = 7;
			}
			else{
				estado = 'E';
			}
		}
		printf("siguiente estado: %d\n", estado);
		i = i + 1;
		signo = palabra[i];
	}
	printf("estado final: %d\n", estado);
	if(estado != 4 && estado != 7){
		return 0;
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