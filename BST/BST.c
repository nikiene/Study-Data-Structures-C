#include "BST.h"

Celula bstCriaCelula(int info) {

	Celula novaCelula = (Celula)malloc(sizeof(Celula));

	return novaCelula;
}

Arvore* bstCriaArvore() {

	Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));

	arvore->raiz = NULL;

	return arvore;
}

void transplante(Arvore arvore*, Celula celulaA, Celula celulaB) {

	if (celulaA->pai == NULL)
	{
		arvore->raiz = celulaB;
	}
	else if (celulaA == celulaA->pai->fEsq)
	{
		celulaA->pai->fEsq = celulaB;
	}
	else 
	{
		celulaA->pai->fDir = celulaB;
	}

	if (celulaB != NULL)
	{
		celulaB->pai = celulaA->pai;
	}
}

void bstRemover(Arvore* arvore, Celula celula) {

	if (celula->fEsq == NULL)
	{
		transplante(arvore, celula, celula->fDir);
	}
	else if (celula->fDir == NULL)
	{
		transplante(arvore, celula, celula->fEsq);
	}
	else 
	{
		Celula aux = bstMinimo(celula->fDir);
		if (aux->pai != celula)
		{
			transplante(arvore, aux, aux->fDir);
			aux->fDir = arvore->fDir;
			aux->dir->pai = aux;
		}
		transplante(arvore, celula, aux);
		aux->fEsq = celula->fEsq;
		aux->fEsq->pai = aux;
	}
}

Celula bstMinimo(Arvore* arvore) {

	if (arvore->raiz->fEsq == NULL)
	{
		return arvore->raiz;
	}

	Celula aux = arvore->raiz;

	while(aux != NULL) 
	{
		aux = aux->fEsq;
	}

	return aux; 		
}

Celula bstMaximo(Arvore* arvore) {
	
	if (arvore->raiz->fDir == NULL)
	{
		return arvore->raiz;
	}

	Celula aux = arvore->raiz;

	while(aux != NULL)
	{
		aux = aux->fDir;
	}

	return aux;
}