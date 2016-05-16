#ifndef PAGINA_H_
#define PAGINA_H_

#include "colaboracao.h"

typedef struct pagina Pagina;

Pagina *initListaPagina(void);

Pagina *initPagina(char *nome, char *arquivo);

void inserePagina(Pagina **lista, Pagina *novaPagina);

int retiraPagina(Pagina **lista, char *xPagina);

Pagina *freeListaPagina(Pagina *lista);

Colab **pageColabs(Pagina *lista);

Pagina *nextPagina(Pagina *pagina);

//Debug
void imprimePaginas(Pagina *lista);

#endif
