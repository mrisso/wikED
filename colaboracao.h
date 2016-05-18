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

typedef struct colab Colab;

Colab *initListaColab(void);

Colab *initColab(char *nome, char *content, char *autor, Editor *editores);

void insereColab(Colab **lista, Colab *novaColab);

int retiraColab(Colab **lista, char* xColab);

Colab *freeListaColab(Colab *lista);

char *colabName(Colab *colab);

char *colabContent(Colab *colab);

Colab *nextColab(Colab *colab);

Editor *colabEditor(Colab *colab);

void colabStatus(Colab *colab, int status);

#endif
