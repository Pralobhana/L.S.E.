#include <stdio.h>
#include <stdlib.h>
struct ptr 
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;
void cria_lista_inv();
void remover();
void mostra();
int main()
{
	cria_lista_inv();
	mostra();
	remover();
	mostra();
}
void cria_lista_inv()
{
	int valor;
	struct ptr *aux;
	inicio = (struct ptr *)NULL;
	printf("ENTRE COM O VALOR: ");
	scanf("%d", &valor);
	while(valor >= 0)
	{
		aux = (struct ptr *)malloc(sizeof(struct ptr));
		aux->valor = valor;
		aux->prox = inicio;
		inicio = aux;
		printf("ENTRE COM O VALOR: ");
		scanf("%d", &valor);
	}
	aux = (struct ptr *)NULL;
}
void mostra()
{
	printf("\n");
	struct ptr *aux;
	if(inicio == (struct ptr *)NULL)
		printf("LISTA VAZIA!");
	else
	{
		aux = inicio;
		while(aux != (struct ptr *)NULL)
		{
			printf("%d\t", aux->valor);
			aux=aux->prox;
		}
	}
}
void remover()
{
	int valor;
	struct ptr *maior, *menor;
	printf("\nENTRE COM O VALOR  SER DELETADO: ");
	scanf("%d", &valor);
	if(inicio == (struct ptr *)NULL)
		printf("LISTA VAZIA!");
	else
	{
		if(inicio->prox == (struct ptr *)NULL)
			if(inicio->valor != valor)
				printf("VALOR NAO ENCONTRADO!");
			else
			{
				free(inicio);
				inicio = (struct ptr *)NULL;
			}
		else
		{
			if(valor == inicio->valor)
			{
				maior = inicio;
				inicio = inicio->prox;
				maior->prox = (struct ptr *)NULL;
				free(maior);
				maior = (struct ptr *)NULL;
			}
			else
			{
				maior = inicio;
				while((maior->valor != valor) && (maior->prox) != (struct ptr *)NULL)
				{
					menor = maior;
					maior = maior->prox;
				}
				if(maior->valor != valor)
					printf("VALOR NAO ENCONTRADO!");
				else
				{
					if(maior->prox == (struct ptr *)NULL)
					{
						menor->prox = (struct ptr *)NULL;
						free(maior);
						maior = (struct ptr *)NULL;
						menor = maior;
					}
					else
					{
						menor->prox = maior->prox;
						maior->prox = (struct ptr *)NULL;
						free(maior);
						maior = (struct ptr *)NULL;
						menor = maior;
					}
				}
			}
		}
	}
}
