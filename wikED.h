#ifndef WIKED_H_
#define WIKED_H_

void addPagina(char *nome, char *arquivo, char **lista);

int delPagina(char *nome, Pagina **lista);

void addEditor(char *nome, Editor **lista);

int delEditor(char *nome, Editor **lista);

void addColab(char *nome, char *content, char *autor, char *pagina, Editor *editores, Pagina **lista);

int delColab(char *nome, char *autor, char *pagina, Pagina **lista);

void addLink(char *orig, char *dest, Pagina **lista);

void printPagina(char *nome, Pagina *lista);

void caminho(char *orig, char *dest, Pagina *lista);

void printWikED(Pagina *paginas, Editor *editores);

#endif
