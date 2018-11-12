#include <stdio.h>
struct ptr
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;
void inserir_ordenado(int valor, struct ptr *p, struct ptr *aux);
void cria_lista_ordenada(struct ptr *aux);
int main()
{
	cria_lista_ordenada((struct ptr *)NULL);
}
void cria_lista_ordenada(struct ptr *aux)
{
	int valor;
	if(aux == (struct ptr *)NULL)
		inicio = (struct ptr *)NULL;
	printf("ENTRE COM O VALOR: ");
	scanf("%d", &valor);
	if(valor >= 0)
	{
		inserir_ordenado(valor, (struct ptr *)NULL, inicio);
		cria_lista_ordenada(inicio);
	}
}
inserir_ordenado(int valor, struct ptr *p, struct ptr *aux)
{
	if(inicio == (struct ptr *)NULL)
	{
		inicio = (struct ptr *)malloc(sizeof(struct ptr));
		inicio->valor = valor;
		inicio->prox = (struct ptr *)NULL;	
	}	
	else
	{
		if(inicio->valor > valor)
		{
			aux = (struct ptr *)malloc(sizeof(struct ptr));
			aux->valor = valor;
			aux->prox = inicio;
			inicio = aux;
		}
		else
		{
			if(aux->prox != (struct ptr *)NULL && aux->valor <= valor)
			{
				p = aux;
				aux = aux->prox;
				inserir_ordenado(valor, p, aux);
			}
			else
			{
				if(aux->valor <= valor)
				{
					aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
					aux = aux->prox;
					aux->valor = valor;
					aux->prox = (struct ptr *)NULL;
				}
				else
				{
					p->prox = (struct ptr *)malloc(sizeof(struct ptr));
					p = p->prox;
					p->valor = valor;
					p->prox = aux;
				}
			}
		}
		aux = (struct ptr *)NULL;
		p = aux;
	}
}
