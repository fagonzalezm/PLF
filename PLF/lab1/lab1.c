#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int verificarTerminal(char * palabra){
	if(strcmp(palabra,".") == 0){
		return 1;
	}
	if(strcmp(palabra,":=") == 0){
		return 1;
	}
	if(strcmp(palabra,"=") == 0){
		return 1;
	}
	if(strcmp(palabra,",") == 0){
		return 1;
	}
	if(strcmp(palabra,";") == 0){
		return 1;
	}
	if(strcmp(palabra,"+") == 0){
		return 1;
	}
	if(strcmp(palabra,"-") == 0){
		return 1;
	}
	if(strcmp(palabra,"*") == 0){
		return 1;
	}
	if(strcmp(palabra,"/") == 0){
		return 1;
	}
	if(strcmp(palabra,"(") == 0){
		return 1;
	}
	if(strcmp(palabra,")") == 0){
		return 1;
	}

	if(strcmp(palabra,"#") == 0){
		return 1;
	}
	if(strcmp(palabra,"<=") == 0){
		return 1;
	}
	if(strcmp(palabra,"<") == 0){
		return 1;
	}
	if(strcmp(palabra,">=") == 0){
		return 1;
	}
	if(strcmp(palabra,">") == 0){
		return 1;
	}
	return 0;
}

int verificarTerminalEnMedio(char * palabra){
	if(strstr(palabra, ".") != NULL){
		return 1;
	}
	if(strstr(palabra, ":=") != NULL){
		return 1;
	}
	if(strstr(palabra, "=") != NULL){
		return 1;
	}
	if(strstr(palabra, ",") != NULL){
		return 1;
	}
	if(strstr(palabra, ";") != NULL){
		return 1;
	}
	if(strstr(palabra, "+") != NULL){
		return 1;
	}
	if(strstr(palabra, "-") != NULL){
		return 1;
	}
	if(strstr(palabra, "*") != NULL){
		return 1;
	}
	if(strstr(palabra, "/") != NULL){
		return 1;
	}
	if(strstr(palabra, "(") != NULL){
		return 1;
	}
	if(strstr(palabra, ")") != NULL){
		return 1;
	}
	if(strstr(palabra, "#") != NULL){
		return 1;
	}
	if(strstr(palabra, "<=") != NULL){
		return 1;
	}
	if(strstr(palabra, "<") != NULL){
		return 1;
	}
	if(strstr(palabra, ">=") != NULL){
		return 1;
	}
	if(strstr(palabra, ">") != NULL){
		return 1;
	}
	return 0;
}

char * obtenerTerminalEnMedio(char * palabra){
	if(strstr(palabra, "<=") != NULL){
		return "<=";
	}
	if(strstr(palabra, ">=") != NULL){
		return ">=";
	}
	if(strstr(palabra, ":=") != NULL){
		return ":=";
	}
	if(strstr(palabra, ".") != NULL){
		return ".";
	}
	if(strstr(palabra, "=") != NULL){
		return "=";
	}
	if(strstr(palabra, ",") != NULL){
		return ",";
	}
	if(strstr(palabra, ";") != NULL){
		return ";";
	}
	if(strstr(palabra, "+") != NULL){
		return "+";
	}
	if(strstr(palabra, "-") != NULL){
		return "-";
	}
	if(strstr(palabra, "*") != NULL){
		return "*";
	}
	if(strstr(palabra, "/") != NULL){
		return "/";
	}
	if(strstr(palabra, "(") != NULL){
		return "(";
	}
	if(strstr(palabra, ")") != NULL){
		return ")";
	}
	if(strstr(palabra, "#") != NULL){
		return "#";
	}
	if(strstr(palabra, "<") != NULL){
		return "<";
	}
	if(strstr(palabra, ">") != NULL){
		return ">";
	}
	return "";
}

char * primeraPalabraSeparacion(char * palabra, char * terminal){
	char * respuesta = NULL;
	respuesta = (char *)malloc(sizeof(char) * strlen(palabra));
	strcpy(respuesta, "");
	int posicionTerminal = (int)strlen(palabra) - (int)strlen(strstr( palabra, terminal));
	respuesta = strncat(respuesta, palabra, posicionTerminal);
	return respuesta;
}

char * terceraPalabraSeparacion(char * palabra, char * terminal){
	char * respuesta = NULL;
	respuesta = (char *)malloc(sizeof(char) * strlen(palabra));
	strcpy(respuesta, "");
	palabra = strstr(palabra, terminal);
	int i;
	if(strlen(terminal) == 1){
		for(i = 1; i < strlen(palabra); i++){
			respuesta[i - 1] = palabra[i];
			respuesta[i] = '\0';
		}
	}
	if(strlen(terminal) == 2){
		for(i = 2; i < strlen(palabra); i++){
			respuesta[i - 2] = palabra[i];
			respuesta[i - 1] = '\0';
		}
	}
	return respuesta;
}

int verificarSiUnCaracterEsNumero(char caracter){
	if(caracter == '0' || caracter == '1' || caracter == '2' || caracter == '3' || caracter == '4' || caracter == '5' || caracter == '6' || caracter == '7' || caracter == '8' || caracter == '9'){
		return 1;
	}
	return 0;
}

int verificarNumero(char *  palabra){
	int largoPalabra = strlen(palabra);
	int i;
	for(i = 0; i < largoPalabra; i++){
		if(verificarSiUnCaracterEsNumero(palabra[i]) == 0){
			return 0;
		}
	}
	if(strcmp(palabra, "") == 0){
		return 0;
	}
	return 1;
}

int verificarSiParteConNumero(char * palabra){

	if(verificarSiUnCaracterEsNumero(palabra[0]) == 1){
		return 1;
	}
	return 0;
}

char * parteDeLaPalabraQueNoEsNumero(char * palabra){
	char * respuesta = NULL;
	respuesta = (char *)malloc(sizeof(char) * strlen(palabra));
	int i = 0;
	int j = 0;
	while(verificarSiUnCaracterEsNumero(palabra[i]) == 1){
		i = i + 1;
	}
	while(i < strlen(palabra)){
		respuesta[j] = palabra[i];
		j = j + 1;
		i = i + 1;
	}
	return respuesta;
}

void identificarPalabra(char * palabra, FILE * archivoSalida){
	if(strcmp(palabra, "") == 0){
		//Hacer nada
	}

	else if(verificarTerminal(palabra) == 1){
		//Escribir palabra
		fprintf(archivoSalida, "%s\n", palabra);
	}
	
	else if(verificarTerminalEnMedio(palabra) == 1){
		char * primeraPalabra = NULL;
		char * terminalEnMedio = NULL;
		char * terceraPalabra = NULL;
		terminalEnMedio = obtenerTerminalEnMedio(palabra);
		primeraPalabra = primeraPalabraSeparacion(palabra, terminalEnMedio);
		terceraPalabra = terceraPalabraSeparacion(palabra, terminalEnMedio);
		identificarPalabra(primeraPalabra, archivoSalida);
		free(primeraPalabra);
		primeraPalabra = NULL;
		//Escribir terminalEnMedio
		fprintf(archivoSalida, "%s\n", terminalEnMedio);
		identificarPalabra(terceraPalabra, archivoSalida);
		free(terceraPalabra);
		terceraPalabra = NULL;
	}

	else if(verificarNumero(palabra) == 1){
		//Escribir NUMERO
		fprintf(archivoSalida, "NUMERO\n");
	}

	else if(verificarSiParteConNumero(palabra) == 1){
		//Escribir NUMERO
		fprintf(archivoSalida, "NUMERO\n");
		char * parteQueNoEsNumero = NULL;
		parteQueNoEsNumero = parteDeLaPalabraQueNoEsNumero(palabra);
		identificarPalabra(parteQueNoEsNumero, archivoSalida);
		free(parteQueNoEsNumero);
		parteQueNoEsNumero = NULL;
	}
	else{
		//Escribir IDENTIFICADOR
		if(strcmp(palabra, "const")== 0){
			fprintf(archivoSalida, "const\n");
		}
		else if(strcmp(palabra, "var") == 0){
			fprintf(archivoSalida, "var\n");
		}
		else if(strcmp(palabra, "procedure") == 0){
			fprintf(archivoSalida, "procedure\n");
		}
		else if(strcmp(palabra, "call") == 0){
			fprintf(archivoSalida, "call\n");
		}
		else if(strcmp(palabra, "begin") == 0){
			fprintf(archivoSalida, "begin\n");
		}
		else if(strcmp(palabra, "end") == 0){
			fprintf(archivoSalida, "end\n");
		}
		else if(strcmp(palabra, "if") == 0){
			fprintf(archivoSalida, "if\n");
		}
		else if(strcmp(palabra, "then") == 0){
			fprintf(archivoSalida, "then\n");
		}
		else if(strcmp(palabra, "while") == 0){
			fprintf(archivoSalida, "while\n");
		}
		else if(strcmp(palabra, "do") == 0){
			fprintf(archivoSalida, "do\n");
		}
		else if(strcmp(palabra, "odd") == 0){
			fprintf(archivoSalida, "odd\n");
		}
		else{
			fprintf(archivoSalida, "IDENTIFICADOR\n");
		}
	}	
}

void leerArchivo(char * nombreArchivoEntrada, FILE * archivoSalida){
	char * palabra = NULL;
	FILE * archivo;
	archivo = fopen(nombreArchivoEntrada, "r");
	if(!archivo){
		printf("Error: El archivo de entrada no existe\n");
		fclose(archivoSalida);
		fclose(archivo);
	}
	else{
		while(!feof(archivo)){
			palabra = (char *)malloc(sizeof(char) * 100);
			fscanf(archivo, "%s", palabra);
			identificarPalabra(palabra, archivoSalida);
			free(palabra);
			palabra = NULL;
		}
		fclose(archivoSalida);
		fclose(archivo);
		free(palabra);
		palabra = NULL;
	}
}

void escribirArchivoDeSalida(char * nombreArchivoSalida, char * nombreArchivoEntrada){
	FILE * archivo;
	archivo = fopen(nombreArchivoSalida, "r");
	if(archivo){
		printf("Error: El archivo de salida ya existe\n");
	}
	if(!archivo){
		archivo = fopen(nombreArchivoSalida, "w");
		leerArchivo(nombreArchivoEntrada, archivo);
	}
}

int main(int argc, char *argv[]){
	if(argc < 3){
		printf("Error: Faltan parámetros en la línea de comandos.\n");
		printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
	}
	else if(argc > 3){
		printf("Error: Demasiados parámetros en la línea de comandos.\n");
		printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
	}
	else if (argc == 3){
		escribirArchivoDeSalida(argv[2], argv[1]);
	}
	return 0;
}
