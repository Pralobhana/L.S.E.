#include <stdio.h>
struct ptr 
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;
void cria_lista();
float media();
int main()
{
	cria_lista();
	printf("\nMEDIA DOS ELEMENTOS DA LISTA: %.1f", media());
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
float media()
{
	struct ptr *aux;
	int soma = 0, cont = 0;
	aux = inicio;
	if(inicio == (struct ptr *)NULL)
		return 0;
	else
	{
		while(aux != (struct ptr *)NULL)
		{
			cont++;
			soma += aux->valor;
			aux = aux->prox;
		}
		return (float)soma/cont;
	}
}
