#include <stdio.h>
#include <stdlib.h>
struct arvore
{
    char valor;
    struct arvore *esq, *dir;
};

struct arvore *inicio;
void constroi(struct arvore **inicio);
int tot_nos(struct arvore *aux, int cont);
int tot_folha(struct arvore*aux, int cont);
int altura(struct arvore *aux, int maior, int nivel);
int foo(struct arvore *aux, int nivel, int cont, int n);
int nos_nivel(int altura, int nivel);
int cont;

int main()
{
    constroi(&inicio);
    infix(inicio);
    printf("%d", tot_nos(inicio, 0));
    printf("%d", tot_folha(inicio, 0));
    printf("\nALTURA DA ARVORE: ");
    printf("%d", altura(inicio, 0, 0));
    nos_nivel(altura(inicio, 0, 0), 0);
}

//constrói a árvore binária
void constroi(struct arvore **inicio)
{
    char n;
    printf("ENTRE COM O VALOR: ");
    scanf(" %c",&n);
    if(n!='.')
	{
        *inicio = (struct arvore *)malloc(sizeof(struct arvore));
        (*inicio)->valor = n;
        constroi(&(*inicio)->esq);
        constroi(&(*inicio)->dir);
    }
    else 
        *inicio = (struct arvore *)NULL;
}

//retorna o total de nós da árvore
int tot_nos(struct arvore *aux, int cont)
{
    if(aux == inicio)
        printf("TOTAL DE NOS: ");
    if(aux != (struct arvore*)NULL)
	{
        cont++;
        cont = tot_nos(aux->esq, cont);
        cont = tot_nos(aux->dir, cont);
    }    
    return cont;
}

//retorna o total de nós folha
int tot_folha(struct arvore *aux, int cont)
{
    if(aux == inicio)
        printf("\nTOTAL DE NOS FOLHA: ");
    if(aux != (struct arvore*)NULL)
	{
        if((aux->esq == (struct arvore*)NULL) && (aux->dir == (struct arvore*)NULL))
            cont++;
        cont = tot_folha(aux->esq, cont);
        cont = tot_folha(aux->dir, cont);
    }    
    return cont;
}

//retorna a altura da árvore
int altura(struct arvore *aux, int maior, int nivel)
{
    if(aux != (struct arvore*)NULL)
	{
        if(nivel > maior)
            maior = nivel;
       maior = altura(aux->esq, maior, nivel+1);
       maior = altura(aux->dir, maior, nivel+1);
    }
    return maior;
}

//retorna a quantidade de nós por nível
int nos_nivel(int altura, int nivel)
{
    if(nivel <= altura)
	{
        printf("\nNIVEL %d: %d NOS", nivel, foo(inicio, 0, 0, nivel));
        nos_nivel(altura,nivel+1);
    }
}

//retorna o número de nós em um dado nivel
int foo(struct arvore *aux, int nivel, int cont, int n)
{
    if(aux != (struct arvore*)NULL)
	{
        if(nivel == n)
        	cont++;
		cont = foo(aux->esq, nivel+1, cont, n);
    	cont = foo(aux->dir, nivel+1, cont, n);
        
    }
    return cont;
}

//printa a árvore de maneira infixa
void infix(struct arvore *arv)
{
	if(arv != NULL)
	{
		printf("%c ", arv->valor);
		infix(arv->esq);
		infix(arv->dir);
	}
	else 
		printf(". ");
}
