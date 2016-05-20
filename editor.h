#ifndef EDITOR_H_
#define EDITOR_H_

#define OK											0
#define NAO_ENCONTRADO								1

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Estrutura Editor (tipo opaco)
 - nome (string)
 - prox (Editor *) ~ Ponteiro para a própria estrutura
 */
typedef struct editor Editor;

/*Inicializa uma lista de Editores
 * inputs: nenhum
 * output: ponteiro para NULL
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro para a primeira posição inicializado
 */
Editor *initListaEditor(void);

/*Inicializa uma estrutura Editor
 * inputs: nome (string)
 * output: um ponteiro para a estrutura criada
 * pre-condicao: nome válido para a estrutura
 * pos-condicao: estrutura criada com o campo nome copiado e campo prox com valor NULL
 */
Editor *initEditor(char* nome);

/*Insere um editor na última posição da lista de editores
 * inputs: ponteiro para a lista e ponteiro para o novo editor
 * output: nenhum
 * pre-condicao: lista de editores e nova estrutura incializada
 * pos-condicao: lista possui nova estrutura na ultima posição
 */
void insereEditor(Editor **lista, Editor *novoEditor);

/*Procura um editor na lista de editores
 * inputs: lista de editores e nome do editor a ser pesquisado
 * output: ponteiro para o editor se encontrado. Caso contrário, ponteiro para NULL
 * pre-condicao: lista de editores não vazia e nome válido para editor
 * pos-condicao: nenhuma
 */
Editor *procuraEditor(Editor *lista, char *nome);

/*Retira um editor da lista de editores
 * inputs: ponteiro para a lista e nome do editor a ser retirado
 * output: retorna 0(OK) caso o editor tenha sido retirado e 1(NAO_ENCONTRADO) caso não exista o editor na lista
 * pre-condicao: lista de editores não vazia e nome do editor válido
 * pos-condicao: lista não possui mais o editor com nome xEditor (string)
 */
int retiraEditor(Editor **lista, char* xEditor);

/*Libera todo o espaço de memória alocado pela lista de editores
 * inputs: lista de editores
 * outputs: ponteiro para NULL (lista vazia)
 * pre-condicao: lista de editores não vazia
 * pos-condicao: memória alocada pela lista liberada
 */
Editor *freeListaEditor(Editor *lista);

/*Retorna o campo nome da estrutura Editor
 * input: ponteiro para o editor desejado
 * output: campo nome (string) do editor desejado
 * pre-condicao: estrutura Editor válida e inicializada
 * pos-condicao: nenhuma
 */
char *editorName(Editor *editor);

#endif
