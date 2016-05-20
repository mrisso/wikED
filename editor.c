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

	//Inicializando campo prox
	new->prox = NULL;

	return new;
}

void insereEditor(Editor **lista, Editor *novoEditor)
{
	Editor *andador = *lista; //Andador recebe a primeira posição da lista

	if(andador==NULL) //Se a lista for vazia, insere na primeira posição
		*lista=novoEditor;
	
	else
	{
		while(andador->prox!=NULL) //Navega até a última posição da lista
			andador=andador->prox; 
		andador->prox = novoEditor; //Insere no campo prox da última estrutura
	}
}

Editor *procuraEditor(Editor *lista, char *nome)
{
	Editor *andador = lista; //Andador recebe a primeira posição da lista

	while(andador!=NULL) //Anda até o fim da lista
	{
		if(!strcmp(andador->nome,nome))
			return andador; //Retorna o editor caso encontrado
		andador=andador->prox;
	}

	return NULL;
}

int retiraEditor(Editor **lista, char* xEditor)
{
	Editor *ant, *aux;

	ant = NULL;
	aux= *lista;
	if(aux==NULL) //Caso a lista seja vazia, retorna NAO_ENCONTRADO
		return NAO_ENCONTRADO;

	else
	{
		while(aux!=NULL) //Anda até o fim da lista
		{
			if(!strcmp(aux->nome,xEditor)) //Compara nome do elemento com o nome do
											//editor a ser excluído
			{
				if(aux==*lista)
					*lista = aux->prox; //Caso seja a primeira posição, mude para a prox
				else
					ant->prox=aux->prox; //Caso seja qualquer outra posição,
										//Mude o prox do anterior para o prox do atual
				//Libera campos alocados na estrutura
				free(aux->nome);
				free(aux);
				return OK;
			}
			ant = aux;
			aux = aux->prox;
		}
	}
	return NAO_ENCONTRADO; //Retorna NAO_ENCONTRADO caso chegue ao final sem retornar OK
}

Editor *freeListaEditor(Editor *lista)
{
	Editor *aux, *prox;

	aux = lista; //aux recebe a primeira posição da lista

	while(aux!=NULL) //Anda pelas posições da lista até o fim
	{
		prox = aux->prox; //Guarda a posição do próximo elemento
		//Libera os campos alocados na estrutura
		free(aux->nome);
		free(aux);
		aux = prox; //Vai para próxima posição
	}

	return NULL;
}

char *editorName(Editor *editor)
{
	return editor->nome;
}
