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

#include "biblion.hh"
#include "cita-lexer.h"


namespace octetos
{
	Biblion::Biblion(std::string& file) : IBiblion(file)
	{
	}
	
	std::string Biblion::get_Cita(const std::string& str)
	{
		octetos_biblion_Tray ty;
		octetos_biblion_init(&ty);

		//ty.str = (const char*)malloc(str.size());
		//strcpy((char*)ty.str,(char*)str.c_str());
		ty.str = str.c_str();
		//ty.lenguaje = BiblionLenguaje::ESPANOL;
		ty.lenguaje = get_lenguaje().c_str();
		int ret = cita_parser(&ty);

		if(ret == 0) return "Cita...";
		return "#error";
	}







	 const std::string& IBiblion::get_lenguaje() const
	 {
		return lenguaje;
	 }
	 IBiblion::IBiblion(std::string& file)
	 {
		this->file = file; 
		 
		libconfig::Config cfg;
		cfg.readFile(file.c_str());
		
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