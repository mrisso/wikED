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
 * - nome (string)
 * - content (string) ~ Conteúdo da colaboração
 * - delete (int) ~ Flag determina se colaboração existe ou não
 * - autor (Editor *) ~ Ponteiro para seu autor na lista de editores (tipo opaco definido em editor.h)
 * - prox (Colab *) ~ Ponteiro para a propria estrutura
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
 * inputs: ponteiro para a lista (passagem por referência) e ponteiro para nova colaboração
 */
void insereColab(Colab **lista, Colab *novaColab);

int retiraColab(Colab **lista, char* xColab);

Colab *freeListaColab(Colab *lista);

char *colabName(Colab *colab);

char *colabContent(Colab *colab);

Colab *nextColab(Colab *colab);

Editor *colabEditor(Colab *colab);

void colabSetStatus(Colab *colab, int status);

int colabStatus(Colab *colab);

#endif
