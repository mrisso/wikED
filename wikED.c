//wikED.c

#include "wikED.h"

//Funções
void addPagina(char *nome, char *arquivo, Pagina **lista)
{
	inserePagina(lista, initPagina(nome,arquivo));
}

int delPagina(char *nome, Pagina **lista)
{
	return retiraPagina(lista,nome);
}

void addEditor(char *nome, Editor **lista)
{
	insereEditor(lista, initEditor(nome));
}

int delEditor(char *nome, Editor **lista, Pagina **paginas)
{
	Pagina *andador;
	Colab *aux;

	if(retiraEditor(lista,nome))
		return NAO_ENCONTRADO;
	
	for(andador=*paginas;andador!=NULL;andador=nextPagina(andador))
			for(aux=*pageColabs(andador);aux!=NULL;aux=nextColab(aux))
				if(!strcmp(editorName(colabEditor(aux)),nome))
					retiraColab(pageColabs(andador),colabName(aux));

	return OK;
}

int addColab(char *nome, char *content, char *autor, char *pagina, Editor *editores, Pagina **lista)
{
	Pagina *andador;
	Colab *new;

	if((new=initColab(nome,content,autor,editores))==NULL)
		return NAO_ENCONTRADO; //Editor Não Encontrado

	for(andador=*lista;andador!=NULL;andador=nextPagina(andador))
		if(!strcmp(pageName(andador),pagina))
			insereColab(pageColabs(andador),new);

	return OK;
}

int delColab(char *nome, char *autor, char *pagina, Pagina **lista)
{
	Pagina *andador;
	Colab *aux;

	for(andador=*lista;andador!=NULL;andador=nextPagina(andador))
		if(!strcmp(pageName(andador),pagina))
			for(aux=*pageColabs(andador);aux!=NULL;aux=nextColab(aux))
				if(!strcmp(colabName(aux),nome) && !strcmp(editorName(colabEditor(aux)),autor))
				{
					colabSetStatus(aux,DELETADO);
					return OK;
				}
	return NAO_ENCONTRADO;
}

void addLink(char *orig, char *dest, Pagina **lista)
{
	Pagina *andador, *origem, *destino;

	for(andador=*lista;andador!=NULL;andador=nextPagina(andador))
	{
		if(!strcmp(pageName(andador),orig))
			origem = andador;
		
		else if(!strcmp(pageName(andador),dest))
			destino = andador;
	}

	criarLink(&origem,destino);
}

void printPagina(char *nome, Pagina *lista)
{
	FILE *arquivo;
	Pagina *andador;
	Colab *aux;
	Link *aux2;
	
	for(andador=lista;andador!=NULL;andador=nextPagina(andador))
		if(!strcmp(pageName(andador),nome))
		{
			arquivo=fopen(pageFile(andador),"w");
			fprintf(arquivo,"%s\n\n",pageName(andador));
			fprintf(arquivo,"--> Historico de contribuicoes\n");
			for(aux=*pageColabs(andador);aux!=NULL;aux=nextColab(aux))
				fprintf(arquivo,"%s %s\n",editorName(colabEditor(aux)),colabName(aux));
			fprintf(arquivo,"\n--> Links\n");
			for(aux2=pageLinks(andador);aux2!=NULL;aux2=nextLink(aux2))
				fprintf(arquivo,"%s %s\n",pageName(pageOnLink(aux2)), pageFile(pageOnLink(aux2)));
			fprintf(arquivo,"\n--> Textos\n");
			for(aux=*pageColabs(andador);aux!=NULL;aux=nextColab(aux))
			{
				if(colabStatus(aux))
				{
					fprintf(arquivo,"\n-------- %s (%s) --------\n\n",colabName(aux),editorName(colabEditor(aux)));
					fprintf(arquivo,"%s\n",colabContent(aux));
				}
			}

			break;
		}

	fclose(arquivo);
}

int caminho(char *orig, char *dest, Pagina **lista)
{
	Pagina *andador = *lista;
	Link *aux;
	int check=0;

	if(andador==NULL)
		return SEM_CAMINHO;

	for(;andador!=NULL;andador=nextPagina(andador))
			if(!strcmp(pageName(andador),orig))
			{
				for(aux=pageLinks(andador);aux!=NULL;aux=nextLink(aux))
					if(!pageStatus(pageOnLink(aux)))
					{
						chPageStatus(pageOnLink(aux),SIM);
						check = check ||
								(!strcmp(pageName(pageOnLink(aux)),dest)) ||
								caminho(pageName(pageOnLink(aux)),dest,lista);
						if(check)
							return COM_CAMINHO;
					}
				return SEM_CAMINHO;
			}

	return SEM_CAMINHO;
}

void printWikED(Pagina *lista)
{
	Pagina *andador;

	for(andador=lista;andador!=NULL;andador=nextPagina(andador))
		printPagina(pageName(andador),lista);
}
