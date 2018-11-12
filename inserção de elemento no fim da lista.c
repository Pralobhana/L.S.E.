#include <stdio.h>
struct ptr
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;
void cria_lista_inv();
void inserir_fim();
void mostra();
int main()
{
	cria_lista_inv();
	inserir_fim();
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
void inserir_fim()
{
	struct ptr *aux;
	int valor;
	printf("ENTRE COM O VALOR: ");
	scanf("%d", &valor);
	if(inicio == (struct ptr *)NULL)
	{
		inicio->valor = valor;
		inicio->prox = (struct ptr *)NULL;
	}
	else
	{
		aux = inicio;
		while(aux->prox != (struct ptr *)NULL)
			aux = aux->prox;
		aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
		aux = aux->prox;
		aux->valor = valor;
		aux->prox = (struct ptr *)NULL;
	}
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
			aux = aux->prox;
		}
	}
}
