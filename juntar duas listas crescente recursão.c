#include <stdio.h>

struct ptr
{
	int valor;
	struct ptr *prox;
};

void mostrar(struct ptr *aux);
struct ptr *inicio;
void unidas();

int main()
{
	unidas();
	mostra(inicio);
}

void mostra(struct ptr *aux)
{
	if(inicio == (struct ptr*)NULL)
		printf("LISTA VAZIA");
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

void unidas()
{
	struct ptr *l1, *l2;
	l1 = (struct ptr *)NULL;
	l2 = l1;
	void criar(struct ptr *fim, struct ptr **aux, int valor)
	{
		printf("ENTRE COM O VALOR: ");
		scanf("%d", &valor);
		if(*aux == (struct ptr *)NULL)
		{
			*aux = (struct ptr *)malloc(sizeof(struct ptr));
			(*aux)->valor = valor;
			(*aux)->prox = (struct ptr *)NULL;
			criar(*aux, &(*aux), valor);
		}
		else
		{
			if(valor >= 0)
			{
				fim->prox = (struct ptr *)malloc(sizeof(struct ptr));
				fim = fim->prox;
				fim->valor = valor;
				fim->prox = (struct ptr *)NULL;
				criar(fim, &(*aux), valor);
			}
		}
	}
	void juntas(struct ptr *aux1, struct ptr **aux2)
	{
		if(aux1->prox != (struct ptr *)NULL)
		{
			aux1 = aux1->prox;
			juntas(aux1, &(*aux2));
		}
		else
		{
			aux1->prox = *aux2;
			*aux2 = (struct ptr *)NULL;
			aux1 = *aux2;
		}
		
	}
	void organizar(struct ptr *aux, struct ptr *aux2)
	{
			void inserir_ordenado(struct ptr *maior, struct ptr *menor, int valor)
			{
				if(aux == (struct ptr *)NULL)
				{
					aux = (struct ptr *)malloc(sizeof(struct ptr));
						aux->prox = (struct ptr *)NULL;
						aux->valor = valor;
					}
					else
					{
						if(valor < aux->valor)
						{
							maior = (struct ptr *)malloc(sizeof(struct ptr));
							maior->valor = valor;
							maior->prox = aux;
							aux = maior;
							maior = (struct ptr *)NULL;
						}
						else
						{
							if(maior->valor < valor && maior->prox != (struct ptr *)NULL)
							{
								menor = maior;
								maior = maior->prox;
								inserir_ordenado(maior, menor, valor);
							}
							else
							{
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
			}
			if(inicio != (struct ptr *)NULL){
				inserir_ordenado(aux, aux, inicio->valor);
				aux2 = inicio->prox;
				free(inicio);
				inicio = aux2;
				organizar(aux, aux2);
			}
			else
				inicio = aux;
	}
	criar(l1, &l1, 0);
	criar(l2, &l2, 0);
	juntas(l1, &l2);
	inicio = l1;
	organizar((struct ptr *)NULL, (struct ptr *)NULL);
}
