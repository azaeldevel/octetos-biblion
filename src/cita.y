%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cita-lexer.h"

%}

%lex-param {struct octetos_biblion_Tray* ty}
%parse-param {struct octetos_biblion_Tray* ty}

%union {
	unsigned short sval;
	const char* str;
}

%token <sval> LIBRO_VALOR
%token <sval> CAPITULO_VALOR
%token <sval> VERSICULO_VALOR

%locations

%%
%start cita;

	cita : cita_uno | cita_rango ;

	cita_uno : LIBRO_VALOR CAPITULO_VALOR ':' VERSICULO_VALOR
	{
		ty->cita.cita.uno = malloc(sizeof(struct Cita_Uno));
		ty->cita.cita.uno->libro = $1;
		ty->cita.cita.uno->capitulo = $2;
		ty->cita.cita.uno->versiculo = $4;
		ty->cita.tipo = UNO;
		YYACCEPT;
	};
	cita_rango: LIBRO_VALOR CAPITULO_VALOR ':' VERSICULO_VALOR '-' VERSICULO_VALOR
	{
		ty->cita.cita.rango = malloc(sizeof(struct Cita_Rango));
		ty->cita.cita.rango->libro = $1;
		ty->cita.cita.rango->capitulo = $2;
		ty->cita.cita.rango->versIni = $4;
		ty->cita.cita.rango->versFin = $6;
		ty->cita.tipo = RANGO;
		YYACCEPT;
	};

%%
void yyerror(struct octetos_biblion_Tray* ty,const char* s) {
	if(ty->dysplay_erro > 0) fprintf(stderr, "Parse error: %s\n", s);
}
int cita_parser(struct octetos_biblion_Tray* ty) {
  return yyparse(ty);
}

