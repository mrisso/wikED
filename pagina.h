#ifndef PAGINA_H_
#define PAGINA_H_

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

void criarLink(Pagina **orig, Pagina *dest);

int pageStatus(Pagina *pagina);

Link *pageLinks(Pagina *pagina);

Link *nextLink(Link *link);

void chPageStatus(Pagina *pagina, int status);

Pagina *pageOnLink(Link *link);

//Debug
void imprimePaginas(Pagina *lista);

#endif
