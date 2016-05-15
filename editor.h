#ifndef EDITOR_H_
#define EDITOR_H_

typedef struct editor Editor;

Editor *initListaEditor(void);

Editor *initEditor(char* nome);

void insereEditor(Editor **lista, Editor *novoEditor);

Editor *procuraEditor(Editor *lista, char *nome);

int retiraEditor(Editor **lista, char* xEditor);

Editor *freeListaEditor(Editor *lista);

#endif
