//pagina.c

#include "pagina.h"

//Estruturas
struct link
{
	Pagina *pagina;
	Link *prox;
};

struct pagina
{
	char *nome;
	char *arquivo;
	int repeat;
	Pagina *prox;
	Colab *colabs;
	Link *links;
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
	new->links = NULL;
	new->repeat = NAO;

	return new;
}

void inserePagina(Pagina **lista, Pagina *novaPagina)
{
	Pagina *andador = *lista;

	if(andador==NULL)
		*lista=novaPagina;
	
	else
	{
		while(andador->prox!=NULL)
			andador=andador->prox;
		andador->prox = novaPagina;
	}
}

int retiraPagina(Pagina **lista, char *xPagina)
{
	Pagina *ant, *aux;

	ant = NULL;
	aux= *lista;
	if(aux==NULL)
		return NAO_ENCONTRADO;

	else
	{
		while(aux!=NULL)
		{
			if(!strcmp(aux->nome,xPagina))
			{
				if(aux==*lista)
					*lista = aux->prox;
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
		freeListaLink(aux->links);
		free(aux->nome);
		free(aux->arquivo);
		free(aux);
		aux = prox;
	}

	return NULL;
}

Colab **pageColabs(Pagina *pagina)
{
	return &pagina->colabs;
}

void imprimePaginas(Pagina *lista)
{
	Pagina *andador = lista;
	Colab *andaColab;

	while(andador!=NULL)
	{
		printf("Pg: %s\nArq: %s\n",andador->nome,andador->arquivo);
		andaColab = *pageColabs(andador);
		while(andaColab != NULL)
		{
			printf("Colab: %s\n%s\n\n",colabName(andaColab),colabContent(andaColab));
			andaColab = nextColab(andaColab);
		}
		printf("---------------------------------------------------------------------\n");
		andador = andador->prox;
	}
}

Pagina *nextPagina(Pagina *pagina)
{
	return pagina->prox;
}

char *pageName(Pagina *pagina)
{
	return pagina->nome;
}

void criarLink(Pagina **orig, Pagina *dest)
{
	Link *andador = (*orig)->links;
	Link *new = (Link *) malloc(sizeof(Link));

	new->pagina = dest;
	new->prox = NULL;

	if(andador==NULL)
		(*orig)->links = new;

	else
	{
		while(andador->prox!=NULL)
			andador=andador->prox;
		andador->prox = new;
	}
}	

int pageStatus(Pagina *pagina)
{
	return pagina->repeat;
}

Link *pageLinks(Pagina *pagina)
{
	return pagina->links;
}

Link *nextLink(Link *link)
{
	return link->prox;
}

void chPageStatus(Pagina *pagina, int status)
{
	pagina->repeat = status;
}

Pagina *pageOnLink(Link *link)
{
	return link->pagina;
}

void freeListaLink(Link *lista)
{
	Link *aux, *prox;

	aux = lista;

	while(aux!=NULL)
	{
		prox = aux->prox;
		free(aux);
		aux = prox;
	}
}
