#include <stdio.h>
struct ptr
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;
void cria_lista_ordenada();
void inserir_ordenado(int valor);
void mostra();
int main()
{
	cria_lista_ordenada();
	mostra();
}
void cria_lista_ordenada()
{
	int valor;
		inicio = (struct ptr *)NULL;
	printf("ENTRE COM VALOR: ");
	scanf("%d", &valor);
	while(valor >= 0)
	{
		inserir_ordenado(valor);
		printf("ENTRE COM O VALOR: ");
		scanf("%d", &valor);
	}
}
void inserir_ordenado(int valor)
	{
		struct ptr *maior, *menor;
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
			aux=aux->prox;
		}
	}
}
