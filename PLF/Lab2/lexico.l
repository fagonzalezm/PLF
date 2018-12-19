%{
	#include<stdio.h>
	FILE * archivo = NULL;
%}

LETRA	[a-zA-Z]+
DIGITO	[0-9]

%%

"."|"="|","|";"|":="|"+"|"*"|"/"|"("|")"|"#"|"<"|"<="|">"|">="					{fprintf(archivo, "%s\n", yytext);}
"const"|"var"|"procedure"|"call"|"begin"|"end"|"if"|"then"|"while"|"do"|"odd"	{fprintf(archivo, "%s\n", yytext);}
{DIGITO}+																		{fprintf(archivo, "NUMERO\n");}
{LETRA}({DIGITO}|{LETRA})*|({LETRA})*											{fprintf(archivo,"IDENTIFICADOR\n");}
<<EOF>> 																		{yyterminate();}
. ;

%%

int main(int argc, char ** argv){
	++argv;
	--argc;
	if(argc < 1){
		printf("Error: Falta parámetro en la línea de comandos.\nUso: lexico.exe archivo_entrada archivo_salida");
	}
	if(argc = 1){
		if(!fopen(argv[0],"r")){
			printf("Error: El archivo de entrada no existe.");
			return 0;
		}
		if(fopen(argv[1],"r")){
			printf("Error: El archivo de salida ya existe.");
			return 0;
		}
		archivo = fopen(argv[1],"w");
		yyin = fopen(argv[0], "r");
	}
	else{
		printf("Error: Demasiados parámetros en la línea de comandos.\nUso: lexico.exe archivo_entrada archivo_salida");
		return 0;
	}

	yylex();
	return 0;
}
