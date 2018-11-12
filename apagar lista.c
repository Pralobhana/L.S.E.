#include <stdio.h>
struct ptr {
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;
void cria_lista_inv();
void apagar();
int main()
{
	cria_lista_inv();
	apagar();
}
void cria_lista_inv()
{
	int valor;
	struct ptr *aux;
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
void apagar()
{
	struct ptr *aux;
	while(inicio != (struct ptr *)NULL)
	{
		aux = inicio;
		inicio = inicio->prox;
		aux->prox = (struct ptr *)NULL;
		free(aux);
	}
	aux = (struct ptr *)NULL;
	printf("LISTA DELETADA COM SUCESSO!");
}
