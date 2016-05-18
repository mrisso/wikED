#ifndef PAGINA_H_
#define PAGINA_H_

//Constantes
#define OK											0
#define NAO_ENCONTRADO								1

#define NAO											0
#define SIM											1

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colaboracao.h"

typedef struct link Link;
typedef struct pagina Pagina;

Pagina *initListaPagina(void);

Pagina *initPagina(char *nome, char *arquivo);

void inserePagina(Pagina **lista, Pagina *novaPagina);

int retiraPagina(Pagina **lista, char *xPagina);

Pagina *freeListaPagina(Pagina *lista);

Colab **pageColabs(Pagina *lista);

Pagina *nextPagina(Pagina *pagina);

char *pageName(Pagina *pagina);

char *pageFile(Pagina *pagina);

void criarLink(Pagina **orig, Pagina *dest);

void freeListaLink(Link *lista);

int pageStatus(Pagina *pagina);

Link *pageLinks(Pagina *pagina);

Link *nextLink(Link *link);

void chPageStatus(Pagina *pagina, int status);

void chAllStatus(Pagina **lista, int status);

Pagina *pageOnLink(Link *link);

//Debug
void imprimePaginas(Pagina *lista);

#endif
