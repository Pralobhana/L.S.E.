#include <stdio.h>

struct ptr 
{
	int valor;
	struct ptr *prox;
};

struct ptr *inicio;
void organizar();
void mostra(struct ptr *aux);
void cria_lista_inv();

int main()
{
	cria_lista_inv();
	mostra(inicio);
	organizar();
	printf("\n");
	mostra(inicio);
}

void mostra(struct ptr *aux)
{
	if(inicio == (struct ptr *)NULL)
		printf("LISTA VAZIA");
	else
	{
		if(aux != (struct ptr *)NULL)
		{
			printf("%d\t", aux->valor);
			aux = aux->prox;
			mostra(aux);
		}
	}
}

void cria_lista_inv()
{
	int valor;
	struct ptr *aux;
	printf("ENTRE COM UM VALOR: ");
	scanf("%d", &valor);
	if(valor < 0)
		aux = (struct ptr *)NULL;
	else
	{
		aux = (struct ptr *)malloc(sizeof(struct ptr));
		aux->valor = valor;
		aux->prox = inicio;
		inicio = aux;
		cria_lista_inv();
	}
}

void organizar()
{
	struct ptr *aux, *aux2;
	aux = (struct ptr *)NULL;
		void inserir_ordenado(struct ptr *maior, struct ptr *menor, int valor)
		{
			if(aux == (struct ptr *)NULL)
			{
				aux = (struct ptr *)malloc(sizeof(struct ptr));
				aux->prox = (struct ptr *)NULL;
				aux->valor = valor;
			}
			else
			{
				if(valor < aux->valor)
				{
					maior = (struct ptr *)malloc(sizeof(struct ptr));
					maior->valor = valor;
					maior->prox = aux;
					aux = maior;
					maior = (struct ptr *)NULL;
				}
				else
				{
					if(maior->valor < valor && maior->prox != (struct ptr *)NULL)
					{
						menor = maior;
						maior = maior->prox;
						inserir_ordenado(maior, menor, valor);
					}
					else
					{
						if(maior->valor < valor)
						{
							maior->prox = (struct ptr *)malloc(sizeof(struct ptr));
							maior = maior->prox;
							maior->valor = valor;
							maior->prox = (struct ptr *)NULL;
							maior = (struct ptr *)NULL;
							menor = maior;
						}
						else
						{
							menor->prox = (struct ptr *)malloc(sizeof(struct ptr));
							menor->prox->prox = maior;
							menor->prox->valor = valor;
							menor = (struct ptr *)NULL;
							maior = menor;
						}
					}
				}
			}
		}
	while(inicio != (struct ptr *)NULL)
	{
		inserir_ordenado(aux, aux, inicio->valor);
		aux2 = inicio->prox;
		free(inicio);
		inicio = aux2;
	}
		inicio = aux;	
}
