%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "cita-lexer.h"

%}


%union {
	short sval;
	unsigned long ulval;
	const char* str;
}

%token LIBRO_VALOR<sval>;
%token CAPITULO_VALOR<str>;
%token VERSICULO_VALOR<sval>;
%token GUION_TK;
%token COLUMNA_TK;

%locations

%%
%start stmt;

	stmt : ;
		
%%
void yyerror(const char* s) 
{
	
}


