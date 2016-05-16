#ifndef COLAB_H_
#define COLAB_H_

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
