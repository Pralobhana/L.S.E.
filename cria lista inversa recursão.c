#include <stdio.h>

struct ptr 
{
	int valor;
	struct ptr *prox;
};

struct ptr *inicio, *aux;
void cria_lista_inv(struct ptr *aux);

int main()
{
	cria_lista_inv((struct ptr *)NULL);
}

void cria_lista_inv(struct ptr *aux)
{
	int valor;
	printf("ENTRE COM O VALOR: ");
	scanf("%d", &valor);
	if(valor >= 0)
	{
		aux = (struct ptr *)malloc(sizeof(struct ptr));
		aux->valor = valor;
		aux->prox = inicio;
		inicio = aux;
		cria_lista_inv(aux);
	}
	aux = (struct ptr *)NULL;
}
