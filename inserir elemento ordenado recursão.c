// OBS: Supor que, se a lista exstir, ela estará em ordem crescente.
// Exemplo: entrar com 5, 4, 2, 1, -1 e 3.

#include <stdio.h>
struct ptr
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;
void cria_lista_inv(struct ptr *aux);
void inserir_ordenado(int valor, struct ptr *p, struct ptr *aux);
void mostra(struct ptr *aux);
int main()
{
	cria_lista_inv((struct ptr *)NULL);
	inserir_ordenado(10, (struct ptr *)NULL, inicio);
	mostra(inicio);
}
cria_lista_inv(struct ptr *aux)
{
	int valor;
	inicio = (struct ptr *)NULL;
	printf("ENTRE COM O VALOR: ");
	scanf("%d", &valor);
	if(valor >= 0)
	{
		aux = (struct ptr *)malloc(sizeof(struct ptr));
		aux->valor = valor;
		aux->prox = inicio;
		inicio = aux;
	}
	aux = (struct ptr *)NULL;
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
