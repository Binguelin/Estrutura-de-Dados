#include <bits/std++.h>


// estrutura da arvore
typedef struct arvore{
	int chave;
	int bal;           // balanco dos nohs
	arvore *esq;
	arvore *dir;
}no;

int cria(no **arv) //cria arvore chamando insere repetidas vezes
{
	int n, x, flag;
	printf("Quantos nós serao adicionados: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &x);
		flag = insere(&(*arv), x);
	}
	return flag;
}

void imprime(no **arv) // imprime a arvore em formato de barras
{
    int h;
    h =  altura(&(*arv));
    if(h>0)
    {
        for(int i=0;i<h;i++)
            printf("-");
        printf("%d", (*arv)->chave);
        imprime(&(*arv)->esq);
        imprime(&(*arv)->dir); 
    }
}

int busca(no **arv, int chave, no **pai) //funçao que busca um noh na arvore e retorna o pai desse noh por referencia 
{
	no *aux;
	aux = (*arv);
	while((aux->esq != NULL && aux->dir != NULL) || aux->chave==chave)
	{
		(*pai) = aux;
		if(chave > aux->chave && aux->dir!=NULL)
			aux= aux->dir;
		else
		{
			if(chave > aux->chave && aux->dir== NULL)
				return 0;
			else
			{
				if(chave < aux->chave && aux->esq!=NULL)
					aux = aux->esq;
				else
					return 0;
			}
		}
	}
	if(aux->chave == chave)
		return 1;
	else
		return 0;
}

int desbalanceado(no **arv, no **aux) //verifica qual o primeiro no nao balaceado de baixo para cima
{
	no  *ult; //ult eh o ultimo no que esta desbalanceado
	ult = (*arv); //aux eh o no a ser retornado por referencia
	while(ult != NULL)
	{
				
	}
}

int altura(no **arv) // altura para calcular o balanco
{
	int h=0;
	no *aux;
	if(aux==NULL)
		return 0;
	else
	{
		if(altura(&aux->dir) > altura(aux->esq))
			h = altura(&aux->dir) + 1;
		else
			h = altura(&aux->esq) + 1;
	}
	return h;
}

int bal(no **arv)// balanco sera usando na insercao
{
	return altura(&(*arv)->dir) - altura(&*(arv)->esq)
}

int insere(no **arv, int chave) //atentar aos casos de rotacao
{

	// com o fator de bal pode-se retirar a funcao desbalanceado
	// , a funcao bal e talvez a funcao altura
	int flag=1, galf;
	no *aux, *pai, *desb; //desb esta desbalanceado
	if((*arv)== NULL)
	{
		(*arv) = (no *) malloc(sizeof(no));
		(*arv)->chave = chave;
		(*arv)->esq=NULL;
		(*arv)->dir=NULL;
	}
	else
	{
		aux  =  (*arv);
		while(aux != NULL)
		{
			pai = aux;
			if(chave < aux->chave)
			{
				aux = aux->esq;
				bal--;
				flag=0;
			}
			else
			{	
				if(chave > aux->chave )
				{
					aux = aux->dir;
					flag=1;
				}
				else
					return 0;
			}
		}
		aux->chave =  chave;
		aux->esq=NULL;
		aux->dir=NULL;
		if(flag==1)
			pai->dir = aux;
		else
			pai->esq = aux;
		glaf = desbalanceado(&(*arv), &(*desb));
		if(glaf==1) // olhar o nó pai e o nó filho com o maior bal para ver a rotacao
			rota
	}
	return 1;
}

void rotacao(no **arv, int tipo) //tipo q eh qual a rotacao sera feita
{

}

int main()
{
	int op, x;
	no *arv;
	printf("Criando a arvore\n");
	cria(&(*arv));
	scanf("%d", &op);
	while(op!=5) //opcoes para o usuario
	{
		printf("1 - insere um no\n");
		printf("2 - verifica se um no esta na arvore\n");
		printf("3 - remove um noda arvore\n");
		printf("4 - imprime a arvore em diagrama de barras\n");
		printf("5 - fim\n");
		if(op==1)
			cria(&(*arv));
		else
		{
			if(op==2)
			{
				scanf("%d", &x);
				printf("%d\n", busca(&(*arv), x)); // 1 se o no esta na arvore e 0 caso contrario
			}
			else
			{
				if(op==3)
				{
					scanf("%d", &x);
					printf("O no %d foi removido\n", x);
				}
				else
				{
					imprime(&(*arv));
				}
			}
		}
		scanf("%d", &op);
	}
        // liberar todos os nohs da memoria para destruir a arvore
	return 0;
}
