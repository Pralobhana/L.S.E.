#include <stdio.h>

struct ptr 
{
	int valor;
	struct ptr *prox;
};

struct ptr *inicio;
void cria_lista();

int main()
{
	cria_lista();
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
