//main.c

//Constantes
#define NUMERO_ARGUMENTOS						2
#define MAX_ARGS								3
#define MAX_TAM									30

#define OK										0
#define ERRO_NUMERO_ARGUMENTOS					1
#define ERRO_ABRINDO_ARQUIVO					2

#define LOG_FILE								"log.txt"

#include "wikED.h"

int main (int argc, char *argv[])
{
	FILE *entrada, *log;
	char comando[MAX_TAM], argumentos[MAX_ARGS][MAX_TAM], *colab;
	Pagina *lPaginas;
	Editor *lEditores;

	if(argc!=NUMERO_ARGUMENTOS)
	{
		printf("Modo de uso: %s <arquivo-de-entrada>\n", argv[0]);
		return ERRO_NUMERO_ARGUMENTOS;
	}

	if((entrada = fopen(argv[1],"r"))==NULL || (log = fopen(LOG_FILE,"w"))==NULL)
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
			if(delPagina(argumentos[0],&lPaginas))
				fprintf(log,"ERRO: Não existe a página %s\n",argumentos[0]);
		}

		else if(!strcmp(comando,"INSEREEDITOR"))
		{
			fscanf(entrada,"%s\n",argumentos[0]);
			addEditor(argumentos[0],&lEditores);
		}

		else if(!strcmp(comando,"RETIRAEDITOR"))
		{
			fscanf(entrada,"%s\n",argumentos[0]);
			if(delEditor(argumentos[0],&lEditores))
				fprintf(log,"ERRO: Não existe editor de nome %s\n",argumentos[0]);
		}

		else if(!strcmp(comando,"INSERECONTRIBUICAO"))
		{
			fscanf(entrada,"%s %s %s\n",argumentos[0],argumentos[1],argumentos[2]);
			if((colab = readColabFile(argumentos[2]))==NULL)
				fprintf(log,"ERRO: Não foi possível ler arquivo %s\n",argumentos[2]);
			else if(addColab(argumentos[2],colab,argumentos[1],argumentos[0],lEditores,&lPaginas))
			{
				fprintf(log,"ERRO: Não foi possível adicionar colaboração %s. Editor %s inexistente\n", argumentos[2], argumentos[0]);
				free(colab);
			}
			else
				free(colab);
		}

		else if(!strcmp(comando,"RETIRACONTRIBUICAO"))
		{
			fscanf(entrada,"%s %s %s\n",argumentos[0],argumentos[1],argumentos[2]);
			if(delColab(argumentos[2],argumentos[1],argumentos[0],&lPaginas))
				fprintf(log,"ERRO: Não existe a colaboração %s de autor %s na página %s\n",argumentos[2],argumentos[1],argumentos[0]);
		}

		else if(!strcmp(comando,"INSERELINK"))
		{
			fscanf(entrada,"%s %s\n",argumentos[0],argumentos[1]);
			addLink(argumentos[0],argumentos[1],&lPaginas);
		}

		else if(!strcmp(comando,"RETIRALINK"))
		{
			fscanf(entrada,"%s %s\n",argumentos[0],argumentos[1]);
			delLink(argumentos[0],argumentos[1],&lPaginas);
		}

		else if(!strcmp(comando,"CAMINHO"))
		{
			fscanf(entrada,"%s %s\n",argumentos[0],argumentos[1]);
			if(caminho(argumentos[0],argumentos[1],&lPaginas))
				fprintf(log,"HA CAMINHO DA PAGINA %s PARA %s\n",argumentos[0],argumentos[1]);
			else
				fprintf(log,"NAO HA CAMINHO DA PAGINA %s PARA %s\n",argumentos[0],argumentos[1]);
			chAllStatus(&lPaginas,NAO);
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
			fscanf(entrada,"\n");
			fprintf(log,"ERRO: Comando %s inexistente\n", comando);
		}
	}

	fclose(entrada);
	fclose(log);

	freeListaEditor(lEditores);
	freeListaPagina(lPaginas);

	return OK;
}
