
#include "cita-lexer.h"


void octetos_biblion_init(struct octetos_biblion_Tray* ty)
{
	ty->str = 0;
	ty->state = INICIAL;
	ty->dysplay_erro = 0;
	ty->buffer = 0;
	ty->lenguaje = NINGUNO;
	ty->cita = 0;
	ty->cita_tipo = NOCITA;
}