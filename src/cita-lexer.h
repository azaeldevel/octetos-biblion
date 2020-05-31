#ifndef OCTETOS_BIBLIOS_LEXER_HH
#define OCTETOS_BIBLIOS_LEXER_HH

typedef unsigned short Capitulo;
typedef unsigned short Versiculo;
enum Libros
{
	NINGUNO,
	GENESIS,
	EXODO,
	LEVITICOS,
	NUMEROS,
	DEUTERONOMIOS,
	JOSUE,
	JUECES,
	RUT,
	SAMUEL1,
	SAMUEL2,
	REYES1,
	REYES2,
	CRONICAS1,
	CRONICAS2,
	ESDRAS,
	NEHEMIAS,
	ESTER,
	JOB,
	SALMOS,
	PROVERBIOS,
	ECLESIASTES,
	CANTARES,
	ISAIAS,
	JEREMIAS,
	LAMENTACIONES,
	EZEQUIEL,
	DANIEL,
	OSEAS,
	JOEL,
	AMOS,
	ABDIAS,
	JONAS,
	MIQUEAS,
	NAHUM,
	HABACUC,
	SOFONIAS,
	HAGEO,
	ZACARIAS,
	MALAQUIAS,
	SANMATEO,
	SANMARCOS,
	SANLUCAS,
	SANJUAN,
	HECHOS,
	ROMANOS,
	CORINTIOS1,
	CORINTIOS2,
	GALATAS,
	EFESIOS,
	FILIPENSES,
	COLOSENSES,
	TESALONICENSES1,
	TESALONICENSES2,
	TIMOTEO1,
	TIMOTEO2,
	TITO,
	FILEMON,
	HEBREOS,
	SANTIAGO,
	PEDRO1,
	PEDRO2,
	JUAN1,
	JUAN2,
	JUAN3,
	JUDAS,
	APOCALIPSIS	
};
/*enum BiblionLenguaje
{
	SILENCIO,
	ESPANOL
};*/
enum Cita_Tipo
{
	NOCITA,
	UNO,
	RANGO,
};
struct Cita_Uno
{
	enum Libros libro;
	Capitulo capitulo;
	Versiculo versiculo;
};
struct Cita_Rango
{
	enum Libros libro;
	Capitulo capitulo;
	Versiculo versIni;
	Versiculo versFin;
};
enum BiblionStates
{
	INICIAL,
	LIBRO_LEIDO,
	CAPITULO_LEIDO,
	COLUMNA_LEIDA,
	VERSICULO_LEIDO,
};
struct Cita
{
	enum Cita_Tipo tipo;
	union
	{
		struct Cita_Uno* uno;
		struct Cita_Rango* rango;
	} cita;
};
struct octetos_biblion_Tray
{
    int dysplay_erro;
	void* buffer;
	const char* str;
	enum BiblionStates state;
	const char* lenguaje;
	enum Cita_Tipo cita_tipo;
	struct Cita cita;
};
#ifdef __cplusplus  
extern "C" {
#endif 
	void octetos_biblion_init(struct octetos_biblion_Tray* ty);
    int cita_parser(struct octetos_biblion_Tray* ty);
#ifdef __cplusplus 
} 
#endif

#endif
