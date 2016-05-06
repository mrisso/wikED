#ifndef EDITOR_H_
#define EDITOR_H_

typedef struct editor Editor;

Editor *initListaEditor(void);

Editor *initEditor(char* nome);

void insereEditor(Editor *lista, Editor *novoEditor);

void retiraEditor(Editor *lista, char* editor);

Editor *freeListaEditor(Editor *lista);

#endif
