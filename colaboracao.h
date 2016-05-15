#ifndef COLAB_H_
#define COLAB_H_

typedef struct colab Colab;

Colab *initListaColab(void);

Colab *initColab(char *nome, char *content, char *autor, void *editores);

void insereColab(Colab **lista, Colab *novaColab);

int retiraColab(Colab **lista, char* xColab);

Colab *freeListaColab(Colab *lista);

char *colabName(Colab *colab);

char *colabContent(Colab *colab);

Colab *nextColab(Colab *colab);

#endif
