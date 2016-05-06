//Constantes
#define OK											0
#define NAO_ENCONTRADO								1

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pagina.h"
#include "colaboracao.h"

//Estruturas
struct pagina
{
	char *nome;
	char *arquivo;
	Pagina *prox;
	//Adicionar lista de Contribuições
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

void inserePagina(Pagina *lista, Pagina *novaPagina)
{
	Pagina *andador = lista;

	if(andador==NULL)
		lista=novaPagina;
	
	else
	{
		while(andador->prox!=NULL)
			andador=andador->prox;
		andador->prox = novaPagina;
	}
}

int retiraPagina(Pagina *lista, char *xPagina)
{
	Pagina *ant, *prox;

	ant = NULL;
	prox = lista;
	if(prox==NULL)
		return NAO_ENCONTRADO;

	else
	{
		while(prox->prox!=NULL)
		{
			if(!strcmp(prox->nome,xPagina))
			{
				//Adicionar free às Contribuições
				ant->prox=prox->prox;
				free(prox->nome);
				free(prox->arquivo);
				free(prox);
				return OK;
			}
			ant = prox;
			prox = prox->prox;
		}
	}
	return NAO_ENCONTRADO;
}






