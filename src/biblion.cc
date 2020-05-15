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

#include "biblion.hh"

extern "C" int yylex(const char* str);


namespace octetos
{
	Biblion::Biblion(std::string& file) : IBiblion(file)
	{
	}
	
	std::string Biblion::get_Cita(const std::string& c)
	{
		yylex("Genesis 1:1");

		return "";
	}







	 
	 IBiblion::IBiblion(std::string& file)
	 {
		 this->file = file;
	 }
}