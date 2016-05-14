//pagina.c
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
	Colab *colabs;
};

//Funções
Pagina *initListaPagina(void)
{
	return NULL;
}

Pagina *initPagina(char *nome, char *arquivo)
{
	Pagina *new = (Pagina*) malloc(sizeof(Pagina));
	new->nome = (char*) malloc((strlen(nome)+1)*sizeof(char));
	new->arquivo = (char*) malloc((strlen(arquivo)+1)*sizeof(char));

	strcpy(new->nome,nome);
	strcpy(new->arquivo,arquivo);
	new->prox = NULL;
	new->colabs = NULL;

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
	Pagina *ant, *aux;

	ant = NULL;
	aux= lista;
	if(aux==NULL)
		return NAO_ENCONTRADO;

	else
	{
		while(aux!=NULL)
		{
			if(!strcmp(aux->nome,xPagina))
			{
				if(aux==lista)
					lista = aux->prox;
				else
					ant->prox=aux->prox;
				freeListaColab(aux->colabs); //Função de Free de colaboracao.h 
				free(aux->nome);
				free(aux->arquivo);
				free(aux);
				return OK;
			}
			ant = aux;
			aux = aux->prox;
		}
	}
	return NAO_ENCONTRADO;
}

Pagina *freeListaPagina(Pagina *lista)
{
	Pagina *aux, *prox;

	aux = lista;

	while(aux!=NULL)
	{
		prox = aux->prox;
		freeListaColab(aux->colabs); //Função de Free de colaboracao.h
		free(aux->nome);
		free(aux->arquivo);
		free(aux);
		aux = prox;
	}

	return NULL;
}
