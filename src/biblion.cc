/*
 * Copyright (C) 2020 Azael R. <azael.devel@gmail.com>
 * 
 * octetos-biblion is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * octetos-biblion is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "config.h"
#include <stdio.h>
#include <string.h>
#include <libconfig.h++>
#include <iostream>
#include <fstream>


#include "biblion.hh"
#include "cita-lexer.h"


namespace octetos
{
	Biblion::Biblion(std::string& file) : IBiblion(file)
	{
		
	}
	
	std::string Biblion::get_Cita(const std::string& str)
	{
		//std::cout << "Step 1: " << '\n';
		Cita cita = parseCita(str);
		//std::cout << "Step 2: " << '\n';
		if(cita.tipo == UNO)
		{
			//std::cout << "Step 2.1: " << '\n';
			std::string f = get_file();
			f += "/" + iltosl(cita.cita.uno->libro);
			f += "/" + std::to_string(cita.cita.uno->capitulo);
			f += "/" + std::to_string(cita.cita.uno->versiculo);
			//std::cout << "Step 2.2: " << '\n';
			std::ifstream fs;
			fs.open(f);
			std::string line,strcita;
			//std::cout << "Step 2.3: " << '\n';
		  	if (fs.is_open())
		  	{
				//std::cout << "Step 2.3.1: " << '\n';
				while ( std::getline (fs,line) )
				{
				  //std::cout << line << '\n';
					strcita += line;
				}
				fs.close();
				return strcita;
		  	}
			else
			{
				std::cerr << "Fail to open file : " << f << "\n";
			}
		}
		else if(cita.tipo == RANGO)
		{
			std::string strcita;
			//std::cout << "Step 2.1: " << '\n';
			for(int i = cita.cita.rango->versIni; i <= cita.cita.rango->versFin; i++)
			{
				//std::cout << "Leyendo versiculo :" << i << " de " << cita.cita.rango->versFin << "\n";
				std::string f = get_file();
				f += "/" + iltosl(cita.cita.rango->libro);
				f += "/" + std::to_string(cita.cita.rango->capitulo);
				f += "/" + std::to_string(i);
				//std::cout << "Open " << f << "\n";
				std::ifstream fs;
				fs.open(f);
				std::string line;
				//std::cout << "Step 2.3: " << '\n';
			  	if (fs.is_open())
			  	{
					//std::cout << "Step 2.3.1: " << '\n';
					while ( std::getline (fs,line) )
					{					  
						strcita += line;
					}
					fs.close();
			  	}
				else
				{
					std::cerr << "Fail to open file : " << f << "\n";
				}
			}
					return strcita;
		}
		
		return "Cita...";
	}





	std::string IBiblion::get_file()
	{
		return file;
	}
	std::string IBiblion::iltosl(Libros l)
	{
		if(get_lenguaje().compare("Español") == 0)
		{
			switch(l)
			{
				case GENESIS:
					return "Genesis";
				case EXODO:
					return  "Exodo";
				case LEVITICOS:	
					return "Leviticos";
				case NUMEROS:
					return "Numeros";
				case DEUTERONOMIOS:
					return "Deuteronomios";
				case JOSUE:
					return "Jouse";
				case JUECES:
					return "Jueces";
				case RUT:
					return "Rut";
				case SAMUEL1:
					return "Samuel1";
				case SAMUEL2:
					return "Samuel2";
				case REYES1:
					return "Reyes1";
				case REYES2:
					return "Reyes2";
				case CRONICAS1:
					return "Cronicas1";
				case CRONICAS2:
					return "Crinicas2";
				case ESDRAS:
					return "Esdras";
				case NEHEMIAS:
					return "Nehemias";
				case ESTER:
					return "Ester";
				case JOB:
					return "Job";
				case SALMOS:
					return "Salmos";
				case PROVERBIOS:
					return "Proverbios";
				case ECLESIASTES:
					return "Eclesiastes";
				case CANTARES:
					return "Canteres";
				case ISAIAS:
					return "Isaisas";
				case JEREMIAS:
					return "Jeremias";
				case LAMENTACIONES:
					return "Lamentaciones";
				case EZEQUIEL:
					return "Ezquiel";
				case DANIEL:
					return "Daniel";
				case OSEAS:
					return "Oseas";
				case JOEL:
					return "Joel";
				case AMOS:
					return "Amos";
				case ABDIAS:
					return "Abdias";
				case JONAS:
					return "Jonas";
				case MIQUEAS:
					return "Miqueas";
				case NAHUM:
					return "Nahum";
				case HABACUC:
					return "Habacuc";
				case SOFONIAS:
					return "Sofonias";
				case HAGEO:
					return "Hageo";
				case ZACARIAS:
					return "Zacarias";
				case MALAQUIAS:
					return "Malaquias";
				case SANMATEO:
					return "SanMateo";
				case SANMARCOS:
					return "SanMarcos";
				case SANLUCAS:
					return "SanLucas";
				case SANJUAN:
					return "SanJuan";
				case HECHOS:
					return "Hechos";
				case ROMANOS:
					return "Romanos";
				case CORINTIOS1:
					return "Corintios";
				case CORINTIOS2:
					return "Corintios";
				case GALATAS:
					return "Galatas";
				case EFESIOS:
					return "Efisios";
				case FILIPENSES:
					return "Filipensese";
				case COLOSENSES:
					return "Colosenses";
				case TESALONICENSES1:
					return "Tesalonicenses1";
				case TESALONICENSES2:
					return "Tesalonicenses2";
				case TIMOTEO1:
					return "Tomiteo1";
				case TIMOTEO2:
					return "Tomiteo2";
				case TITO:
					return "Tito";
				case FILEMON:
					return "Filemon";
				case HEBREOS:
					return "Hebreos";
				case SANTIAGO:
					return "Santiago";
				case PEDRO1:
					return "Pedro1";
				case PEDRO2:
					return "Pedro2";
				case JUAN1:
					return "Juan1";
				case JUAN2:
					return "Juan2";
				case JUAN3:
					return "Juan3";
				case JUDAS:
					return "Judas";
				case APOCALIPSIS:
					return "Apocalipsis";	
			}
		}
	}
	
	Cita IBiblion::parseCita(const std::string& str)
	{		
		octetos_biblion_Tray ty;
		octetos_biblion_init(&ty);

		ty.str = str.c_str();
		ty.lenguaje = get_lenguaje().c_str();
		int ret = cita_parser(&ty);

		if(ret == 0) return ty.cita;
		return ty.cita;		
	}
	const std::string& IBiblion::get_lenguaje() const
	{
		return lenguaje;
	}
	IBiblion::IBiblion(std::string& file)
	{
		this->file = file; 
		 
		libconfig::Config cfg;
		std::string fconf = file + "/.conf";
		cfg.readFile(fconf.c_str());
		
		const libconfig::Setting& root = cfg.getRoot();
		lenguaje = (const std::string&)root["lenguaje"];
		//std::cout << "Lenguaje : " << lenguaje << "\n";	 
	}




	bool getPackageInfo(core::Artifact& packinfo)
	{
		packinfo.name = PACKAGE;
		packinfo.brief = "Libreria Biblion de Octetos.";
		//packinfo.url = "https://github.com/azaeldevel/";
		packinfo.name_decorated = "Libreria Biblion de Octetos";
		//std::string ver = VERSION;
		if(!packinfo.version.set(VERSION)) 
		{
			printf("Version '%s'\n",VERSION);
			return false;
		}		
		packinfo.licence.type = core::Licence::Type::GPLv3;		
		packinfo.licence.name_public = PACKAGE;
		packinfo.licence.owner = "Azael Reyes";
		packinfo.licence.year = 2020;
        packinfo.licence.contact = "azael.devel@gmail.com";
		
		return true;	
	}
}