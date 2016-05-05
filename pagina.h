#ifndef PAGINA_H_
#define PAGINA_H_

typedef struct pagina Pagina;

Pagina *initListaPagina(void);

Pagina *initPagina(char *nome);

void inserePagina(Pagina *lista, Pagina *novaPagina);

void retiraPagina(Pagina *lista, Pagina *xPagina);

void excluirPagina(Pagina *lista, Pagina *xPagina);

#endif
