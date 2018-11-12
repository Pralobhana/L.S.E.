#include <stdio.h>
struct ptr
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;
void cria_lista_inv(struct ptr *aux);
void mostra(struct ptr *aux);
void remover(int valor, struct ptr *p, struct ptr *aux);
int main()
{
	cria_lista_inv((struct ptr *)NULL);
	mostra(inicio);
	remover(10, (struct ptr *)NULL, inicio);
	mostra(inicio);
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
void mostra(struct ptr *aux)
{
	if(inicio == (struct ptr *)NULL)
		printf("LISTA VAZIA!");
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
void remover(int valor, struct ptr *p, struct ptr *aux)
{
	if(inicio == (struct ptr *)NULL)
		printf("LISTA VAZIA!");
	else
	{
		if(inicio->valor == valor)
		{
			aux = inicio;
			inicio = inicio->prox;
			aux->prox = (struct ptr *)NULL;
			free(aux);
			aux = (struct ptr *)NULL;	
		}	
		else
		{
			aux = inicio;
			while(aux->prox != (struct ptr *)NULL && aux->valor != valor)
			{
				p = aux;
				aux = aux->prox;
			}
			if(aux->valor == valor)
			{
				p->prox = aux->prox;
				aux->prox = (struct ptr *)NULL;
				free(aux);
				aux = (struct ptr *)NULL;
			}
			else
				printf("ELEMENTO NAO ENCONTRADO!");
		}
	}
	aux = (struct ptr *)NULL;
	p = aux;
}
