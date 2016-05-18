//editor.c

#include "editor.h"

//Estruturas
struct editor
{
	char *nome;
	Editor *prox;
};

//Funções
Editor *initListaEditor(void)
{
	return NULL;
}

Editor *initEditor(char *nome)
{
	//Alocando editor
	Editor *new = (Editor*) malloc(sizeof(Editor));

	//Alocando espaço para nome
	new->nome = (char*) malloc((strlen(nome)+1)*sizeof(char));

	//Copiando nome
	strcpy(new->nome, nome);

	new->prox = NULL;

	return new;
}

void insereEditor(Editor **lista, Editor *novoEditor)
{
	Editor *andador = *lista;

	if(andador==NULL)
		*lista=novoEditor;
	
	else
	{
		while(andador->prox!=NULL)
			andador=andador->prox;
		andador->prox = novoEditor;
	}
}

Editor *procuraEditor(Editor *lista, char *nome)
{
	Editor *andador = lista;

	while(andador!=NULL)
	{
		if(!strcmp(andador->nome,nome))
			return andador;
		andador=andador->prox;
	}

	return NULL;
}

int retiraEditor(Editor **lista, char* xEditor)
{
	Editor *ant, *aux;

	ant = NULL;
	aux= *lista;
	if(aux==NULL)
		return NAO_ENCONTRADO;

	else
	{
		while(aux!=NULL)
		{
			if(!strcmp(aux->nome,xEditor))
			{
				if(aux==*lista)
					*lista = aux->prox;
				else
					ant->prox=aux->prox;
				free(aux->nome);
				free(aux);
				return OK;
			}
			ant = aux;
			aux = aux->prox;
		}
	}
	return NAO_ENCONTRADO;
}

Editor *freeListaEditor(Editor *lista)
{
	Editor *aux, *prox;

	aux = lista;

	while(aux!=NULL)
	{
		prox = aux->prox;
		free(aux->nome);
		free(aux);
		aux = prox;
	}

	return NULL;
}

char *editorName(Editor *editor)
{
	return editor->nome;
}
