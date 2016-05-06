#ifndef PAGINA_H_
#define PAGINA_H_

typedef struct pagina Pagina;

Pagina *initListaPagina(void);

Pagina *initPagina(char *nome, char *arquivo);

void inserePagina(Pagina *lista, Pagina *novaPagina);

void retiraPagina(Pagina *lista, Pagina *xPagina);

Pagina *freeListaPagina(Pagina *lista);

#endif
