//wikED.c
//Constantes
#define NAO_ENCONTRADO								1
#define OK											0

//Includes

#include "wikED.h"

//Funções
void addPagina(char *nome, char *arquivo, Pagina **lista)
{
	inserePagina(lista, initPagina(nome,arquivo));
}

int delPagina(char *nome, Pagina **lista)
{
	return retiraPagina(lista,nome);
}

void addEditor(char *nome, Editor **lista)
{
	insereEditor(lista, initEditor(nome));
}

int delEditor(char *nome, Editor **lista, Pagina **paginas)
{
	Pagina *andador;
	Colab *aux;

	if(retiraEditor(lista,nome))
		return NAO_ENCONTRADO;
	
	for(andador=*paginas;andador!=NULL;andador=nextPagina(andador))
			for(aux=*pageColabs(andador);aux!=NULL;aux=nextColab(aux))
				if(!strcmp(editorName(colabEditor(aux)),nome))
					retiraColab(pageColabs(andador),colabName(aux));

	return OK;
}
