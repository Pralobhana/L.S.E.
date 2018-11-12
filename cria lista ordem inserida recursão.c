#include <stdio.h>
struct ptr
{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;
void mostra(struct ptr *aux);
void cria_lista(struct ptr *aux);
int main()
{
    cria_lista((struct ptr *)NULL);
    mostra(inicio);
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
void cria_lista(struct ptr *aux){ 
    int valor;
    if(aux == (struct ptr *)NULL)
        inicio = (struct ptr *)NULL;
    printf("ENTRE COM O VALOR: ");
    scanf("%d", &valor);
    if(valor >= 0)
	{
        if(inicio == (struct ptr *)NULL)
		{
            inicio = (struct ptr *)malloc(sizeof(struct ptr));
            inicio->valor = valor;
            inicio->prox = (struct ptr *)NULL;
            aux = inicio;
        }
        else
		{
            aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
            aux = aux->prox;
            aux->valor = valor;
            aux->prox = (struct ptr *)NULL;
        }
       cria_lista(aux);
    }
    aux = (struct ptr *)NULL;
}
