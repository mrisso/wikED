//colaboracao.c
//Constantes

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colaboracao.h"
#include "editor.h"

//Estruturas
struct colab
{
	char *nome, *arquivo, *content;
	int flag;
	Editor *autor;
	Colab *prox;
};

//Funções
Colab *initListaColab(void)
{
	return NULL;
}

Colab *initColab(char *nome, char *arquivo, char *content, char *autor)
{
	Editor *editor = procuraEditor(autor);
	Colab *new;

	if(editor == NULL)
		return NULL; // Função procuraEditor retorna NULL caso não exista este editor
					// initColab também retornará NULL como um sinal de falha na inicialização.
	
	new = (Colab*) malloc(sizeof(Colab)); // Alocando estrutura Colab
	
	//Alocando espaço para strings
	new->nome = (char*) malloc((strlen(nome)+1)*sizeof(char));
	new->arquivo = (char*) malloc((strlen(arquivo)+1)*sizeof(char));
	new->content = (char*) malloc((strlen(content)+1)*sizeof(char));

	//Copiando Strings
	strcpy(new->nome,nome);
	strcpy(new->nome,nome);
	strcpy(new->arquivo,arquivo);
	strcpy(new->content,content);

	//Linkando Colab ao seu autor
	new->autor = editor;

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
