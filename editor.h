#ifndef EDITOR_H_
#define EDITOR_H_

#define OK											0
#define NAO_ENCONTRADO								1

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct editor Editor;

Editor *initListaEditor(void);

Editor *initEditor(char* nome);

void insereEditor(Editor **lista, Editor *novoEditor);

Editor *procuraEditor(Editor *lista, char *nome);

int retiraEditor(Editor **lista, char* xEditor);

Editor *freeListaEditor(Editor *lista);

char *editorName(Editor *editor);

#endif
