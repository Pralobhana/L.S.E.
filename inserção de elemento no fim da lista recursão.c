#include <stdio.h>

struct ptr
{
	int valor;
	struct ptr *prox;
};

struct ptr *inicio;
void cria_lista_inv(struct ptr *aux);
void inserir_fim(struct ptr *aux, int valor);
void mostra(struct ptr *aux);

int main()
{
	cria_lista_inv((struct ptr *)NULL);
	inserir_fim(inicio,10);
	mostra(inicio);
}

void cria_lista_inv(struct ptr *aux)
{
	int valor;
	printf("ENTRE COM O VALOR: ");
	scanf("%d", &valor);
	if (valor >= 0)
	{
		aux = (struct ptr *)malloc(sizeof(struct ptr));
		aux->valor = valor;
		aux->prox = inicio;
		inicio = aux;
		cria_lista_inv(aux);
	}
	aux = (struct ptr *)NULL;
}

void inserir_fim(struct ptr *aux, int valor)
{
	if(aux == inicio)
	{
		printf("ENTRE COM O VALOR: ");
		scanf("%d", &valor);
	}
		if(inicio == (struct ptr *)NULL)
		{
			inicio = (struct ptr *)malloc(sizeof(struct ptr));
			inicio->valor = valor;
			inicio->prox = (struct ptr *)NULL;
		}
		else
			if(aux->prox != (struct ptr *)NULL)
				inserir_fim(aux->prox, valor);
			else
			{
				aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
				aux = aux->prox;
				aux->valor = valor;
				aux->prox = (struct ptr *)NULL;
			}
}

void mostra(struct ptr *aux)
{
	if(inicio == (struct ptr *)NULL)
		printf("LISTA VAZIA!");
	else
	{
		if(aux != (struct ptr *)NULL)
		{
			printf("%d\t", aux->valor);
			mostra(aux->prox);
		}
	}
}
