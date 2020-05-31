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

#include <string>
#include <octetos/core/Artifact.hh>
#include "cita-lexer.h"

namespace octetos
{


/**
* \brief retorna la informacion del paquete
**/
bool getPackageInfo(core::Artifact&);

/**
* \brief Interface Biblion
**/
class IBiblion
{
private:
	std::string file;
	std::string lenguaje;

protected:
	Cita parseCita(const std::string&);

public:
	IBiblion(std::string& file);
	virtual std::string get_Cita(const std::string&) = 0;
	const std::string& get_lenguaje()const;	
	std::string iltosl(Libros);	
	std::string get_file();
};

/**
*\brief Mi formato de biblia
*/
class Biblion : public IBiblion
{
private:
	
public:
	Biblion(std::string& file);
	virtual std::string get_Cita(const std::string&);
};

/**
*\brief Formato de Youversion
*/
class Youversion : public IBiblion
{
public:
	Youversion(std::string& file);
	virtual std::string get_Cita(const std::string&);
};


}