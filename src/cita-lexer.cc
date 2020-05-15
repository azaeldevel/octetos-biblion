/**
 * 
 *  This file is part of octetos-core.
 *  octetos-core is a core C/C++ Octeto's library.
 *  Copyright (C) 2018  Azael Reyes
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <octetos/core/Buffer.hh>

#include "cita.tab.h"
#include "cita-lexer.h"

bool is_digit(char c)
{
	if( c >= 48 and c <= 57) return true;
	return false;	
}

Libros trans_Libro_es(const char* str)
{
	std::string strLibro;
	
	//Genesis
	strLibro = "Genesis";
	if(strLibro.compare(str) == 0) return Libros::GENESIS;
	strLibro = "Génesis";
	if(strLibro.compare(str) == 0) return Libros::GENESIS;
	strLibro = "genesis";
	if(strLibro.compare(str) == 0) return Libros::GENESIS;
	strLibro = "génesis";
	if(strLibro.compare(str) == 0) return Libros::GENESIS;
	strLibro = "gen";
	if(strLibro.compare(str) == 0) return Libros::GENESIS;
	
	//Exodo
	strLibro = "Exodo";
	if(strLibro.compare(str) == 0) return Libros::EXODO;
	strLibro = "Éxodo";
	if(strLibro.compare(str) == 0) return Libros::EXODO;
	strLibro = "exodo";
	if(strLibro.compare(str) == 0) return Libros::EXODO;
	strLibro = "éxodo";
	if(strLibro.compare(str) == 0) return Libros::EXODO;	
	strLibro = "exo";
	if(strLibro.compare(str) == 0) return Libros::EXODO;
	
	//Levítico
	strLibro = "Levitico";
	if(strLibro.compare(str) == 0) return Libros::LEVITICOS;
	strLibro = "Levítico";
	if(strLibro.compare(str) == 0) return Libros::LEVITICOS;
	strLibro = "levitico";
	if(strLibro.compare(str) == 0) return Libros::LEVITICOS;
	strLibro = "levítico";
	if(strLibro.compare(str) == 0) return Libros::LEVITICOS;	
	strLibro = "lev";
	if(strLibro.compare(str) == 0) return Libros::LEVITICOS;
	
	//Números
	strLibro = "Numeros";
	if(strLibro.compare(str) == 0) return Libros::NUMEROS;
	strLibro = "Números";
	if(strLibro.compare(str) == 0) return Libros::NUMEROS;
	strLibro = "numeros";
	if(strLibro.compare(str) == 0) return Libros::NUMEROS;
	strLibro = "números";
	if(strLibro.compare(str) == 0) return Libros::NUMEROS;	
	strLibro = "num";
	if(strLibro.compare(str) == 0) return Libros::NUMEROS;
	
	//Deuteromios
	strLibro = "Deuteronomios";
	if(strLibro.compare(str) == 0) return Libros::DEUTERONOMIOS;
	strLibro = "deuteronomios";
	if(strLibro.compare(str) == 0) return Libros::DEUTERONOMIOS;	
	strLibro = "dtn";
	if(strLibro.compare(str) == 0) return Libros::DEUTERONOMIOS;
	
	strLibro = "Josué";
	if(strLibro.compare(str) == 0) return Libros::JOSUE;
	strLibro = "Josue";
	if(strLibro.compare(str) == 0) return Libros::JOSUE;
	strLibro = "josué";
	if(strLibro.compare(str) == 0) return Libros::JOSUE;
	strLibro = "josue";
	if(strLibro.compare(str) == 0) return Libros::JOSUE;	
	strLibro = "jos";
	if(strLibro.compare(str) == 0) return Libros::JOSUE;

	strLibro = "Jueces";
	if(strLibro.compare(str) == 0) return Libros::JUECES;
	strLibro = "jueces";
	if(strLibro.compare(str) == 0) return Libros::JUECES;	
	strLibro = "jue";
	if(strLibro.compare(str) == 0) return Libros::JUECES;
	
	strLibro = "Rut";
	if(strLibro.compare(str) == 0) return Libros::RUT;
	strLibro = "rut";
	if(strLibro.compare(str) == 0) return Libros::RUT;

	strLibro = "1 Samuel";
	if(strLibro.compare(str) == 0) return Libros::SAMUEL1;
	strLibro = "1 samuel";
	if(strLibro.compare(str) == 0) return Libros::SAMUEL1;
	strLibro = "1sam";
	if(strLibro.compare(str) == 0) return Libros::SAMUEL1;

	strLibro = "2 Samuel";
	if(strLibro.compare(str) == 0) return Libros::SAMUEL2;
	strLibro = "2 samuel";
	if(strLibro.compare(str) == 0) return Libros::SAMUEL2;
	strLibro = "2sam";
	if(strLibro.compare(str) == 0) return Libros::SAMUEL2;
	
	strLibro = "1 Reyes";
	if(strLibro.compare(str) == 0) return Libros::REYES1;
	strLibro = "1 Reyes";
	if(strLibro.compare(str) == 0) return Libros::REYES1;
	strLibro = "1rey";
	if(strLibro.compare(str) == 0) return Libros::REYES1;

	strLibro = "2 Reyes";
	if(strLibro.compare(str) == 0) return Libros::REYES2;
	strLibro = "2 Reyes";
	if(strLibro.compare(str) == 0) return Libros::REYES2;
	strLibro = "2rey";
	if(strLibro.compare(str) == 0) return Libros::REYES2;
	
	strLibro = "1 Cronicas";
	if(strLibro.compare(str) == 0) return Libros::CRONICAS1;
	strLibro = "1 Crónicas";
	if(strLibro.compare(str) == 0) return Libros::CRONICAS1;
	strLibro = "1 cronicas";
	if(strLibro.compare(str) == 0) return Libros::CRONICAS1;
	strLibro = "1 crónicas";
	if(strLibro.compare(str) == 0) return Libros::CRONICAS1;
	strLibro = "1cro";
	if(strLibro.compare(str) == 0) return Libros::CRONICAS1;
	
	strLibro = "2 Cronicas";
	if(strLibro.compare(str) == 0) return Libros::CRONICAS2;
	strLibro = "2 Crónicas";
	if(strLibro.compare(str) == 0) return Libros::CRONICAS2;
	strLibro = "2 cronicas";
	if(strLibro.compare(str) == 0) return Libros::CRONICAS2;
	strLibro = "2 crónicas";
	if(strLibro.compare(str) == 0) return Libros::CRONICAS2;
	strLibro = "2cro";
	if(strLibro.compare(str) == 0) return Libros::CRONICAS2;
		
	strLibro = "Esdras";
	if(strLibro.compare(str) == 0) return Libros::ESDRAS;
	strLibro = "esdras";
	if(strLibro.compare(str) == 0) return Libros::ESDRAS;
	strLibro = "esd";
	if(strLibro.compare(str) == 0) return Libros::ESDRAS;
	
	strLibro = "Nehemias";
	if(strLibro.compare(str) == 0) return Libros::NEHEMIAS;
	strLibro = "Nehemías";
	if(strLibro.compare(str) == 0) return Libros::NEHEMIAS;
	strLibro = "nehemias";
	if(strLibro.compare(str) == 0) return Libros::NEHEMIAS;
	strLibro = "Nehemías";
	if(strLibro.compare(str) == 0) return Libros::NEHEMIAS;
	strLibro = "neh";
	if(strLibro.compare(str) == 0) return Libros::NEHEMIAS;
			
	strLibro = "Ester";
	if(strLibro.compare(str) == 0) return Libros::ESTER;
	strLibro = "ester";
	if(strLibro.compare(str) == 0) return Libros::ESTER;
	strLibro = "est";
	if(strLibro.compare(str) == 0) return Libros::ESTER;
	
	strLibro = "Job";
	if(strLibro.compare(str) == 0) return Libros::JOB;
	strLibro = "job";
	if(strLibro.compare(str) == 0) return Libros::JOB;
	
	strLibro = "Salmos";
	if(strLibro.compare(str) == 0) return Libros::SALMOS;
	strLibro = "salmos";
	if(strLibro.compare(str) == 0) return Libros::SALMOS;
	strLibro = "sal";
	if(strLibro.compare(str) == 0) return Libros::SALMOS;
	
	strLibro = "Proverbios";
	if(strLibro.compare(str) == 0) return Libros::PROVERBIOS;
	strLibro = "proverbios";
	if(strLibro.compare(str) == 0) return Libros::PROVERBIOS;
	strLibro = "prv";
	if(strLibro.compare(str) == 0) return Libros::PROVERBIOS;
	
	strLibro = "Eclesiatés";
	if(strLibro.compare(str) == 0) return Libros::ECLESIASTES;
	strLibro = "Eclesiates";
	if(strLibro.compare(str) == 0) return Libros::ECLESIASTES;
	strLibro = "eclesiatés";
	if(strLibro.compare(str) == 0) return Libros::ECLESIASTES;
	strLibro = "eclesiates";
	if(strLibro.compare(str) == 0) return Libros::ECLESIASTES;	
	strLibro = "ecl";
	if(strLibro.compare(str) == 0) return Libros::ECLESIASTES;
	
	strLibro = "Cantares";
	if(strLibro.compare(str) == 0) return Libros::CANTARES;
	strLibro = "cantares";
	if(strLibro.compare(str) == 0) return Libros::CANTARES;
	strLibro = "cnt";
	if(strLibro.compare(str) == 0) return Libros::CANTARES;
	
	strLibro = "Isaías";
	if(strLibro.compare(str) == 0) return Libros::ISAIAS;
	strLibro = "Isaias";
	if(strLibro.compare(str) == 0) return Libros::ISAIAS;
	strLibro = "isaías";
	if(strLibro.compare(str) == 0) return Libros::ISAIAS;
	strLibro = "isaias";
	if(strLibro.compare(str) == 0) return Libros::ISAIAS;	
	strLibro = "isa";
	if(strLibro.compare(str) == 0) return Libros::ISAIAS;
	
	strLibro = "Jeremías";
	if(strLibro.compare(str) == 0) return Libros::JEREMIAS;
	strLibro = "Jeremias";
	if(strLibro.compare(str) == 0) return Libros::JEREMIAS;
	strLibro = "jeremías";
	if(strLibro.compare(str) == 0) return Libros::JEREMIAS;
	strLibro = "jeremias";
	if(strLibro.compare(str) == 0) return Libros::JEREMIAS;	
	strLibro = "jer";
	if(strLibro.compare(str) == 0) return Libros::JEREMIAS;
	
	strLibro = "Lamentaciones";
	if(strLibro.compare(str) == 0) return Libros::LAMENTACIONES;
	strLibro = "lamantaciones";
	if(strLibro.compare(str) == 0) return Libros::LAMENTACIONES;
	strLibro = "lam";
	if(strLibro.compare(str) == 0) return Libros::LAMENTACIONES;
	
	strLibro = "Ezequiel";
	if(strLibro.compare(str) == 0) return Libros::EZEQUIEL;
	strLibro = "ezequiel";
	if(strLibro.compare(str) == 0) return Libros::EZEQUIEL;
	strLibro = "eze";
	if(strLibro.compare(str) == 0) return Libros::EZEQUIEL;
	
	strLibro = "Daniel";
	if(strLibro.compare(str) == 0) return Libros::DANIEL;
	strLibro = "daniel";
	if(strLibro.compare(str) == 0) return Libros::DANIEL;
	strLibro = "dan";
	if(strLibro.compare(str) == 0) return Libros::DANIEL;

	strLibro = "Oseas";
	if(strLibro.compare(str) == 0) return Libros::OSEAS;
	strLibro = "oseas";
	if(strLibro.compare(str) == 0) return Libros::OSEAS;
	strLibro = "ose";
	if(strLibro.compare(str) == 0) return Libros::OSEAS;
	
	strLibro = "Joel";
	if(strLibro.compare(str) == 0) return Libros::JOEL;
	strLibro = "joel";
	if(strLibro.compare(str) == 0) return Libros::JOEL;
	strLibro = "joe";
	if(strLibro.compare(str) == 0) return Libros::JOEL;

	strLibro = "Amós";
	if(strLibro.compare(str) == 0) return Libros::AMOS;
	strLibro = "Amos";
	if(strLibro.compare(str) == 0) return Libros::AMOS;
	strLibro = "amós";
	if(strLibro.compare(str) == 0) return Libros::AMOS;
	strLibro = "amos";
	if(strLibro.compare(str) == 0) return Libros::AMOS;
	strLibro = "ams";
	if(strLibro.compare(str) == 0) return Libros::AMOS;

	strLibro = "Abdías";
	if(strLibro.compare(str) == 0) return Libros::ABDIAS;
	strLibro = "Abdias";
	if(strLibro.compare(str) == 0) return Libros::ABDIAS;
	strLibro = "abdías";
	if(strLibro.compare(str) == 0) return Libros::ABDIAS;
	strLibro = "abdias";
	if(strLibro.compare(str) == 0) return Libros::ABDIAS;
	strLibro = "abd";
	if(strLibro.compare(str) == 0) return Libros::ABDIAS;
	
	strLibro = "Jonás";
	if(strLibro.compare(str) == 0) return Libros::JONAS;
	strLibro = "Jonas";
	if(strLibro.compare(str) == 0) return Libros::JONAS;
	strLibro = "jonás";
	if(strLibro.compare(str) == 0) return Libros::JONAS;
	strLibro = "jonas";
	if(strLibro.compare(str) == 0) return Libros::JONAS;
	strLibro = "jon";
	if(strLibro.compare(str) == 0) return Libros::JONAS;
	
	strLibro = "Miqueas";
	if(strLibro.compare(str) == 0) return Libros::MIQUEAS;
	strLibro = "miqueas";
	if(strLibro.compare(str) == 0) return Libros::MIQUEAS;
	strLibro = "miq";
	if(strLibro.compare(str) == 0) return Libros::MIQUEAS;
	
	strLibro = "Nahum";
	if(strLibro.compare(str) == 0) return Libros::NAHUM;
	strLibro = "nahum";
	if(strLibro.compare(str) == 0) return Libros::NAHUM;
	strLibro = "nah";
	if(strLibro.compare(str) == 0) return Libros::NAHUM;
	
	strLibro = "Habacuc";
	if(strLibro.compare(str) == 0) return Libros::HABACUC;
	strLibro = "habacuc";
	if(strLibro.compare(str) == 0) return Libros::HABACUC;
	strLibro = "hab";
	if(strLibro.compare(str) == 0) return Libros::HABACUC;
	
	strLibro = "Sofonías";
	if(strLibro.compare(str) == 0) return Libros::SOFONIAS;
	strLibro = "Sofonias";
	if(strLibro.compare(str) == 0) return Libros::SOFONIAS;
	strLibro = "sofonías";
	if(strLibro.compare(str) == 0) return Libros::SOFONIAS;
	strLibro = "sofonias";
	if(strLibro.compare(str) == 0) return Libros::SOFONIAS;
	strLibro = "sof";
	if(strLibro.compare(str) == 0) return Libros::SOFONIAS;

	strLibro = "Hageo";
	if(strLibro.compare(str) == 0) return Libros::HAGEO;
	strLibro = "hageo";
	if(strLibro.compare(str) == 0) return Libros::HAGEO;
	strLibro = "hag";
	if(strLibro.compare(str) == 0) return Libros::HAGEO;
	
	strLibro = "Zacarías";
	if(strLibro.compare(str) == 0) return Libros::ZACARIAS;
	strLibro = "Zacarias";
	if(strLibro.compare(str) == 0) return Libros::ZACARIAS;
	strLibro = "zacarías";
	if(strLibro.compare(str) == 0) return Libros::ZACARIAS;
	strLibro = "zacarias";
	if(strLibro.compare(str) == 0) return Libros::ZACARIAS;
	strLibro = "zac";
	if(strLibro.compare(str) == 0) return Libros::ZACARIAS;

	strLibro = "Malaquías";
	if(strLibro.compare(str) == 0) return Libros::MALAQUIAS;
	strLibro = "Malaquias";
	if(strLibro.compare(str) == 0) return Libros::MALAQUIAS;
	strLibro = "malaquías";
	if(strLibro.compare(str) == 0) return Libros::MALAQUIAS;
	strLibro = "malaquias";
	if(strLibro.compare(str) == 0) return Libros::MALAQUIAS;
	strLibro = "mal";
	if(strLibro.compare(str) == 0) return Libros::MALAQUIAS;
	
	return NINGUNO;
}
extern "C" int yylex(struct octetos_biblion_Tray* ty)
{	
	if(!ty->buffer)
	{
		ty->buffer = new octetos::core::Buffer(ty->str); 
	}
	octetos::core::Buffer* buffer = (octetos::core::Buffer*)ty->buffer;
	char c = buffer->next_char();
	
	while (true)
	{
		switch(ty->state)
		{
			case INICIAL:
			{
				esperandoLibro:
				if(c != ' ')
				{
					c = buffer->next_char();
					goto esperandoLibro;
				}
				else
				{
					buffer->prev_char();
				}
				buffer->proceed();
				char* strlibro = NULL;
				short strl = strlen(buffer->get_text());
				strlibro = (char*)malloc(strl);
				strcpy((char*)(strlibro),buffer->get_text());
				//std::cout << "Libro : '" << strlibro << "'\n";
				yylval.sval = trans_Libro_es(strlibro);
				ty->state = LIBRO_LEIDO;
				return LIBRO_VALOR;
			}
			case LIBRO_LEIDO:	
			{
				esperandoNumero:
				if(c == ' ')
				{
					c = buffer->next_char();
					goto esperandoNumero;
				}
				if(is_digit(c))
				{
					while(is_digit(c))
					{
						c = buffer->next_char();
					}
					buffer->prev_char();
					buffer->proceed();
					//no es digit, no importa que sea ya termino de leer el capitulo
					yylval.sval=(short)atoi(buffer->get_text());
					//std::cout << "Capitulo : " << yylval.sval << "\n";
					ty->state =  CAPITULO_LEIDO;
					return CAPITULO_VALOR;
				}
				else
				{
					return c;
				}
			}
			case CAPITULO_LEIDO:
			{
				if(c == ':')
				{
					buffer->proceed();
					ty->state =  COLUMNA_LEIDA;
					//std::cout << " : \n";
					return ':';
				}

				return c;
			}
			case COLUMNA_LEIDA:
			{
				esperandoNumero2:
				if(c == ' ')
				{
					c = buffer->next_char();
					goto esperandoNumero2;
				}
				if(is_digit(c))
				{
					while(is_digit(c))
					{
						c = buffer->next_char();
					}
					buffer->prev_char();
					buffer->proceed();
					//no es digit, no importa que sea ya termino de leer el versiculo
					yylval.sval=(short)atoi(buffer->get_text());
					//std::cout << "Versiculo : " << yylval.sval << "\n";
					ty->state =  VERSICULO_LEIDO;
					return VERSICULO_VALOR;
				}
			}
			default:
				return 0;
		};
	}
	
	return 0;
}