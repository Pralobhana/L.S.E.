#include <stdio.h>
struct ptr
{
	int valor;
	struct ptr *prox;	
};
struct ptr *inicio;
void cria_lista_inv(struct ptr *aux);
void apagar();
void mostra(struct ptr *aux);
int main()
{
	cria_lista_inv((struct ptr *)NULL);
	apagar();
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
void apagar()
{
	struct ptr *aux;
    if(inicio != (struct ptr *)NULL)
	{
        aux = inicio;
        inicio = inicio->prox;
        aux->prox = (struct ptr *)NULL;
        free(aux);
        aux = (struct ptr *)NULL;
        apagar();
    }
}
