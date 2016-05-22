//main.c

//Constantes
#define NUMERO_ARGUMENTOS						2
#define MAX_ARGS								3
#define MAX_TAM									30

#define OK										0
#define ERRO_NUMERO_ARGUMENTOS					1
#define ERRO_ABRINDO_ARQUIVO					2
#define COMANDO_INEXISTENTE						3

#include "wikED.h"

int main (int argc, char *argv[])
{
	FILE *entrada;
	char comando[MAX_TAM], argumentos[MAX_ARGS][MAX_TAM], *colab;
	Pagina *lPaginas;
	Editor *lEditores;

	if(argc!=NUMERO_ARGUMENTOS)
	{
		printf("Modo de uso: %s <arquivo-de-entrada>\n", argv[0]);
		return ERRO_NUMERO_ARGUMENTOS;
	}

	if((entrada = fopen(argv[1],"r"))==NULL)
	{
		printf("Erro ao abrir arquivo!\n");
		return ERRO_ABRINDO_ARQUIVO;
	}

	lPaginas = initListaPagina();
	lEditores = initListaEditor();

	while(1)
	{
		fscanf(entrada,"%s ",comando); // Lê a primeira palavra da linha (comando)
		if(!strcmp(comando,"INSEREPAGINA"))
		{
			fscanf(entrada,"%s %s\n",argumentos[0],argumentos[1]);
			addPagina(argumentos[0],argumentos[1],&lPaginas);
		}

		else if(!strcmp(comando,"RETIRAPAGINA"))
		{
			fscanf(entrada,"%s\n",argumentos[0]);
			delPagina(argumentos[0],&lPaginas);
		}

		else if(!strcmp(comando,"INSEREEDITOR"))
		{
			fscanf(entrada,"%s\n",argumentos[0]);
			addEditor(argumentos[0],&lEditores);
		}

		else if(!strcmp(comando,"RETIRAEDITOR"))
		{
			fscanf(entrada,"%s\n",argumentos[0]);
			delEditor(argumentos[0],&lEditores);
		}

		else if(!strcmp(comando,"INSERECONTRIBUICAO"))
		{
			fscanf(entrada,"%s %s %s\n",argumentos[0],argumentos[1],argumentos[2]);
			colab = readColabFile(argumentos[2]);
			addColab(argumentos[2],colab,argumentos[1],argumentos[0],lEditores,&lPaginas);
			free(colab);
		}

		else if(!strcmp(comando,"RETIRACONTRIBUICAO"))
		{
			fscanf(entrada,"%s %s %s\n",argumentos[0],argumentos[1],argumentos[2]);
			delColab(argumentos[2],argumentos[1],argumentos[0],&lPaginas);
		}

		else if(!strcmp(comando,"INSERELINK"))
		{
			fscanf(entrada,"%s %s\n",argumentos[0],argumentos[1]);
			addLink(argumentos[0],argumentos[1],&lPaginas);
		}

		else if(!strcmp(comando,"RETIRALINK"))
		{
			fscanf(entrada,"%s %s\n",argumentos[0],argumentos[1]);
			//delLink(argumentos[0],argumentos[1],&lPaginas);
		}

		else if(!strcmp(comando,"CAMINHO"))
		{
			fscanf(entrada,"%s %s\n",argumentos[0],argumentos[1]);
			caminho(argumentos[0],argumentos[1],&lPaginas);
		}

		else if(!strcmp(comando,"IMPRIMEPAGINA"))
		{
			fscanf(entrada,"%s\n",argumentos[0]);
			printPagina(argumentos[0],lPaginas,lEditores);
		}

		else if(!strcmp(comando,"IMPRIMEWIKED"))
		{
			fscanf(entrada,"\n");
			printWikED(lPaginas,lEditores);
		}

		else if(!strcmp(comando,"FIM"))
			break;

		else
		{
			printf("Comando %s inexistente\n", comando);
			return COMANDO_INEXISTENTE;
		}
			
	}

	fclose(entrada);

	freeListaEditor(lEditores);
	freeListaPagina(lPaginas);

	return OK;
}
