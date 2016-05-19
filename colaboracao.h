#ifndef COLAB_H_
#define COLAB_H_

//Constantes
#define OK									0
#define NAO_ENCONTRADO						1

#define DELETADO							0
#define EXISTENTE							1

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor.h"

/*Estrutura Colaboração (tipo opaco)
 - nome (string)
 - content (string) ~ Conteúdo da colaboração
 - delete (int) ~ Flag determina se colaboração existe ou não
 - autor (Editor *) ~ Ponteiro para seu autor na lista de editores (tipo opaco definido em editor.h)
 - prox (Colab *) ~ Ponteiro para a propria estrutura
 */
typedef struct colab Colab;

/*Inicializa uma lista de Colaborações
 * inputs: nenhum
 * output: ponteiro para primeira posição inicializado
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro para estrutura existe e aponta para NULL
 */
Colab *initListaColab(void);

/*Inicializa uma estrutura Colab
 * inputs: o nome, o conteúdo, o nome do autor e a lista de editores existentes
 * outputs: um ponteiro para a estrutura criada caso o editor exista. Caso contrário, ponteiro para NULL
 * pre-condicao: nome e conteudo validos, e nome do autor existente na lista de editores
 * pos-condicao: estrutura criada com os campos nome, conteudo copiados; ponteiro prox com valor NULL; ponteiro autor apontando para o autor na lista de editores
 */
Colab *initColab(char *nome, char *content, char *autor, Editor *editores);

/*Insere uma colaboração na última posição da lista de colaborações
 * inputs: ponteiro para a lista e ponteiro para nova colaboração
 * outputs: nenhum
 * pre-condicao: lista inicializada e nova estrutura inicializada
 * pos-condicao: lista possui nova estrutura na ultima posição
 */
void insereColab(Colab **lista, Colab *novaColab);

/*Retira uma colaboração da lista de colaborações
 * inputs: ponteiro para a lista e noma da colaboração a ser retirada
 * outputs: retorna 0(OK) caso a contribuição tenha sido retirada e 1(NAO_ENCONTRADO) caso não exista a colaboração na lista
 * pre-condicao: lista com contribuições não vazia e nome da contribuição valido
 * pos-condicao: lista não possui mais a contribuição com nome xColab (string)
 */
int retiraColab(Colab **lista, char* xColab);

/*Libera todo o espaço de memória (recursivamente) alocado pela lista de colaborações
 * inputs: lista de colaborações
 * outputs: ponteiro para NULL (lista vazia)
 * pre-condicao: lista de contribuições não vazia
 * pos-condicao: memória alocada pela lista liberada
 */
Colab *freeListaColab(Colab *lista);

/*Retorna o campo nome da estrutura Colab
 * input: ponteiro para colaboração desejada
 * output: campo nome (string) da colaboração desejada
 * pre-condicao: estrutura Colab válida e inicializada
 * pos-condicao: nenhuma
 */
char *colabName(Colab *colab);

/*Retorna o campo content da estrutura Colab
 * input: ponteiro para colaboração desejada
 * output: campo content (string) da colaboração desejada
 * pre-condicao: estrutura Colab válida e inicializada
 * pos-condicao: nenhuma
 */
char *colabContent(Colab *colab);

/*Retorna o campo prox da estrutura Colab
 * input: ponteiro para colaboração desejada
 * output: campo prox (Colab *) da colaboração desejada
 * pre-condicao: estrutura Colab válida e inicializada
 * pos-condicao: nenhuma
 */
Colab *nextColab(Colab *colab);

/*Retorna o campo autor da estrutura Colab
 * input: ponteiro para colaboração desejada
 * output: campo autor (Editor *) da colaboração desejada
 * pre-condicao: estrutura Colab válida e inicializada
 * pos-condicao: nenhuma
 */
Editor *colabEditor(Colab *colab);

/*Atualiza o status de uma colaboração
 * input: ponteiro para a colaboração desejada e codigo do status desejado (int)
 * output: nenhum
 * pre-condicao: estrutura Colab válida e inicializada
 * pos-condicao: estrutura Colab com o campo delete alterado para int status
 */
void colabSetStatus(Colab *colab, int status);

/*Retorna o status de uma colaboração
 * input: ponteiro para a colaboração desejada
 * output: campo delete (int) da colaboração desejada
 * pre-condicao: estrutura Colab válida e inicializada
 * pos-condicao: nenhuma
 */
int colabStatus(Colab *colab);

#endif
