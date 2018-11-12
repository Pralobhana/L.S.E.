// OBS: Supor que, se a lista exstir, ela estará em ordem crescente.
// Exemplo: entrar com 5, 4, 2, 1, -1 e 3.

#include <stdio.h>
struct ptr
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;
void cria_lista_inv();
void inserir_ordenado();
void mostra();
int main()
{
	cria_lista_inv();
	inserir_ordenado();
	mostra();
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
void inserir_ordenado()
{
	struct ptr *maior, *menor;
	int valor;
	printf("ENTRE COM O VALOR: ");
	scanf("%d", &valor);
	if(inicio == (struct ptr *)NULL)
	{
		inicio = (struct ptr *)malloc(sizeof(struct ptr));
		inicio->prox = (struct ptr *)NULL;
		inicio->valor = valor;
	}
	else
	{
		if(valor < inicio->valor)
		{
			maior = (struct ptr *)malloc(sizeof(struct ptr));
			maior->valor = valor;
			maior->prox = inicio;
			inicio = maior;
			maior = (struct ptr *)NULL;
		}
		else
		{
			maior = inicio;
			while((maior->valor < valor) && (maior->prox != (struct ptr *)NULL))
			{
				menor = maior;
				maior = maior->prox;
			}
			if(maior->valor < valor)
			{
				maior->prox = (struct ptr *)malloc(sizeof(struct ptr));
				maior = maior->prox;
				maior->valor = valor;
				maior->prox = (struct ptr *)NULL;
				maior = (struct ptr *)NULL;
				menor = maior;
			}
			else
			{
				menor->prox = (struct ptr *)malloc(sizeof(struct ptr));
				menor->prox->prox = maior;
				menor->prox->valor = valor;
				menor = (struct ptr *)NULL;
				maior = menor;
			}
		}
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
