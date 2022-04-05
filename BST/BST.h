#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* pai;
	int info;
	struct node* fEsq;
	struct node* fDir;
} Node;

typedef Node* Celula;

typedef struct arvore
{
	Celula raiz;
} Arvore;

Celula bstCriaCelula(int info);

Arvore* bstCriaArvore();

void bstRemover(Arvore* arvore, Celula celula);

Celula bstMinimo(Arvore* arvore);

Celula bstMaximo(Arvore* arvore);