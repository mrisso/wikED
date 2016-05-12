//colaboracao.c
//Constantes
#define OK									0
#define NAO_ENCONTRADO						1

#define DELETADO							0
#define EXISTENTE							1

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colaboracao.h"
#include "editor.h"

//Estruturas
struct colab
{
	char *nome, *content;
	int delete;
	Editor *autor;
	Colab *prox;
};

//Funções
Colab *initListaColab(void)
{
	return NULL;
}

Colab *initColab(char *nome, char *content, char *autor)
{
	Editor *editor = procuraEditor(autor);
	Colab *new;

	if(editor == NULL)
		return NULL; // Função procuraEditor retorna NULL caso não exista este editor
					// initColab também retornará NULL como um sinal de falha na inicialização.
	
	new = (Colab*) malloc(sizeof(Colab)); // Alocando estrutura Colab
	
	//Alocando espaço para strings
	new->nome = (char*) malloc((strlen(nome)+1)*sizeof(char));
	new->content = (char*) malloc((strlen(content)+1)*sizeof(char));

	//Copiando Strings
	strcpy(new->nome,nome);
	strcpy(new->content,content);

	//Linkando Colab ao seu autor
	new->autor = editor;

	//Incializando campo delete como 0 para verificações futuras
	new->delete = 0;

	new->prox = NULL;

	return new; //Retorna nova Colab
}

void insereColab(Colab *lista, Colab *novaColab)
{
	Colab *andador = lista;

	if(andador==NULL)
		lista=novaColab;
	
	else
	{
		while(andador->prox!=NULL)
			andador=andador->prox;
		andador->prox = novaColab;
	}
}

int retiraColab(Colab *lista, char *xColab)
{
	Colab *ant, *aux;

	ant = NULL;
	aux= lista;
	if(aux==NULL)
		return NAO_ENCONTRADO;

	else
	{
		while(aux!=NULL)
		{
			if(!strcmp(aux->nome,xColab))
			{
				ant->prox=aux->prox;
				free(aux->nome);
				free(aux->content);
				free(aux);
				return OK;
			}
			ant = aux;
			aux = aux->prox;
		}
	}
	return NAO_ENCONTRADO;
}
