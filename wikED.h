#ifndef WIKED_H_
#define WIKED_H_

//Constantes
#define NAO_ENCONTRADO								1
#define OK											0

#define DELETADO									0

#define SEM_CAMINHO									0
#define COM_CAMINHO									1

#define NAO											0
#define SIM											1

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor.h"
#include "colaboracao.h"
#include "pagina.h"

void addPagina(char *nome, char *arquivo, Pagina **lista);

int delPagina(char *nome, Pagina **lista);

void addEditor(char *nome, Editor **lista);

int delEditor(char *nome, Editor **lista, Pagina **paginas);

int addColab(char *nome, char *content, char *autor, char *pagina, Editor *editores, Pagina **lista);

int delColab(char *nome, char *autor, char *pagina, Pagina **lista);

void addLink(char *orig, char *dest, Pagina **lista);

void printPagina(char *nome, Pagina *lista);

int caminho(char *orig, char *dest, Pagina **lista);

void printWikED(Pagina *paginas, Editor *editores);

#endif
