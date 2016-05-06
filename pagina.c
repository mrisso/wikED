//Constantes

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pagina.h"

//Estruturas
struct pagina
{
	char *nome;
	char *arquivo;
	Pagina *prox;
};

Pagina *initListaPagina(void)
{
	return NULL;
}

Pagina *initPagina(char *nome, char *arquivo)
{
	Pagina *new = (Pagina*) malloc(sizeof(Pagina));

	strcpy(new->nome,nome);
	strcpy(new->arquivo,arquivo);
	new->prox = NULL;

	return new;
}

