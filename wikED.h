#ifndef WIKED_H_
#define WIKED_H_

//Constantes
#define NAO_ENCONTRADO								1
#define OK											0

#define DELETADO									0

#define SEM_CAMINHO									0
#define COM_CAMINHO									1

#define NAO											0
#define SIM											1

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor.h"
#include "colaboracao.h"
#include "pagina.h"

/*Adiciona uma página na wikED
 * inputs: nome da página, nome do arquivo a ser criado, ponteiro para a lista de páginas wikED
 * output: nenhum
 * pre-condicao: nome da página e nome do arquivo válidos; lista de páginas wikED inicializada
 * pos-condicao: página com o nome e arquivo (copiados para estrutura) adicionada à lista de páginas wikED
 */
void addPagina(char *nome, char *arquivo, Pagina **lista);

/*Deleta uma página da wikED
 * inputs: nome da página e ponteiro para lista de páginas wikED
 * output: retorna 0(OK) caso a página tenha sido deletada e 1(NAO_ENCONTRADO) caso não exista a página na wikED
 * pre-condicao: lista de páginas wikED não vazia e nome válido para página
 * pos-condicao: página deletada da wikED
 */
int delPagina(char *nome, Pagina **lista);

/*Adiciona um editor na wikED
 * inputs: nome do editor e ponteiro para a lista de editores wikED
 * output: nenhum
 * pre-condicao: nome do editor válido; lista de editores wikED inicializada
 * pos-condicao: editor com seu nome (copiado para estrutura) adicionado à lista de editores wikED
 */
void addEditor(char *nome, Editor **lista);

/*Exclui um editor da wikED
 * inputs: nome do editor e ponteiro para a lista de editores wikED
 * output: retorna 0(OK) caso o editor tenha sido excluído e 1(NAO_ENCONTRADO) caso não exista o editor na wikED
 * pre-condicao: lista de editores wikED não vazia e nome válido para editor
 * pos-condicao: editor excluído da wikED
 */
int delEditor(char *nome, Editor **lista);

/*Adiciona uma colaboração à wikED
 * inputs: nome da contribuição, conteúdo, nome do autor, nome da página (strings); lista de editores e ponteiro para lista de páginas wikED
 * output: retorna 0(OK) caso o editor seja válido e a colaboração tenha sido adicionada à pagina especificada e 1(NAO_ENCONTRADO) casoo o editor não exista (página não adicionada)
 * pre-condicao: strings válidas para nome, conteúdo, autor e página; editor existe na lista de editores; lista de editores e páginas não vazias
 * pos-condicao: colaboração, com todos os campos de strings copiadas e ponteiro para o editor, adicionada à wikED
 */
int addColab(char *nome, char *content, char *autor, char *pagina, Editor *editores, Pagina **lista);

/*Deleta uma colaboração da wikED
 * inputs: nome da contribuição, nome do autor, nome da página (strings) e ponteiro para lista de páginas wikED
 * output: retorna 0(OK) caso a página tenha sido deletada e 1(NAO_ENCONTRADO) caso a página não tenha sido encontrada
 * pre-condicao: strings válidas para nome, autor e página; lista de páginas não nula
 * pos-condicao: campo delete da colaboração escolhida alterado para 0(DELETADO) ~ Flag
 */
int delColab(char *nome, char *autor, char *pagina, Pagina **lista);

/*Adiciona um link de uma página de origem para uma página destino
 * inputs: nome da página de origem e destino (strings); ponteiro para lista de páginas
 * output: nenhum
 * pre-condicao: strings válidas para os nomes das páginas; lista de páginas não nula; páginas existem
 * pos-condicao: link adicionado da página origem para a página destino
 */
void addLink(char *orig, char *dest, Pagina **lista);

/*Retira um link de uma página de origem para uma página destino
 * inputs: nome da página de origem e destino (string); ponteiro para a lista de páginas
 * output: nenhum
 * pre-condicao: strings válidas para os nomes das páginas; lista de páginas não nula; páginas existem; link existe
 * pos-condicao: link retirado da página de origem para a página destino
 */
void delLink(char *orig, char *dest, Pagina **lista);

/*Imprime uma página da wikED
 * inputs: nome da página, lista de páginas, lista de editores
 * output: nenhum
 * pre-condicao: nome válido para página, lista de páginas e editores não nulas
 * pos-condicao: conteúdo da página escrito em seu respectivo arquivo (campo arquivo da estrutura Pagina)
 */
void printPagina(char *nome, Pagina *lista, Editor *editores);

/*Verifica (recursivamente) se existe um caminho da página de origem para a página de destino
 * inputs: nome da página de origem e destino (strings); ponteiro para lista de páginas
 * output: retorna 0(SEM_CAMINHO) se não existir caminho da página de origem para a de destino. Caso contrário retorna 1(COM_CAMINHO)
 * pre-condicao: nome válido para os nomes das páginas; lista de páginas não nula
 * pos-condicao: nenhuma
 */
int caminho(char *orig, char *dest, Pagina **lista);

/*Imprime todas as páginas da wikED
 * inputs: lista de páginas, lista de editores wikED
 * output: nenhum
 * pre-condicao: listas de páginas e editores não nulas
 * pos-condicao: conteúdo das páginas escrito em seus respectivos arquivos (campo arquivo da estrutura Pagina)
 */
void printWikED(Pagina *lista, Editor *editores);

/*Lê um arquivo inteiro de colaboração fornecido
 * inputs: nome do arquivo (string)
 * output: conteúdo inteiro do arquivo (string) ou NULL caso não seja possível ler arquivo
 * pre-condicao: nome de arquivo válido e arquivo de colaboração existe
 * pos-condicao: nenhuma
 */
char *readColabFile(char *fileName);

#endif
