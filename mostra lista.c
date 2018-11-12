#include <stdio.h>

struct ptr 
{
	int valor;
	struct ptr *prox;
};

struct ptr *inicio;
void cria_lista();
void mostra();

int main()
{
	cria_lista();
	mostra();
}

void cria_lista()
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
