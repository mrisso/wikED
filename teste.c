#include "wikED.h"

int main(void)
{
	Pagina *lPaginas;
	Editor *lEditores;

	lPaginas = initListaPagina();
	lEditores = initListaEditor();

	addPagina("Fisica","fisica.txt",&lPaginas);
	addPagina("Artes","artes.txt",&lPaginas);
	addPagina("UFES", "ufes.txt",&lPaginas);

	if(delPagina("Psicologia",&lPaginas))
		printf("Não existe a página Psicologia!\n");

	addEditor("Pedro",&lEditores);
	addEditor("Maria",&lEditores);
	addEditor("Joao",&lEditores);
	addEditor("Ana",&lEditores);
	addEditor("Edu",&lEditores);

	if(delEditor("Edu",&lEditores,&lPaginas))
		printf("Não existe Edu!\n");

	if(addColab("c1.txt","CONTEÚDOC1","Maria","Fisica",lEditores,&lPaginas))
		printf("Não existe Maria!\n");

	if(addColab("c2.txt","CONTEÚDOC2","Maria","Fisica",lEditores,&lPaginas))
		printf("Não existe Maria!\n");

	if(addColab("c3.txt","CONTEÚDOC3","Pedro","Fisica",lEditores,&lPaginas))
		printf("Não existe Pedro!\n");

	addLink("Fisica","Artes",&lPaginas);

	if(addColab("c4.txt","CONTEÚDOC4","Maria","Artes",lEditores,&lPaginas))
		printf("Não existe Maria!\n");

	if(addColab("c5.txt","CONTEÚDOC5","Ana","Artes",lEditores,&lPaginas))
		printf("Não existe Ana!\n");

	if(delColab("c5.txt","Ana","Artes",&lPaginas))
		printf("Erro excluíndo c5.txt");

	addLink("Artes","Fisica",&lPaginas);

	if(addColab("c6.txt","CONTEÚDOC6","Joao","UFES",lEditores,&lPaginas))
		printf("Não existe Joao!\n");

	if(addColab("c7.txt","CONTEÚDOC7","Joao","UFES",lEditores,&lPaginas))
		printf("Não existe Joao!\n");

	if(addColab("c8.txt","CONTEÚDOC8","Ana","UFES",lEditores,&lPaginas))
		printf("Não existe Ana!\n");

	addLink("UFES","Fisica",&lPaginas);
	addLink("UFES","Artes",&lPaginas);

	if(caminho("UFES","Fisica",&lPaginas))
		printf("Existe caminho UFES -> Fisica\n");
	else
		printf("Não existe caminho UFES -> Fisica\n");

	chAllStatus(&lPaginas,NAO);

	if(caminho("Fisica","UFES",&lPaginas))
		printf("Existe caminho Fisica -> UFES\n");
	else
		printf("Não existe caminho Fisica -> UFES\n");

	chAllStatus(&lPaginas,NAO);

	freeListaPagina(lPaginas);
	freeListaEditor(lEditores);

	return OK;
}
