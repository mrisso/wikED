#ifndef COLAB_H_
#define COLAB_H_

typedef struct colab Colab;

Colab *initListaColab(void);

Colab *initColab(char *nome, char *content);

void insereColab(Colab *lista, Colab *novaColab);

void retiraColab(Colab *lista, char* xColab);

Colab *freeListaColab(Colab *lista);

#endif
