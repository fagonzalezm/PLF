#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int automata(char * palabra){
	int estado = 1;
	char simbolo = palabra[0];
	while(simbolo != '\0'){
		switch(estado)
		{
			case 1:
					if(simbolo == 'a'){
						estado = 1;
					}

					else if(simbolo == 'b'){
						estado = 2;
					}

			case 2:

					if(simbolo == '\0'){
						return 1;
					}
					else if(simbolo == 'a'){
						return 0;
					}
					else if(simbolo == 'b'){
						return 0;
					}

		}
		
	}


}

int main(){
	int respuesta = automata("ab");
	printf("respuesta: %d\n", respuesta);
	return 0;
}