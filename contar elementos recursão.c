#include <stdio.h>
struct ptr 
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio, *aux;
void cria_lista_inv(struct ptr *aux);
void conta(struct ptr *aux, int cont);
int main()
{
	cria_lista_inv((struct ptr *)NULL);
	conta(inicio, 0);
}
void cria_lista_inv(struct ptr *aux)
{
    int valor;
    if(aux == (struct ptr *)NULL)
        inicio = (struct ptr *)NULL;
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
void conta(struct ptr *aux, int cont)
{
	if(aux != (struct ptr *)NULL)
	{
		cont++;
		aux = aux->prox;
		conta(aux, cont);
	}
	else
		printf("\nTOTAL DE ELEMENTOS: %d", cont);
}
