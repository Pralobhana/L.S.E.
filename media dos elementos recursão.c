#include <stdio.h>
struct ptr 
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio, *aux;
void cria_lista_inv(struct ptr *aux);
float media(struct ptr *aux, int soma, int cont);
int main()
{
	cria_lista_inv((struct ptr *)NULL);
	printf("\nMEDIA DOS ELEMENTOS DA LISTA: %.1f", media(inicio, 0, 0));
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
float media(struct ptr *aux, int soma, int cont)
{
	if(aux != (struct ptr *)NULL)
	{
		cont++;
		soma += aux->valor;
		aux = aux->prox;
		return media(aux, soma, cont);
	}
	else
	{
		if(cont)
			return (float)soma/cont;
		else
			return 0;
	}
}
