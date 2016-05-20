//colaboracao.c

#include "colaboracao.h"

//Estruturas
struct colab
{
	char *nome, *content;
	int delete; //Flag para excluir página mantendo histórico de contribuições
	Editor *autor;
	Colab *prox;
};

//Funções
Colab *initListaColab(void)
{
	return NULL;
}

Colab *initColab(char *nome, char *content, char *autor, Editor *editores)
{
	Editor *editor = procuraEditor(editores,autor);
	Colab *new;

	if(editor == NULL)
		return NULL; // Função procuraEditor retorna NULL caso não exista este editor
					// initColab também retornará NULL como um sinal de falha na inicialização.
	
	new = (Colab*) malloc(sizeof(Colab)); // Alocando estrutura Colab
	
	//Alocando espaço para strings
	new->nome = (char*) malloc((strlen(nome)+1)*sizeof(char));
	new->content = (char*) malloc((strlen(content)+1)*sizeof(char));

	//Copiando Strings
	strcpy(new->nome,nome);
	strcpy(new->content,content);

	//Linkando Colab ao seu autor
	new->autor = editor;

	//Incializando campo delete como 0 para verificações futuras
	new->delete = EXISTENTE;

	new->prox = NULL;

	return new; //Retorna nova Colab
}

void insereColab(Colab **lista, Colab *novaColab)
{
	Colab *andador = *lista; //Andador recebe a primeira posição da lista

	if(andador==NULL) //Se a lista for vazia, insere na primeira posição
		*lista=novaColab; 
	
	else
	{
		while(andador->prox!=NULL) //Navega até a última posição da lista
			andador=andador->prox;
		andador->prox = novaColab; //Insere no campo prox da última estrutura
	}
}

int retiraColab(Colab **lista, char *xColab)
{
	Colab *ant, *aux;

	ant = NULL;
	aux= *lista;
	if(aux==NULL) //Caso a lista seja vazia, retorna NAO_ENCONTRADO
		return NAO_ENCONTRADO;

	else
	{
		while(aux!=NULL) //Anda até o fim da lista
		{
			if(!strcmp(aux->nome,xColab)) //Compara nome do elemento com o nome da
										//colaboração a ser excluída
			{
				if(aux==*lista)
					*lista = aux->prox; //Caso seja a primeira posição, mude para a prox
				else
					ant->prox=aux->prox; //Caso seja qualquer outra posição,
										//Mude o prox do anterior para o prox do atual
				//Libera campos alocados na estrutura
				free(aux->nome);
				free(aux->content);
				free(aux);
				return OK;
			}
			ant = aux;
			aux = aux->prox;
		}
	}
	return NAO_ENCONTRADO; //Retorna NAO_ENCONTRADO caso chegue ao final sem retornar OK
}

Colab *freeListaColab(Colab *lista)
{
	Colab *aux, *prox;

	aux = lista; //aux recebe a primeira posição da lista

	while(aux!=NULL) //Anda pelas posições da lista até o fim
	{
		prox = aux->prox; //Guarda a posição do próximo elemento
		//Libera os campos alocados na estrutura
		free(aux->nome);
		free(aux->content);
		free(aux);
		aux = prox; //Vai para a próxima posição
	}

	return NULL;
}

char *colabName(Colab *colab)
{
	return colab->nome;
}

char *colabContent(Colab *colab)
{
	return colab->content;
}

Colab *nextColab(Colab *colab)
{
	return colab->prox;
}

Editor *colabEditor(Colab *colab)
{
	return colab->autor;
}

void colabSetStatus(Colab *colab, int status)
{
	colab->delete = status;
}

int colabStatus(Colab *colab)
{
	return colab->delete;
}
