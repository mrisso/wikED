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

/*Estrutura Link (tipo opaco)
 - pagina (Pagina *) ~ Ponteiro para uma pagina (definido abaixo)
 - prox (Link *) ~ Ponteiro para a propria estrutura
 */
typedef struct link Link;

/*Estrutura Pagina (tipo opaco)
 - nome (string)
 - arquivo (string) ~ nome do arquivo que será gerado para a pagina
 - repeat (int) ~ Flag para navegação (usado na função caminhos)
 - colabs (Colab *) ~ Ponteiro para primeira colaboração de uma lista (cada página possui uma lista de colaborações - definido em colaboracao.h)
 - links (Link *) ~ Ponteiro para o primeiro link de uma lista (cada página possui uma lista de links para outras páginas)
 */
typedef struct pagina Pagina;

/*Inicializa uma lista de Páginas
 * inputs: nenhum
 * output: ponteiro para NULL
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro para primeira posição inicializado
 */
Pagina *initListaPagina(void);

/*Inicializa uma estrutura Pagina
 * inputs: o nome e o nome do arquivo pertecente à página
 * output: um ponteiro para a estrutura criada
 * pre-condicao: nome e nome de arquivo válidos
 * pos-condicao: estrutura criada com campos nome e arquivo copiados; ponteiros prox, colabs e links com o valor NULL
 */
Pagina *initPagina(char *nome, char *arquivo);

/*Insere uma página na última posição da lista de colaborações
 * inputs: ponteiro para a lista e ponteiro para a nova página
 * output: nenhum
 * pre-condicao: lista de páginas e nova estrutura inicializada
 * pos-condicao: lista possui nova estrutura na ultima posição
 */
void inserePagina(Pagina **lista, Pagina *novaPagina);

/*Retira uma página da lista de páginas
 * inputs: ponteiro para a lista e nome da página a ser retirada
 * output: retorna 0(OK) caso a página tenha sido retirada e 1(NAO_ENCONTRADO) caso não exista a página na lista
 * pre-condicao: lista com contribuições não vazia e nome da contribuição válido
 * pos-condicao: lista não possui mais a página com nome xPagina (string)
 */
int retiraPagina(Pagina **lista, char *xPagina);

/*Libera todo o espaço de memória alocado pela lista de páginas
 * inputs: lista de páginas
 * output: ponteiro para NULL (lista vazia)
 * pre-condicao: lista de páginas não vazia
 * pos-condicao: memória alocada pela lista liberada
 */
Pagina *freeListaPagina(Pagina *lista);

/*Retorna a lista de colaborações de uma página
 * inputs: ponteiro para a página desejada
 * output: ponteiro para a lista de colaborações (Colab **)  da página desejada
 * pre-condicao: estrutura Pagina válida e inicializada
 * pos-condicao: nenhuma
 */
Colab **pageColabs(Pagina *lista);

/*Retorna o campo prox da estrutura Pagina
 * inputs: ponteiro para a página desejada
 * output: campo prox (Pagina *) da página desejada
 * pre-condicao: estrutura Pagina válida e inicializada
 * pos-condicao: nenhuma
 */
Pagina *nextPagina(Pagina *pagina);

/*Retorna o campo nome da estrutura Pagina
 * inputs: ponteiro para a página desejada
 * output: campo nome (char *) da página desejada
 * pre-condicao: estrutura Pagina válida e inicializada
 * pos-condicao: nenhuma
 */
char *pageName(Pagina *pagina);

/*Retorna o campo arquivo da estrutura Pagina
 * inputs: ponteiro para a página desejada
 * output: campo arquivo (char *) da página desejada
 * pre-condicao: estrutura Pagina válida e inicializada
 * pos-condicao: nenhuma
 */
char *pageFile(Pagina *pagina);

/*Cria um link entre duas páginas
 * inputs: ponteiro para o ponteiro da página de origem e ponteiro para a página destino
 * output: nenhum
 * pre-condicao: duas paginas válidas
 * pos-condicao: pagina origem tem em sua lista de links um link para a pagina destino
 */
void criarLink(Pagina **orig, Pagina *dest);

/*Libera todo o espaço de memória (recursivamente) alocado pela lista de links
 * inputs: lista de links
 * output: nenhum
 * pre-condicao: lista de links não vazia
 * pos-condicao: memória alocada pela lista liberada
 */
void freeListaLink(Link *lista);

/*Retorna o campo repeat da estrutura Pagina
 * inputs: ponteiro para a página desejada
 * output: campo repeat (int) da página desejada
 * pre-condicao: estrutura Pagina válida e inicializada
 * pos-condicao: nenhuma
 */
int pageStatus(Pagina *pagina);

/*Retorna o campo links da estrutura Pagina
 * inputs: ponteiro para a página desejada
 * output: campo links (Link *) da página desejada
 * pre-condicao: estrutura Pagina válida e inicializada
 * pos-condicao: nenhuma
 */
Link *pageLinks(Pagina *pagina);

/*Retorna o campo prox da estrutura Link 
 * inputs: ponteiro para o link desejado
 * output: campo prox (Link *) do link desejado
 * pre-condicao: estrutura Link válida e inicializada
 * pos-condicao: nenhuma
 */
Link *nextLink(Link *link);

/*Altera o status (campo repeat) de uma página
 * inputs: ponteiro para a página e status desejado (int)
 * output: nenhum
 * pre-condicao: estrutura Pagina válida e inicializada
 * pos-condicao: estrutura Pagina com o campo repeat alterado para int status
 */
void chPageStatus(Pagina *pagina, int status);

/*Altera recursivamente o status (campo repeat) de todas as páginas de uma lista
 * inputs: ponteiro para a lista de páginas e status desejado (int)
 * output: nenhum
 * pre-condicao: lista de páginas não vazia
 * pos-condicao: lista de páginas com o campo repeat de todas as páginas alterado para int status
 */
void chAllStatus(Pagina **lista, int status);

/*Retorna o campo pagina da estrutura Link
 * inputs: ponteiro para o link desejado
 * output: campo pagina (Pagina *) do link desejado
 * pre-condicao: estrutura Link válida e inicializada
 * pos-condicao: nenhuma
 */
Pagina *pageOnLink(Link *link);

//Debug
/*Imprime as páginas (e suas contribuições) de uma lista de páginas na linha de comando
 * inputs: lista de páginas
 * output: nenhum
 * pre-condicao: lista de páginas não vazia
 * pos-condicao: lista de páginas e suas contribuições impressas na tela (CLI)
 */
void imprimePaginas(Pagina *lista);

#endif
