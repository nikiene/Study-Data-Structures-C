#include "BST.h"

Celula bstCriaCelula(int chave)
{
	Celula novaCelula = (Celula)malloc(sizeof(Node));

	novaCelula->chave = chave;

	novaCelula->pai = NULL;

	novaCelula->fEsq = NULL;
	novaCelula->fDir = NULL;

	return novaCelula;
}

int bstAlturaMaxima(int altura)
{
	return (pow(2, altura) -1);
}

int bstMaximoFolhas(int altura)
{
	return pow(2, altura -1);
}

Celula bstBusca(Celula raiz, int alvo)
{
	if (raiz == NULL || raiz->chave == alvo)
	{
		return raiz;
	} 
	else if (alvo > raiz->chave)
	{
		return bstBusca(raiz->fDir, alvo);
	}
	else 
	{
		return bstBusca(raiz->fEsq, alvo);
	}
}

Celula bstMinimo(Celula raiz)
{
	if (raiz == NULL || raiz->fEsq == NULL)
	{
		return raiz;
	} 
	else
	{
		return bstMinimo(raiz->fEsq);
	}
}

Celula bstMaximo(Celula raiz)
{
	if (raiz == NULL || raiz->fDir == NULL)
	{
		return raiz;
	}
	else
	{
		return bstMaximo(raiz->fDir);
	}
}

Celula bstInsert(Celula raiz, int chave)
{
	if (raiz == NULL)
	{
		return bstCriaCelula(chave);
	}

	if (chave > raiz->chave)
	{
		raiz->fDir = bstInsert(raiz->fDir, chave);
	}
	else
	{
		raiz->fEsq = bstInsert(raiz->fEsq, chave);
	}

	return  raiz;
}

void inOrder(Celula raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	inOrder(raiz->fEsq);
	printf("%d ", raiz->chave);
	inOrder(raiz->fDir);
}

void preOrder(Celula raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	printf("%d ", raiz->chave);
	preOrder(raiz->fEsq);
	preOrder(raiz->fDir);
}

void postOrder(Celula raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	postOrder(raiz->fEsq);
	postOrder(raiz->fDir);
	printf("%d ", raiz->chave);
}

void bstPrint(Celula raiz)
{
	int opc = 0;

	printf("\nDigite o algoritmo desejado: 1- inOrder | 2- preOrder | 3- postOrder\n");
	scanf("%d", &opc);
	getchar();

	switch(opc)
	{
		//InOrder (Esquerda, Raiz, Direita)
		case 1:
			inOrder(raiz);
			break;
		//PreOrder (Raiz, Esquerda, Direita)
		case 2:
			preOrder(raiz);
			break;
		//PostOrder (Esquerda, Direita, Raiz)
		case 3:
			postOrder(raiz);
			break;
		default:
			break;
	}
}