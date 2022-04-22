#include "BST.h"

Raiz* bstCriaRaiz()
{
	Raiz* novaRaiz = (Raiz*)malloc(sizeof(Raiz));

	novaRaiz->raiz = NULL;

	return novaRaiz;
}

Celula bstCriaCelula()
{
	
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