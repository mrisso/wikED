#include <stdio.h>
#include <stdlib.h>

#include "pagina.h"
#include "colaboracao.h"
#include "editor.h"

int main(void)
{
	Pagina *lPaginas, *novaPagina;
	Editor *lEditores, *novoEditor;
	Colab *novaColab, *pageList;
	
	lPaginas = initListaPagina();
	lEditores = initListaEditor();

	novaPagina = initPagina("Computação", "computacao.txt");
	inserePagina(&lPaginas,novaPagina);

	novaPagina = initPagina("Jornalismo", "jornalismo.txt");
	inserePagina(&lPaginas,novaPagina);
	
	novaPagina = initPagina("UFES", "ufes.txt");
	inserePagina(&lPaginas,novaPagina);

	if((novaColab=initColab("c1.txt","tudo isso e mais um pouco", "Jesus", (Editor *)lEditores))==NULL)
		printf("1Não existe este editor\n");
	else
		insereColab(pageColabs(novaPagina),novaColab);

	novoEditor = initEditor("Jesus");
	insereEditor(&lEditores,novoEditor);

	if((novaColab=initColab("c1.txt","tudo isso e mais um pouco", "Jesus", (Editor *) lEditores))==NULL)
		printf("2Não existe este editor\n");
	else
		insereColab(pageColabs(novaPagina),novaColab);
	

	novoEditor = initEditor("Mariah");
	insereEditor(&lEditores,novoEditor);

	if((novaColab=initColab("c2.txt","tudo isso e mais um pouco", "Mariah", (Editor *) lEditores))==NULL)
		printf("3Não existe este editor\n");
	else
		insereColab(pageColabs(novaPagina),novaColab);

	imprimePaginas(lPaginas);

	freeListaPagina(lPaginas);
	freeListaEditor(lEditores);

	return 0;		
}
