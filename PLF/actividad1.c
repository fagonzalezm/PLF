#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int automata(char * palabra){
	int largoPalabra = strlen(palabra);
	printf("largoPalabra: %d\n", largoPalabra);
	int estado = 1;
	int indice;
	char simbolo = palabra[indice];
	for(indice = 0; indice < largoPalabra + 2; indice++){
		printf("simbolo: %c\n", simbolo);
		printf("estado: %d\n", estado);
		switch(estado)
		{
			case 1:
					if(simbolo == 'a'){
						estado = 1;
					}

					else if(simbolo == 'b'){
						estado = 2;
					}
					else{
						return 0;
					}
					break;
			case 2:
					return 1;
		}
		//printf("estado: %d\n", estado);
		printf("indice: %d\n", indice);
		indice = indice + 1;
		simbolo = palabra[indice];
	}
	printf("estado: %d\n", estado);
	return 0;

}

int main(){
	int respuesta = automata("ab");
	printf("respuesta: %d\n", respuesta);
	return 0;
}