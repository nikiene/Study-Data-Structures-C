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

Raiz* bstCriaRaiz()
{
	Raiz* novaRaiz = (Raiz*)malloc(sizeof(Raiz));

	novaRaiz->raiz = NULL;

	return novaRaiz;
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

void bstInsert(Celula raiz, int chave)
{
	if (raiz == NULL)
	{
		raiz = bstCriaCelula(chave);
		return;
	}

	if (novaCelula->chave > raiz->chave)
	{
		raiz->fDir = bstInsert(raiz->fDir, chave);
	}
	else
	{
		raiz->fEsq = bstInsert(raiz->fEsq, chave);
	}
}

void bstPrint(Celula raiz, int opc)
{
	switch(opc)
	{
		//InOrder (Esquerda, Raiz, Direita)
		case 1:
			
			break;
		//PreOrder (Raiz, Esquerda, Direita)
		case 2:

			break;
		//PostOrder (Esquerda, Direita, Raiz)
		case 3:
			
			break;
		default:
			break;
	}
}