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
void cria_lista()
{
	int valor;
	struct ptr *fim;
	printf("ENTRE COM O VALOR: ");
	scanf("%d", &valor);
	inicio = (struct ptr *)NULL;
	fim = inicio;
	if(valor >= 0)
	{
		inicio = (struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor =  valor;
		inicio->prox = (struct ptr *)NULL;
		fim = inicio;
		printf("ENTRE COM O VALOR: ");
		scanf("%d", &valor);
		while(valor >= 0)
		{
			fim->prox = (struct ptr *)malloc(sizeof(struct ptr));
			fim = fim->prox;
			fim->valor = valor;
			fim->prox = (struct ptr *)NULL;
			printf("ENTRE COM O VALOR: ");
			scanf("%d", &valor);
		}
		fim = (struct ptr *)NULL;
	}
}
