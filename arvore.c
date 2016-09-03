//O programa preenche os nós de uma arvore binária
//Os filhos dessa arvore serão alocados por níveis
// da esquerda para a direita

#include <stdio.h>

#define max 1000

typedef struct arvore
{
	int info;      //informação do nó
	nos *dir;
	nos *esq;
}nos;

void aloca_nos(nos *raiz);

int main()
{
	int numero-nos, k, lista[max];
	nos *raiz;
	raiz = NULL;
	printf("Qual a quantidade de nós que a arvore terá : ");
	scanf("%d", &numero-nos);
	for(k=0;k<numero-nos;k++)
	{
		lista[k]=-1;
	}
	for(k=0; k<numero-nos;k++)
	{
		aloca_nos(raiz);
	}
	return 0;
}
void aloca_nos(nos *raiz, int fila[])
{
	int aux=0;
	nos *novo_no;
	printf("Qual a informação armazenada no nó: ");
	scanf("%d", novo_no.info);
	novo_no.dir = NULL;
	novo_no.esq = NULL;
	while(lista[aux]!=1)
	{
		aux++;
	}
	lista[aux]=novo_no.info;
	if(raiz==NULL)
	{
		printf("Esse será o nó raiz: %d\n", novo_no.info);
		raiz = novo_no;
		fila[0] = novo_no.info;
	}
	else
	{
		aux=0;
		while(lista)
	}
}