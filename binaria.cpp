#include <bits/stdc++.h>

using namespace std;

typedef struct arvore{
  int chave;
  arvore *esq;
  arvore *dir;
}no;

void insere(no **arv, int chave)
{
  if((*arv)==NULL)
  {
    (*arv) = (no *) malloc(sizeof(no));
    (*arv)->chave = chave;
    (*arv)->esq = NULL;
    (*arv)->dir = NULL;
  }
  else
  {
    if((*arv)->chave > chave)
      insere(&((*arv)->esq), chave);
    else
      insere(&((*arv)->dir), chave);
  }
  
}
void cria_arvore(no ** arv)
{
    int n, x;
    scanf("%d", &n); //número de nós da arvore
    for(int i=0;i<n;i++)
    {
        scanf("%d", &x);
        insere(&(*arv), x);
    }
}
int busca(no **arv, int chave, no **pai)
{
    no *aux;
    aux = (*arv);
    if(aux == NULL)
        return 0;
    while(aux->chave!=chave && aux!=NULL)
    {
        (*pai) = aux;
        if(aux->chave > chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    return 1;
}
void remove(no **arv, int x)
{
    no *pt, *pai_pt;
    pt = (*arv);
    busca(&pt, x,&pai_pt);
    if(pt->esq == NULL && pt->dir == NULL)
    {
        if(pai_pt->dir == pt)
            pai_pt->dir=NULL;
        else
            pai_pt->esq=NULL;
        free(pt);
    }
    else
    {
        if(pt->esq == NULL)
        {
            no *aux;
            aux =  pt->dir;
            while(aux != NULL)
                aux = aux->esq;
            (pt->dir)->chave = aux->chave;
            remove(&aux, aux->chave);
        }
        else
        {
            if(pt->dir == NULL)
            {
                no *aux;
                aux = pt->esq;
                while(aux != NULL)
                    aux = aux->dir;
                (pt->esq)->chave = aux->chave;
                remove(&aux, aux->chave);
            }
        }
    }
}
int altura(no ** arv)
{
	int h=1;
	no *aux;
	if(aux==NULL)
		return 0;
	while(aux!=NULL)
	{
		if(altura(&aux->dir) > altura(&aux->esq))
			h = altura(&aux->dir) + 1;
		else
			h = altura(&aux->esq) + 1;
	}
	return h;
}
void imprime(no **arv)
{
    int h;
    h = altura(&(*arv));
    if(h>0)
    {
         for(int i=0;i<h;i++)
             printf("-");
         printf("%d", (*arv)->chave);
         imprime(&(*arv)->esq);
         imprime(&(*arv)->dir);
    }
}
int main ()
{
  no *arv, *aux, *aux1;
  int teste;
  scanf("%d", &teste);
  for(int i=0; i<teste;i++)
  {
    arv = NULL;
    cria_arvore(&arv);
    free(arv);
  }
  return 0;
}
