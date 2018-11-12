#include <stdio.h>

struct ptr 
{
	int valor;
	struct ptr *prox;
};

struct ptr *inicio;
void cria_lista_inv();
void conta();

int main()
{
	cria_lista_inv();
	conta();
}

void cria_lista_inv()
{
	struct ptr *aux;
	int valor;
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

void conta()
{
	struct ptr *aux;
	int cont = 0;
	aux = inicio;
	while (aux != (struct ptr *)NULL)
	{
		cont++;
		aux = aux->prox;
	}
	printf("\nTOTAL DE ELEMENTOS: %d", cont);
}
