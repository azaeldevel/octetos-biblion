
#include <CUnit/Basic.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "config.h"


#include <octetos/core/Artifact.hh>

#include <biblion.hh>


int init(void)
{
	return 0;
}
int clean(void)
{
	return 0;
}

void testParser()
{
	std::string strbib = "tests/biblion";
	octetos::Biblion bib(strbib);
	std::string msg = bib.get_Cita("Genesis 1:1");
	if(msg.length() > 0)
	{
		if(msg.compare("#error") == 0) CU_ASSERT(false);
		CU_ASSERT(true);
	}
	else
	{
		CU_ASSERT(false);
	}
}

int main(int argc, char *argv[])
{  
	octetos::core::Artifact packinfo;
	/*if(!octetos::getPackageInfo(packinfo))
	{
		std::cerr << "Fallo en consulta de version.\n";
		return EXIT_FAILURE;
	}
	if(octetos::core::Error::check())
	{
		std::cerr << (const std::string&)octetos::core::Error::get() << "\n";
		return EXIT_FAILURE;
	}
	*/
	
	/*int majorNumber = 0;
	if(majorNumber != packinfo.version.getMajor())
	{
		std::cerr << "Cree un nuevo archivo para la version '" << majorNumber << "' estas en la version'" << (std::string)packinfo.version << "'\n";
		return EXIT_FAILURE;
	}*/
	
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	/*std::string& pkName = packinfo.name;
	std::string headerTest = pkName + " " + (std::string)packinfo.version + "\n" + packinfo.licence.getText() + "\n" + packinfo.brief + "\n";*/
	CU_pSuite pSuite = NULL;
	pSuite = CU_add_suite("Modulo de pruebas para Bibilion", init, clean);
	if (NULL == pSuite) 
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	if ((NULL == CU_add_test(pSuite, "Probando el Parser.", testParser)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();	
}
